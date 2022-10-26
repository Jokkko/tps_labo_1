/*
 * eJugador.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */
#include <stdio.h>
#include <string.h>
#include "eJugador.h"
#include "input.h"
#include "output.h"


#define VACIO 0
#define LLENO 1

int InicializarEstado(eJugador jugadores[],int SIZE){
	int retorno =-1;

	if(SIZE >0 && jugadores !=NULL){
		for(int i=0;i<SIZE;i++){
			jugadores[i].isEmpty =VACIO;
		}
	}

	return retorno;
}

int BuscarIndiceVacio(eJugador jugadores[],int SIZE){
	int retorno =-1;

		if(SIZE >0 && jugadores !=NULL){
			for(int i=0;i<SIZE;i++){
				if(jugadores[i].isEmpty==VACIO){
					retorno =i;
					break;
				}
			}
		}
		return retorno;
}

int BuscarIdJugador(eJugador jugadores[],int SIZE,int id){
	int retorno =-1;
	int i;
		if(SIZE >0 && jugadores !=NULL){
			for(i=0;i<SIZE;i++){
				if(jugadores[i].isEmpty==LLENO && jugadores[i].id ==id ){
					retorno =i;
					break;
				}
			}
		}
		return retorno;
}


int AltaJugador(eJugador jugadores[],int SIZE, int IdAutoincremental,eConfederacion confederacion[],int SIZE2){
	int indice;
	int error;
	if(jugadores !=NULL && confederacion != NULL && SIZE>0 && SIZE2>0){
		indice = BuscarIndiceVacio(jugadores,SIZE);
		if (indice != -1){
			jugadores[indice].id = IdAutoincremental;

			do{
				error = getNombre(jugadores[indice].nombre,50,"Ingrese nombre del Jugador: ");
			}while(error == -1);
			fflush(stdin);

			do{
				error = getPosicion(jugadores[indice].posicion,50,"Ingrese posicion del Jugador (Portero,Defensor,Delantero,Mediocampista): ");
			}while(error == -1);
			fflush(stdin);

			do{
				error = utn_getShort(&jugadores[indice].numeroCamiseta, "Ingrese numero de camiseta: ", "Error, Ingrese numero valido.",1, 99, 1);
			}while(error == -1);

			do{
				error = utn_getShort(&jugadores[indice].aniosContrato, "Ingrese anios de contraro: ", "Error, Ingrese numero valido.",1, 99, 1);
			}while(error == -1);

			do{
				MostrarConfederacion(confederacion,SIZE2);
				error = utn_getNumero(&jugadores[indice].idConfederacion, "Ingrese ID de la confederacion: ", "Error, Ingrese una id valida.",100, 105, 1);
			}while(error == -1);

			do{
				error = utn_getFloat(&jugadores[indice].salario, "Ingrese salario: ", "Error, Ingrese salario valido.",0.1, 166000000, 1);
			}while(error == -1);

			jugadores[indice].isEmpty = LLENO;
		}
	}
	return indice;
}



int SwapJugador(eJugador jugadores[], int i,int j){
	int retorno=-1;
	eJugador aux;
	if(jugadores !=NULL){
		aux = jugadores[i];
		jugadores[i] = jugadores[j];
		jugadores[j] = aux;
		retorno =1;
	}
	return retorno;
}




int BajaJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	int id;
	int error;
	int confirmacion;
	int indice;

	if(SIZE>0 && SIZE2>0 && jugadores != NULL && confederacion != NULL){
		MostrarJugadorPorID(jugadores,SIZE,confederacion,SIZE2);

		do{
			error = utn_getNumero(&id, "Ingrese el id del jugador a dar de baja: ", "Error, Ingrese un id valido.",0, 4000, 1);
		}while(error==-1);


		indice = BuscarIdJugador(jugadores,SIZE,id);
		if(indice!=-1){
			do{
				error = utn_getNumero(&confirmacion, "Confirmar? 1.Si | 2.No ", "Error, Ingrese 1 (Si) o 2 (No).",1, 2, 1);
			}while(error==-1);

			if(confirmacion==1){
				jugadores[indice].isEmpty=VACIO;
				retorno=1;
			}
			else{
				retorno=0;
			}
		}
	}
	return retorno;
}

int ModificarJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno=-1;
	int opcionModificar;
	int error;
	int id;
	int indice;

	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){

		MostrarJugadorPorID(jugadores,SIZE,confederacion,SIZE2);

		do{
			error = utn_getNumero(&id, "Ingrese el id del jugador a dar a modificar: ", "Error, Ingrese un id valido.",0, 4000, 1);
		}while(error==-1);

		indice = BuscarIdJugador(jugadores,SIZE,id);
		if(indice !=-1){
			do{
				opcionModificar = MostrarMenu("1. Modificar Nombre.","2. Modificar Posicion.","3. Numero de camiseta.","4. Confederacion.","5. Salarios.","6. Anios de contrato.","7.Salir.","Menu Modificar");
				switch(opcionModificar){
				case 1:
					MensajeError(ModificarNombre(jugadores,indice,SIZE));
					break;
				case 2:
					MensajeError(ModificarPosicion(jugadores,indice,SIZE));
					break;
				case 3:
					MensajeError(ModificarNumeroCamiseta(jugadores,indice,SIZE));
					break;
				case 4:
					MensajeError(ModificarConfederacion(jugadores,indice,SIZE,confederacion,SIZE2));
					break;
				case 5:
					MensajeError(ModificarSalario(jugadores,indice,SIZE));
					break;
				case 6:
					MensajeError(ModificarAniosContrato(jugadores,indice,SIZE));
					break;
				case 7:
					printf("\nSaliendo...\n");
					break;
				default:
					printf("\nError ingrese una opcion valida.\n\n");
					break;
				}
			}while(opcionModificar!=7);
			retorno =1;
		}
	}
	return retorno;
}

