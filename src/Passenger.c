/*
 * funcionTP2.c
 *
 *  Created on: 9 may. 2022
 *      Author: Silvera Micaela
 */

#include "Passenger.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MENSAJES 100

//desarrollo

struct ePassenger crearPasajero(int idPasajero){

	struct ePassenger pasajeroNuevo;

	pasajeroNuevo.id = idPasajero;

	printf("Ingrese nombre del pasajero: \n");
	scanf("%s" , &pasajeroNuevo.nombre );

	printf("Ingrese apellido del pasajero: \n");
	scanf("%s" , &pasajeroNuevo.apellido );

	char mensaje[MENSAJES];
	memcpy(&mensaje, "Ingrese el precio del vuelo: \n", MENSAJES);
	pasajeroNuevo.precio = (float)validarEntero(mensaje);

	printf("Ingrese codigo de vuelo: \n");
	scanf("%s", &pasajeroNuevo.codigoVuelo );

	memcpy(&mensaje, "Ingrese tipo de pasajero: [1. Turista - 2. Ejecutivo - 3. Primera Clase] \n", MENSAJES);
	pasajeroNuevo.tipoPasajero = validarEstado(mensaje);

	memcpy(&mensaje, "Ingrese estado de vuelo: [1. Activo - 2. Abordando - 3. Cancelado] \n", MENSAJES);
	pasajeroNuevo.estadoVuelo = validarEstado(mensaje);

	pasajeroNuevo.isEmpty = 0;

