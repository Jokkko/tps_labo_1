/*
 * FuncionesEntradaYSalida.c
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s %d\n", mensajeError, reintentos);
		if (reintentos == 0) {
			retorno=-1;
			printf("Saliendo...");
		}

	}
	return retorno;
}

int utn_getPositivo(int *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt > 0) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s %d", mensajeError, reintentos);
		if (reintentos == 0) {
			printf("\nSaliendo...\n");
		}

	}
	return retorno;
}

int utn_getChar(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos > -1) {
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);
			fflush(stdin);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

int ContarConfederacion(int *pContadorAFC, int *pContadorCAF, int *pContadorCONCACAF, int *pContadorCONMEBOL, int *pContadorUEFA, int *pContadorOFC){
	int retorno= -1;
	int confederacion;

	if(utn_getNumero(&confederacion,"Ingrese confederacion (1.AFC | 2.CAF | 3.CONCACAF | 4. CONMEBOL | 5. UEFA | 6. OFC): ","Error ingrese un numero entre 1 y 6 Intentos restantes : ", 1, 6,3)==0){
		switch (confederacion) {
		case 1:
			*pContadorAFC = *pContadorAFC + 1;
			break;
		case 2:
			*pContadorCAF = *pContadorCAF + 1;
			break;
		case 3:
			*pContadorCONCACAF = *pContadorCONCACAF + 1;
			break;
		case 4:
			*pContadorCONMEBOL = *pContadorCONMEBOL + 1;
			break;
		case 5:
			*pContadorUEFA = *pContadorUEFA + 1;
			break;
		case 6:
			*pContadorOFC = *pContadorOFC + 1;
			break;
		}
		retorno = 1;
	}
	return retorno;
}



