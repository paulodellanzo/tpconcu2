#include "Cliente.h"

Cliente :: Cliente ( char* archivo,char letra ) {
	this->cola = new Cola<Peticion> ( archivo,letra );
	this->pid = getpid();
}

Cliente :: ~Cliente() {
	//this->cola->destruir ();
	delete this->cola;
}

Peticion Cliente :: enviarPeticion ( Peticion peticion) {
	//Peticion peticion;
	Peticion respuesta;

	this->cola->escribir ( peticion );
	this->cola->leer ( this->pid, &respuesta );

	return respuesta;
}

int Cliente :: getPID() {
	return this->pid;
}
