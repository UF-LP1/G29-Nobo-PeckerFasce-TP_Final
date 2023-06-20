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









	delete hospital;
	return 0;
}