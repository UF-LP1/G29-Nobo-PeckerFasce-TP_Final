#include "archivos.h"

using namespace std;
string BASE_PATH = "..//..//..//";

int main() {

	cHOSPITAL* hospital = new cHOSPITAL("NoboPecker", "micasa");
	string archivo = ("MOCK_DATA.csv");
	
	try {
		leerArchivo(archivo,hospital->get_pacientes());
	}
	catch (exArchivoNoExistente& error) {
		cout << error.what() << endl;
	}








	delete hospital;
	return 0;
}