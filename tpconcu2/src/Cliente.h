#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string.h>

#include "Mensajes.h"
#include "Cola.h"

class Cliente {

	private:
		Cola<mensaje>* cola;

	public:
		Cliente ( char* archivo,char letra );
		virtual ~Cliente();
		mensaje enviarPeticion ( int id,char* texto );
};

#endif /* CLIENTE_H_ */