int ModificarConfederacion(eJugador jugadores[],int indice,int SIZE,eConfederacion confederacion[],int SIZE2){
	int retorno= -1;
	int error;
	int ConfederacionNueva;
	int confirmacion;
	if(jugadores !=NULL && SIZE>0 && confederacion != NULL && SIZE2>0){
		MostrarConfederacion(confederacion,SIZE2);
		do{
			error = utn_getNumero(&ConfederacionNueva,"\nIngrese ID de la confederacion: ","\nError ingrese un ID valido",100,105,1);
		}while(error ==-1);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar la ID? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			jugadores[indice].idConfederacion=ConfederacionNueva;
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

int ModificarNombre(eJugador jugadores[],int indice,int SIZE){
	int retorno= -1;
	char NombreNuevo[50];
	int confirmacion;
	int error;
	if(jugadores !=NULL && SIZE>0){
			do{
				error =getNombre(NombreNuevo,50,"\nIngrese Nombre del jugador: ");
			}while(error ==-1);
			fflush(stdin);
			do{
				error = utn_getNumero(&confirmacion,"\nDesea confirmar el nombre? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
			}while(error ==-1);

				if(confirmacion==1){
					strcpy(jugadores[indice].nombre,NombreNuevo);
					retorno=1;
				}
				else{
				retorno=0;
				}
	}

	return retorno;
}

int ModificarPosicion(eJugador jugadores[],int indice,int SIZE){
	int retorno= -1;
	char PosicionNueva[50];
	int confirmacion;
	int error;
	if(jugadores !=NULL && SIZE>0){
		do{
			error =getNombre(PosicionNueva,50,"\nIngrese Posicion del jugador: ");
		}while(error ==-1);
		fflush(stdin);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar la posicion? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			strcpy(jugadores[indice].posicion,PosicionNueva);
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

int ModificarNumeroCamiseta(eJugador jugadores[],int indice,int SIZE){
	int retorno= -1;
	short CamisetaNueva;
	int confirmacion;
	int error;
	if(jugadores !=NULL && SIZE>0){
		do{
			error =utn_getShort(&CamisetaNueva,"\nIngrese numero de camiseta: ","\nError ingrese un numero valido.",1,99,1);
		}while(error ==-1);
		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar la posicion? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);
		if(confirmacion==1){
			jugadores[indice].numeroCamiseta=CamisetaNueva;
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}



int ModificarSalario(eJugador jugadores[],int indice,int SIZE){
	int retorno= -1;
	float SalarioNuevo;
	int confirmacion;
	int error;
	if(jugadores !=NULL && SIZE>0){
		do{
			error =utn_getFloat(&SalarioNuevo,"\nIngrese salario: ","\nError ingrese un salario valido.",0.1,166000000,1);
		}while(error ==-1);

		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar el salario? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			jugadores[indice].salario=SalarioNuevo;
			retorno=1;
		}
		else{
			retorno=0;
		}
	}

	return retorno;
}

int ModificarAniosContrato(eJugador jugadores[],int indice,int SIZE){
	int retorno= -1;
	short AnioNuevo;
	int confirmacion;
	int error;
	if(jugadores !=NULL && SIZE>0){
		do{
			error =utn_getShort(&AnioNuevo,"\nIngrese anios de contrato: ","\nError ingrese una cantidad anios valida.",1,99,1);
		}while(error ==-1);

		do{
			error = utn_getNumero(&confirmacion,"\nDesea confirmar la cantidad de anios? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
		}while(error ==-1);

		if(confirmacion==1){
			jugadores[indice].aniosContrato=AnioNuevo;
			retorno=1;
		}
		else{
			retorno=0;
		}
	}

	return retorno;
}



int DetectarJugadores(eJugador jugadores[],int SIZE){
	int retorno =0;
	if(jugadores !=NULL && SIZE>0){
		for(int i=0;i<SIZE;i++){
			retorno=0;
			if(jugadores[i].isEmpty==LLENO){
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}


float TotalDeSalarios(eJugador jugadores[],int SIZE,float *pAcumulador){
	int retorno=-1;

	if(jugadores !=NULL && SIZE>0 && pAcumulador !=NULL){
		retorno =1;
		for(int i=0;i<SIZE;i++){
			if(jugadores[i].isEmpty==LLENO){
				*pAcumulador+=jugadores[i].salario;
			}
		}
	}
	return retorno;
}

int ContadorJugadores(eJugador jugadores[],int SIZE){
	int contador=0;

	if(jugadores !=NULL && SIZE>0 ){
		for(int i=0;i<SIZE;i++){
			if(jugadores[i].isEmpty==LLENO){
				contador++;
			}
		}
	}
	return contador;
}


int PromedioSalarios(float salarios, int cantJugadores,float *pResultado){
	int retorno;

	if(salarios>0 && cantJugadores>0){
		retorno=1;
		*pResultado = salarios/cantJugadores;
	}
	return retorno;
}

int JugadoresArribaPromedio(eJugador jugadores[],int SIZE){
	int retorno=0;
	float promedioTotal;
	float totalSalarios;
	int cantJugadores;
	TotalDeSalarios(jugadores,SIZE,&totalSalarios);
	cantJugadores = ContadorJugadores(jugadores,SIZE);
	PromedioSalarios(totalSalarios,cantJugadores,&promedioTotal);
	for(int i=0;i<SIZE;i++){
		if(jugadores[i].isEmpty==LLENO && jugadores[i].salario>promedioTotal){
			retorno++;
		}
	}
	return retorno;
}


