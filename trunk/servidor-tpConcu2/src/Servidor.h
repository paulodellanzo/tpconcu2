#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <string.h>

#include "Mensajes.h"
#include "Cola.h"
#include "BaseDeDatos.h"

class Servidor {

	private:
		Cola<Peticion>* cola;
		Peticion peticionRecibida;
		Peticion respuesta;
		BaseDeDatos* base;

	public:
		Servidor ( char* archivo,char letra );
		virtual ~Servidor ();

		int recibirPeticion ();
		int procesarPeticion ();
		int responderPeticion ();

		Peticion getPeticionRecibida ();
		Peticion getRespuesta ();
		BaseDeDatos* getBase();
		Peticion consultar(Peticion peticion, BaseDeDatos* base);
		Peticion darDeAlta(Peticion peticion, BaseDeDatos* base);

};

#endif /* SERVIDOR_H_ */
