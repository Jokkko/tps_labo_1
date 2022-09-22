/*
 * Logica.c
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */
#include <stdio.h>


int CalcularPromedio(float *pPromedio,int divisor, int dividendo ){
	int retorno = -1;

	if(divisor!=0){
		*pPromedio = dividendo /divisor;
		retorno = 1;
	}
	return retorno;
}


int CalcularPorcentaje(int *pPorcentaje, int numero, float porcentaje){
	int retorno =-1;
	porcentaje = porcentaje/100;
	*pPorcentaje= numero *porcentaje;
		retorno = 1;
	return retorno;
}

