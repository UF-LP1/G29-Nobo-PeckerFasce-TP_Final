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
public:
	const char* what()const throw() {
		return "El paciente no ha sido diagnosticado con ninún tumor";
	}
};

class exPacienteYaExistente :public exception {
public:
	const char* what()const throw() {
		return "El paciente ya esta en la lista de pacientes";
	}
};

class exPacienteNoEncontrado :public exception {
public:
	const char* what()const throw() {
		return "No se ha encontrado el paciente en la lista de pacientes";
	}
};

class exDosisMaxAlcanzadaTumor :public exception {
public:
	const char* what()const throw() {
		return "La dosis maxima de este tumor fue alcanzada";
	}
};

class exDosisMaxAlcanzadaPaciente :public exception {
public:
	const char* what()const throw() {
		return "La dosis maxima de este paciente fue alcanzada";
	}
};

class exArchivoNoExistente :public exception {
public:
	const char* what()const throw() {
		return "El archivo que se intenta abrir es inexistente";
	}
};

class exSangreInexistente :public exception {
public:
	const char* what()const throw() {
		return "Tipo de sangre invalido";
	}
};