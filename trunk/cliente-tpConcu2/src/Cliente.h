#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string.h>
#include <iostream>

#include "Mensajes.h"
#include "Cola.h"
#include <unistd.h>

using namespace std;

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
		void realizarConsulta();
		void realizarAlta();
};

#endif /* CLIENTE_H_ */
