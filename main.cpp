#include "cHOSPITAL.h"

using namespace std;

int main() {
	//--------------------------------------------------------SIMULACION------------------------------------------------------------------
	//me creo un hospital
	cHOSPITAL* hospital = new cHOSPITAL("NoboPecker", "micasa");
	//instancio pacientes
	cPACIENTE* paciente1 = new cPACIENTE("Susana Gimenez", "45678099", eTipoSangre(0), 'f');
	paciente1->set_enEspera(false);
	paciente1->set_salud(0.5);
	paciente1->set_telefono("2235448098");
	cPACIENTE* paciente2 = new cPACIENTE("Moria Casan", "44568099", eTipoSangre(4), 'f');
	paciente2->set_enEspera(false);
	paciente2->set_salud(0.1);
	paciente2->set_telefono("2267948098");
	cPACIENTE* paciente3 = new cPACIENTE("Ricky Fort", "45000099", eTipoSangre(2), 'm');
	paciente3->set_enEspera(false);
	paciente3->set_salud(0.9);
	paciente3->set_telefono("2235448778");
	//los agrego a la lista de pacientes del hospital
	*hospital + paciente1;
	*hospital + paciente2;
	*hospital + paciente3;
	//instancio dosimetristas - oncologos
	cDOSIMETRISTA* dosimetrista = new cDOSIMETRISTA("Doctor Milagro", "67098112");
	cONCOLOGO* oncologo1 = new cONCOLOGO("RuPaul", "10101010");
	cONCOLOGO* oncologo2 = new cONCOLOGO("Jesus Cristo", "0000000001");
	//los agrego a las listas de oncologo y dosimetrista
	*hospital + dosimetrista;
	*hospital + oncologo1;
	*hospital + oncologo2;
	//les creo una ficha asi tienen un cancer porque sino que te curo
	oncologo1->generar_ficha_nueva(paciente1, dosimetrista);
	oncologo2->generar_ficha_nueva(paciente2, dosimetrista);
	oncologo2->generar_ficha_nueva(paciente3, dosimetrista);
	//te muestro que bendicion les di 
	cout << *paciente1;
	cout << *paciente2;
	cout << *paciente3;
	//los atiendo asi les curo el cancer que les di <3
	//podriamos hacer un tratamiento entero en un loop hasta que se cure pero se hace un loop muy largo por la diferencia de proporcion que hay entre las dosis por seseion y las maximas
	try {
		oncologo1->atender_paciente(paciente1);
		oncologo2->atender_paciente(paciente2);
		oncologo2->atender_paciente(paciente3);
	}
	catch (exDosisMaxAlcanzadaTumor& etumor) {
		cout << etumor.what() << endl;
	}
	catch (exDosisMaxAlcanzadaPaciente& epaciente) {
		cout << epaciente.what() << endl;
	}
	//a ver como vienen
	cout<<"Ficha del paciente 1"<<endl << *(paciente1->get_ficha());
	cout<<"Ficha del paciente 2"<<endl << *(paciente2->get_ficha());
	cout<<"Ficha del paciente 3"<<endl << *(paciente3->get_ficha());
	//ponemos a un paciente en lista de espera y lo volvemos a reevaluar
	try {
		oncologo2->pasar_lista_espera(paciente2);
	}
	catch (exDosisMaxAlcanzadaPaciente& epaciente) {
		cout << epaciente.what() << endl;
	}
	try {
		oncologo2->sacar_lista_espera(paciente2, dosimetrista); 
		cout << "Ficha del paciente 2" << endl << *(paciente2->get_ficha());
	}
	catch (exDosisMaxAlcanzadaTumor& etumor) {
		cout << etumor.what() << endl;
	}
	catch (exDosisMaxAlcanzadaPaciente& epaciente) {
		cout << epaciente.what() << endl;
	}
	//buscamos en la lista del hospital descripciones al azar
	try {
		cout << endl << "Lista de pacientes con menos del 5% de dosis necesaria para curar un tumor" << endl;
		list<cPACIENTE*> pacientesConMenosDel5 = hospital->buscar_por_menos_del_5porciento();
	}
	catch (exNoHayPacientesMatch& error) {
		cout << error.what()<<endl;
	}
	try {
		cout << endl << "Lista de pacientes con tumores de ojo siendo tratados con radioterapia de haz externo" << endl;
		list<cPACIENTE*> pacientesConTratamientoTumor = hospital->buscar_por_tratamiento_y_tumor(eRadioterapia(hazExterno), eTipoTumor(ojo));
	}
	catch (exNoHayPacientesMatch& error) {
		cout << error.what() << endl;
	}
	//probamos si coincide un oncologo con su paciente
	if (*paciente1 == oncologo2->get_dni()) {
		cout << "El paciente " << paciente1->get_nombre() << " es atendido por el oncologo " << oncologo2->get_nombre() << endl;
	}
	else {
		cout << "El paciente " << paciente1->get_nombre() << " no es atendido por el oncologo " << oncologo2->get_nombre() << endl;
	}
	//eliminar de las listas
	*hospital - paciente1;
	*hospital - paciente2;
	*hospital - paciente3;
	*hospital - oncologo1;
	*hospital - oncologo2;
	*hospital - dosimetrista;
	//deletes
	delete hospital;
	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete dosimetrista;
	delete oncologo1;
	delete oncologo2;
	return 0;
}