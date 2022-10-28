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

int AltaConfederacion(int IdAutoincremental,eConfederacion confederacion[],int SIZE);

int BuscarIdMaximo(eConfederacion confederacion[],int SIZE);

int BuscarIndiceVacioConf(eConfederacion confederacion[],int SIZE);

int BajaConfederacion(eConfederacion confederacion[],int SIZE);

int ModificarNombreConfe(eConfederacion confederacion[],int indice,int SIZE);

int ModificarRegionConfe(eConfederacion confederacion[],int indice,int SIZE);

int ModificarAnio(eConfederacion confederacion[],int indice,int SIZE);

int BuscarIdMin(eConfederacion confederacion[],int SIZE);

#endif /* ECONFEDERACION_H_ */
