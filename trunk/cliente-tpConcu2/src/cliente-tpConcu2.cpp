//============================================================================
// Name        : cliente-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "Cola.h"
#include "Mensajes.h"

#define CLIENTE_ID 1

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Cola<PeticionConsulta> cola((char *)"/home/damian/file.txt",'a');

	PeticionConsulta peticion;
	peticion.mtype = PETICION_CONSULTA;
	peticion.clienteId = CLIENTE_ID;
	peticion.peticionId = 1;
	strcpy(peticion.nombre,"damian");

	cout << "Voy a escribir" << endl;
	cola.escribir(peticion);
	cout << "Escribí" << endl;

	return 0;
}
