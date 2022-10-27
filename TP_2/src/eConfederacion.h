/*
 * eConfederacion.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_


typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;

}eConfederacion;

int HardcodeoConfederacion(eConfederacion confederaciones[],int SIZE);

int SwapConfederacion(eConfederacion confederacion[], int i,int j);

int BuscarIndiceConf(eConfederacion confederacion[],int SIZE,int id);

int InicializarEstadoConf(eConfederacion confederacion[],int SIZE);

int AltaConfederacion(eConfederacion confederacion[],int SIZE, int IdAutoincremental);

#endif /* ECONFEDERACION_H_ */
