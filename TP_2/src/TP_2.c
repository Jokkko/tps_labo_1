/*
 ============================================================================
 Name        : TP_2.c
 Author      : Fernandes Joaquin DIV K
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "eConfederacion.h"
#include "eJugador.h"
#include "output.h"
#define CANT_JUGADORES 3000
#define CANT_CONFEDERACIONES 6

//MASCARA SHORT %hd

int main(void){
	setbuf(stdout,NULL);
	eConfederacion confederaciones[CANT_CONFEDERACIONES];
	eJugador jugadores[CANT_JUGADORES];

	int opcionPrincipal;
	int idAutoincremental=0;
	int banderaEstado;

	HardcodeoConfederacion(confederaciones,CANT_CONFEDERACIONES);

	do{
		banderaEstado=DetectarJugadores(jugadores,CANT_JUGADORES);
		opcionPrincipal= MostrarMenu("1. ALTA DE JUGADOR:","2. BAJA DE JUGADOR:","3. MODIFICACIÓN DE JUGADOR:","4. INFORMES:","5. SALIR:"," "," ","Menu Principal");
		switch(opcionPrincipal){
		case 1:
				if(AltaJugador(jugadores,CANT_JUGADORES,idAutoincremental,confederaciones,CANT_CONFEDERACIONES)!= -1){
					idAutoincremental++;
					printf("\nDado de alta con exito.\n");
				}
				else{
					printf("\nOcurrio un error al dar de alta.\n");
				}
			break;
		case 2:
			if(banderaEstado==1){
				MensajeError(BajaJugador(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES));
			}else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}
			break;
		case 3:
			if(banderaEstado==1){
				MensajeError(ModificarJugador(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES));
			}
			else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}
			break;
		case 4:
			if(banderaEstado==1){
				Informes(jugadores, CANT_JUGADORES, confederaciones,CANT_CONFEDERACIONES);

			}
			else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}


			break;
		case 5:
			printf("\nSaliendo...");
			break;
		default:
			printf("\nError ingrese una opcion valida.\n\n");
			break;
		}
	}while(opcionPrincipal !=5);


	return EXIT_SUCCESS;
}
