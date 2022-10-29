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


int main(void){
	setbuf(stdout,NULL);
	eConfederacion confederaciones[CANT_CONFEDERACIONES];
	eJugador jugadores[CANT_JUGADORES];

	int opcionPrincipal,opcionModificar,opcionInformes;
	int idAutoincremental=1;
	int banderaEstado;
	int error,id,indice;
	int confirmacion;

	HardcodeoConfederacion(confederaciones,CANT_CONFEDERACIONES);
	InicializarEstado(jugadores,CANT_JUGADORES);

	do{
		banderaEstado=ContadorJugadores(jugadores,CANT_JUGADORES);
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
			if(banderaEstado>0){
				MensajeError(BajaJugador(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES));
			}else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}
			break;
		case 3:
			if(banderaEstado>0){
				OrdenarJugadorPorID(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
				MostrarJugador(jugadores, CANT_JUGADORES, confederaciones,CANT_CONFEDERACIONES);
				do{
					error = utn_getNumero(&id, "Ingrese el id del jugador a modificar: ", "Error, Ingrese un id valido.",1, 4000, 1);
				}while(error==-1);

				indice = BuscarIdJugador(jugadores,CANT_JUGADORES,id);
				if(indice !=-1){
					do{
						opcionModificar = MostrarMenu("1. Modificar Nombre.","2. Modificar Posicion.","3. Numero de camiseta.","4. Confederacion.","5. Salarios.","6. Anios de contrato.","7.Salir.","Menu Modificar");
						switch(opcionModificar){
						case 1:
							MensajeError(ModificarNombre(jugadores,indice,CANT_JUGADORES));
							break;
						case 2:
							MensajeError(ModificarPosicion(jugadores,indice,CANT_JUGADORES));
							break;
						case 3:
							MensajeError(ModificarNumeroCamiseta(jugadores,indice,CANT_JUGADORES));
							break;
						case 4:
							MensajeError(ModificarConfederacion(jugadores,indice,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES));
							break;
						case 5:
							MensajeError(ModificarSalario(jugadores,indice,CANT_JUGADORES));
							break;
						case 6:
							MensajeError(ModificarAniosContrato(jugadores,indice,CANT_JUGADORES));
							break;
						case 7:
							printf("\nSaliendo...\n");
							break;
						default:
							printf("\nError ingrese una opcion valida.\n\n");
							break;
						}
					}while(opcionModificar!=7);
				}else{
					printf("\nNo se encontro al jugador\n");
				}
			}
			else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}
			break;
		case 4:
			if(banderaEstado>0){
				do{
					opcionInformes = MostrarMenu("1. Orden alfabetico de Confederacion y de Jugadores.","2. Confederaciones y sus Jugadores.","3. Total y promedio de todos los salarios y jugadores sobre el promedio.","4. Confederacion con mayor cantidad de anios de contratos.","5. Porcentaje de jugadores por Confederacion.","6. Region con mas Jugadores y sus Jugadores.","7.Salir.","Menu Informes");
					switch(opcionInformes){
					case 1:
						OrdenarAlfabetico(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
						MostrarJugador(jugadores, CANT_JUGADORES, confederaciones,CANT_CONFEDERACIONES);
						break;
					case 2:
						MostrarConfederacionesYJugadores(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
						break;
					case 3:
						MostrarPromedioYSalarios(jugadores,CANT_JUGADORES);
						break;
					case 4:
						MostrarConfeMasAnios(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
						break;
					case 5:
						MostrarPorcentajeConfe(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
						break;
					case 6:
						MostrarRegionMax(jugadores,CANT_JUGADORES,confederaciones,CANT_CONFEDERACIONES);
						break;
					case 7:
						printf("\nSaliendo...\n");
						break;
					}
				}while(opcionInformes!=7);
			}
			else{
				printf("\nERROR debe haber cargado almenos 1 jugador para poder ingresar\n");
			}
			break;
		case 5:
			do{
				error = utn_getNumero(&confirmacion,"\nDesea Salir? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
			}while(error ==-1);
			if(confirmacion==1){
				printf("\nSaliendo...");
			}else{
				opcionPrincipal=0;
			}

			break;
		default:
			printf("\nError ingrese una opcion valida.\n\n");
			break;
		}
	}while(opcionPrincipal !=5);


	return EXIT_SUCCESS;
}
