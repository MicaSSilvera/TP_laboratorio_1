/*
 * funciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: micasilvera
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void clearConsole(){
	printf("\n");
	printf("\n");
}

void mostrarMenu(float kilometrosIngresados, float precioVuelosAerolineas, float precioVuelosLatam ){
	printf("1) Ingresar Kilómetros: ( km = %.2f", kilometrosIngresados);
	printf(" )");
	printf("\n2) Ingresar Precio de Vuelos: (Aerolíneas = %.2f", precioVuelosAerolineas);
	printf(", Latam = %.2f", precioVuelosLatam);
	printf(" )");
	printf("\n3) Calcular todos los costos: \n"
					"4) Informar Resultados \n"
					"5) Carga forzada de datos \n"
					"6) Salir \n");
}

float ingresarKilometros(void){
	float kilometrosIngresados=0;

	printf("Ingrese los Kms del vuelo: ");
	scanf("%f", &kilometrosIngresados);

	return kilometrosIngresados;
}

float ingresarPreciosAerolineas(void){
	float precio = 0;

	printf("Ingrese precio de vuelos Aerolineas : ");
	scanf("%f", &precio);

	return precio;
}

float ingresarPreciosLatam(void){
	float precio = 0;

	printf("Ingrese precio de vuelos Latam : ");
	scanf("%f", &precio);

	return precio;
}

float calcularPrecioDebito(float precio){
	float descuento =0;

	descuento = (precio * 10)/100;

	precio = precio - descuento;

	return precio;
}

float calcularPrecioCredito(float precio){
	float intereses =0;

	intereses = (precio * 25)/100;

	precio = precio + intereses;

	return precio;
}

float calcularPrecioBitcoin(float precio){
	float bitcoin = 4606954.55;

	precio = precio / bitcoin;

	return precio;
}

float calcularPrecioPorKilometro(float precio, float kilometros){
	float precioPorKilometro =0;

	precioPorKilometro = precio / kilometros;

	return precioPorKilometro;
}

float calcularDiferencia(float precioUno, float precioDos){
	float resultado =0;

	if(precioUno > precioDos ){
		resultado = precioUno - precioDos;
	}else if(precioDos > precioUno){
		resultado = precioDos - precioUno;
	}

	return resultado;
}

void informarResultadosAerolineas(float kilometrosIngresados, float precioVuelosAerolineas, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioKilometrosAerolineas){

	printf("KMs Ingresados: %.2f", kilometrosIngresados);
	printf(" km");

	printf("\n\nPrecio Aerolineas:  $ %.2f", precioVuelosAerolineas);
	printf("\na) Precio con tarjeta de debito:  $ %.2f", precioDebitoAerolineas);
	printf("\nb) Precio con tarjeta de credito:  $ %.2f", precioCreditoAerolineas);
	printf("\nc) Precio pagando con bitcoin: $ %.2f", precioBitcoinAerolineas);
	printf(" BTC");
	printf("\nd) Mostrar precio unitario:  $ %.2f", precioKilometrosAerolineas);

}

void informarResultadosLatam(float precioVuelosLatam, float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioKilometrosLatam, float resultadoDiferencia){

	printf("\n\nPrecio Latam:  $ %.2f", precioVuelosLatam);
	printf("\na) Precio con tarjeta de debito:  $ %.2f", precioDebitoLatam);
	printf("\nb) Precio con tarjeta de credito:  $ %.2f", precioCreditoLatam);
	printf("\nc) Precio pagando con bitcoin: $ %.2f", precioBitcoinLatam);
	printf(" BTC");
	printf("\nd) Mostrar precio unitario:  $ %.2f", precioKilometrosLatam);

	printf("\n\nLa diferencia de precio es:  $ %.2f", resultadoDiferencia);

}





