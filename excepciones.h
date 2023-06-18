#pragma once
#include <exception>
using namespace std;

class exTratamientoNoComenzado :public exception {
public:
	const char* what() const throw() {
		return "El tratamiento del paciente aun no ha comenzado";
	}
};
class exNoHayTumores :public exception {
	const char* what()const throw() {
		return "El paciente no ha sido diagnosticado con ninún tumor";
	}
};
