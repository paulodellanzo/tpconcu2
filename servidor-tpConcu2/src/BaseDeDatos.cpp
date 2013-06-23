/*
 * BaseDeDatos.cpp
 *
 *  Created on: 22/06/2013
 *      Author: damian
 */

#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos() {
	// TODO Auto-generated constructor stub

}

int BaseDeDatos::addRegistro(char* nombre, char* direccion, char* telefono) {
	Registro registro;
	strcpy(registro.nombre, nombre);
	strcpy(registro.direccion, direccion);
	strcpy(registro.telefono, telefono);
	registros.push_front(registro);
	return 0;
}

Registro BaseDeDatos::consulta(char* nombre, char* direccion, char* telefono) {
	list<Registro>::iterator it;
	for (it = this->registros.begin(); it != this->registros.end(); it++) {
		bool valido = true;
		if(nombre != NULL) {
			if(strcmp((*it).nombre, nombre) != 0) valido = false;
		}

		if(direccion != NULL) {
			if(strcmp((*it).direccion, direccion) != 0) valido = false;
		}

		if(telefono != NULL) {
			if(strcmp((*it).telefono, telefono) != 0) valido = false;
		}

		if(valido) return (*it);
	}
	Registro reg;
	return reg;
}

BaseDeDatos::~BaseDeDatos() {
	// TODO Auto-generated destructor stub
}

