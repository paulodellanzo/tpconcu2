#include "Servidor.h"

Servidor :: Servidor ( char* archivo,char letra ) {
	this->cola = new Cola<mensaje> ( archivo,letra );
}

Servidor :: ~Servidor () {
	delete this->cola;
}

int Servidor :: recibirPeticion () {
	this->peticionRecibida.id = 0;
	this->cola->leer ( PETICION,&(this->peticionRecibida) );
	return 0;
}

int Servidor :: procesarPeticion () {
	char txt_respuesta[TEXTO_SIZE];

	strcpy ( txt_respuesta,"[Respuesta a ");
	strcat ( txt_respuesta,this->peticionRecibida.texto );
	strcat ( txt_respuesta,"]" );

	this->respuesta.mtype = RESPUESTA;
	this->respuesta.id = this->peticionRecibida.id;
	strcpy ( this->respuesta.texto,txt_respuesta );

	return 0;
}

int Servidor :: responderPeticion () {
	this->cola->escribir ( this->respuesta );
	return 0;
}

mensaje Servidor :: getPeticionRecibida () {
	return this->peticionRecibida;
}

mensaje Servidor :: getRespuesta () {
	return this->respuesta;
}

