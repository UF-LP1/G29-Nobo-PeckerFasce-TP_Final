#pragma once
#include <exception>
using namespace std;

class exTratamientoNoComenzado :public exception {
public:
	const char* what() const throw() {
		return "El tratamiento del paciente aun no ha comenzado";
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

class exDosimetristaYaExistente :public exception {
public:
	const char* what()const throw() {
		return "El dosimetrista ya esta en la lista de dosimetristas";
	}
};

class exDosimetristaNoEncontrado :public exception {
public:
	const char* what()const throw() {
		return "No se ha encontrado el dosimetrista en la lista de dosimetristas";
	}
};

class exOncologoYaExistente :public exception {
public:
	const char* what()const throw() {
		return "El oncologo ya esta en la lista de oncologos";
	}
};

class exOncologoNoEncontrado :public exception {
public:
	const char* what()const throw() {
		return "No se ha encontrado el oncologo en la lista de oncologos";
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
		return "Este paciente se ha pasado a lista de espera";
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

class exNoEsBool :public exception {
public:
	const char* what() const throw() {
		return "El dato ingresado no corresponde a un bool";
	}
};

class exNoHayPacientesMatch : public exception {
public:
	const char* what() const throw() {
		return "No hay pacientes que cumplan con la descripcion solicitada";
	}
};