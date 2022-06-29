/*
 * funciones.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Silvera Micaela
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "funciones.h"
#include "Passenger.h"

void mostrarMenu (){

	printf("\n 1) Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
	printf("\n 2) Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).");
	printf("\n 3) Alta de pasajero");
	printf("\n 4) Modificar datos de pasajero");
	printf("\n 5) Baja de pasajero");
	printf("\n 6) Borrar todos los pasajeros");
	printf("\n 7) Listar pasajero");
	printf("\n 8) Ordenar pasajeros");
	printf("\n 9) Guardar los datos de los pasajeros en el archivo data.csv (modo texto)");
	printf("\n 10) Guardar los datos de los pasajeros en el archivo data.csv (modo binario).");
	printf("\n 11) Salir");

	return;

}//fin mostrarMenu
///
void clearConsole(){
	printf("\n");
	printf("\n");

	return;
}//FIN clearConsole()
///
int esEntero(char linea[]) {
	int esEntero = 1;
	int longitud = strlen(linea);

	if (longitud == 0) {
		esEntero = 0;
	} else if (longitud == 1 && !isdigit(linea[0])) {
		esEntero = 0;
	} else {
		int indice = 0;

		if (linea[0] == '+' || linea[0] == '-') {
			indice = 1;
		} else {
			indice = 0;
		}//FIN IF

		while (indice < longitud) {

			if (!isdigit(linea[indice])) {
				esEntero = 0;
				break;
			}//FIN IF

			indice++;
		}//FIN WHILE
	}//FIN IF

	return esEntero;
}//FIN esEntero()
///
int validarEntero(char mensaje[]){
	int numero = 0;

	char linea[50];
	int repite = 1;

	do {
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			repite = 0;
		} else {
			printf("\nNo has ingresado un valor entero. Intentalo nuevamente\n");
		}
		fflush(stdin);
	} while (repite);

	numero = atoi(linea);

	return numero;
}//FIN validarEntero()
///
int validarEstado(char mensaje[]){
	int numero = 0;

	char linea[50];
	int repite = 1;

	do {
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			numero = atoi(linea);
			if(numero == 1 || numero == 2 || numero == 3){
				repite = 0;
			}else{
				printf("No has ingresado una opcion correcta. Intentalo nuevamente\n");
			}//fin if

		} else {
			printf("No has ingresado un valor entero. Intentalo nuevamente\n");
		}//fin if
		fflush(stdin);
	} while (repite);

	numero = atoi(linea);

	return numero;
}//FIN validarEntero()
///
char validarRespuesta(){
	char rta;
	int repite = 1;

	while(repite == 1) {
		printf("\n ESTAS SEGURO DE ELIMINAR TODOS LOS PASAJEROS? [ s / n ] ");
		scanf ("%c", &rta);

		if (rta == 's' || rta == 'n' ) {
			repite = 0;
		} else {
			printf("\nNo has ingresado un valor correcto. Intentalo nuevamente");
		}
		fflush(stdin);

	}//FIN WHILE

	return rta;
}//FIN validarRespuesta()
///
int validarPasajeros(LinkedList* listaPasajeros){

	int validacion = 0;
	int size = 0;
	 //llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
	 size = ll_len(listaPasajeros);

	if(size > 0){
		validacion = 1;
	}

	return validacion;
}//fin funcion validar
