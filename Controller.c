#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
		char *texto = NULL,
		delimitador[] = ",";
		size_t len = 0;

		int countLinea = 0;
		int countAtributos = 0;

		pArchivo = fopen(path, "r");

		while (getline(&texto, &len, pArchivo) != -1){

			char* token = strtok(texto, delimitador);

			if(countLinea > 0){

				Passenger* pasajeroNuevo;

				pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

				if(token != NULL){


					while(token != NULL){
						// Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL

						switch(countAtributos){
							case 0:
								pasajeroNuevo->id = atoi(token);
								break;
							case 1:
								strcpy(pasajeroNuevo->nombre, token);
								break;
							case 2:
								strcpy(pasajeroNuevo->apellido, token);
								break;
							case 3:
								pasajeroNuevo->precio = atoi(token);
								break;
							case 4:
								strcpy(pasajeroNuevo->codigoVuelo, token);
								break;
							case 5:
								pasajeroNuevo->tipoPasajero = obtenerTipoPasajeroPorTexto(token);
								break;
							case 6:
								strtok(token, "\n");
								pasajeroNuevo->estadoVuelo = obtenerEstadoVueloPorTexto(token);
								break;
						}//FIN SWITCH

						countAtributos++;

						token = strtok(NULL, delimitador);
					}//FIN WHILE

					//llamo a la funcion ll_add() para agregar un elemento al final de LinkedList
					ll_add(pArrayListPassenger, pasajeroNuevo);

					countAtributos = 0;
				}//FIN IF

			}//FIN IF
			countLinea++;

		}//FIN WHILE

	fclose(pArchivo);
	free(texto);

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	FILE* pArchivoBin;

		 if(path != NULL){

			 pArchivoBin = fopen(path, "rb");

			 if(pArchivoBin != NULL){

				 while (!feof(pArchivoBin))	{
				    /* Hay datos disponibles para leer */

					 Passenger* pasajeroNuevo;

					 pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

					 fread(pasajeroNuevo, sizeof(Passenger), 1, pArchivoBin );

					 //pongo esta condicion ya que al leer el archivo binario me trae un registro de mas con informacion basura.
					 if(pasajeroNuevo->tipoPasajero == 1 || pasajeroNuevo->tipoPasajero == 2 || pasajeroNuevo->tipoPasajero == 3 ){

						//llamo a la funcion ll_add() para agregar un elemento al final de LinkedList
						ll_add(pArrayListPassenger, pasajeroNuevo);
					 }

				 } //FIN WHILE

				 retorno = 1;
				 fclose(pArchivoBin);

			}//FIN IF

		 }//fin if


    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{

	int size = 0;

		FILE* pArchivo;

		// la funcion fopen() devuelve un puntero de tipo FILE. Si hay un error al abrirse, devuelve NULLL
		pArchivo = fopen(path, "w" );

		//llamo a la funcion ll_len() para que retorne el tamaño del LinkedList.
		 size = ll_len(pArrayListPassenger);

		 Passenger* pasajeroLista;

		 pasajeroLista = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

		 fprintf(pArchivo, "id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoVuelo\n");

		 for(int i = 0; i<size ;i++){

			//llamo a la funcion ll_get() que le paso un lista para que retorne el indice de un pasajero
			 pasajeroLista = ll_get(pArrayListPassenger, i);

			fprintf(pArchivo, "%d,", pasajeroLista->id);

			fprintf(pArchivo, "%s,", pasajeroLista->nombre);

			fprintf(pArchivo, "%s,", pasajeroLista->apellido);

			fprintf(pArchivo, "%.2f,", pasajeroLista->precio);

			fprintf(pArchivo, "%s,", pasajeroLista->codigoVuelo);

			fprintf(pArchivo, "%s,", obtenerTipoPasajeroPorEntero(pasajeroLista->tipoPasajero) );

			fprintf(pArchivo, "%s\n", obtenerEstadoVueloPorEntero(pasajeroLista->estadoVuelo));

		 }//fin for


		fclose(pArchivo);

	    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{

	int retorno = 0;
	int size;

	FILE* pArchivoBin;

	//Passenger* pPassengerAux;

	 if(path != NULL && pArrayListPassenger != NULL){

		 pArchivoBin = fopen(path, "wb");
		 size = ll_len(pArrayListPassenger);

		 for(int i = 0; i < size ; i++){
			Passenger* pasajeroNuevo;

			pasajeroNuevo = (Passenger*) malloc(sizeof(Passenger)); // declaro memoria dinámica

			pasajeroNuevo = ll_get(pArrayListPassenger, i);

			 if(pArchivoBin != NULL){
				 fwrite(pasajeroNuevo, sizeof(Passenger), 1, pArchivoBin);
			 }//fin if

		 }//fin for

		 retorno = 1;
		 fclose(pArchivoBin);

	 }//fin if


    return retorno;
}

