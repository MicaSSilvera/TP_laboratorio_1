/*
 * mostrarDatos.h
 *
 *  Created on: 8 abr. 2022
 *      Author: micasilvera
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
///
void clearConsole(void);
///
void mostrarMenu(float kilometrosIngresados, float precioVuelosAerolineas, float precioVuelosLatam );
///
float ingresarKilometros(void);
///
float ingresarPreciosAerolineas(void);
///
float ingresarPreciosLatam(void);
///
float calcularPrecioDebito(float precio);
///
float calcularPrecioCredito(float precio);
///
float calcularPrecioBitcoin(float precio);
///
float calcularPrecioPorKilometro(float precio, float kilometros);
///
float calcularDiferencia(float precioUno, float precioDos);
///
void informarResultadosAerolineas(float kilometrosIngresados, float precioVuelosAerolineas, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBitcoinAerolineas, float precioKilometrosAerolineas);
///
void informarResultadosLatam(float precioVuelosLatam, float precioDebitoLatam, float precioCreditoLatam, float precioBitcoinLatam, float precioKilometrosLatam, float resultadoDiferencia);
///
void cargaForzada (void);

#endif /* FUNCIONES_H_ */
