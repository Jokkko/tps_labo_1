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
#include <ctype.h>
#include <string.h>

#include "input.h"
#include "Logica.h"
#define TAM 22

#define LIBRE 0
#define OCUPADO 1

int main(void) {
	setbuf(stdout, NULL);
	int opcion, opcionCosto, opcionCarga;
	int costoHospedaje = 0, costoComida = 0, costoTransporte = 0,
			costoMantenimiento = 0;
	int contArq = 0, contDef = 0, contMC = 0, contDel = 0;
	int numCamiseta[TAM], estado[TAM], confederacion[TAM];
	char respuesta;
	int bufferNumeroCamiseta;
	int contadorAFC=0, contadorCAF=0, contadorCONCACAF=0, contadorCONMEBOL=0,contadorUEFA=0,contadorOFC=0;

	InicializarArray(estado, TAM);
	InicializarArray(numCamiseta, TAM);

	do {
		printf(
				"Menu principal\n "
						"\n1. Ingreso de los costos de Mantenimiento. \nCosto de hospedaje -> %d \nCosto de comida -> %d \nCosto de transporte -> %d "
						"\n2. Carga de jugadores: \nCantidad de Arqueros -> %d \nCantidad de Defensores -> %d \nCantidad de Mediocampistas -> %d \nCantidad de Delanteros -> %d"
						" \n3. Realizar todos los cálculos."
						" \n4. Informar todos los resultados."
						" \n5. Salir."
						"\nIngrese Opcion: ", costoHospedaje, costoComida,
				costoTransporte, contArq, contDef, contMC, contDel);
		getInt(&opcion);

		switch (opcion) {

		case 1:
			do {
				printf("\nElegir monto a cargar: "
						"\n1. Costo de Hospedaje."
						"\n2. Costo de Comida."
						"\n3. Costo de Transporte."
						"\n4. Salir."
						"\nIngrese Opcion: ");
				getInt(&opcionCosto);

				switch (opcionCosto) {
				case 1:
					utn_getPositivo(&costoHospedaje,
							"\nIngrese costo de Hospedaje: ",
							"Error ingrese un costo mayor a 0. Reintentos restantes: ",
							3);
					costoMantenimiento += costoHospedaje;
					break;
				case 2:
					utn_getPositivo(&costoComida, "\nIngrese costo de Comida: ",
							"Error ingrese un costo mayor a 0. Reintentos restantes: ",
							3);
					costoMantenimiento += costoComida;
					break;
				case 3:
					utn_getPositivo(&costoTransporte,
							"\nIngrese costo de Transporte: ",
							"Error ingrese un costo mayor a 0. Reintentos restantes: ",
							3);
					costoMantenimiento += costoTransporte;
					break;
				case 4:
					printf("Saliendo...\n");
					break;
				default:
					printf("Opcion incorrecta.\n");
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
						"\n5. Salir."
						"\nIngrese Opcion: ");
				getInt(&opcionCarga);
				switch (opcionCarga) {
				case 1:
					do {
						if (contArq < 2) {
							for (int i = 0; i < TAM; i++) {
								if (estado[i] == LIBRE) {
									contArq++;

									utn_getNumero(&bufferNumeroCamiseta, "\nIngrese numero de camiseta: ",
												"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
												1, 99, 3);
										for (int j = 0; j < TAM; j++) {
											if (bufferNumeroCamiseta == numCamiseta[j]) {
												do {
													printf("Error, ese numero de camiseta ya esta asignado");
													utn_getNumero(&bufferNumeroCamiseta,
															"\nIngrese numero de camiseta: ",
															"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
															1, 99, 3);
												} while (bufferNumeroCamiseta == numCamiseta[j]);

											}
										}
										numCamiseta[i]=bufferNumeroCamiseta;


									utn_getNumero(&confederacion[i],
											"\nIngrese el numero segun la confederacion (1.AFC | 2.CAF | 3.CONCACAF | 4. CONMEBOL | 5. UEFA | 6. OFC)",
											"Error eliga un numero entre 1 y 6. Reintentos restantes:",
											1, 6, 3);
									estado[i]= OCUPADO;
									break;
								}
							}
						} else {
							printf("Error ya se cargaron 2 arqueros.");
							break;
						}
						utn_getChar(&respuesta,
								"Desea agregar otro arquero? 'S' para continuar, o cualquier otra tecla para salir.",
								"\nIngrese S o N", 65, 122, 3);
						respuesta = toupper(respuesta);
					} while (respuesta == 'S');

					break;
				case 2:
					do {
						if (contDef < 8) {
							for (int i = 0; i < TAM; i++) {
								if (estado[i] == LIBRE) {
									contDef++;

									utn_getNumero(&bufferNumeroCamiseta, "\nIngrese numero de camiseta: ",
												"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
												1, 99, 3);
										for (int j = 0; j < TAM; j++) {
											if (bufferNumeroCamiseta == numCamiseta[j]) {
												do {
													printf("Error, ese numero de camiseta ya esta asignado");
													utn_getNumero(&bufferNumeroCamiseta,
															"\nIngrese numero de camiseta: ",
															"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
															1, 99, 3);
												} while (bufferNumeroCamiseta == numCamiseta[j]);

											}
										}
										numCamiseta[i]=bufferNumeroCamiseta;


									utn_getNumero(&confederacion[i],
											"\nIngrese el numero segun la confederacion (1.AFC | 2.CAF | 3.CONCACAF | 4. CONMEBOL | 5. UEFA | 6. OFC)",
											"Error eliga un numero entre 1 y 6. Reintentos restantes:",
											1, 6, 3);
									estado[i]= OCUPADO;
									break;
								}
							}
						} else {
							printf("Error ya se cargaron 8 Defensores.");
							break;
						}
						utn_getChar(&respuesta,
								"Desea agregar otro Defensor? 'S' para continuar, o cualquier otra tecla para salir.",
								"\nIngrese S o N", 65, 122, 3);
						respuesta = toupper(respuesta);
					} while (respuesta == 'S');

					break;
				case 3:
					do {
						if (contMC < 8) {
							for (int i = 0; i < TAM; i++) {
								if (estado[i] == LIBRE) {
									contMC++;

									utn_getNumero(&bufferNumeroCamiseta, "\nIngrese numero de camiseta: ",
												"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
												1, 99, 3);
										for (int j = 0; j < TAM; j++) {
											if (bufferNumeroCamiseta == numCamiseta[j]) {
												do {
													printf("Error, ese numero de camiseta ya esta asignado");
													utn_getNumero(&bufferNumeroCamiseta,
															"\nIngrese numero de camiseta: ",
															"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
															1, 99, 3);
												} while (bufferNumeroCamiseta == numCamiseta[j]);

											}
										}
										numCamiseta[i]=bufferNumeroCamiseta;


									utn_getNumero(&confederacion[i],
											"\nIngrese el numero segun la confederacion (1.AFC | 2.CAF | 3.CONCACAF | 4. CONMEBOL | 5. UEFA | 6. OFC)",
											"Error eliga un numero entre 1 y 6. Reintentos restantes:",
											1, 6, 3);
									estado[i]= OCUPADO;
									break;
								}
							}
						} else {
							printf("Error ya se cargaron 8 Mediocampistas.");
							break;
						}
						utn_getChar(&respuesta,
								"\nDesea agregar otro MedioCampista? 'S' para continuar, o cualquier otra tecla para salir.",
								"\nIngrese S o N", 65, 122, 3);
						respuesta = toupper(respuesta);
					} while (respuesta == 'S');

					break;
				case 4:
					do {
											if (contDel < 4) {
												for (int i = 0; i < TAM; i++) {
													if (estado[i] == LIBRE) {
														contDel++;

														utn_getNumero(&bufferNumeroCamiseta, "\nIngrese numero de camiseta: ",
																	"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
																	1, 99, 3);
															for (int j = 0; j < TAM; j++) {
																if (bufferNumeroCamiseta == numCamiseta[j]) {
																	do {
																		printf("Error, ese numero de camiseta ya esta asignado");
																		utn_getNumero(&bufferNumeroCamiseta,
																				"\nIngrese numero de camiseta: ",
																				"Error el numero de camiseta debe estar entre 1 y 99. Reintentos restantes:",
																				1, 99, 3);
																	} while (bufferNumeroCamiseta == numCamiseta[j]);

																}
															}
															numCamiseta[i]=bufferNumeroCamiseta;


														utn_getNumero(&confederacion[i],
																"\nIngrese el numero segun la confederacion (1.AFC | 2.CAF | 3.CONCACAF | 4. CONMEBOL | 5. UEFA | 6. OFC)",
																"Error eliga un numero entre 1 y 6. Reintentos restantes:",
																1, 6, 3);
														estado[i]= OCUPADO;
														break;
													}
												}
											} else {
												printf("Error ya se cargaron 4 Delanteros.");
												break;
											}
											utn_getChar(&respuesta,
													"\nDesea agregar otro Delantero? 'S' para continuar, o cualquier otra tecla para salir.",
													"\nIngrese S o N", 65, 122, 3);
											respuesta = toupper(respuesta);
										} while (respuesta == 'S');
					break;
				case 5:
					printf("Saliendo...\n");
					break;
				default:
					printf("Opcion incorrecta.\n");
					break;
				}
			} while (opcionCarga != 5);

			break;
		case 3:

			for(int i =0;i<TAM;i++){
				switch(confederacion[i]){
				case 1:
					contadorAFC++;
					break;
				case 2:
					contadorCAF++;
					break;
				case 3:
					contadorCONCACAF++;
					break;
				case 4:
					contadorCONMEBOL++;
					break;
				case 5:
					contadorUEFA++;
					break;
				case 6:
					contadorOFC++;
					break;
				}
			}



			break;
		case 4:
			break;
		case 5:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion incorrecta.\n");
			break;
		}

	} while (opcion != 5);

	return 1;
}
