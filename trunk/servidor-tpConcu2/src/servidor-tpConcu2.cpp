//============================================================================
// Name        : servidor-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cola.h"

#include "SIGINT_Handler.h"
#include "SignalHandler.h"
#include "Servidor.h"

using namespace std;

int main() {
	cout << "Server Corriendo" << endl;
	// event handler para la senial SIGINT (-2)
	SIGINT_Handler sigint_handler;

	// se registra el event handler declarado antes
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

	Cola<Peticion> cola((char *)"file.txt",'c');

	Servidor* server = new Servidor((char*) "file.txt", 'a');
	// mientras no se reciba la senial SIGINT, el servidor realiza su trabajo
	while ( sigint_handler.getGracefulQuit() == 0 ) {
		cout << "Esperando para procesar" << endl;
		server->recibirPeticion();
		server->procesarPeticion();
		server->getBase()->mostrarRegistros();

	}

	// se recibio la senial SIGINT, el proceso termina
	SignalHandler :: destruir ();
	delete server;
	cout << "Termino el proceso" << endl;
	return 0;
}
