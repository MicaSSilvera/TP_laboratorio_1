#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"


#define MENSAJES 100
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(){
	setbuf(stdout,NULL);
    int opcion = 0;
    int idPasajero = 0;


    int opcionModificar = 0;
    int idIngresado = 0;

    int contaPasajeros = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    Passenger* miPasajero;

    while(opcion != 10){

    	 mostrarMenu();

    	 char mensaje[MENSAJES];
		memcpy(&mensaje, "Ingrese una opcion: ", MENSAJES);
		opcion = validarEntero(mensaje);

		clearConsole();
		int validar = 0;

    	 switch(opcion){

    	             case 1:
    	                 if(controller_loadFromText("data.csv",listaPasajeros) == 1){
    	                	 //llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
    	                	 idPasajero = ll_len(listaPasajeros);

    	                	 printf("SE CARGO LA LISTA DE PASAJEROS EXITOSAMENTE.");
    	                 }else{
    	                	 printf("SURGIO UN ERROR AL INTENTAR CARGAR LA LISTA DE PASAJEROS.");
    	                 }
    	                 clearConsole();
    	                 break;

    	             case 2:
    	            	 if(controller_loadFromBinary("data.bin",listaPasajeros) == 1){
							 //llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
							 idPasajero = ll_len(listaPasajeros);

							 printf("SE CARGO LA LISTA DE PASAJEROS EXITOSAMENTE.");
						 }else{
							 printf("SURGIO UN ERROR AL INTENTAR CARGAR LA LISTA DE PASAJEROS.");
						 }
    	            	 clearConsole();
    	            	 break;

    	             case 3: // ALTA DE PASAJEROS
    	            	 idPasajero++;

    	            	 //llamo la funcion Passenger_new() para poder cargar los datos de los pasajeros que ingresa el usuario
    	             	miPasajero = Passenger_new(idPasajero);

    	             	//llamo a la funcion ll_add() para agregar un elemento al final de LinkedList
    	             	ll_add(listaPasajeros, miPasajero);
    	             	clearConsole();
    	             	break;

    	             case 4: // MODIFICAR DATOS DE PASAJEROS

    	            	validar = validarPasajeros(listaPasajeros);
						if(validar == 1){

    	            	 //llamo a la funcion mostrarListaPasajeros() para que muestre todos los datos de los pasajeros ingresados para poder hacer la modificación correspondiente
    	            	 mostrarListaPasajeros(listaPasajeros);

    	            	 printf("\n *************************");

    	            	 char mensaje[MENSAJES];
						 memcpy(&mensaje, "\nIngrese el ID del pasajero que quiere modificar: ", MENSAJES);
						 idIngresado = validarEntero(mensaje);

    	            	 //llamo a la funcion buscarPasajeroPorId() para que busque el pasajero al ingresar el numero de id correspomdiemte;
    	            	 miPasajero = buscarPasajeroPorId( listaPasajeros, idIngresado);

    	            	 //llamo a la funcion mostrarMenuModificarPasajeros() para que muestre las opciones de datos que se pueden modificar.
    	            	 mostrarMenuModificarPasajeros();

    	            	 printf("\n Ingrese una opcion para modificar");
						 scanf("%d", &opcionModificar);

						 //llamo a la funcion modificarDato() para que el usuario elija que campo modificar;
						 modificarDato(opcionModificar, miPasajero);

						}else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");
						}//fin if

    	            	 clearConsole();
    	             break;

    	             case 5://BAJA DE PASAJEROS

    	            	 validar = validarPasajeros(listaPasajeros);
						 if(validar == 1){

    	            	 //llamo a la funcion mostrarListaPasajeros() para que muestre todos los datos de los pasajeros ingresados para poderdar la baja correspondiente
						 mostrarListaPasajeros(listaPasajeros);

						 printf("\n *************************");

						 printf("\n Ingrese el id del pasajero a eliminar:");
						 scanf("%d", &idIngresado);

						 //llamo a la funcion eliminarPasajero() para que se pueda dar de baja los datos del pasajero seleccionado
						eliminarPasajero(listaPasajeros, idIngresado);
						 }else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");
						}//fin if


    	            	 clearConsole();
    	             break;

    	             case 6://LISTAR PASAJEROS

    	            	 validar = validarPasajeros(listaPasajeros);
						 if(validar == 1){

						 //llamo a la funcion mostrarListaPasajeros() para que muestre todos los datos de los pasajeros ingresados.
    	            	 mostrarListaPasajeros(listaPasajeros);

						 }else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");

						 }//fin if
    	            	 clearConsole();
    	             break;

    	             case 7:// ORDENAR PASAJEROS

    	            	 validar = validarPasajeros(listaPasajeros);
						 if(validar == 1){
							 ll_sort(listaPasajeros, Passenger_sortByApellido, 1);

						 //llamo a la funcion mostrarListaPasajeros() para que muestre todos los datos de los pasajeros ingresados.
						 mostrarListaPasajeros(listaPasajeros);

						 }else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");

						 }//fin if
    	            	 clearConsole();
    	             break;

    	             case 8:
    	            	 validar = validarPasajeros(listaPasajeros);
						 if(validar == 1){

							 if(controller_saveAsText("data.csv",listaPasajeros) ==1 ){

							 	 printf("SE GUARDO LA LISTA DE PASAJEROS EXITOSAMENTE.");
							 }else{
								 printf("SURGIO UN ERROR AL INTENTAR GUARDAR LA LISTA DE PASAJEROS.");
							 }


						 }else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");

						 }//fin if
						 clearConsole();
						 break;

    	             case 9:
    	            	 validar = validarPasajeros(listaPasajeros);
						 if(validar == 1){

							 if(controller_saveAsBinary("data.bin",listaPasajeros) == 1  ){

								 //llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
								 idPasajero = ll_len(listaPasajeros);

								 printf("SE GUARDO LA LISTA DE PASAJEROS EXITOSAMENTE.");
							 }else{
								 printf("SURGIO UN ERROR AL INTENTAR GUARDO LA LISTA DE PASAJEROS.");
							 }

						 }else {
							printf("NO SE HA INGRESADO NINGUN PASAJERO.");

						 }//fin if
						 clearConsole();
						 break;

    	             case 10://salir

    	            	 printf("saliendo");

    	             break;

    	             default:
    	 				printf("LA OPCION INGRESADA ES INCORRECTA");
    	 				break;

    	         }//fin switch
        fflush(stdin);
    }//fin while

}//fin main

