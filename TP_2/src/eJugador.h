/*
 * eJugador.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#ifndef EJUGADOR_H_
#define EJUGADOR_H_
#include "eConfederacion.h"

typedef struct{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;



int InicializarEstado(eJugador jugadores[],int SIZE);

int BuscarIndiceVacio(eJugador jugadores[],int SIZE);

int BuscarIdJugador(eJugador jugadores[],int SIZE,int indice);

int AltaJugador(eJugador jugadores[],int SIZE, int IdAutoincremental,eConfederacion confederacion[],int SIZE2);

int BajaJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

int ModificarJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

int ModificarConfederacion(eJugador jugadores[],int indice,int SIZE,eConfederacion confederacion[],int SIZE2);

int ModificarNombre(eJugador jugadores[],int indice,int SIZE);

int ModificarPosicion(eJugador jugadores[],int indice,int SIZE);

int ModificarNumeroCamiseta(eJugador jugadores[],int indice,int SIZE);

int ModificarSalario(eJugador jugadores[],int indice,int SIZE);

int ModificarAniosContrato(eJugador jugadores[],int indice,int SIZE);

int SwapJugador(eJugador jugadores[], int i,int j);

int DetectarJugadores(eJugador jugadores[],int SIZE);

float TotalDeSalarios(eJugador jugadores[],int SIZE,float *pAcumulador);

int ContadorJugadores(eJugador jugadores[],int SIZE);

int PromedioSalarios(float salarios, int cantJugadores,float *pResultado);

int JugadoresArribaPromedio(eJugador jugadores[],int SIZE);

#endif /* EJUGADOR_H_ */
