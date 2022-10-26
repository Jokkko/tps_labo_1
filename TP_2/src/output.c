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


int MostrarJugadorPorID(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;

	for(int i=0; i<SIZE-1; i++){
		for( int j=i+1; j<SIZE; j++ ){

			if( jugadores[i].id > jugadores[j].id ){
				SwapJugador(jugadores,i,j);
			}
		}
	}
	MostrarJugador(jugadores, SIZE, confederacion,SIZE2);
	return retorno;
}

int Informes(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno =-1;
	int opcionInformes;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		retorno =1;
		do{
			opcionInformes = MostrarMenu("1. Orden alfabetico de Confederacion y de Jugadores.","2. Confederaciones y sus Jugadores.","3. Total y promedio de todos los salarios y jugadores sobre el promedio.","4. Confederacion con mayor cantidad de anios de contratos.","5. Porcentaje de jugadores por Confederacion.","6. Region con mas Jugadores y sus Jugadores.","7.Salir.","Menu Informes");
			switch(opcionInformes){
			case 1:
					OrdenarAlfabetico(jugadores,SIZE,confederacion,SIZE2);
					MostrarJugador(jugadores, SIZE, confederacion,SIZE2);
				break;
			case 2:
					MostrarConfederacionesYJugadores(jugadores,SIZE,confederacion,SIZE2);
				break;
			case 3:
					MostrarPromedioYSalarios(jugadores,SIZE);
				break;
			case 4:

				break;
				case 5:

				break;
			case 6:

				break;
			case 7:
				printf("\nSaliendo...\n");
				break;
			}
		}while(opcionInformes!=7);

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


int OrdenarAlfabetico(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	int idConfI;
	int idConfJ;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		retorno=1;
			for(int i=0; i<SIZE-1; i++){
			for( int j=i+1; j<SIZE; j++ ){
				idConfI= BuscarIdConf(confederacion,SIZE2,jugadores[i].idConfederacion);
				idConfJ = BuscarIdConf(confederacion,SIZE2,jugadores[j].idConfederacion);
				if( strcmp(confederacion[idConfI].nombre,confederacion[idConfJ].nombre)>0 ){

					 SwapJugador(jugadores,i,j);
				}
				else{
					if(jugadores[i].idConfederacion == jugadores[j].idConfederacion ){
						if(strcmp(jugadores[i].nombre,jugadores[j].nombre)>0){
							SwapJugador(jugadores,i,j);
						}
					}
				}
			}
		}
	}
	return retorno;
}

