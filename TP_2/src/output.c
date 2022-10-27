/*
 * output.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */
#include <stdio.h>
#include <string.h>
#include "input.h"
#include "output.h"
#define LLENO 1
#define VACIO 0

int MostrarOpcion(char *opcion){
	int retorno = -1;
	if(opcion != NULL){
		printf("%s\n",opcion);
		retorno =1;
	}
	return retorno;
}

int MostrarMenu(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *menu){
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
		fflush(stdin);
		do{
			utn_getNumero(&retorno,"\nIngrese Opcion:","",1,7,1);
		}while(retorno ==-1);
	}
	return retorno;
}

void MensajeError(int caso){
	switch(caso){
	case 1:
		printf("\nOperacion realizada con exito.\n");
		break;
	case 0:
		printf("\nOperacion cancelada.\n");
		break;
	default:
		printf("\nOcurrio un error al realizar la operacion.\n");
		break;
	}
}


int MostrarJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	if(SIZE>0 && SIZE2>0 && jugadores !=NULL && confederacion != NULL){
		retorno=1;



		printf(   "_________________________________________________________________________________________________________________________________________\n"
				   "|%-5s|%-15s|%-20s|%-20s|%-20s|%-20s|%-30s|\n"
				   "|=====|===============|====================|====================|====================|====================|==============================|\n",
				   "ID","NOMBRE","ANIOS DE CONTRATO","CONFEDERACION","NUMERO DE CAMISETA","POSICION","SALARIO");
			for(int i=0;i<SIZE;i++){
				for(int y=0;y<SIZE2;y++){
					if(jugadores[i].isEmpty==LLENO && jugadores[i].idConfederacion==confederacion[y].id){
						printf("|%-5d|%-15s|%-20d|%-20s|%-20d|%-20s|%-30.2f|\n",jugadores[i].id,jugadores[i].nombre,jugadores[i].aniosContrato,confederacion[y].nombre,jugadores[i].numeroCamiseta,
								jugadores[i].posicion,jugadores[i].salario);
					}
				}
			}
			printf("|_____|_______________|____________________|____________________|____________________|____________________|______________________________|\n");
	}

	return retorno;
}

int MostrarConfederacion(eConfederacion confederacion[],int SIZE){
	int retorno=-1;
	if(SIZE>0 && confederacion != NULL){
		retorno =1;
		printf(   " __________________________________________________________________________\n"
				   "|%-5s|%-15s|%-30s|%-20s|\n"
				   "|=====|===============|==============================|====================|\n",
				   " ID  ","NOMBRE","REGION","ANIO DE CREACION");
		for(int i=0;i<SIZE;i++){
			printf("|%-5d|%-15s|%-30s|%-20d|\n",confederacion[i].id,confederacion[i].nombre,confederacion[i].region,confederacion[i].anioCreacion);
		}
		printf("|_____|_______________|______________________________|____________________|\n");
	}

	return retorno;
}




int MostrarPromedioYSalarios(eJugador jugadores[],int SIZE){
	int retorno;
	float acumuladorSalarios=0;
	float promedioTotal;
	int cantJugadores;
	int cantJugadoresArribaPromedio;
	if(jugadores !=NULL && SIZE>0){
		retorno =1;
		TotalDeSalarios(jugadores,SIZE,&acumuladorSalarios);
		cantJugadores = ContadorJugadores(jugadores,SIZE);
		PromedioSalarios(acumuladorSalarios,cantJugadores,&promedioTotal);
		cantJugadoresArribaPromedio=JugadoresArribaPromedio(jugadores,SIZE);

		printf("\nLa suma total de todos los salarios es de: %.2f\n",acumuladorSalarios);
		printf("\nEl promedio de todos los salarios es de: %.2f\n",promedioTotal);
		printf("\nLa cantidad de jugadores con salario por encima del promedio es de: %d\n",cantJugadoresArribaPromedio);
	}
	return retorno;
}


int MostrarConfederacionesYJugadores(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		retorno =1;
		for(int i=0;i<SIZE2;i++){
			if(confederacion[i].isEmpty==LLENO){
				printf(   "_____________________________________________________________________\n"
						   "|%-15s|%-30s|%-20s|\n"
						   "|===============|==============================|====================|\n",
						   "NOMBRE","REGION","ANIO DE CREACION");
				printf("|%-15s|%-30s|%-20d|\n",confederacion[i].nombre,confederacion[i].region,confederacion[i].anioCreacion);
				printf("|_______________|______________________________|____________________|\n");
				for(int j=0;j<SIZE;j++){
					if(jugadores[j].isEmpty==LLENO && jugadores[j].idConfederacion==confederacion[i].id){
					printf(   "________________________________________________________________________________________________________________\n"
									   "|%-15s|%-20s|%-20s|%-20s|%-30s|\n"
									   "|===============|====================|====================|====================|==============================|\n",
									   "NOMBRE","ANIOS DE CONTRATO","NUMERO DE CAMISETA","POSICION","SALARIO");
					printf("|%-15s|%-20d|%-20d|%-20s|%-30.2f|\n",jugadores[j].nombre,jugadores[j].aniosContrato,jugadores[j].numeroCamiseta,jugadores[j].posicion,jugadores[j].salario);
					printf("|_______________|____________________|____________________|____________________|______________________________|\n");
					}
				}
			}
		}
	}
	return retorno;
}

int MostrarConfeMasAnios(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	int id;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		id=IDConfeMasAnios(jugadores,SIZE,confederacion,SIZE2);
		id=BuscarIndiceConf(confederacion,SIZE2,id);
		printf("\nLa confederacion con mayor cantidad de anios de contratos es: %s\n",confederacion[id].nombre);
	}
	return retorno;
}

int MostrarPorcentajeConfe(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	int totalJugadores;
	int contador;
	float porcentaje;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		totalJugadores = DetectarJugadores(jugadores,SIZE);
		for(int i=0;i<SIZE2;i++){
			if(confederacion[i].isEmpty==LLENO){
				ContarJugadoresPorConfe(jugadores,SIZE,confederacion,&contador,i);
				porcentaje= (contador*100)/totalJugadores;
				printf("\nEl porcentaje de jugadores de la confederacion %s es de: %.2f\n",confederacion[i].nombre,porcentaje);
			}
		}
	}
	return retorno;
}

int MostrarRegionMax(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	char regionmax[50];
	int indiceConfe;
	if(jugadores !=NULL && SIZE>0 && confederacion !=NULL && SIZE2>0){
		indiceConfe = ContarJugadoresPorRegion(jugadores,SIZE,confederacion,SIZE2,regionmax);
		printf("\nLa region con mas cantidad de jugadores es %s\n",regionmax);

		for(int j=0;j<SIZE;j++){
			if(jugadores[j].isEmpty==LLENO && jugadores[j].idConfederacion==confederacion[indiceConfe].id){
				printf("________________________________________________________________________________________________________________\n"
					   "|%-15s|%-20s|%-20s|%-20s|%-30s|\n"
					   "|===============|====================|====================|====================|==============================|\n",
					   "NOMBRE","ANIOS DE CONTRATO","NUMERO DE CAMISETA","POSICION","SALARIO");
				printf("|%-15s|%-20d|%-20d|%-20s|%-30.2f|\n",jugadores[j].nombre,jugadores[j].aniosContrato,jugadores[j].numeroCamiseta,jugadores[j].posicion,jugadores[j].salario);
				printf("|_______________|____________________|____________________|____________________|______________________________|\n");
			}
		}
	}
	return retorno;
}
