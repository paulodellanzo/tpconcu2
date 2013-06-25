//============================================================================
// Name        : cliente-tpConcu2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : tpconcu2
//============================================================================

#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Cola.h"
#include "Mensajes.h"
#include "Cliente.h"

#define CLIENTE_ID 1

using namespace std;

int main() {
	cout << "Bienvenido seleccione la opcion para continuar" << endl;
	cout << "1: Consulta de la Base de Datos" << endl;
	cout << "2: Alta de la Base de Datos" << endl;
	cout << "4: Salir" << endl;

	int opcion = 2;
	Cliente* cliente = new Cliente((char*)"file.txt",'a');

	while (opcion != SALIR){
		cout << "Ingrese opcion: " << endl;
		char opcionChar;
		cin.getline(&opcionChar,10);
		opcion = atoi(&opcionChar);
		if (opcion == PETICION_ALTA){
			cliente->realizarAlta();
		}
		else if (opcion == PETICION_CONSULTA){
			cliente->realizarConsulta();
		}
		else if (opcion == SALIR){
			cout << "Saliendo..." << endl;
		}
		else {
			cout << "Opcion incorrecta vuelva a intentarlo" << endl;
			cin.ignore();
		}
	}

	/*Peticion peticion;
	peticion.mtype = SALIR;
	peticion.clienteId = cliente->getPID();
	peticion.peticionId = 1;
	Peticion rta = cliente->enviarPeticion(peticion);
	*/
	delete cliente;
	return 0;
}
