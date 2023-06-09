#include "cONCOLOGO.h"

cONCOLOGO::cONCOLOGO(string nombre, string dni): nombre(nombre), dni(dni) {

}

cONCOLOGO::~cONCOLOGO() {

}

void cONCOLOGO::set_telefono(string telefono)
{
	this->telefono = telefono;
}

string cONCOLOGO::get_telefono() const
{
	return this->telefono;
}

string cONCOLOGO::get_nombre() const
{
	return this->nombre;
}

string cONCOLOGO::get_dni() const
{
	return this->dni;
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
	float nuevadosisT = 0;
	float nuevadosisP = 0;
	bool flagtumor = false;
	bool flagalguntumor = false;
	int tamanio = paciente->get_ficha()->get_tumores().size();

	for (int i = 0; i < tamanio; i++) {
		flagtumor = false;
		//segun el tipo de tratamiento del tumor me guardo las dosis correspondientes
		if (dynamic_cast<cBRAQUITERAPIA*>(paciente->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr) {
			nuevadosisT = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion()+paciente->get_ficha()->get_tumores()[i]->get_dosisAcumTumor();
			nuevadosisP = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion()* 0.6 + paciente->get_ficha()->get_dosisAcumTotal();
			if (nuevadosisT  > cBRAQUITERAPIA::dosisMaxTumor) { //si la dosis nueva supera la maxima del tumor
				flagtumor = true;
				flagalguntumor = true;
			}
			if (nuevadosisP> cBRAQUITERAPIA::dosisMaxPaciente) {
				pasar_lista_espera(paciente); //si el paciente ya alcanzo su dosis de radiacion maxima lo paso a lista de espera
				return; //me voy de la funcion porque nova a continuar su tratamiento por ahora
			}
		}else if (dynamic_cast<cHAZEXTERNO*>(paciente->get_ficha()->get_tumores()[i]->get_tratamiento()) != nullptr){
			nuevadosisT = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() + paciente->get_ficha()->get_tumores()[i]->get_dosisAcumTumor();
			nuevadosisP = paciente->get_ficha()->get_tumores()[i]->get_tratamiento()->get_dosisPorSesion() * 0.3 + paciente->get_ficha()->get_dosisAcumTotal();
			if (nuevadosisT > cHAZEXTERNO::dosisMaxTumor) {
				flagtumor = true;
				flagalguntumor = true;
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
				flagtumor = true;
				flagalguntumor = true;
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
		else {
			if (paciente->get_ficha()->get_tumores().size() == 1) { //si alcanzo la dosis maxima de su unico tumor lo paso a lista de espera
				pasar_lista_espera(paciente);
			}
		}
	}
		if(flagalguntumor)
			throw exDosisMaxAlcanzadaTumor(); //lanzo una excepcion si se curo de algun cancer

	paciente->get_ficha()->acomodar_fechas();
	return;
}

void cONCOLOGO::generar_ficha_nueva(cPACIENTE* paciente, cDOSIMETRISTA* dosimetrista) {
	paciente->get_ficha()->set_dniOncologo(this->dni);
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
	int cantTumores = rand() % 3+1;
	vector<eTipoTumor> tipos_tumores;
	for (int i = 0; i < cantTumores; i++) {
		
			tipos_tumores.push_back(eTipoTumor(rand() % 9));
			if ((paciente->get_sexo() == 'f' && tipos_tumores[i] == prostata) || (paciente->get_sexo() == 'm' && (tipos_tumores[i] == mama || tipos_tumores[i] == utero)))
			{
				tipos_tumores.erase(tipos_tumores.begin() + i);
				i--;
			}
		
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
	float max;
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
	
	for (int i = 0; i < paciente->get_ficha()->get_tumores().size(); i++) {
		
		cRADIOTERAPIA* tratamiento=new cSISTEMICA(mediano);
		eTipoTumor aux = paciente->get_ficha()->get_tumores()[i]->tipo;
		srand(time(NULL));
		int hazExt = rand() % 8;//para que no tenga una probabilidad tan alta de ser hazexterno, pongo un nro grande
		//como el haz externo trata todos los tumores primero veo si lo trato con esto y sino le pongo el tratamiento especifico para el tipo de tumor del paciente 
		if (hazExt == 1 || aux == pulmon || aux == intestino) {
			delete tratamiento;
			tratamiento = new cHAZEXTERNO(paciente->get_ficha()->get_tumores()[i]->get_tamanio());
			
		}
		else {
			delete tratamiento;
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

ostream& operator<<(ostream& out, cONCOLOGO& oncologo)
{
	out << oncologo.to_string();
	return out;
}
