
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "Cliente.h"
#include "Servidor.h"
#include "Mensajes.h"

#define CANTIDAD_INTERCAMBIOS	3

using namespace std;

int main () {

	int processId = fork ();

	if ( processId == 0 ) {

		// servidor
		Servidor servidor ( (char *) "main2.cc",'a' );

		for ( int i=0;i<CANTIDAD_INTERCAMBIOS;i++ ) {
			cout << "Servidor: esperando peticiones" << endl;
			servidor.recibirPeticion ();
			cout << "Servidor: peticion recibida: " << servidor.getPeticionRecibida().texto << endl;
			servidor.procesarPeticion ();
			cout << "Servidor: peticion procesada - enviando respuesta: " << servidor.getRespuesta().texto << endl;
			servidor.responderPeticion ();
			cout << "Servidor: respuesta enviada" << endl << endl;
		}

		return 0;

	} else {

		// cliente
		Cliente cliente ( (char *) "main2.cc",'a' );
		char peticion[50];
		char numero[10];

		for ( int i=0;i<CANTIDAD_INTERCAMBIOS;i++ ) {
			cin.get ();

			// se arma el texto del mensaje
			sprintf ( numero,"%u",i+1 );
			strcpy ( peticion,"Peticion " );
			strcat ( peticion,numero );
			strcat ( peticion," del cliente" );

			// se envia el mensaje al servidor
			mensaje rta = cliente.enviarPeticion ( i+1,peticion );
			cout << "Cliente: respuesta recibida = (ID = " << rta.id << ") - " << rta.texto << endl;
		}

		wait ( NULL );

		return 0;
	}
}

