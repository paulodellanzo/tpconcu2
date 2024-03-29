
#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

#include <iostream>
#include <list>
#include <string.h>
#include <fstream>
#include "Mensajes.h"

#define BASE "base.txt"
#define LINEA 300

using namespace std;

class BaseDeDatos {
public:
	BaseDeDatos();
	virtual ~BaseDeDatos();
	int addRegistro(char* nombre, char* direccion, char* telefono);
	int consulta(Registro* reg, char* nombre, char* direccion, char* telefono);
	void mostrarRegistros();

private:
	list<Registro> registros;


};

#endif /* BASEDEDATOS_H_ */
