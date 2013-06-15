#include "Cliente.h"

Cliente :: Cliente ( char* archivo,char letra ) {
	this->cola = new Cola<mensaje> ( archivo,letra );
}

Cliente :: ~Cliente() {
	this->cola->destruir ();
	delete this->cola;
}

mensaje Cliente :: enviarPeticion ( int id,char* texto ) {
	mensaje peticion;
	mensaje respuesta;

	peticion.mtype = PETICION;
	peticion.id = id;
	strcpy ( peticion.texto,texto );

	this->cola->escribir ( peticion );
	this->cola->leer ( RESPUESTA,&respuesta );

	return respuesta;
}
