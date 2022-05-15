/*
 * funcionTP2.h
 *
 *  Created on: 9 may. 2022
 *      Author: Silvera Micaela
 */

#ifndef FUNCIONTP2_H_
#define FUNCIONTP2_H_

#define STRING 51

struct ePassenger {
	int id;
	char nombre [STRING];
	char apellido[STRING];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;
};

#endif /* FUNCIONTP2_H_ */

///
struct ePassenger crearPasajero(int contador);
///
int initPasajeros(struct ePassenger* listaPasajero , int len);
///
void mostrarLista(struct ePassenger* listaPasajero , int len);
///
void guardarPasajero(struct ePassenger* listaPasajero, struct ePassenger pasajeroNuevo, int len );
///
int validarPasajeros(struct ePassenger* listaPasajero , int len);
///
int validarEspacioLista(struct ePassenger* listaPasajero , int len);
///
void modificarPasajero(struct ePassenger* listaPasajero , int len, struct ePassenger pasajero);
///
void borrarPasajero(struct ePassenger* listaPasajero , int len, int idPasajero);
///
void ordenarPasajerosPorApellido(struct ePassenger* listaPasajero, int len);
///
void ordenarPasajerosPorCodVuelo(struct ePassenger* listaPasajero, int len);
///
void cargarDatosForzados(struct ePassenger* listaPasajero, int len);
