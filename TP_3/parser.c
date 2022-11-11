#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int retornoFscanf;
	char idAux[30];
	char nombreCompletoAux[50];
	char edadAux[30];
	char posicionAux[30];
	char nacionalidadAux[30];
	char idSeleccionAux[30];
	if(pFile != NULL && pArrayListJugador != NULL){

		fscanf(pFile,"%s\n",nombreCompletoAux);
		while(feof(pFile) == 0){
			retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux);
			if(retornoFscanf == 6){
				pJugador = jug_newParametros(idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux);
				ll_add(pArrayListJugador,pJugador);
			}
		}
		printf("\nJugadores cargados con exito\n");
	}else{
		printf("\nERROR no se encontro el archivo\n");
	}

    return 1;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{

	Jugador* pJugador;
	int leidos;

	if(pFile != NULL && pArrayListJugador != NULL){
		ll_clear(pArrayListJugador);
		while(feof(pFile) == 0){
			pJugador = jug_new();
			leidos = fread(pJugador,sizeof(Jugador),1,pFile);
			if(leidos ==1){
				ll_add(pArrayListJugador,pJugador);
			}
		}

			printf("\nJugadores cargados con exito\n");
		}else{
			printf("\nERROR no se encontro el archivo\n");
		}

	    return 1;

}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* pSeleccion;
	int retornoFscanf;
	char idAux[30];
	char paisAux[50];
	char confederacionAux[30];
	char convocadosAux[30];

	if(pFile != NULL && pArrayListSeleccion != NULL){
		fscanf(pFile,"%s\n",paisAux);
		while(feof(pFile) == 0){
			retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,paisAux,confederacionAux,convocadosAux);
			if(retornoFscanf == 4){
				pSeleccion = selec_newParametros(idAux,paisAux,confederacionAux,convocadosAux);
				ll_add(pArrayListSeleccion,pSeleccion);
			}
		}
		printf("Selecciones cargadas con exito\n");
	}else{
		printf("\nERROR no se encontro el archivo\n");
	}
    return 1;
}

