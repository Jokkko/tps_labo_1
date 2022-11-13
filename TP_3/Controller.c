#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "output.h"
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
	int retorno=-1;

	if(path !=NULL && pArrayListJugador != NULL){
		retorno =1;
		archivo = fopen(path,"r");
		if(archivo != NULL){
			parser_JugadorFromText(archivo,pArrayListJugador);
			fclose(archivo);
		}else{
			printf("\nNo se encontro la ruta al archivo.\n");
		}
	}

    return retorno;
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
	FILE* archivo;
	int retorno=-1;

	if(path !=NULL && pArrayListJugador != NULL){
		retorno =1;
		archivo = fopen(path,"rb");
		if(archivo != NULL){
			parser_JugadorFromBinary(archivo,pArrayListJugador);
			fclose(archivo);
		}else{
			printf("\nNo se encontro la ruta al archivo.\n");
		}
	}
	return retorno;
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
	int retorno=-1;
	archivo = fopen("ID.csv","r");
	if(archivo != NULL){
		fscanf(archivo,"%[^\n]",contador);
		fclose(archivo);

		if(pArrayListJugador!= NULL){
			retorno =1;
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
	}else{
		printf("\nOcurrio un error al abrir el archivo de IDS\n");
	}

	return retorno;
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
	int retorno =-1;
	if(pArrayListJugador!=NULL){
		retorno =1;
		largoll = ll_len(pArrayListJugador);
		printf(" _________________________________________________________________________________________________________\n"
			   "|%-5s|%-30s|%-30s|%-30s|%-5s|\n"
			   "|=====|==============================|==============================|==============================|=====|\n",
			     "ID","Nombre","Posicion","Nacionalidad","Edad");
		for(int i=0;i<largoll;i++){
			pJugador=(Jugador*)ll_get(pArrayListJugador,i);
			 jug_getId(pJugador,&auxId);
			 jug_getNombreCompleto(pJugador,auxNombre);
			 jug_getPosicion(pJugador,auxPosicion);
			 jug_getNacionalidad(pJugador,auxNacionalidad);
			 jug_getEdad(pJugador,&auxEdad);
			 printf("|%-5d|%-30s|%-30s|%-30s|%-5d|\n",auxId,auxNombre,auxPosicion,auxNacionalidad,auxEdad);
		}
		printf("|_____|______________________________|______________________________|______________________________|_____|\n");
	}

    return retorno;
}

