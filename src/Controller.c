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
	int retorno = -1;
	FILE* pArchivo;

	if(pArrayListPassenger!=NULL && path!=NULL){

		if(ll_len(pArrayListPassenger) > 0){
			ll_clear(pArrayListPassenger);
		}//FIN IF

		pArchivo = fopen(path, "r");

		if(pArchivo!=NULL){
			if( parser_PassengerFromText(pArchivo , pArrayListPassenger) == 1){
				retorno = 1;
			}
		}//FIN IF
		fclose(pArchivo);

	}//FIN IF
	return retorno;
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
	FILE *pArchivoBin;
	int retorno = -1;

	if(pArrayListPassenger != NULL && path != NULL){

		if(ll_len(pArrayListPassenger) > 0){
			ll_clear(pArrayListPassenger);
		}//FIN IF

		pArchivoBin = fopen(path, "rb");

		if(pArchivoBin!=NULL){

			if(parser_PassengerFromBinary(pArchivoBin,pArrayListPassenger) == 1 ){
				retorno = 1;
			}//FIN IF

		}//FIN IF
		fclose(pArchivoBin);

	}//FIN IF

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
