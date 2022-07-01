/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Silvera Micaela
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#define MENSAJES 100

///
struct Passenger* Passenger_new(int idNuevoPasajero){

	Passenger* pasajeroNuevo;

	pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

	pasajeroNuevo->id = idNuevoPasajero;

	printf("Ingrese el nombre del pasajero  \n");
	scanf("%s", &pasajeroNuevo->nombre);

	printf("Ingrese el apellido del pasajero  \n");
	scanf("%s", &pasajeroNuevo->apellido);

	char mensaje[MENSAJES];
	memcpy(&mensaje, "Ingrese el precio : \n", MENSAJES);
	pasajeroNuevo->precio = (float)validarEntero(mensaje);

	memcpy(&mensaje, "Ingrese tipo de pasajero: [1. EconomyClass - 2. ExecutiveClass - 3. FirstClass] \n", MENSAJES);
	pasajeroNuevo->tipoPasajero = validarEstado(mensaje);

	printf("Ingrese el codigo de vuelo  \n");
	scanf("%s", &pasajeroNuevo->codigoVuelo);

	memcpy(&mensaje, "Ingrese estado de vuelo: [1. En Horario - 2. En Vuelo - 3. Aterrizado - 4. Demorado] \n", MENSAJES);
	pasajeroNuevo->estadoVuelo = validarEstado(mensaje);


	pasajeroNuevo->isEmpty =0;

	return pasajeroNuevo;

}//fin Passenger_new
///
void  mostrarListaPasajeros(LinkedList* listaPasajeros){
	int size = 0;
	 //llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
	 size = ll_len(listaPasajeros);

	 Passenger* pasajeroLista;

	 pasajeroLista = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

	 for(int i = 0; i<size ;i++){

		//llamo a la funcion ll_get() que le paso un lista para que retorne el indice de un pasajero
		pasajeroLista = ll_get(listaPasajeros, i);

		/*printf("\n *************************");

		printf("\n ID : %d", pasajeroLista->id);

		printf("\n NOMBRE : %s",pasajeroLista->nombre );

		printf("\n APELLIDO : %s",pasajeroLista->apellido );

		printf("\n PRECIO : %.2f",pasajeroLista->precio );

		printf("\n TIPO PASAJERO : %d [ %s ]",pasajeroLista->tipoPasajero, obtenerTipoPasajeroPorEntero(pasajeroLista->tipoPasajero) );

		printf("\n CODIGO DE VUELO : %s",pasajeroLista->codigoVuelo );

		printf("\n ESTADO DEL VUELO : %d [ %s ]",pasajeroLista->estadoVuelo, obtenerEstadoVueloPorEntero(pasajeroLista->estadoVuelo) );

		printf("\n *************************");*/

		printf("||%-4d | %13s | %17s | %.2f | %15s | %18s | %15s||\n", pasajeroLista->id, pasajeroLista->nombre, pasajeroLista->apellido, pasajeroLista->precio, pasajeroLista->codigoVuelo, obtenerTipoPasajeroPorEntero(pasajeroLista->tipoPasajero), obtenerEstadoVueloPorEntero(pasajeroLista->estadoVuelo));

	 }//fin for

	 free(pasajeroLista);

}//fin funcion mostrarListaPasajeros
///
void mostrarMenuModificarPasajeros(){
	printf("\n *************************");

	printf("\n 1) Modificar nombre: ");
	printf("\n 2) Modificar apellido: ");
	printf("\n 3) Modificar precio: ");
	printf("\n 4) Modificar tipo Pasajero: ");
	printf("\n 5) Modificar codigo de vuelo: ");

}// fin mostrarMenuModificarPasajeros
///
Passenger* buscarPasajeroPorId(LinkedList* listaPasajeros, int idPasajero){

	Passenger* pasajeroRetorno;

	int size =0;

	//llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
	size = ll_len(listaPasajeros);

	for(int i =0; i< size; i++){

		Passenger* pasajeroLista;

		//llamo a la funcion ll_get() que le paso un lista para que retorne el indice de un pasajero
		pasajeroLista = ll_get(listaPasajeros, i);

		if(pasajeroLista->id == idPasajero){

			pasajeroRetorno = pasajeroLista;

		}//fin if

	}//fin for

	return pasajeroRetorno;

}// fin buscarIdPasajero

