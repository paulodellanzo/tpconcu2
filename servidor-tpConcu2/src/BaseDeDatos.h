/*
 * BaseDeDatos.h
 *
 *  Created on: 22/06/2013
 *      Author: damian
 */

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include <list>
#include <string.h>
#include "Mensajes.h"

using namespace std;

class BaseDeDatos {
public:
	BaseDeDatos();
	virtual ~BaseDeDatos();
	int addRegistro(char* nombre, char* direccion, char* telefono);
	Registro consulta(char* nombre, char* direccion, char* telefono);

private:
	list<Registro> registros;


};

#endif /* BASEDEDATOS_H_ */