#include "cHOSPITAL.h"

using namespace std;

int main() {

	cHOSPITAL* hospital = new cHOSPITAL("NoboPecker", "micasa");
	//instancio pacientes
	cPACIENTE* paciente1 = new cPACIENTE("Susana Gimenez", "45678099", eTipoSangre(0), 'f');
	paciente1->set_enEspera(false);
	paciente1->set_salud(0.5);
	paciente1->set_telefono("2235448098");

	cPACIENTE* paciente2 = new cPACIENTE("Moria Casan", "44568099", eTipoSangre(4), 'f');
	paciente1->set_enEspera(false);
	paciente1->set_salud(0.1);
	paciente1->set_telefono("2267948098");

	cPACIENTE* paciente3 = new cPACIENTE("Ricky Fort", "45000099", eTipoSangre(2), 'm');
	paciente1->set_enEspera(false);
	paciente1->set_salud(0.9);
	paciente1->set_telefono("2235448778");

	//instancio dosimetristas - oncologos
	cDOSIMETRISTA* dosimetrista = new cDOSIMETRISTA("Doctor Milagro", "67098112");

	cONCOLOGO* oncologo1 = new cONCOLOGO("RuPaul", "10101010");


	//me creo un dosimetrista y un oncologo (o 2)
	//llamo a generar ficha nueva
	//llamo a atender paciente
	//algun q otro sacar y poner en lista de espera EN UN TRY CATCH
	//en poner en lista de espera le tendiramos q decir q la prox sesion es en 6 meses ponele
	//buscar por tal y tal
	//sacar y sumar con sobrecargas
	//probar sobrecarga del ==


	delete hospital;
	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete dosimetrista;
	return 0;
}