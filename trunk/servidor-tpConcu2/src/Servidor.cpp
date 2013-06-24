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
	//Por default el servidor recibe un mensaje de salir, simulando la caida del cliente
	this->peticionRecibida.mtype = SALIR;
	//Ponemos tipo 0 para leer el siguiente mensaje en la cola
	this->cola->leer ( 0 ,&(this->peticionRecibida) );
	return 0;
}

int Servidor :: procesarPeticion () {

	switch (this->peticionRecibida.mtype) {
			case PETICION_CONSULTA:

					RespuestaConsulta respConsulta;
					//Realizamos la consulta y escribimos la respuesta luego
					this->respuesta = this->consultar(this->peticionRecibida, this->base);
					this->responderPeticion();
					break;
			case PETICION_ALTA:

					RespuestaAlta respAlta;
					//Hacemos el alta del registro nuevo y enviamos la respuesta al cliente
					this->respuesta = this->darDeAlta(this->peticionRecibida, this->base);
					this->responderPeticion();
					break;
			case SALIR:
					break;
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
	Registro* reg = new Registro;
	//Se pide la consulta a la base de datos que tiene el servidor
	int estado = base->consulta( reg, peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = peticion.clienteId;
	respuesta.peticionId = peticion.peticionId;
	respuesta.estado = estado;
	//Se arma la respuesta en funcion del registro obtenido
	strcpy(respuesta.nombre, reg->nombre);
	strcpy(respuesta.direccion, reg->direccion);
	strcpy(respuesta.telefono, reg->telefono);
	return respuesta;
}

Peticion Servidor :: darDeAlta(Peticion peticion, BaseDeDatos* base) {
	Peticion respuesta;
	//Agregamos a la base de datos el registro nuevo que ingreso el cliente y devuelve un
	//estado que es 0 OK, -1 ERROR
	int estado = base->addRegistro(peticion.nombre, peticion.direccion, peticion.telefono);
	respuesta.clienteId = peticion.clienteId;
	respuesta.mtype = peticion.clienteId;
	respuesta.peticionId = peticion.peticionId;
	respuesta.estado = estado;
	return respuesta;
}

