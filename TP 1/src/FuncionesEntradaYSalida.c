/*
 * FuncionesEntradaYSalida.c
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int PedirNumero(char mensaje[]){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	return numero;

}

int PedirEnteroPostivo(char mensaje[], char mensajeError[]){
	int numero;

	numero = PedirNumero(mensaje);

	while (numero < 1){
		numero = PedirNumero(mensajeError);
	}

	return numero;
}

int ImprimirMensaje(char mensaje[]){
	printf("%s ",mensaje);
	return 1;
}

int MostrarNumero(char mensaje[], int numero){

	printf("%s %d",mensaje,numero);
	return 1;

}

char PedirChar(char mensaje[]){
	char caracter;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&caracter);
	caracter = toupper(caracter);

	return caracter;
}

int PedirNumeroPorRango(char mensaje[],char mensajeError[],int minimo,int maximo){
	int numero;

	numero = PedirNumero(mensaje);

	while(numero < minimo || numero > maximo){
		numero = PedirNumero(mensajeError);
	}

	return numero;
}

int PedirString(char array[],int SIZE,char mensaje[])
{
	int retorno;
	char buffer[1024];
	int largoCadena;
	retorno = -1;//Error si size es menor a 0 devuelve -1

	if(SIZE > 0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		largoCadena = strlen(buffer);
		retorno = 0;

		if(SIZE > largoCadena)
		{
			strcpy(array,buffer);
			retorno = 1; //si sale bien devuelve 1
		}

	}

	return retorno;

}

