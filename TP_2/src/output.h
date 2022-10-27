/*
 * output.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include "eJugador.h"
#include "eConfederacion.h"

int MostrarOpcion(char *opcion);
int MostrarMenu(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *menu);
void MensajeError(int caso);
int MostrarJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);
int MostrarConfederacion(eConfederacion confederacion[],int SIZE);
int MostrarConfederacionesYJugadores(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);
int MostrarPromedioYSalarios(eJugador jugadores[],int SIZE);
int MostrarConfeMasAnios(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);
int MostrarPorcentajeConfe(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

int MostrarRegionMax(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);
#endif /* OUTPUT_H_ */
