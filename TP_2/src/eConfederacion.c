/*
 * eConfederacion.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */
#include "eJugador.h"
#include "eConfederacion.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <string.h>

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
	if(confederacion != NULL){
		retorno=1;
		eConfederacion aux;

		aux = confederacion[i];
		confederacion[i] = confederacion[j];
		confederacion[j] = aux;

	}
	return retorno;
}

int BuscarIndiceConf(eConfederacion confederacion[],int SIZE,int id){
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

int BuscarIdMaximo(eConfederacion confederacion[],int SIZE){
	int idmax=-1;

	int bandera=0;
	for(int i =0;i<SIZE;i++){
		if(confederacion[i].isEmpty==LLENO){
			if(bandera==0||confederacion[i].id>idmax){
				idmax=confederacion[i].id;
				bandera=1;
			}
		}
	}

	return idmax;
}

int BuscarIdMin(eConfederacion confederacion[],int SIZE){
	int idmin=-1;

	int bandera=0;
	for(int i =0;i<SIZE;i++){
		if(confederacion[i].isEmpty==LLENO){
			if(bandera==0||confederacion[i].id<idmin){
				idmin=confederacion[i].id;
				bandera=1;
			}
		}
	}

	return idmin;
}
int BuscarIndiceVacioConf(eConfederacion confederacion[],int SIZE){
	int retorno =-1;

		if(SIZE >0 && confederacion !=NULL){
			for(int i=0;i<SIZE;i++){
				if(confederacion[i].isEmpty==VACIO){
					retorno =i;
					break;
				}
			}
		}
		return retorno;
}

int AltaConfederacion(int IdAutoincremental,eConfederacion confederacion[],int SIZE){
	int indice;
	int error;
	if(confederacion != NULL && SIZE>0){
		indice = BuscarIndiceVacioConf(confederacion,SIZE);
		if (indice != -1){

			confederacion[indice].id = IdAutoincremental;
			do{
				error = getNombre(confederacion[indice].nombre,50,"Ingrese nombre de la confederacion: ");
			}while(error == -1);
			fflush(stdin);

			do{
				error = getNombre(confederacion[indice].nombre,50,"Ingrese region de la confederacion: ");
			}while(error == -1);
			fflush(stdin);

			do{
				error = utn_getNumero(&confederacion[indice].anioCreacion, "Ingrese anio de creacion: ", "Error, Ingrese numero valido.",1, 2022, 1);
			}while(error == -1);

			confederacion[indice].isEmpty = LLENO;
		}
	}
	return indice;
}


int BajaConfederacion(eConfederacion confederacion[],int SIZE){
	int retorno=-1;
	int id;
	int error;
	int confirmacion;
	int indice;

	if(SIZE>0 && confederacion != NULL){
		do{
			error = utn_getNumero(&id, "Ingrese el id de la confederacion a dar de baja: ", "Error, Ingrese un id valido.",100, 200, 1);
		}while(error==-1);


		indice = BuscarIndiceConf(confederacion,SIZE,id);
		if(indice!=-1){
			do{
				error = utn_getNumero(&confirmacion, "Confirmar? 1.Si | 2.No ", "Error, Ingrese 1 (Si) o 2 (No).",1, 2, 1);
			}while(error==-1);

			if(confirmacion==1){
				confederacion[indice].isEmpty=VACIO;
				retorno=1;
			}
			else{
				retorno=0;
			}
		}
	}
	return retorno;
}

int ModificarNombreConfe(eConfederacion confederacion[],int indice,int SIZE){
	int retorno= -1;
	char NombreNuevo[50];
	int confirmacion;
	int error;
	if(confederacion !=NULL && SIZE>0){
		do{
			error =getNombre(NombreNuevo,50,"\nIngrese Nombre de la confederacion: ");
		}while(error ==-1);
		fflush(stdin);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar el nombre? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			strcpy(confederacion[indice].nombre,NombreNuevo);
			retorno=1;
		}
			else{
		retorno=0;
		}
	}
	return retorno;
}

int ModificarRegionConfe(eConfederacion confederacion[],int indice,int SIZE){
	int retorno= -1;
	char NombreNuevo[50];
	int confirmacion;
	int error;
	if(confederacion !=NULL && SIZE>0){
		do{
			error =getNombre(NombreNuevo,50,"\nIngrese region: ");
		}while(error ==-1);
		fflush(stdin);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar la region? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			strcpy(confederacion[indice].region,NombreNuevo);
			retorno=1;
		}
			else{
		retorno=0;
		}
	}
	return retorno;
}

int ModificarAnio(eConfederacion confederacion[],int indice,int SIZE){
	int retorno= -1;
	int anioNuevo;
	int confirmacion;
	int error;
	if(confederacion !=NULL && SIZE>0){
		do{
			error =utn_getNumero(&anioNuevo,"\nIngrese anio: ","\nError ingrese un numero valido.",1,2022,1);
		}while(error ==-1);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar el anio? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);
		if(confirmacion==1){
			confederacion[indice].anioCreacion=anioNuevo;
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

