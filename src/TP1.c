/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int opcion;
float kilometrosIngresados = 0;
float precioVuelosAerolineas = 0;
float precioVuelosLatam =0;
//punto 3
float precioDebitoLatam = 0;
float precioDebitoAerolineas = 0;
float precioCreditoAerolineas =0;
float precioCreditoLatam =0;
float precioBitcoinAerolineas = 0;
float precioBitcoinLatam =0;
float precioKilometrosAerolineas =0;
float precioKilometrosLatam =0;
float resultadoDiferencia =0;

int main(void) {
	setbuf(stdout, NULL);

	while(opcion != 6){

		mostrarMenu(kilometrosIngresados, precioVuelosAerolineas, precioVuelosLatam );

		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		clearConsole();

		switch (opcion){
			case 1:
				kilometrosIngresados = ingresarKilometros();
				clearConsole();
				break;
			case 2:
				precioVuelosAerolineas = ingresarPreciosAerolineas();
				precioVuelosLatam = ingresarPreciosLatam();
				clearConsole();
				break;
			case 3:
				calcularCostos();
				clearConsole();
				break;
			case 4:
				mostrarResultados();
				clearConsole();
				break;
			case 5:
				cargaForzada();
				clearConsole();
				break;
			case 6:
				printf("HASTA LA PROXIMA :)");
				clearConsole();
				break;
			default:
				printf("OPCION INCORRECTA :(");
				clearConsole();
				break;

		} //FIN SWITCH

	}//FIN WHILE
	return EXIT_SUCCESS;
} //FIN MAIN

void calcularCostos(){

	if(precioVuelosAerolineas == 0 || precioVuelosLatam == 0 || kilometrosIngresados == 0){
		printf("NO SE PUEDE REALIZAR CALCULOS SI NO HAY VUELOS INGRESADOS");
	}else{

		precioDebitoAerolineas = calcularPrecioDebito(precioVuelosAerolineas);
		precioDebitoLatam = calcularPrecioDebito(precioVuelosLatam);

		precioCreditoAerolineas = calcularPrecioCredito(precioVuelosAerolineas);
		precioCreditoLatam = calcularPrecioCredito(precioVuelosLatam);

		precioBitcoinAerolineas = calcularPrecioBitcoin(precioVuelosAerolineas);
		precioBitcoinLatam = calcularPrecioBitcoin(precioVuelosLatam);

		precioKilometrosAerolineas = calcularPrecioPorKilometro( precioVuelosAerolineas,kilometrosIngresados);
		precioKilometrosLatam = calcularPrecioPorKilometro(precioVuelosLatam, kilometrosIngresados);

		resultadoDiferencia = calcularDiferencia(precioVuelosAerolineas , precioVuelosLatam);

		printf("SE CALCULARON LOS COSTOS DEL VUELO INGRESADO");
	}//FIN IF
}

void mostrarResultados(){

	if(precioVuelosAerolineas == 0 || precioVuelosLatam == 0 || kilometrosIngresados == 0){
		printf("NO SE PUEDE REALIZAR CALCULOS SI NO HAY VUELOS INGRESADOS");
	}else{
		informarResultadosAerolineas(kilometrosIngresados,  precioVuelosAerolineas,  precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioKilometrosAerolineas);
		informarResultadosLatam(precioVuelosLatam, precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioKilometrosLatam, resultadoDiferencia);
	}

}

void cargaForzada (void){
	kilometrosIngresados = 7090;
	precioVuelosAerolineas = 162965;
	precioVuelosLatam = 159339;

	calcularCostos();
	clearConsole();
	mostrarResultados();
}
