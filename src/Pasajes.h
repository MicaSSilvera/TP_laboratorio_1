/*
 * Pasajes.h
 *
 *  Created on: 14 may. 2022
 *      Author: Silvera Micaela
 */
#include "Passenger.h"

#ifndef PASAJES_H_
#define PASAJES_H_

struct ePasajes {
	float acumPasajes;
	float promPasajes;
	int contPrecioPromedio;
};

#endif /* PASAJES_H_ */

struct ePasajes calcularPasajes(struct ePassenger* listaPasajero , int len);
