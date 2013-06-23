#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string.h>

#include "Mensajes.h"
#include "Cola.h"
#include <unistd.h>

class Cliente {

	private:
		Cola<Peticion>* cola;
		Cola<RespuestaConsulta>* colaRta;
		int pid;

	public:
		Cliente ( char* archivo,char letra );
		virtual ~Cliente();
		Peticion enviarPeticion ( Peticion peticion);
		int getPID();
};

#endif /* CLIENTE_H_ */
