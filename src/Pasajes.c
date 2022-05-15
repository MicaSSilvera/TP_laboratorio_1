/*
 * Pasajes.c
 *
 *  Created on: 14 may. 2022
 *      Author: nikobm
 */
#include "Pasajes.h"
#include "Passenger.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct ePasajes calcularPasajes(struct ePassenger* listaPasajero , int len){

	struct ePasajes objPasajes;

	objPasajes.acumPasajes = 0;
	objPasajes.contPrecioPromedio = 0;
	objPasajes.promPasajes = 0;

	int contPasajeros = 0;

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 0 ){
			contPasajeros++;
			objPasajes.acumPasajes = objPasajes.acumPasajes + listaPasajero[i].precio;
		}//fin if

	}//fin for

	objPasajes.promPasajes = objPasajes.acumPasajes / contPasajeros;

	for(int i = 0; i < len; i++){

		if(listaPasajero[i].isEmpty == 0 &&  listaPasajero[i].precio  > objPasajes.promPasajes){
			objPasajes.contPrecioPromedio++;
		}//fin if

	}//fin for

	return objPasajes;
}//fin calcularPasajes()