void modificarDato(int opcionModificar, Passenger* pasajeroModificar){

	switch (opcionModificar){
		case 1:
			printf("Ingrese el nombre del pasajero a modificar\n");
			scanf("%s", &pasajeroModificar->nombre);
			break;
		case 2:
			printf("Ingrese el apellido del pasajero a modificar\n");
			scanf("%s", &pasajeroModificar->apellido);
			break;
		case 3:
			printf("Ingrese el precio del vuelo a modificar\n");
			scanf("%f", &pasajeroModificar->precio);
			break;
		case 4:
			printf("Ingrese el tipo de pasajero a modificar\n");
			scanf("%d", &pasajeroModificar->tipoPasajero);
			break;
		case 5:
			printf("Ingrese el codigo de vuelo a modificar\n");
			scanf("%s", &pasajeroModificar->codigoVuelo);
			break;

	}//fin switch


}// fin modificarDato
///
void eliminarPasajero(LinkedList* listaPasajeros, int idPasajero ){

	int size =0;
	int indice = -1;

	//llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
	size = ll_len(listaPasajeros);

	for(int i = 0; i <size; i++){

		Passenger* pasajeroLista;

		//llamo a la funcion ll_get() que le paso un lista para que retorne el indice de un pasajero
		pasajeroLista = ll_get(listaPasajeros, i);

		if(pasajeroLista->id == idPasajero){

			indice = i;

		}//fin if

	}//fin for

	if(indice > -1){
		//llamo la funcion ll_remove() elimina un elemento de la lista
		ll_remove( listaPasajeros,indice);
	}//fin if

}//fin eliminarPasajero
///
int obtenerTipoPasajeroPorTexto(char* texto){

	const char* str1 = "EconomyClass";
	const char* str2 = "ExecutiveClass";
	const char* str3 = "FirstClass";

	int tipoPasajero = 0;

	if(strcmp(texto, str1) == 0){
		tipoPasajero = 1;
	}else if (strcmp(texto, str2) == 0){
		tipoPasajero = 2;
	}else if (strcmp(texto, str3) == 0){
		tipoPasajero = 3;
	}//FIN IF

	return tipoPasajero;
}// FIN obtenerTipoPasajero
///
char* obtenerTipoPasajeroPorEntero(int numero){

	char *tipoPasajero = malloc(14);

	if(numero == 1){
		strcpy(tipoPasajero, "EconomyClass");
	}else if (numero == 2){
		strcpy(tipoPasajero, "ExecutiveClass");
	}else if (numero == 3){
		strcpy(tipoPasajero, "FirstClass");
	}//FIN IF

	return tipoPasajero;
}// FIN obtenerTipoPasajero*/
///
int obtenerEstadoVueloPorTexto(char* texto){

	const char* str4 = "En Horario";
	const char* str5 = "En Vuelo";
	const char* str6 = "Aterrizado";
	const char* str7 = "Demorado";

	int estadoVuelo = 0;

	if(strcmp(texto, str4) == 0){
		estadoVuelo = 1;
	}else if (strcmp(texto, str5) == 0){
		estadoVuelo = 2;
	}else if (strcmp(texto, str6) == 0){
		estadoVuelo = 3;
	}else if (strcmp(texto, str7) == 0){
		estadoVuelo = 4;
	}//FIN IF

	return estadoVuelo;
}// FIN obtenerTipoPasajero
///
char* obtenerEstadoVueloPorEntero(int numero){

	char *estadoVuelo = malloc(10);

	if(numero == 1){
		strcpy(estadoVuelo, "En Horario");
	}else if (numero == 2){
		strcpy(estadoVuelo, "En Vuelo");
	}else if (numero == 3){
		strcpy(estadoVuelo, "Aterrizado");
	}else if (numero == 4){
		strcpy(estadoVuelo, "Demorado");
	}//FIN IF

	return estadoVuelo;
}// FIN obtenerTipoPasajero*/
///
int Passenger_sortByApellido(void* pasajeroUno, void* pasajeroDos ){

	int retorno = -1;
	char apellidoAuxUno[STRING];
	char apellidoAuxDos[STRING];

	if(pasajeroUno != NULL && pasajeroDos != NULL){

		if(Passenger_getApellido(pasajeroUno, apellidoAuxUno) == 1){

			if(Passenger_getApellido(pasajeroDos, apellidoAuxDos) == 1){

				retorno = strcmp(apellidoAuxUno, apellidoAuxDos );

			}//fin if

		}//fin if

	}//fin if

	return retorno;

}//fin Passenger_sortByApellido

int Passenger_getApellido(Passenger* this,char* apellido){

	strcpy(apellido, this->apellido);

	return 1;
}
