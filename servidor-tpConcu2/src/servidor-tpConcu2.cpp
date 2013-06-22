//============================================================================
// Name        : servidor-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cola.h"
#include "Mensajes.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Cola<PeticionConsulta> cola((char *)"/home/damian/file.txt",'a');
	PeticionConsulta peticion;
	cout << "Voy a leer" << endl;
	cola.leer(PETICION_CONSULTA,&peticion);
	cout << "Leí:" << peticion.nombre << endl;
	return 0;
}
