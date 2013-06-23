//============================================================================
// Name        : cliente-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "Cola.h"
#include "Mensajes.h"
#include "Cliente.h"

#define CLIENTE_ID 1

using namespace std;

int main1() {
	cout << "Bienvenido seleccione la opcion para continuar" << endl;
	cout << "1: Consulta de la Base de Datos" << endl;
	cout << "2: Alta de la Base de Datos" << endl;
	cout << "4: Salir" << endl;

	int opcion = 2;
	Cliente* cliente = new Cliente((char*)"file.txt",'a');

	while (opcion != SALIR){
		cout << "Ingrese opcion: " << endl;
		cin >> opcion;
		if (opcion == PETICION_ALTA){
			Peticion peticion;
			peticion.mtype = PETICION_ALTA;
			peticion.clienteId = cliente->getPID();
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

			Peticion rta = cliente->enviarPeticion(peticion);
			cout << "Respuesta:" << rta.estado << endl;

		}
		else if (opcion == PETICION_CONSULTA){
			Peticion peticion;
			peticion.mtype = PETICION_CONSULTA;
			peticion.clienteId = cliente->getPID();
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

			Peticion rta = cliente->enviarPeticion(peticion);
			if (rta.estado == 0){
				cout << "Respuesta:" << endl << "Nombre: " << rta.nombre;
				cout << " Direccion: " << rta.direccion << " Telefono: " << rta.telefono << endl;
			}
			else {
				cout << "Empty set" << endl;
			}
		}
		else if (opcion == SALIR){
			break;
		}
		else {
			cout << "Opcion incorrecta vuelva a intentarlo" << endl;
		}
		//Cola<Peticion> cola((char *)"file.txt",'a');

	}

	/*Peticion peticion;
	peticion.mtype = SALIR;
	peticion.clienteId = cliente->getPID();
	peticion.peticionId = 1;
	Peticion rta = cliente->enviarPeticion(peticion);
	cout << "Respuesta:" << rta.estado << endl;
	*/

	delete cliente;
	return 0;
}
