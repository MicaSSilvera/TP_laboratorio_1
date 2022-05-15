/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
//#include<enteros.h>

#include "Passenger.h"
#include "Pasajes.h"
#include "Funciones.h"

#define PASAJEROS 5
#define MENSAJES 100

int main(void) {
	setbuf(stdout,NULL);

	int opcion = 0;
	int countPasajero = 0;
	int idPasajero = 0;

	struct ePassenger miPasajero;
	struct ePassenger listaPasajeros[PASAJEROS];

	initPasajeros(listaPasajeros, PASAJEROS);

	while(opcion != 6){
		mostrarMenu();

		char mensaje[MENSAJES];
		memcpy(&mensaje, "Ingrese una opcion: ", MENSAJES);
		opcion = validarEntero(mensaje);

		clearConsole();
		int validar = 0;

		 switch(opcion){
				case 1://ALTA
					validar = validarEspacioLista(listaPasajeros , PASAJEROS);
					if(validar == 1){
						countPasajero++;

						miPasajero = crearPasajero(countPasajero);

						guardarPasajero( listaPasajeros , miPasajero, PASAJEROS);

					}else{
						printf("NO HAY MAS ESPACIO EN LA LISTA DE PASAJEROS.");
					}
					clearConsole();
			        break;
				case 2://MODIFICAR
					validar = validarPasajeros(listaPasajeros , PASAJEROS);
					if(validar == 1){
						mostrarLista( listaPasajeros , PASAJEROS);

						char mensaje[MENSAJES];
						memcpy(&mensaje, "\nIngrese el ID del pasajero que quiere modificar: ", MENSAJES);
						idPasajero = validarEntero(mensaje);

						miPasajero = crearPasajero(idPasajero);

						modificarPasajero( listaPasajeros ,PASAJEROS, miPasajero);

					}else {
						printf("NO SE HA INGRESADO NINGUN PASAJERO.");
					}
					clearConsole();
					break;
				case 3://BORRAR
					validar = validarPasajeros(listaPasajeros , PASAJEROS);
					if(validar == 1){
						mostrarLista( listaPasajeros , PASAJEROS);

						char mensaje[MENSAJES];
						memcpy(&mensaje, "\nIngrese el ID del pasajero que quiere eliminar: ", MENSAJES);
						idPasajero = validarEntero(mensaje);

						char rta = validarRespuesta();
						if(rta == 's'){
							borrarPasajero( listaPasajeros ,PASAJEROS, idPasajero);
						}
					}else {
						printf("NO SE HA INGRESADO NINGUN PASAJERO.");
					}
					clearConsole();
					break;
				case 4://INFORMAR
					validar = validarPasajeros(listaPasajeros , PASAJEROS);
					if(validar == 1){
						ordenarPasajerosPorApellido( listaPasajeros , PASAJEROS);
						printf("LISTA DE PASAJEROS ORDENADOS POR APELLIDO Y TIPO DE PASAJERO: \n");
						mostrarLista( listaPasajeros , PASAJEROS);

						struct ePasajes objPasajes;
						objPasajes = calcularPasajes(listaPasajeros , PASAJEROS);

						printf("\nRECAUDACION TOTAL: %.2f \n", objPasajes.acumPasajes);
						printf("\nPROMEDIO DE LOS PRECIOS DE LOS PASAJES: %.2f \n", objPasajes.promPasajes);
						printf("\nPASAJEROS QUE SUPERAN EL PRECIO PROMEDIO: %d \n", objPasajes.contPrecioPromedio);
						ordenarPasajerosPorCodVuelo( listaPasajeros , PASAJEROS);
						printf("\nLISTA DE PASAJEROS ORDENADOS POR CODIGO DE VUELO Y ESTADO DE VUELO: \n");
						mostrarLista( listaPasajeros , PASAJEROS);
					}else {
					   printf("NO SE HA INGRESADO NINGUN PASAJERO.");
					}
					clearConsole();
					break;
				case 5:
					printf("CARGA FORZADA DE DATOS... \n");
					initPasajeros(listaPasajeros, PASAJEROS);
					cargarDatosForzados(listaPasajeros, PASAJEROS);
					countPasajero =5;
					mostrarLista( listaPasajeros , PASAJEROS);
					clearConsole();
					break;
				case 6:
					printf("SALIENDO :)");
					clearConsole();
					break;
				default:
					printf("LA OPCION INGRESADA ES INCORRECTA");
					clearConsole();
					break;
			}//fin swicht
		 fflush(stdin);
	}//fin while

	return EXIT_SUCCESS;
}//fin del main

