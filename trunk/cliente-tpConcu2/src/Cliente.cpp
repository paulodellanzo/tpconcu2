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
	Peticion respuesta;
	this->cola->escribir ( peticion );
	this->cola->leer ( this->pid, &respuesta );
	return respuesta;
}

int Cliente :: getPID() {
	return this->pid;
}

void Cliente :: realizarAlta() {
	Peticion peticion;
	peticion.mtype = PETICION_ALTA;
	peticion.clienteId = this->getPID();
	peticion.peticionId = 1;

	cout << "Ingresar datos para dar de alta" << endl;
	cout << "Nombre:" << endl;
	char nombre[NOMBRE_SIZE];
	cin >> nombre ;
	strcpy(peticion.nombre,nombre);

	cout << "Direccion:" << endl;
	char direccion[DIRECCION_SIZE];
	cin >> direccion ;
	strcpy(peticion.direccion,direccion);

	cout << "Telefono:" << endl;
	char telefono[TELEFONO_SIZE];
	cin >> telefono ;
	strcpy(peticion.telefono,telefono);

	Peticion rta = this->enviarPeticion(peticion);
	if (rta.estado == 0){
		cout << "Respuesta: Se realizo correctamente el alta del registro con resultado" << rta.estado << endl;
	}
	else {
		cout << "Error al dar de alta el registro en el servidor" << endl;
	}

}

void Cliente :: realizarConsulta(){
	Peticion peticion;
	peticion.mtype = PETICION_CONSULTA;
	peticion.clienteId = this->getPID();
	peticion.peticionId = 1;

	cout << "Ingresar datos para consulta" << endl;
	cout << "Nombre:" << endl;
	char nombre[NOMBRE_SIZE];
	cin >> nombre ;
	strcpy(peticion.nombre,nombre);

	cout << "Direccion:" << endl;
	char direccion[DIRECCION_SIZE];
	cin >> direccion ;
	strcpy(peticion.direccion,direccion);

	cout << "Telefono:" << endl;
	char telefono[TELEFONO_SIZE];
	cin >> telefono ;
	strcpy(peticion.telefono,telefono);

	Peticion rta = this->enviarPeticion(peticion);
	if (rta.estado == 0){
		cout << "Respuesta:" << endl << "Nombre: " << rta.nombre;
		cout << " Direccion: " << rta.direccion << " Telefono: " << rta.telefono << endl;
	}
	else {
		cout << "Empty set" << endl;
	}
}
