#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <string.h>

#include "Mensajes.h"
#include "Cola.h"

class Servidor {

	private:
		Cola<mensaje>* cola;
		mensaje peticionRecibida;
		mensaje respuesta;

	public:
		Servidor ( char* archivo,char letra );
		virtual ~Servidor ();

		int recibirPeticion ();
		int procesarPeticion ();
		int responderPeticion ();

		mensaje getPeticionRecibida ();
		mensaje getRespuesta ();

};

#endif /* SERVIDOR_H_ */
