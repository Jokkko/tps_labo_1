#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "input.h"
#include "parser.h"
/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* archivo;

	if(path !=NULL && pArrayListJugador != NULL){
		archivo = fopen(path,"r");
		if(archivo != NULL){
			parser_JugadorFromText(archivo,pArrayListJugador);
			fclose(archivo);
		}else{
			printf("\nNo se encontro la ruta al archivo.\n");
		}
	}

    return 1;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	FILE* archivo;
	Jugador* pJugador=NULL;
	char posicionAux[30];
	char edadAux[10];
	char nombreCompletoAux[100];
	char nacionalidadAux[70];
	char contador[10];
	int contadorAux;
	int error;

	archivo = fopen("ID.csv","r");
	if(archivo != NULL){
		fscanf(archivo,"%[^\n]",contador);
		fclose(archivo);

		if(pArrayListJugador!= NULL){
			do{
				error=getPosicion(posicionAux,30,"Ingrese posicion del jugador (Portero, Defensa central, Lateral izquierdo, Lateral derecho, Pivote, Mediocentro, Mediocentro ofensivo, Extremo izquierdo, Mediapunta, Delantero centro, Extremo derecho, Interior derecho o Interior izquierdo): \n");
			}while(error==-1);
			do{
				getString(edadAux,10,"Ingrese una edad mayor o igual a 18 anios y menor a 100: ");
				if(esNumerica(edadAux)){
					error=atoi(edadAux);
				}
			}while(error < 18 || error > 99);
			do{
				error=getNombre(nombreCompletoAux,100,"Ingrese el nombre del jugador: ");
			}while(error==-1);
			do{
				error=getNacionalidad(nacionalidadAux,70,"Ingrese nacionalidad del jugador (Argentino, Brasilero, Uruguayo, Portugues, Ingles, Aleman, Mexicano, Estado Unidense, Camerunes, Senegales, Australiano o Qatari): \n");
			}while(error==-1);
				fflush(stdin);
			pJugador = jug_newParametros(contador,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,"0");
			if(pJugador!=NULL){
				ll_add(pArrayListJugador,pJugador);
				printf("\nDado de alta con exito.\n");
			}else{
				printf("\nERROR.\n");
			}
		}
		archivo = fopen("ID.csv","w");
		contadorAux=atoi(contador);
		contadorAux++;
		fseek (archivo , 0L , SEEK_SET );
		fprintf(archivo,"%d\n",contadorAux);
		fclose(archivo);
	}

    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int largoll;
	int auxId;
	char auxNombre[100];
	char auxPosicion[100];
	char auxNacionalidad[100];
	int auxEdad;
	int auxIdSeleccion;
	largoll = ll_len(pArrayListJugador);

	for(int i=0;i<largoll;i++){
		pJugador=(Jugador*)ll_get(pArrayListJugador,i);
		 jug_getId(pJugador,&auxId);
		 jug_getNombreCompleto(pJugador,auxNombre);
		 jug_getPosicion(pJugador,auxPosicion);
		 jug_getNacionalidad(pJugador,auxNacionalidad);
		 jug_getEdad(pJugador,&auxEdad);
		 jug_getSIdSeleccion(pJugador,&auxIdSeleccion);

		 printf("%d,%s,%s,%s,%d,%d\n",auxId,auxNombre,auxPosicion,auxNacionalidad,auxEdad,auxIdSeleccion);
	}

    return 1;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idModificar;
	int auxId;
	int largoll;
	int error;
	int opcionModificar;
	char posicionAux[30];
	int edadAux;
	char nombreCompletoAux[100];
	char nacionalidadAux[70];
	if(pArrayListJugador!= NULL){
		do{
			if(error==1){
				printf("\nNo se encontro el ID vuelva a intentarlo.\n");
			}
			error=1;
			controller_listarJugadores(pArrayListJugador);
			utn_getNumero(&idModificar,"\nIngrese ID del jugador a modificar: ","Ingrese ID valida.\n",0,10000,3);
			largoll = ll_len(pArrayListJugador);
			for(int i=0;i<largoll;i++){
				pJugador=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(pJugador,&auxId);
				if(idModificar==auxId){
					error=0;
					break;
				}
			}
		}while(error==1);
		do{
			printf("MENU MODIFICAR\n"
					"1.NOMBRE.\n"
					"2.EDAD.\n"
					"3.POSICION\n"
					"4.NACIONALIDAD\n"
					"5.Salir\n");
			fflush(stdin);
			utn_getNumero(&opcionModificar,"\nIngrese Opcion:\n","Ingrese opcion valida",1,5,3);
			switch(opcionModificar){
			case 1:
				do{
					error=getNombre(nombreCompletoAux,100,"Ingrese el nuevo nombre del jugador: ");
				}while(error==-1);
				jug_setNombreCompleto(pJugador,nombreCompletoAux);
				break;
			case 2:
				do{
					error=utn_getNumero(&edadAux,"Ingrese una edad mayor o igual a 18 anios y menor a 100: ","Ingrese edad valida",18,99,1);
				}while(error==-1);
				jug_setEdad(pJugador,edadAux);
				break;
			case 3:
				do{
					error=getPosicion(posicionAux,30,"Ingrese posicion del jugador (Portero, Defensa central, Lateral izquierdo, Lateral derecho, Pivote, Mediocentro, Mediocentro ofensivo, Extremo izquierdo, Mediapunta, Delantero centro, Extremo derecho, Interior derecho o Interior izquierdo): \n");
				}while(error==-1);
				jug_setPosicion(pJugador,posicionAux);
				break;
			case 4:
				do{
					error=getNacionalidad(nacionalidadAux,70,"Ingrese nacionalidad del jugador (Argentino, Brasilero, Uruguayo, Portugues, Ingles, Aleman, Mexicano, Estado Unidense, Camerunes, Senegales, Australiano o Qatari): \n");
				}while(error==-1);
				jug_setNacionalidad(pJugador,nacionalidadAux);
				break;
		case 5:
				printf("Saliendo...\n");
				break;
			}
		}while(opcionModificar!=5);
	}
    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugador;
	int idModificar;
	int auxId;
	int largoll;
	int error;
	int i;
	if(pArrayListJugador!= NULL){
		do{
			if(error==1){
				printf("\nNo se encontro el ID vuelva a intentarlo.\n");
			}
			error=1;
			controller_listarJugadores(pArrayListJugador);
			utn_getNumero(&idModificar,"\nIngrese ID del jugador a dar de baja: ","Ingrese ID valida.\n",0,10000,3);
			largoll = ll_len(pArrayListJugador);
			for(i=0;i<largoll;i++){
				pJugador=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(pJugador,&auxId);
				if(idModificar==auxId){
					error=0;
					break;
				}
			}
		}while(error==1);

		jug_delete(pJugador);
		ll_remove(pArrayListJugador,i);
	}

    return 1;

}



/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{

	FILE* archivo;
	if(path !=NULL && pArrayListSeleccion != NULL){
		archivo = fopen(path,"r");
		if(archivo!=NULL){
			parser_SeleccionFromText(archivo,pArrayListSeleccion);
			fclose(archivo);
		}
		else{
		printf("\nNo se encontro la ruta al archivo.\n");
		}
	}
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{

    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	Seleccion* pSeleccion;
	int largoll;
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;
	largoll = ll_len(pArrayListSeleccion);
	printf("largoll:%d\n",largoll);

	for(int i=0;i<largoll;i++){
		pSeleccion=(Seleccion*)ll_get(pArrayListSeleccion,i);
		selec_getId(pSeleccion,&id);
		selec_getPais(pSeleccion,pais);
		selec_getConfederacion(pSeleccion,confederacion);
		selec_getConvocados(pSeleccion,&convocados);

		printf("%d,%s,%s,%d\n",id,pais,confederacion,convocados);

		}

    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


