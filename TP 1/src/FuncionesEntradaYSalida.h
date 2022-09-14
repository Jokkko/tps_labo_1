/*
 * FuncionesEntradaYSalida.h
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */

#ifndef FUNCIONESENTRADAYSALIDA_H_
#define FUNCIONESENTRADAYSALIDA_H_

int PedirNumero(char mensaje[]);
int PedirEnteroPostivo(char mensaje[], char mensajeError[]);
int ImprimirMensaje(char mensaje[]);
int MostrarNumero(char mensaje[], int numero);
char PedirChar(char mensaje[]);
int PedirNumeroPorRango(char mensaje[],char mensajeError[],int minimo,int maximo);
int PedirString(char array[],int SIZE,char mensaje[]);

#endif /* FUNCIONESENTRADAYSALIDA_H_ */
