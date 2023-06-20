#include "archivos.h"

using namespace std;

int main() {

	cHOSPITAL* hospital = new cHOSPITAL("NoboPecker", "micasa");
	string archivo = ("MOCK_DATA.csv");
	
	try {
		leerArchivo(archivo,hospital->get_pacientes());
		//no lee bien las cosas y no me deja abrirlo
	}
	catch (exArchivoNoExistente& error) {
		cout << error.what() << endl;
	}

	//me creo un dosimetrista y un oncologo (o 2)
	//llamo a generar ficha nueva
	//llamo a atender paciente
	//algun q otro sacar y poner en lista de espera EN UN TRY CATCH
	//en poner en lista de espera le tendiramos q decir q la prox sesion es en 6 meses ponele
	//buscar por tal y tal
	//sacar y sumar con sobrecargas
	//probar sobrecarga del ==


	delete hospital;
	return 0;
}