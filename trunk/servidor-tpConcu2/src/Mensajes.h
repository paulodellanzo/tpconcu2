#ifndef MENSAJES_H_
#define MENSAJES_H_

#define	PETICION_CONSULTA	1
#define	PETICION_ALTA	2
#define	RESPUESTA_CONSULTA	3
#define	RESPUESTA_ALTA	3
#define NOMBRE_SIZE	61
#define DIRECCION_SIZE	120
#define TELEFONO_SIZE	13

//typedef struct Registro {
//	char nombre[NOMBRE_SIZE];
//	char direccion[DIRECCION_SIZE];
//	char telefono[TELEFONO_SIZE];
//} Registro;

typedef struct PeticionConsulta {
	long mtype;
	int clienteId;
	int peticionId;
	char nombre[NOMBRE_SIZE];
} PeticionConsulta;

typedef struct RespuestaConsulta {
	long mtype;
	int clienteId;
	int peticionId;
	char nombre[NOMBRE_SIZE];
	char direccion[DIRECCION_SIZE];
	char telefono[TELEFONO_SIZE];
} RespuestaConsulta;

typedef struct PeticionAlta {
	long mtype;
	int clienteId;
	int peticionId;
	char nombre[NOMBRE_SIZE];
	char direccion[DIRECCION_SIZE];
	char telefono[TELEFONO_SIZE];
} PeticionAlta;

typedef struct RespuestaAlta {
	long mtype;
	int clienteId;
	int peticionId;
	int estado; // 0 OK, -1 ERROR
} RespuestaAlta;

#endif /* MENSAJES_H_ */
