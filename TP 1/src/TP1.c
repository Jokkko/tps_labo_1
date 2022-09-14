/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "FuncionesEntradaYSalida.h"
#include "Logica.h"
#define TAM 22

#define LIBRE 0
#define OCUPADO 1



int main(void) {
	setbuf(stdout,NULL);
	int opcion,opcionCosto,opcionCarga;
	int costoHospedaje=0,costoComida=0,costoTransporte=0,costoMantenimiento=0;
	int contArq=0,contDef=0,contMC=0,contDel=0;
	int numCamiseta[TAM], estado[0], posicion[TAM],confederacion[TAM];

	InicializarArray(estado,TAM);

	do{
		ImprimirMensaje("Menu principal\n");
		ImprimirMensaje("\n1. Ingreso de los costos de Mantenimiento.");
		MostrarNumero("\nCosto de hospedaje ->",costoHospedaje);
		MostrarNumero("\nCosto de comida ->",costoComida);
		MostrarNumero("\nCosto de transporte ->",costoTransporte);
		ImprimirMensaje("\n2. Carga de jugadores:");
		MostrarNumero("\nCantidad de Arqueros ->",contArq);
		MostrarNumero("\nCantidad de Defensores ->",contDef);
		MostrarNumero("\nCantidad de Mediocampistas ->",contMC);
		MostrarNumero("\nCantidad de Delanteros ->",contDel);
		ImprimirMensaje("\n3. Realizar todos los cálculos.");
		ImprimirMensaje("\n4. Informar todos los resultados.");
		ImprimirMensaje("\n5. Salir.");
		opcion = PedirNumero("\nIngrese Opcion: ");

		switch(opcion){
//aaaa
			case 1:
				do{
					ImprimirMensaje("\nElegir monto a cargar: ");
					ImprimirMensaje("\n1. Costo de Hospedaje.");
					ImprimirMensaje("\n2. Costo de Comida.");
					ImprimirMensaje("\n3. Costo de Transporte.");
					ImprimirMensaje("\n4. Salir.");
					opcionCosto = PedirNumero("\nIngrese Opcion: ");

					switch(opcionCosto){
						case 1:
							costoHospedaje = PedirEnteroPostivo("\nIngrese costo de Hospedaje: ","Error ingrese un costo mayor a 0: ");
							costoMantenimiento += costoHospedaje;
							break;
						case 2:
							costoComida = PedirEnteroPostivo("\nIngrese costo de Comida: ","Error ingrese un costo mayor a 0: ");
							costoMantenimiento += costoComida;
							break;
						case 3:
							costoTransporte = PedirEnteroPostivo("\nIngrese costo de Transporte: ","Error ingrese un costo mayor a 0: ");
							costoMantenimiento += costoTransporte;
							break;
						case 4:
							ImprimirMensaje("Saliendo...\n");
							break;
						default:
							ImprimirMensaje("Opcion incorrecta.\n");
							break;
					}
				}while(opcionCosto != 4);
				break;
			case 2:
				do{
					ImprimirMensaje("\nElegir posicion del jugador: ");
					ImprimirMensaje("\n1. Arquero.");
					ImprimirMensaje("\n2. Defensor.");
					ImprimirMensaje("\n3. Mediocampista.");
					ImprimirMensaje("\n4. Delantero.");
					ImprimirMensaje("\n5. Salir.");
					opcionCarga = PedirNumero("\nIngrese Opcion: ");

					switch (opcionCarga){
						case 1:
								do{
									if(contArq<2){
										for(int i=0;i<TAM;i++){
											if(estado[i]==LIBRE){
												contArq++;
												numCamiseta[i]=PedirNumeroPorRango("Ingrese numero de camiseta: ","Error el numero de camiseta debe estar entre 1 y 99, reingrese numero de camiseta:",1,99);
												posicion[i]=
												break;
											}
										}
									}
									else{
										ImprimirMensaje("Error ya se cargaron 2 arqueros.");
									}
								}while(PedirChar("Desea agregar otro arquero? S/N")== 'S');

							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							ImprimirMensaje("Saliendo...\n");
							break;
						default:
							ImprimirMensaje("Opcion incorrecta.\n");
							break;
					}
				}while(opcionCarga != 5);


				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				ImprimirMensaje("Saliendo...\n");
				break;
			default:
				ImprimirMensaje("Opcion incorrecta.\n");
				break;
		}

	}while(opcion != 5);



	return 1;
}
