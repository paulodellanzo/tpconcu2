//============================================================================
// Name        : servidor-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cola.h"
#include "BaseDeDatos.h"
#include "SIGINT_Handler.h"
#include "SignalHandler.h"

using namespace std;

RespuestaConsulta consultar(Peticion peticion, BaseDeDatos* base) {
	RespuestaConsulta respuesta;
	Registro reg = base->consulta(peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = RESPUESTA_CONSULTA;
	respuesta.peticionId = peticion.peticionId;
	strcpy(respuesta.nombre, reg.nombre);
	strcpy(respuesta.direccion, reg.direccion);
	strcpy(respuesta.telefono, reg.telefono);
	return respuesta;
}

RespuestaAlta darDeAlta(Peticion peticion, BaseDeDatos* base) {
	RespuestaAlta respuesta;
	int estado = base->addRegistro(peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = RESPUESTA_CONSULTA;
	respuesta.peticionId = peticion.peticionId;
	respuesta.estado = estado;
	return respuesta;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Cola<Peticion> cola((char *)"/home/damian/file.txt",'a');
	Peticion peticion;
	BaseDeDatos* base = new BaseDeDatos();

	// event handler para la senial SIGINT (-2)
	SIGINT_Handler sigint_handler;

	// se registra el event handler declarado antes
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );

	// mientras no se reciba la senial SIGINT, el proceso realiza su trabajo
	while ( sigint_handler.getGracefulQuit() == 0 ) {
		cout << "Voy a leer" << endl;
		cola.leer(PETICION_CONSULTA,&peticion);

		switch (peticion.mtype) {
			case PETICION_CONSULTA:

				RespuestaConsulta respConsulta;
				respConsulta = consultar(peticion,base);

				break;
			case PETICION_ALTA:

				RespuestaAlta respAlta;
				respAlta = darDeAlta(peticion, base);

				break;
			default:
				break;
		}
	}

	// se recibio la senial SIGINT, el proceso termina
	SignalHandler :: destruir ();
	cout << "Termino el proceso" << endl;
	return 0;
}
