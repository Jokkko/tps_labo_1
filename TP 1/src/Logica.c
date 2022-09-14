/*
 * Logica.c
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */
#include <stdio.h>

int InicializarArray(int array[],int SIZE){
	int retorno = -1;//Si la inicializacion sale mal

	if (SIZE>0){
		for(int i =0;i<SIZE;i++){
			array[i]=0;
		}
		retorno = 1;//inicializacion correcta
	}
	return retorno;
}
