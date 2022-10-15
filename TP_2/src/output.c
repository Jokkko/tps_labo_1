/*
 * output.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */
#include <stdio.h>
#include "input.h"

int MostrarOpcion(char *opcion){
	int retorno = -1;
	if(opcion != NULL){
		printf("%s\n",opcion);
		retorno =1;
	}
	return retorno;
}

int MostrarMenu(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *menu){
	int retorno;
	MostrarOpcion(menu);

	MostrarOpcion(opcion1);
	MostrarOpcion(opcion2);
	MostrarOpcion(opcion3);
	MostrarOpcion(opcion4);
	MostrarOpcion(opcion5);
	MostrarOpcion(opcion6);

	if(utn_getNumero(&retorno,"\nIngrese Opcion:", "\nError ingrese una opcion valida.",1,6,3)==-1){
		retorno =-1;
	}

	return retorno;
}
