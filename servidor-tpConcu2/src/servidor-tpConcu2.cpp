//============================================================================
// Name        : servidor-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : tpconcu2
//============================================================================

#include <iostream>
#include "Cola.h"

#include "SIGINT_Handler.h"
#include "SignalHandler.h"
#include "Servidor.h"

using namespace std;

int main1() {
	cout << "Server Corriendo" << endl;
	SIGINT_Handler sigint_handler;

	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

	//Creamos el servidor con un archivo y letra para crear la cola de mensajes luego
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