	return pasajeroNuevo;

}//fin alta pasajero
///
int initPasajeros(struct ePassenger* listaPasajero , int len){

	for(int i = 0; i < len; i++){

		listaPasajero[i].id = 0;
		memcpy(&listaPasajero[i].nombre, "", STRING);
		memcpy(&listaPasajero[i].apellido, "", STRING);
		listaPasajero[i].precio =0;
		memcpy(&listaPasajero[i].codigoVuelo, "", STRING);
		listaPasajero[i].tipoPasajero= 0;
		listaPasajero[i].estadoVuelo  =0;
		listaPasajero[i].isEmpty=1;

	}//fin for

	return 0;

}//FIN FUNCTION INIT
///
void mostrarLista(struct ePassenger* listaPasajero , int len){

	printf("LISTA DE PASAJEROS: \n" );

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 0 ){
			printf("----------------------------------------- \n" );
			printf("ID: %d \n", listaPasajero[i].id );

			printf("Nombre: %s \n", listaPasajero[i].nombre);

			printf("Apellido: %s \n", &listaPasajero[i].apellido );

			printf("Precio: %.2f \n", listaPasajero[i].precio );

			printf("Codigo de vuelo: %s \n",&listaPasajero[i].codigoVuelo );

			if( listaPasajero[i].tipoPasajero == 1){
				printf("Tipo de pasajero: %d [TURISTA] \n", listaPasajero[i].tipoPasajero );
			}else if(listaPasajero[i].tipoPasajero == 2){
				printf("Tipo de pasajero: %d [EJECUTIVO]\n", listaPasajero[i].tipoPasajero );
			}else{
				printf("Tipo de pasajero: %d [PRIMERA CLASE]\n", listaPasajero[i].tipoPasajero );
			}//fin de if

			if( listaPasajero[i].estadoVuelo == 1){
				printf("Estado de vuelo: %d [ACTIVO] \n", listaPasajero[i].estadoVuelo );
			}else if(listaPasajero[i].estadoVuelo == 2){
				printf("Estado de vuelo: %d [ABORDANDO] \n", listaPasajero[i].estadoVuelo );
			}else{
				printf("Estado de vuelo: %d [CANCELADO] \n", listaPasajero[i].estadoVuelo );
			}

		}//fin if
	}//fin for


}//fin funcion mostrar lista
///
void guardarPasajero(struct ePassenger* listaPasajero, struct ePassenger pasajeroNuevo, int len ){
	int guardoDatos = 0;
	int contDatos = 0;

	while(contDatos < len ){

		if(listaPasajero[contDatos].isEmpty == 1){

			listaPasajero[contDatos] = pasajeroNuevo;
			guardoDatos = 1;
			contDatos = len;

		}else{
			contDatos++;
		}//fin del IF


	}//fin de while*/

	if(guardoDatos == 0){
		printf("No se pudo guardar al pasajero, ya que no hay mas lugar.");
	}

}//fin de funcion guardar
///
int validarPasajeros(struct ePassenger* listaPasajero , int len){

	int validacion = 0;

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 0){

			validacion = 1;

		}//fin if

	}//fin for

	return validacion;
}//fin funcion validar
///
int validarEspacioLista(struct ePassenger* listaPasajero , int len){

	int validacion = 0;

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1){

			validacion = 1;

		}//fin if

	}//fin for

	return validacion;
}//fin funcion validar
///
void modificarPasajero(struct ePassenger* listaPasajero , int len, struct ePassenger pasajero){

	for(int i = 0; i < len; i++){

			if(listaPasajero[i].id != 0){

				if(listaPasajero[i].id == pasajero.id){

					listaPasajero[i] = pasajero;

				}//fin if

		  }//fin if

	}//fin for

}//FIN buscarPasajeroPorId()
///
void borrarPasajero(struct ePassenger* listaPasajero , int len, int idPasajero){

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].id != 0){

			if(listaPasajero[i].id == idPasajero){

				listaPasajero[i].id = 0;
				memcpy(&listaPasajero[i].nombre, "", STRING);
				memcpy(&listaPasajero[i].apellido, "", STRING);
				listaPasajero[i].precio = 0;
				memcpy(&listaPasajero[i].codigoVuelo, "", STRING);
				listaPasajero[i].tipoPasajero = 0;
				listaPasajero[i].estadoVuelo = 0;
				listaPasajero[i].isEmpty = 1;

			}//fin if

		}//fin if

	}//fin for


}//FIN borrarPasajero()
///
void ordenarPasajerosPorApellido(struct ePassenger* listaPasajero, int len){


	for(int i = 0; i < len; i++){

		for(int j=0; j<len-1; j++){
			int indiceSiguiente = j + 1;

			if(strcmp(listaPasajero[j].apellido, listaPasajero[indiceSiguiente].apellido) > 0 ){

				struct ePassenger pasajeroAux;

				pasajeroAux = listaPasajero[j];
				listaPasajero[j] = listaPasajero[indiceSiguiente];
				listaPasajero[indiceSiguiente] = pasajeroAux;

			}else if(strcmp(listaPasajero[j].apellido, listaPasajero[indiceSiguiente].apellido) == 0 && listaPasajero[j].tipoPasajero > listaPasajero[indiceSiguiente].tipoPasajero){
				struct ePassenger pasajeroAux;

				pasajeroAux = listaPasajero[j];
				listaPasajero[j] = listaPasajero[indiceSiguiente];
				listaPasajero[indiceSiguiente] = pasajeroAux;
			}//fin if

		}//fin for
	}//fin for


}//fin funcion ordenar

