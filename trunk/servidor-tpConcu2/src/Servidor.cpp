#include "Servidor.h"

Servidor :: Servidor ( char* archivo,char letra ) {
	this->cola = new Cola<Peticion> ( archivo,letra );
	this->base = new BaseDeDatos();
}

Servidor :: ~Servidor () {
	this->cola->destruir();
	delete this->cola;
}

int Servidor :: recibirPeticion () {
	this->peticionRecibida.clienteId = 0;
	this->cola->leer ( 0 ,&(this->peticionRecibida) );
	return 0;
}

int Servidor :: procesarPeticion () {
	/*char txt_respuesta[TEXTO_SIZE];

	strcpy ( txt_respuesta,"[Respuesta a ");
	strcat ( txt_respuesta,this->peticionRecibida.texto );
	strcat ( txt_respuesta,"]" );

	this->respuesta.mtype = RESPUESTA;
	this->respuesta.id = this->peticionRecibida.id;
	strcpy ( this->respuesta.texto,txt_respuesta );
	*/

	//this->cola->leer(PETICION_CONSULTA,&peticion);

	switch (this->peticionRecibida.mtype) {
			case PETICION_CONSULTA:

					Peticion respConsulta;
					this->respuesta = this->consultar(this->peticionRecibida, this->base);
					this->responderPeticion();
					break;
			case PETICION_ALTA:

					Peticion respAlta;
					this->respuesta = this->darDeAlta(this->peticionRecibida, this->base);
					this->responderPeticion();
					break;
			case SALIR:
					return 0;
			default:
					break;
	}
	return 0;
}

int Servidor :: responderPeticion () {
	this->cola->escribir ( this->respuesta );
	return 0;
}

Peticion Servidor :: getPeticionRecibida () {
	return this->peticionRecibida;
}

Peticion Servidor :: getRespuesta () {
	return this->respuesta;
}

BaseDeDatos* Servidor :: getBase(){
	return this->base;
}

Peticion Servidor :: consultar(Peticion peticion, BaseDeDatos* base) {
	Peticion respuesta;
	strcpy(respuesta.nombre, "");
	strcpy(respuesta.direccion, "");
	strcpy(respuesta.telefono, "");
	Registro reg;
	int estado = base->consulta( reg, peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = peticion.clienteId;
	respuesta.peticionId = peticion.peticionId;
	respuesta.estado = estado;
	strcpy(respuesta.nombre, reg.nombre);
	strcpy(respuesta.direccion, reg.direccion);
	strcpy(respuesta.telefono, reg.telefono);
	return respuesta;
}

Peticion Servidor :: darDeAlta(Peticion peticion, BaseDeDatos* base) {
	Peticion respuesta;
	int estado = base->addRegistro(peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = peticion.clienteId;
	respuesta.peticionId = peticion.peticionId;
	respuesta.estado = estado;
	return respuesta;
}

