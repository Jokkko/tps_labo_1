/*
 * eJugador.c
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#include "eJugador.h"

#define VACIO 0
#define LLENO 1

int InicializarEstado(eJugador *jugadores,int SIZE){
	int retorno =-1;

	if(SIZE >0){
		for(int i=0;i<SIZE;i++){
			jugadores[i].isEmpty =VACIO;
		}
	}

	return retorno;
}

int BuscarIndiceVacio(eJugador *jugadores,int SIZE){
	int retorno =-1;

		if(SIZE >0){
			for(int i=0;i<SIZE;i++){
				if(jugadores[i].isEmpty==VACIO){
					retorno =i;
					break;
				}
			}
		}
		return retorno;
}