void ordenarPasajerosPorCodVuelo(struct ePassenger* listaPasajero, int len){

	for(int i = 0; i < len; i++){

		for(int j=0; j<len-1; j++){
			int indiceSiguiente = j + 1;

			if(strcmp(listaPasajero[j].codigoVuelo, listaPasajero[indiceSiguiente].codigoVuelo) > 0 ){

				struct ePassenger pasajeroAux;

				pasajeroAux = listaPasajero[j];
				listaPasajero[j] = listaPasajero[indiceSiguiente];
				listaPasajero[indiceSiguiente] = pasajeroAux;

			}else if(strcmp(listaPasajero[j].codigoVuelo, listaPasajero[indiceSiguiente].codigoVuelo) == 0 && listaPasajero[j].estadoVuelo > listaPasajero[indiceSiguiente].estadoVuelo){
				struct ePassenger pasajeroAux;

				pasajeroAux = listaPasajero[j];
				listaPasajero[j] = listaPasajero[indiceSiguiente];
				listaPasajero[indiceSiguiente] = pasajeroAux;
			}//fin if

		}//fin for
	}//fin for


}//fin funcion ordenar
///
void cargarDatosForzados(struct ePassenger* listaPasajero, int len){

	struct ePassenger pasajeroNuevo;

	pasajeroNuevo.id = 1;
	memcpy(&pasajeroNuevo.nombre, "Mario", STRING);
	memcpy(&pasajeroNuevo.apellido, "Baduel", STRING);
	pasajeroNuevo.precio = 1000;
	memcpy(&pasajeroNuevo.codigoVuelo, "AB110", STRING);
	pasajeroNuevo.tipoPasajero = 2;
	pasajeroNuevo.estadoVuelo = 3;
	pasajeroNuevo.isEmpty = 0;

	int guardo = 0;
	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1  && guardo ==0){
			listaPasajero[i] = pasajeroNuevo;
			guardo = 1;
		}//fin if
	}//fin for

	struct ePassenger pasajeroNuevo2;
	pasajeroNuevo2.id = 2;
	memcpy(&pasajeroNuevo2.nombre, "Maffy", STRING);
	memcpy(&pasajeroNuevo2.apellido, "Alvarez", STRING);
	pasajeroNuevo2.precio = 2000;
	memcpy(&pasajeroNuevo2.codigoVuelo, "AB109", STRING);
	pasajeroNuevo2.tipoPasajero = 2;
	pasajeroNuevo2.estadoVuelo = 3;
	pasajeroNuevo2.isEmpty = 0;

	guardo = 0;
	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1  && guardo ==0){
			listaPasajero[i] = pasajeroNuevo2;
			guardo = 1;
		}//fin if
	}//fin for

	struct ePassenger pasajeroNuevo3;
	pasajeroNuevo3.id = 3;
	memcpy(&pasajeroNuevo3.nombre, "Simon", STRING);
	memcpy(&pasajeroNuevo3.apellido, "Silvera", STRING);
	pasajeroNuevo3.precio = 3000;
	memcpy(&pasajeroNuevo3.codigoVuelo, "AB109", STRING);
	pasajeroNuevo3.tipoPasajero = 3;
	pasajeroNuevo3.estadoVuelo = 1;
	pasajeroNuevo3.isEmpty = 0;

	guardo = 0;
	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1  && guardo ==0){
			listaPasajero[i] = pasajeroNuevo3;
			guardo = 1;
		}//fin if
	}//fin for

	struct ePassenger pasajeroNuevo4;
	pasajeroNuevo4.id = 4;
	memcpy(&pasajeroNuevo4.nombre, "Negra", STRING);
	memcpy(&pasajeroNuevo4.apellido, "Baduel", STRING);
	pasajeroNuevo4.precio = 3000;
	memcpy(&pasajeroNuevo4.codigoVuelo, "AB110", STRING);
	pasajeroNuevo4.tipoPasajero = 1;
	pasajeroNuevo4.estadoVuelo = 1;
	pasajeroNuevo4.isEmpty = 0;

	guardo = 0;
	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1  && guardo ==0){
			listaPasajero[i] = pasajeroNuevo4;
			guardo = 1;
		}//fin if
	}//fin for

	struct ePassenger pasajeroNuevo5;
	pasajeroNuevo5.id = 5;
	memcpy(&pasajeroNuevo5.nombre, "Pamela", STRING);
	memcpy(&pasajeroNuevo5.apellido, "Silvera", STRING);
	pasajeroNuevo5.precio = 3000;
	memcpy(&pasajeroNuevo5.codigoVuelo, "AB108", STRING);
	pasajeroNuevo5.tipoPasajero = 2;
	pasajeroNuevo5.estadoVuelo = 1;
	pasajeroNuevo5.isEmpty = 0;

	guardo = 0;
	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 1  && guardo ==0){
			listaPasajero[i] = pasajeroNuevo5;
			guardo = 1;
		}//fin if
	}//fin for

}//FIN cargarDatosForzados()
