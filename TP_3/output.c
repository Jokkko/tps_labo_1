/*
 * output.c
 *
 *  Created on: 12 nov. 2022
 *      Author: vazzr
 */

#include "input.h"
#include <stdio.h>


int MostrarOpcion(char *opcion){
	int retorno = -1;
	if(opcion != NULL){
		printf("%s\n",opcion);
		retorno =1;
	}
	return retorno;
}

int MostrarMenu11Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *opcion8,char *opcion9,char *opcion10,char *opcion11,char *menu){
	int retorno;
	if(opcion1 != NULL &&opcion2 != NULL &&opcion3 != NULL &&opcion4 != NULL &&opcion5 != NULL &&opcion6 != NULL &&opcion7 != NULL && menu !=NULL){
		MostrarOpcion(menu);

		MostrarOpcion(opcion1);
		MostrarOpcion(opcion2);
		MostrarOpcion(opcion3);
		MostrarOpcion(opcion4);
		MostrarOpcion(opcion5);
		MostrarOpcion(opcion6);
		MostrarOpcion(opcion7);
		MostrarOpcion(opcion8);
		MostrarOpcion(opcion9);
		MostrarOpcion(opcion10);
		MostrarOpcion(opcion11);
		fflush(stdin);
		do{
			utn_getNumero(&retorno,"\nIngrese Opcion:","",1,11,1);
		}while(retorno ==-1);
	}
	return retorno;
}

int MostrarMenu4Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *menu){
	int retorno;
	if(opcion1 != NULL &&opcion2 != NULL &&opcion3 != NULL &&opcion4 != NULL && menu !=NULL){
		MostrarOpcion(menu);

		MostrarOpcion(opcion1);
		MostrarOpcion(opcion2);
		MostrarOpcion(opcion3);
		MostrarOpcion(opcion4);

		fflush(stdin);
		do{
			utn_getNumero(&retorno,"\nIngrese Opcion:","",1,4,1);
		}while(retorno ==-1);
	}
	return retorno;
}

int MostrarMenu3Opc(char *opcion1,char *opcion2,char *opcion3,char *menu){
	int retorno;
	if(opcion1 != NULL &&opcion2 != NULL &&opcion3 != NULL  && menu !=NULL){
		MostrarOpcion(menu);

		MostrarOpcion(opcion1);
		MostrarOpcion(opcion2);
		MostrarOpcion(opcion3);

		fflush(stdin);
		do{
			utn_getNumero(&retorno,"\nIngrese Opcion:","",1,3,1);
		}while(retorno ==-1);
	}
	return retorno;
}

int MostrarMenu5Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *menu){
	int retorno;
	if(opcion1 != NULL &&opcion2 != NULL &&opcion3 != NULL  && menu !=NULL &&opcion4 != NULL &&opcion5 != NULL){
		MostrarOpcion(menu);

		MostrarOpcion(opcion1);
		MostrarOpcion(opcion2);
		MostrarOpcion(opcion3);
		MostrarOpcion(opcion4);
		MostrarOpcion(opcion5);

		fflush(stdin);
		do{
			utn_getNumero(&retorno,"\nIngrese Opcion:","",1,5,1);
		}while(retorno ==-1);
	}
	return retorno;
}
