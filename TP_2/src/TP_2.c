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

int main(void) {
	setbuf(stdout,NULL);
	eConfederacion confederaciones[6];
	eJugador jugadores[CANT_JUGADORES];

	int opcionPrincipal;
	int legajoAutoincremental;

	do{
		opcionPrincipal= MostrarMenu("1. ALTA DE JUGADOR:","2. BAJA DE JUGADOR:","3. MODIFICACIÓN DE JUGADOR:","4. INFORMES:","5. SALIR:"," ","Menu Principal");
		 switch(opcionPrincipal){
		 case 1:
			 break;
		 case 2:
			 break;
		 case 3:
			 break;
		 case 4:
			 break;
		 case 5:
			 printf("\nSaliendo...");
			 break;
		 default:
			 printf("\nError ingrese una opcion valida.\n");
			 break;


		 }
	}while(opcionPrincipal !=5);


	return EXIT_SUCCESS;
}
