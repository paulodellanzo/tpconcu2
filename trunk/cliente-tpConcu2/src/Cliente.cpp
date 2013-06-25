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
	cin.getline(peticion.nombre,NOMBRE_SIZE);

	cout << "Direccion:" << endl;
	cin.getline(peticion.direccion,DIRECCION_SIZE);

	cout << "Telefono:" << endl;
	cin.getline(peticion.telefono,DIRECCION_SIZE);

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
	cin.getline(peticion.nombre,NOMBRE_SIZE);

	cout << "Direccion:" << endl;
	cin.getline(peticion.direccion,DIRECCION_SIZE);

	cout << "Telefono:" << endl;
	cin.getline(peticion.telefono,DIRECCION_SIZE);

	cout << "Nombre " << peticion.nombre << " Direccion " << peticion.direccion << " Telefono " << peticion.telefono << endl;

	Peticion rta = this->enviarPeticion(peticion);
	if (rta.estado == 0){
		cout << "Respuesta:" << endl << "Nombre: " << rta.nombre;
		cout << " Direccion: " << rta.direccion << " Telefono: " << rta.telefono << endl;
	}
	else {
		cout << "Empty set" << endl;
	}
}
