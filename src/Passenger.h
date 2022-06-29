/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define STRING 50
#define CODIGO 7

 typedef struct {
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	int estadoVuelo;
	int isEmpty;

}Passenger;

void mostrarMenu ();
///
struct Passenger* Passenger_new();

///
struct Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);

void Passenger_delete();

int Passenger_setId( Passenger* this,int id);
int Passenger_getId( Passenger* this,int* id);

int Passenger_setNombre( Passenger* this,char* nombre);
int Passenger_getNombre( Passenger* this,char* nombre);

int Passenger_setApellido( Passenger* this,char* apellido);
int Passenger_getApellido( Passenger* this,char* apellido);

int Passenger_setCodigoVuelo( Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo( Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero( Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero( Passenger* this,int* tipoPasajero);

int Passenger_setPrecio( Passenger* this,float precio);
int Passenger_getPrecio( Passenger* this,float* precio);

///
void  mostrarListaPasajeros(LinkedList* listaPasajeros);
///
void mostrarMenuModificarPasajeros();
///
Passenger* buscarPasajeroPorId(LinkedList* listaPasajeros, int idPasajero);
///
void modificarDato(int opcionModificar, Passenger* pasajeroModificar);
///
void eliminarPasajero(LinkedList* listaPasajeros, int idPasajero );
///
int obtenerTipoPasajeroPorTexto(char* texto);
///
char* obtenerEstadoVueloPorEntero(int numero);
///
int obtenerEstadoVueloPorTexto(char* texto);
///
char* obtenerTipoPasajeroPorEntero(int numero);
///
int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos);
#endif /* PASSENGER_H_ */
