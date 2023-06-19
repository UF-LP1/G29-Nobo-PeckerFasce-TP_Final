#include "cONCOLOGO.h"

cONCOLOGO::cONCOLOGO(string nombre, string dni) :cMEDICO(nombre, dni) {

}

cONCOLOGO::~cONCOLOGO() {

}

void cONCOLOGO::pasar_lista_espera(cPACIENTE* paciente) {
	paciente->set_enEspera(true);
	throw exDosisMaxAlcanzadaPaciente();
	return;
}

void cONCOLOGO::sacar_lista_espera(cPACIENTE* paciente,cDOSIMETRISTA* dosimetrista)
{
	paciente->set_enEspera(false);
	generar_ficha_nueva(paciente, dosimetrista);//vuelvo a empezar para ver la salud, que tumores tiene y como los tengo que tratar, etc
}

void cONCOLOGO::atender_paciente(cPACIENTE* paciente) {
	unsigned int nuevadosisT = 0;
	unsigned int nuevadosisP = 0;
	bool flagtumor = false;
	int tamanio = paciente->get_ficha()->get_tumores().size();

	for (int i = 0; i < tamanio; i++) {
		
		//segun el tipo de tratamiento del tumor me guardo las dosis correspondientes
		if (dynamic_cast<cBRAQUITERAPIA*>(paciente->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr) {
			nuevadosisT = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion()+paciente->get_ficha()->get_tumores()[i]->get_dosisAcumTumor();
			nuevadosisP = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion()* 0.6 + paciente->get_ficha()->get_dosisAcumTotal();
			if (nuevadosisT  > cBRAQUITERAPIA::dosisMaxTumor) { //si la dosis nueva supera la maxima del tumor
				paciente->get_ficha()->get_tumores().erase(paciente->get_ficha()->get_tumores().begin() + i); //elimino el tumor de la lista para que no siga siendo tratado
				flagtumor = true;
				throw exDosisMaxAlcanzadaTumor(); //lanzo una excepcion
			}
			if (nuevadosisP> cBRAQUITERAPIA::dosisMaxPaciente) {
				pasar_lista_espera(paciente); //si el paciente ya alcanzo su dosis de radiacion maxima lo paso a lista de espera
				return; //me voy de la funcion porque nova a continuar su tratamiento por ahora
			}
		}else if (dynamic_cast<cHAZEXTERNO*>(paciente->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr){
			nuevadosisT = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() + paciente->get_ficha()->get_tumores()[i]->get_dosisAcumTumor();
			nuevadosisP = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() * 0.3 + paciente->get_ficha()->get_dosisAcumTotal();
			if (nuevadosisT > cHAZEXTERNO::dosisMaxTumor) {
				paciente->get_ficha()->get_tumores().erase(paciente->get_ficha()->get_tumores().begin() + i); 
				flagtumor = true;
				throw exDosisMaxAlcanzadaTumor();
			}
			if (nuevadosisP > cHAZEXTERNO::dosisMaxPaciente) {
				pasar_lista_espera(paciente);
				return;
			}
		}
		else if (dynamic_cast<cSISTEMICA*>(paciente->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr) {
			nuevadosisT = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() + paciente->get_ficha()->get_tumores()[i]->get_dosisAcumTumor();
			nuevadosisP = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() * 0.1 + paciente->get_ficha()->get_dosisAcumTotal();
			if (nuevadosisT > cHAZEXTERNO::dosisMaxTumor) {
				paciente->get_ficha()->get_tumores().erase(paciente->get_ficha()->get_tumores().begin() + i); 
				flagtumor = true;
				throw exDosisMaxAlcanzadaTumor();
			}
			if (nuevadosisP > cHAZEXTERNO::dosisMaxPaciente) {
				pasar_lista_espera(paciente);
				return;
			}
		}

		if (!flagtumor) { //si no alcanzo la max total ni la max del tumor
			paciente->get_ficha()->get_tumores()[i]->set_dosisAcumTumor(nuevadosisT);
			paciente->get_ficha()->set_dosisAcumTotal(nuevadosisP);
		}	
	}

	paciente->get_ficha()->acomodar_fechas();
	return;
}

void cONCOLOGO::generar_ficha_nueva(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista) {
	//me invento tumores
	generar_diagnostico(paciente);
	//me invento tratamientos 
	generar_tratamiento(paciente);
	//pido que me inventen dosis para los tratamientos
	dosimetrista->generar_dosis(paciente);
	//me fijo que tan seguido tiene que volver 
	paciente->get_ficha()->set_frecuenciaSemanal(this->generar_frecuenciaSemanal(paciente));
	//digo que la fecha de la ultima sesion fue hoy y te digo cuando tiene que volver el paciente 
	paciente->get_ficha()->acomodar_fechas();
	//calculo la dosis max del paciente
	paciente->get_ficha()->set_dosisMax(calcular_dosisMax(paciente));
	
	
	return;
}

void cONCOLOGO::generar_diagnostico(cPACIENTE* paciente) {
	srand(time(NULL));
	int cantTumores = rand() % 4+1;
	vector<eTipoTumor> tipos_tumores;
	for (int i = 0; i < cantTumores; i++) {
		do {
			tipos_tumores.push_back(eTipoTumor(rand() % 10));
		} while ((paciente->get_sexo() == 'f' && tipos_tumores[i] == prostata) || (paciente->get_sexo() == 'm' && (tipos_tumores[i] == mama || tipos_tumores[i] == utero)));
	}

	vector<cTUMOR*> tumores;
	for (int j = 0; j < cantTumores; j++)
	{
		cTUMOR* aux=new cTUMOR(tipos_tumores[j]);
		tumores.push_back(aux);
		tumores[j]->set_tamanio(eTamanioTumor(rand() % 3));
	}
	paciente->get_ficha()->set_tumores(tumores);
	
	return;
}

string cONCOLOGO::to_string() {
	stringstream ss;
	ss << "Oncologo " << this->nombre << ", con DNI: " << this->dni << " y numero de telefono: " << this->telefono;
	return ss.str();
}

unsigned int cONCOLOGO::calcular_dosisMax(cPACIENTE* paciente)
{
	bool hayHE, haySIS, hayBRAQ;
	hayHE = haySIS = hayBRAQ = false;
	unsigned int max;
	for (int i = 0; i < paciente->get_ficha()->get_tumores().size(); i++) {
		cRADIOTERAPIA* aux=paciente->get_ficha()->get_tumores()[i]->get_tratamiento();
		if (dynamic_cast<cBRAQUITERAPIA*>(aux) != nullptr)
			hayBRAQ = true;
		else if (dynamic_cast<cSISTEMICA*>(aux) != nullptr)
			haySIS = true;
		else
			hayHE = true;

	}
	if (hayHE || haySIS)
		max = cHAZEXTERNO::dosisMaxPaciente;
	else max = cBRAQUITERAPIA::dosisMaxPaciente;
	return max;
}

void cONCOLOGO::generar_tratamiento(cPACIENTE* paciente) {
	if (paciente->get_ficha()->get_tumores().empty()) {
		throw exNoHayTumores();
	}
	for (int i = 0; i < paciente->get_ficha()->get_tumores().size(); i++) {
		
		cRADIOTERAPIA* tratamiento;
		eTipoTumor aux = paciente->get_ficha()->get_tumores()[i]->tipo;
		srand(time(NULL));
		int hazExt = rand() % 2;
		//como el haz externo trata todos los tumores primero veo si lo trato con esto y sino le pongo el tratamiento especifico para el tipo de tumor del paciente 
		if (hazExt == 1 || aux == pulmon || aux == intestino) {
			tratamiento = new cHAZEXTERNO(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
			
		}
		else {
			switch (aux) {
			case cabeza: {
				tratamiento = new cBRAQUITERAPIA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case cuello: {
				tratamiento = new cBRAQUITERAPIA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case mama: {
				tratamiento = new cBRAQUITERAPIA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case utero: {
				tratamiento = new cBRAQUITERAPIA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case ojo: {
				tratamiento = new cBRAQUITERAPIA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case tiroides: {
				tratamiento = new cSISTEMICA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			case prostata: {
				tratamiento = new cSISTEMICA(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
				break;
			}
			}
		}

		paciente->get_ficha()->get_tumores()[i]->set_tratamiento(tratamiento);
	}
	return;
}

unsigned int cONCOLOGO::generar_frecuenciaSemanal(cPACIENTE* paciente)
{
	unsigned int frecuencia;
	if (paciente->get_salud() < 0.30) {
		frecuencia = 3;
	}
	else if (paciente->get_salud() < 0.60) {
		frecuencia = 2;
	}
	else  {
		frecuencia=1;
	}
	return frecuencia;
}
