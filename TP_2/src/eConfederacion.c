/*
 * eConfederacion.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#include "eConfederacion.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#define VACIO 0
#define LLENO 1

int HardcodeoConfederacion(eConfederacion hardcodeame[],int SIZE){
	int retorno= -1;
		if (SIZE>0 && hardcodeame != NULL){
			eConfederacion confederaciones[]={
									{100,"CONMEBOL","SUDAMERICA",1916,1},
									{101,"UEFA","EUROPA",1954,1},
									{102,"AFC","ASIA",1954,1},
									{103,"CAF","AFRICA",1957,1},
									{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,1},
									{105,"OFC","OCEANIA",1966,1}};
			for(int i=0;i<SIZE;i++){
				hardcodeame[i]=confederaciones[i];
			}
			retorno=1;
		}
		return retorno;
}



int SwapConfederacion(eConfederacion confederacion[], int i,int j){
	int retorno=-1;
	eConfederacion aux;

	aux = confederacion[i];
	confederacion[i] = confederacion[j];
	confederacion[j] = aux;

	return retorno;
}

int BuscarIdConf(eConfederacion confederacion[],int SIZE,int id){
	int retorno =-1;
	int i;
	if(SIZE >0 && confederacion !=NULL){
		for(i=0;i<SIZE;i++){
			if(confederacion[i].isEmpty==LLENO && confederacion[i].id ==id ){
				retorno =i;
				break;
			}
		}
	}
	return retorno;
}