int controller_listarJugadoresYSeleccion(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	Seleccion* pSeleccion;
	Jugador* pJugador;
	int largollJugador;
	int largollSeleccion;
	int auxId;
	char auxNombre[100];
	char auxPosicion[100];
	char auxNacionalidad[100];
	int auxEdad;
	int auxIdSeleccionJug;
	int auxIdSeleccionSel;
	char nombreSeleccion[100];
	int retorno =-1;
	if(pArrayListJugador !=NULL && pArrayListSeleccion!=NULL){
		retorno=1;
		largollJugador = ll_len(pArrayListJugador);
		largollSeleccion = ll_len(pArrayListSeleccion);

		printf(" _______________________________________________________________________________________________________________________________________\n"
			   "|%-5s|%-30s|%-30s|%-30s|%-5s|%-30s|\n"
			   "|=====|==============================|==============================|==============================|=====|==============================|\n",
			     "ID","Nombre","Posicion","Nacionalidad","Edad","Nombre de la Seleccion");
		for(int i=0;i<largollJugador;i++){
			pJugador=(Jugador*)ll_get(pArrayListJugador,i);
			 jug_getId(pJugador,&auxId);
			 jug_getNombreCompleto(pJugador,auxNombre);
			 jug_getPosicion(pJugador,auxPosicion);
			 jug_getNacionalidad(pJugador,auxNacionalidad);
			 jug_getEdad(pJugador,&auxEdad);
			 jug_getSIdSeleccion(pJugador,&auxIdSeleccionJug);
			 for(int j=0;j<largollSeleccion;j++){
				 pSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,j);
				 selec_getId(pSeleccion, &auxIdSeleccionSel);
				 if(auxIdSeleccionJug==0){
					 strcpy(nombreSeleccion,"No convocado");
					 break;
				 }else{
					 if(auxIdSeleccionSel==auxIdSeleccionJug){
						 selec_getPais(pSeleccion, nombreSeleccion);
						 break;
					 }
				 }
			 }

			 printf("|%-5d|%-30s|%-30s|%-30s|%-5d|%-30s|\n",auxId,auxNombre,auxPosicion,auxNacionalidad,auxEdad,nombreSeleccion);
		}
		printf("|_____|______________________________|______________________________|______________________________|_____|______________________________|\n");
	}

    return retorno;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	Seleccion* pSeleccion;
	Jugador* pJugador;
	int largollJugador;
	int largollSeleccion;
	int auxId;
	char auxNombre[100];
	char auxPosicion[100];
	char auxNacionalidad[100];
	int auxEdad;
	int auxIdSeleccionJug;
	int auxIdSeleccionSel;
	char nombreSeleccion[100];
	int retorno=-1;
	if(pArrayListJugador!= NULL &&pArrayListSeleccion !=NULL ){
		largollJugador = ll_len(pArrayListJugador);
		largollSeleccion = ll_len(pArrayListSeleccion);
		printf(" _______________________________________________________________________________________________________________________________________\n"
			   "|%-5s|%-30s|%-30s|%-30s|%-5s|%-30s|\n"
			   "|=====|==============================|==============================|==============================|=====|==============================|\n",
			     "ID","Nombre","Posicion","Nacionalidad","Edad","Nombre de la Seleccion");
		for(int i=0;i<largollJugador;i++){
			pJugador=(Jugador*)ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(pJugador,&auxIdSeleccionJug);
			if(auxIdSeleccionJug!=0){
				jug_getId(pJugador,&auxId);
				jug_getNombreCompleto(pJugador,auxNombre);
				jug_getPosicion(pJugador,auxPosicion);
				jug_getNacionalidad(pJugador,auxNacionalidad);
				jug_getEdad(pJugador,&auxEdad);
				jug_getSIdSeleccion(pJugador,&auxIdSeleccionJug);
				for(int j=0;j<largollSeleccion;j++){
					pSeleccion= (Seleccion*) ll_get(pArrayListSeleccion,j);
					selec_getId(pSeleccion, &auxIdSeleccionSel);
					if(auxIdSeleccionSel==auxIdSeleccionJug){
						selec_getPais(pSeleccion, nombreSeleccion);
						break;
					}
				}
				printf("|%-5d|%-30s|%-30s|%-30s|%-5d|%-30s|\n",auxId,auxNombre,auxPosicion,auxNacionalidad,auxEdad,nombreSeleccion);
			}
		}
		printf("|_____|______________________________|______________________________|______________________________|_____|______________________________|\n");
	}


	return retorno;
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
	int retorno=-1;
	if(pArrayListJugador!= NULL){
		retorno=1;
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
			opcionModificar = MostrarMenu5Opc("1.NOMBRE.\n","2.EDAD.\n","3.POSICION\n","4.NACIONALIDAD\n","5.Salir\n","MENU MODIFICAR\n");
			switch(opcionModificar){
			case 1:
				do{
					error=getNombre(nombreCompletoAux,100,"Ingrese el nombre del jugador: ");
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
    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	Jugador* pJugador;
	Seleccion* pSeleccion;
	int idModificar;
	int auxId;
	int largollJug;
	int largollSel;
	int error;
	int i;
	int j;
	int idSel;
	int idSelAux;
	int convocados;
	int retorno=-1;
	if(pArrayListJugador!= NULL && pArrayListSeleccion != NULL){
		retorno=1;
		do{
			if(error==1){
				printf("\nNo se encontro el ID vuelva a intentarlo.\n");
			}
			error=1;
			controller_listarJugadores(pArrayListJugador);
			utn_getNumero(&idModificar,"\nIngrese ID del jugador a dar de baja: ","Ingrese ID valida.\n",0,10000,3);
			largollJug = ll_len(pArrayListJugador);
			for(i=0;i<largollJug;i++){
				pJugador=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(pJugador,&auxId);
				if(idModificar==auxId){
					error=0;
					break;
				}
			}
		}while(error==1);

		jug_getSIdSeleccion(pJugador,&idSelAux);

		if(idSelAux!=0){

			largollSel = ll_len(pArrayListSeleccion);

			for(j=0; j<largollSel;j++){
				pSeleccion=(Seleccion*)ll_get(pArrayListSeleccion,j);
				selec_getId(pSeleccion,&idSel);

				if(idSelAux==idSel){
					selec_getConvocados(pSeleccion,&convocados);
					convocados--;
					selec_setConvocados(pSeleccion,convocados);
				}
			}
		}

		jug_delete(pJugador);
		ll_remove(pArrayListJugador,i);
		printf("\nDado de baja con exito.\n");
	}

    return retorno;

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
	FILE *archivo;
	int largoll;
	Jugador* pJugador;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int retorno=-1;

	if(path !=NULL && pArrayListJugador != NULL){
		retorno=1;
		archivo = fopen(path,"w");
		largoll = ll_len(pArrayListJugador);
		if(archivo!=NULL){
			fprintf(archivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for(int i=0;i<largoll;i++){
				pJugador = ll_get(pArrayListJugador,i);
				jug_getId(pJugador,&id);
				jug_getNombreCompleto(pJugador,nombreCompleto);
				jug_getPosicion(pJugador,posicion);
				jug_getNacionalidad(pJugador,nacionalidad);
				jug_getEdad(pJugador,&edad);
				jug_getSIdSeleccion(pJugador,&idSeleccion);

				fprintf(archivo,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

			}
			fclose(archivo);
		}
	}
    return retorno;
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
	FILE *archivo;
	int largoll;
	Jugador* pJugador;
	int retorno=-1;

	if(path !=NULL && pArrayListJugador != NULL){
		retorno =1;
		archivo = fopen(path,"wb");
		largoll = ll_len(pArrayListJugador);
		if(archivo!=NULL){
			for(int i=0;i<largoll;i++){
				pJugador = ll_get(pArrayListJugador,i);

				fwrite(pJugador,sizeof(Jugador),1,archivo);
			}

			fclose(archivo);
		}
	}

    return retorno;
}

int controller_filtrarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados ){


	Jugador* pJugador;
	Seleccion* pSeleccion;
	int largollJug;
	int largollSel;
	int error;
	char confeAux[30];
	char confe[30];
	int idSelAux;
	int idSel;
	int retorno =-1;


	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		retorno= 1;
		largollJug = ll_len(pArrayListJugador);
		largollSel = ll_len(pArrayListSeleccion);
		ll_clear(pArrayListConvocados);
		do{
			error = getConfederacion(confeAux,30,"Ingrese la confederacion a filtrar AFC, CAF, CONCACAF, CONMEBOL, UEFA: ");
			fflush(stdin);
		}while(error==-1);

		for(int i=0;i<largollJug;i++){
			pJugador = ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(pJugador,&idSelAux);
			if(idSelAux!=0){
				for(int j=0;j<largollSel;j++){
					pSeleccion = ll_get(pArrayListSeleccion,j);
					selec_getId(pSeleccion,&idSel);
					selec_getConfederacion(pSeleccion,confe);

					if(strcmpi(confe,confeAux)==0 && idSelAux==idSel){
						ll_add(pArrayListConvocados,pJugador);
					}
				}
			}
		}

		retorno = controller_guardarJugadoresModoBinario("JugadoresConvocados.bin", pArrayListConvocados);
		if(retorno==1){
			printf("\nArchivo generado con exito\n");
		}else{
			printf("\nOcurrio un error\n");
		}
	}



	return retorno;
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
	int retorno=-1;
	FILE* archivo;
	if(path !=NULL && pArrayListSeleccion != NULL){

		archivo = fopen(path,"r");
		if(archivo!=NULL){
			retorno=1;
			parser_SeleccionFromText(archivo,pArrayListSeleccion);
			fclose(archivo);
		}else{
		printf("\nNo se encontro la ruta al archivo.\n");
		}
	}
    return retorno;
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
	int retorno=-1;
	if(pArrayListSeleccion!=NULL){
		retorno =1;
		largoll = ll_len(pArrayListSeleccion);;

		printf(" ________________________________________________________________________________\n"
			   "|%-5s|%-30s|%-30s|%-10s|\n"
			   "|=====|==============================|==============================|==========|\n",
			     "ID","Nombre","Confederacion","Convocados");
		for(int i=0;i<largoll;i++){
			pSeleccion=(Seleccion*)ll_get(pArrayListSeleccion,i);
			selec_getId(pSeleccion,&id);
			selec_getPais(pSeleccion,pais);
			selec_getConfederacion(pSeleccion,confederacion);
			selec_getConvocados(pSeleccion,&convocados);
			printf("|%-5d|%-30s|%-30s|%-10d|\n",id,pais,confederacion,convocados);
			}
		printf("|_____|______________________________|______________________________|__________|\n");
	}


    return retorno;
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
	FILE *archivo;
	int largoll;
	Seleccion* pSeleccion;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	int retorno=-1;

	if(path !=NULL && pArrayListSeleccion != NULL){
		archivo = fopen(path,"w");
		largoll = ll_len(pArrayListSeleccion);
		fprintf(archivo,"id,pais,confederacion,convocados\n");
		if(archivo!=NULL){
			retorno =1;
			for(int i=0;i<largoll;i++){
				pSeleccion = ll_get(pArrayListSeleccion,i);
				selec_getId(pSeleccion,&id);
				selec_getPais(pSeleccion,pais);
				selec_getConfederacion(pSeleccion,confederacion);
				selec_getConvocados(pSeleccion,&convocados);

				fprintf(archivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
			}
			fclose(archivo);
		}else{
			printf("\nNo se encontro la ruta al archivo\n");
		}
	}
    return retorno;

}

int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno =-1;
	int error;
	int idJugador;
	int idSeleccion;
	int largoll;
	int auxId;
	int idSeleccionJug;
	int largollSel;
	int cantConvocados;
	Jugador* pJugador;
	Seleccion* pSeleccion;

	if(pArrayListJugador!=NULL && pArrayListSeleccion != NULL ){
		retorno =1;
		do{
			if(error==1){
				printf("\nNo se encontro el ID vuelva a intentarlo.\n");
			}
			error=1;
			controller_listarJugadoresYSeleccion(pArrayListJugador,pArrayListSeleccion);
			utn_getNumero(&idJugador,"\nIngrese ID del jugador a convocar: ","Ingrese ID valida.\n",0,10000,3);
			largoll = ll_len(pArrayListJugador);
			for(int i=0;i<largoll;i++){
				pJugador=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getId(pJugador,&auxId);
				if(idJugador==auxId){
					error=0;
					break;
				}
			}
		}while(error==1);
		jug_getSIdSeleccion(pJugador,&idSeleccionJug);
		if(idSeleccionJug!=0){
			printf("Jugador ya convocado.\n");
		}else{
			do{
				if(error==1){
					printf("\nNo se encontro el ID vuelva a intentarlo.\n");
				}
				error=1;
				controller_listarSelecciones(pArrayListSeleccion);
				utn_getNumero(&idSeleccion,"\nIngrese ID de la seleccion: ","Ingrese ID valida.\n",0,10000,3);
				largollSel = ll_len(pArrayListSeleccion);
				for(int j=0;j<largollSel;j++){
					pSeleccion=(Seleccion*)ll_get(pArrayListSeleccion,j);
					selec_getId(pSeleccion,&auxId);
					if(idSeleccion==auxId){
						error=0;
						break;
					}
				}
			}while(error==1);
			selec_getConvocados(pSeleccion,&cantConvocados);
			if(cantConvocados >= 22){
				printf("La seleccion ya convoco a 22 jugadores.\n");
			}else{
				cantConvocados ++;
				jug_setIdSeleccion(pJugador,idSeleccion);
				selec_setConvocados(pSeleccion,cantConvocados);
				printf("Convocado con exito.\n");
			}
		}
	}
	return retorno;
}

int controller_desconvocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno =-1;
	int error;
	int idJugador;
	int largoll;
	int auxId;
	int largollSel;
	int cantConvocados;
	int auxIdSeleccionJug;
	Jugador* pJugador;
	Seleccion* pSeleccion;

	if(pArrayListJugador!=NULL && pArrayListSeleccion != NULL ){
		retorno=1;
		do{
			if(error==1){
				printf("\nNo se encontro el ID vuelva a intentarlo.\n");
			}
			error=1;
			controller_listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
			utn_getNumero(&idJugador,"\nIngrese ID del jugador a desconvocar: ","Ingrese ID valida.\n",0,10000,3);
			largoll = ll_len(pArrayListJugador);
			for(int i=0;i<largoll;i++){
				pJugador=(Jugador*)ll_get(pArrayListJugador,i);
				jug_getSIdSeleccion(pJugador,&auxIdSeleccionJug);
				if(auxIdSeleccionJug!=0){
					jug_getId(pJugador,&auxId);
					if(idJugador==auxId){
						error=0;
						break;
					}
				}
			}
		}while(error==1);

		largollSel=ll_len(pArrayListSeleccion);

		for(int i=0;i<largollSel;i++){
			pSeleccion=(Seleccion*)ll_get(pArrayListSeleccion,i);
			selec_getId(pSeleccion,&auxId);
			if(auxIdSeleccionJug==auxId){
				selec_getConvocados(pSeleccion,&cantConvocados);
				cantConvocados--;
				selec_setConvocados(pSeleccion,cantConvocados);
			}
		}

		jug_setIdSeleccion(pJugador,0);
		printf("\nJugador desconvocado con exito\n");

	}
	return retorno;
}
