/*
 ============================================================================
Fernandes Joaquin TP1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input.h"
#include "Logica.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion, opcionCosto, opcionCarga;
	int costoHospedaje = 0, costoComida = 0, costoTransporte = 0,
			costoMantenimiento = 0;
	int contArq = 0, contDef = 0, contMC = 0, contDel = 0;
	int numCamiseta;
	char respuesta;
	int contadorAFC = 0, contadorCAF = 0, contadorCONCACAF = 0,
			contadorCONMEBOL = 0, contadorUEFA = 0, contadorOFC = 0;
	float promedioAFC,promedioCAF,promedioCONCACAF,promedioCONMEBOL,promedioUEFA,promedioOFC;
	int aumento;
	int costoFinal;
	int cantJugadores;
	do {
		printf(
				"\nMenu principal\n "
						"\n1. Ingreso de los costos de Mantenimiento. \nCosto de hospedaje -> %d \nCosto de comida -> %d \nCosto de transporte -> %d "
						"\n2. Carga de jugadores: \nCantidad de Arqueros -> %d \nCantidad de Defensores -> %d \nCantidad de Mediocampistas -> %d \nCantidad de Delanteros -> %d"
						" \n3. Realizar todos los calculos."
						" \n4. Informar todos los resultados."
						" \n5. Salir.", costoHospedaje, costoComida,
				costoTransporte, contArq, contDef, contMC, contDel);
		if (utn_getNumero(&opcion, "\nIngrese opcion: ","Error ingrese un numero entre 1 y 5 Intentos restantes:", 1, 5,3) == -1) {
			break;
		}

		switch (opcion) {

		case 1:
			do {
				printf("\nElegir monto a cargar: "
						"\n1. Costo de Hospedaje."
						"\n2. Costo de Comida."
						"\n3. Costo de Transporte."
						"\n4. Salir.");
				if (utn_getNumero(&opcionCosto,"\nIngrese opcion: ","Error ingrese un numero entre 1 y 4 Intentos restantes:", 1,4, 3)==-1){
					break;
				}

				switch (opcionCosto) {
				case 1:
					utn_getPositivo(&costoHospedaje,"\nIngrese costo de Hospedaje: ","Error ingrese un costo mayor a 0. Reintentos restantes: ",3);

					break;
				case 2:
					utn_getPositivo(&costoComida, "\nIngrese costo de Comida: ","Error ingrese un costo mayor a 0. Reintentos restantes: ",3);

					break;
				case 3:
					utn_getPositivo(&costoTransporte,"\nIngrese costo de Transporte: ","Error ingrese un costo mayor a 0. Reintentos restantes: ",3);

					break;
				default:
					printf("Saliendo...\n");
					break;
				}
			} while (opcionCosto != 4);
			break;

		case 2:
			do {
				printf("\nElegir posicion del jugador: "
						"\n1. Arquero."
						"\n2. Defensor."
						"\n3. Mediocampista."
						"\n4. Delantero."
						"\n5. Salir.");
				if (utn_getNumero(&opcionCarga,"\nIngrese opcion: ","Error ingrese un numero entre 1 y 5 Intentos restantes:", 1,5, 3)==-1){
					break;
				}
				switch (opcionCarga) {
				case 1:
					if (contArq < 2) {
						do {

							if (utn_getNumero(&numCamiseta,"Ingrese numero de camiseta: ","Error ingrese un numero entre 1 y 99 Intentos restantes:", 1,99, 3)==-1){
								break;
							}
							if(ContarConfederacion(&contadorAFC, &contadorCAF, &contadorCONCACAF,&contadorCONMEBOL, &contadorUEFA, &contadorOFC)==-1){
								break;
							}

							contArq++;
							respuesta = 'N';
							if (contArq < 2) {
								utn_getChar(&respuesta,"Desea agregar otro arquero? 'S' para continuar, o cualquier otra tecla para salir.","\nIngrese S o N", 32, 126, 3);
								respuesta = toupper(respuesta);
							}
						} while (respuesta == 'S');
					}
					else {
						printf("Error ya se cargaron 2 arqueros.");
					}
				break;
				case 2: //def menor a 8
					if (contDef < 8) {
						do {
							if (utn_getNumero(&numCamiseta,"Ingrese numero de camiseta: ","Error ingrese un numero entre 1 y 99 Intentos restantes:", 1,99, 3)==-1){
								break;
							}
							if (ContarConfederacion(&contadorAFC, &contadorCAF,&contadorCONCACAF, &contadorCONMEBOL,&contadorUEFA, &contadorOFC) == -1) {
								break;
							}
							contDef++;
							respuesta = 'N';
							if (contDef < 8) {
								utn_getChar(&respuesta,"Desea agregar otro Defensor? 'S' para continuar, o cualquier otra tecla para salir.","\nIngrese S o N", 32, 126, 3);
								respuesta = toupper(respuesta);
							}
						} while (respuesta == 'S');
					}
					else {
						printf("Error ya se cargaron 8 defensores.");
					}
				break;
				case 3: //mc menor a 8
					if (contMC < 8) {
						do {
							if (utn_getNumero(&numCamiseta,"Ingrese numero de camiseta: ","Error ingrese un numero entre 1 y 99 Intentos restantes:", 1,99, 3)==-1){
								break;
							}
							if (ContarConfederacion(&contadorAFC, &contadorCAF,&contadorCONCACAF, &contadorCONMEBOL,&contadorUEFA, &contadorOFC) == -1) {
								break;
							}
							contMC++;
							respuesta = 'N';
							if (contMC < 8) {
								utn_getChar(&respuesta,"Desea agregar otro Mediocampista? 'S' para continuar, o cualquier otra tecla para salir.","\nIngrese S o N", 32, 126, 3);
								respuesta = toupper(respuesta);
							}
						} while (respuesta == 'S');
					}
					else {
						printf("Error ya se cargaron 8 Mediocampistas.");
					}
				break;
				case 4: //Del menor a 4
					if (contDel < 4) {
						do {
							if (utn_getNumero(&numCamiseta,"Ingrese numero de camiseta: ","Error ingrese un numero entre 1 y 99 Intentos restantes:", 1,99, 3)==-1){
								break;
							}
							if (ContarConfederacion(&contadorAFC, &contadorCAF,&contadorCONCACAF, &contadorCONMEBOL,&contadorUEFA, &contadorOFC) == -1) {
								break;
							}
							contDel++;
							respuesta = 'N';
							if (contDel < 4) {
								utn_getChar(&respuesta,"Desea agregar otro Delantero? 'S' para continuar, o cualquier otra tecla para salir.","\nIngrese S o N", 32, 126, 3);
								respuesta = toupper(respuesta);
							}
						} while (respuesta == 'S');
					}
					else {
						printf("Error ya se cargaron 4 Delanteros.");
					}
				break;
				default:
					printf("Saliendo...\n");
					break;
				}
			} while (opcionCarga != 5);
			break;

		case 3:
			cantJugadores= contArq + contDef + contMC + contDel;
			if(cantJugadores >0 && (costoHospedaje > 0 && costoComida > 0 && costoTransporte>0)){



				CalcularPromedio(&promedioAFC,cantJugadores, contadorAFC );
				CalcularPromedio(&promedioCAF,cantJugadores, contadorCAF );
				CalcularPromedio(&promedioCONCACAF,cantJugadores, contadorCONCACAF );
				CalcularPromedio(&promedioCONMEBOL,cantJugadores, contadorCONMEBOL );
				CalcularPromedio(&promedioUEFA,cantJugadores, contadorUEFA );
				CalcularPromedio(&promedioOFC,cantJugadores, contadorOFC );

				costoMantenimiento= costoHospedaje+ costoComida + costoTransporte;

				if(contadorUEFA> contadorOFC && contadorUEFA > contadorCONMEBOL && contadorUEFA > contadorCONCACAF  && contadorUEFA > contadorCAF && contadorUEFA > contadorAFC){

					CalcularPorcentaje(&aumento,costoMantenimiento,35);
					costoFinal=costoMantenimiento+aumento;

				}
				printf("\nCalculos realizados correctamente");
			}
			else{
				printf("\nError, faltan datos por cargar.");
			}
			break;
		case 4:
			if(costoMantenimiento>0){
				printf("Promedio AFC: %.2f \nPromedio CAF: %.2f \nPromedio CONCACAF: %.2f \nPromedio CONMEBOL: %.2f \nPromedio UEFA: %.2f \nPromedio OFC: %.2f \n",promedioAFC,promedioCAF,promedioCONCACAF,promedioCONMEBOL,promedioUEFA,promedioOFC);

				if(aumento>0){
					printf("El costo de mantenimiento era de %d y recibio un aumento de %d, su nuevo valor es de: %d",costoMantenimiento,aumento,costoFinal);
				}
				else{
					printf("El costo de mantenimiento es de %d",costoMantenimiento);
				}

			}
			else{
				printf("\nERROR Se deben calcular los datos antes de poder imprimirlos.");
			}
			break;
		default:
			printf("Saliendo...\n");
			break;
		}
	} while (opcion != 5);

	return 1;
}
