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
#include "SIGINT_Handler.h"
#include "SignalHandler.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Cola<PeticionConsulta> cola((char *)"file.txt",'a');
	PeticionConsulta peticion;
	cout << "Voy a leer" << endl;

	// event handler para la senial SIGINT (-2)
	SIGINT_Handler sigint_handler;

	// se registra el event handler declarado antes
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

	// mientras no se reciba la senial SIGINT, el proceso realiza su trabajo
	while ( sigint_handler.getGracefulQuit() == 0 ) {
		cola.leer(PETICION_CONSULTA,&peticion);
		cout << "Leí:" << peticion.nombre << endl;

	}

	// se recibio la senial SIGINT, el proceso termina
	SignalHandler :: destruir ();
	cout << "Termino el proceso" << endl;
	return 0;

}
