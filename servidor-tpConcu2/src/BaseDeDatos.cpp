
#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos() {
	// TODO Auto-generated constructor stub
	FILE* archivo = fopen(BASE,"r");
	char linea[LINEA];
	if (archivo != NULL){
		while (fgets(linea,LINEA,archivo) != NULL){
			printf("%s",linea);
			char *ptr;
			Registro reg;
			ptr = strtok(linea,"\t");
			strcpy(reg.nombre, ptr);
			ptr = strtok(NULL, "\t");
			strcpy(reg.direccion, ptr);
			ptr = strtok(NULL, "\t");
			strcpy(reg.telefono, ptr);
			this->registros.push_front(reg);
		}
		fclose(archivo);
	}
}

int BaseDeDatos::addRegistro(char* nombre, char* direccion, char* telefono) {
	Registro registro;
	strcpy(registro.nombre, nombre);
	strcpy(registro.direccion, direccion);
	strcpy(registro.telefono, telefono);
	registros.push_front(registro);
	const char * separador = "\t";
	FILE* archivo = fopen(BASE, "a");
	fputs(registro.nombre,archivo);
	fputs(separador,archivo);
	fputs(registro.direccion,archivo);
	fputs(separador,archivo);
	fputs(registro.telefono,archivo);
	const char * fin = "\n";
	fputs(fin,archivo);
	fclose(archivo);
	return 0;
}

int BaseDeDatos::consulta(Registro* reg, char* nombre, char* direccion, char* telefono) {
	list<Registro>::iterator it;
	for (it = this->registros.begin(); it != this->registros.end(); it++) {
		bool valido = true;
		if(nombre != NULL) {
			if(strcmp((*it).nombre, nombre) != 0) valido = false;
		}

		if(direccion != NULL) {
			if(strcmp((*it).direccion, direccion) != 0) valido = false;
		}

		if(telefono != NULL) {
			if(strcmp((*it).telefono, telefono) != 0) valido = false;
		}

		if(valido) {
			strcpy(reg->nombre, (*it).nombre);
			strcpy(reg->direccion, (*it).direccion);
			strcpy(reg->telefono, (*it).telefono);
			return 0;
		}
	}
	//Registro reg;
	return -1;
}

void BaseDeDatos::mostrarRegistros() {
	list<Registro>::iterator it;
	int contador = 1;
		for (it = this->registros.begin(); it != this->registros.end(); it++){
			cout << "Registro nro: " << contador << endl;
			cout << "Nombre: " << (it->nombre) << endl;
			cout << "Direccion: " << (it->direccion) << endl;
			cout << "Telefono: " << (it->telefono) << endl;
			contador++;
		}
}

BaseDeDatos::~BaseDeDatos() {
	// TODO Auto-generated destructor stub
}

