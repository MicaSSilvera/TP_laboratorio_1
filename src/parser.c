#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include <string.h>

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){

	char id[CODIGO];
	char nombre[STRING];
	char apellido[STRING];
	char precio[STRING];
	char tipoPasajero[STRING];
	char codigoVuelo[CODIGO];
	char estadoVuelo[STRING];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

	while (!feof(pFile)){

		Passenger* pasajeroNuevo;

		pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

		pasajeroNuevo->id = atoi(id);
		strcpy(pasajeroNuevo->nombre, nombre);
		strcpy(pasajeroNuevo->apellido, apellido);
		pasajeroNuevo->precio = atoi(precio);
		memcpy(pasajeroNuevo->codigoVuelo , codigoVuelo, CODIGO);
		pasajeroNuevo->tipoPasajero = obtenerTipoPasajeroPorTexto(tipoPasajero);
		pasajeroNuevo->estadoVuelo = obtenerEstadoVueloPorTexto(estadoVuelo);

		//llamo a la funcion ll_add() para agregar un elemento al final de LinkedList
		ll_add(pArrayListPassenger, pasajeroNuevo);

	}//FIN WHILE

	return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	 int retorno = 0;

	 while (!feof(pFile))	{
		/* Hay datos disponibles para leer */

		 Passenger* pasajeroNuevo;

		 pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

		 fread(pasajeroNuevo, sizeof(Passenger), 1, pFile );

		 //pongo esta condicion ya que al leer el archivo binario me trae un registro de mas con informacion basura.
		 if(pasajeroNuevo->tipoPasajero == 1 || pasajeroNuevo->tipoPasajero == 2 || pasajeroNuevo->tipoPasajero == 3 ){

			//llamo a la funcion ll_add() para agregar un elemento al final de LinkedList
			ll_add(pArrayListPassenger, pasajeroNuevo);
		 }

	 } //FIN WHILE

	retorno = 1;

	return retorno;
}
