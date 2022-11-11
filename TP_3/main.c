#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"


int main()
{
	setbuf(stdout,NULL);
    int option;
    int opcionListados;
    int opcionConvocar;
    int opcionOrdenar;
    int error;
    int confirmacion;
    int banderaCambios=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaConvocados = ll_newLinkedList();
    do{
    	printf("MENU PRINCIPAL\n"
    			"1.Carga de archivos\n"
    			"2.Alta de jugador\n"
    			"3.Modificacion de jugador\n"
    			"4.Baja de jugador\n"
    			"5.Listados\n"
    			"6.Convocar Jugadores\n"
    			"7.Ordenar y listar\n"
    			"8.Generar archivo binario\n"
    			"9.Cargar archivo binario\n"
    			"10.Guardar archivos CSV\n"
    			"11.Salir\n");
    	utn_getNumero(&option,"\nIngrese Opcion:\n","Ingrese opcion valida",1,11,3);
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
                break;
            case 2:
            	controller_agregarJugador(listaJugadores);
            	banderaCambios=1;
            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores)==0){
					controller_editarJugador(listaJugadores);
					banderaCambios=1;
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores cargados.\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores)==0){
					controller_removerJugador(listaJugadores,listaSelecciones);
					banderaCambios=1;
            	}else{
            	    printf("\nError, no se puede acceder si no hay jugadores cargados.\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaJugadores)==0 ||ll_isEmpty(listaSelecciones)==0 ){
                	do{
                    	printf("MENU LISTADOS\n"
                    			"1.TODOS LOS JUGADORES.\n"
                    			"2.TODAS LAS SELECCIONES.\n"
                    			"3.JUGADORES CONVOCADOS\n"
                    			"4.Salir\n");
                    	utn_getNumero(&opcionListados,"\nIngrese Opcion:\n","Ingrese opcion valida",1,4,3);
                    	switch(opcionListados){
                    	case 1:
                    		controller_listarJugadoresYSeleccion(listaJugadores,listaSelecciones);
                    		break;
                    	case 2:
                    		controller_listarSelecciones(listaSelecciones);
                    		break;
                    	case 3:
                    			controller_listarJugadoresConvocados(listaJugadores,listaSelecciones);
                    		break;
                    	case 4:
                    		printf("Saliendo...");
                    		break;
                    	}
                	}while(opcionListados!=4);
            	}else{
            		 printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaJugadores)==0 || ll_isEmpty(listaSelecciones)==0 ){
                	do{
                    	printf("MENU CONVOCACION\n"
                    			"1.CONVOCAR.\n"
                    			"2.QUITAR DE LA SELECCIÓN.\n"
                    			"3.Salir\n");
                    	utn_getNumero(&opcionConvocar,"\nIngrese Opcion:\n","Ingrese opcion valida",1,3,3);
                    	switch(opcionConvocar){
                    	case 1:
                    		controller_convocarJugadores(listaJugadores,listaSelecciones);
                    		banderaCambios=1;
                    		break;
                    	case 2:
                    		controller_desconvocarJugadores(listaJugadores,listaSelecciones);
                    		banderaCambios=1;
                    		break;
                    	case 3:
                    		printf("Saliendo...");
                    		break;
                    	}
                	}while(opcionConvocar!=3);
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}

            	break;
            case 7:
            	if(ll_isEmpty(listaJugadores)==0 || ll_isEmpty(listaSelecciones)==0 ){
                	do{
                    	printf("MENU ORDENAR\n"
                    			"1.JUGADORES POR NACIONALIDAD.\n"
                    			"2.SELECCIONES POR CONFEDERACIÓN.\n"
                    			"3.JUGADORES POR EDAD.\n"
                    			"4.JUGADORES POR NOMBRE.\n"
                    			"5.Salir.");
                    	utn_getNumero(&opcionOrdenar,"\nIngrese Opcion:\n","Ingrese opcion valida",1,5,3);
                    	switch(opcionOrdenar){
                    	case 1:
                    		ll_sort(listaJugadores, OrdenarPorNacionalidad, 1);
                    		controller_listarJugadores(listaJugadores);
                    		break;
                    	case 2:
                    		ll_sort(listaSelecciones, OrdenarPorConfederacion, 1);
                    		controller_listarSelecciones(listaSelecciones);
                    		break;
                    	case 3:
                    		ll_sort(listaJugadores, OrdenarPorEdad, 1);
                    		controller_listarJugadores(listaJugadores);
                    		break;
                    	case 4:
                    		ll_sort(listaJugadores, OrdenarPorNombre, 1);
                    		controller_listarJugadores(listaJugadores);
                    		break;
                    	case 5:
                    		printf("Saliendo...\n");
                    		break;
                    	}
                	}while(opcionOrdenar!=5);
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}
            	break;
            case 8:
            	if(ll_isEmpty(listaJugadores)==0 || ll_isEmpty(listaSelecciones)==0 ){
            		controller_filtrarJugadoresConvocados(listaJugadores,listaSelecciones,listaConvocados);
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}
            	break;
            case 9:
            	if(ll_isEmpty(listaJugadores)==0 || ll_isEmpty(listaSelecciones)==0 || ll_isEmpty(listaConvocados)==0  ){
					controller_cargarJugadoresDesdeBinario("JugadoresConvocados.bin",listaConvocados);
					//controller_listarJugadores(listaConvocados);
					controller_listarJugadoresYSeleccion(listaConvocados,listaSelecciones);
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas o si no accedio al item 8\n");
            	}

            	break;
            case 10:
            	if(banderaCambios==1){
					controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
					controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores);
					banderaCambios=0;
            	}else{
            		printf("\nNo hay cambios para hacer\n");
            	}
            	break;
            case 11:
            	if(banderaCambios==1){
            		printf("\nTiene cambios sin guardar.\n");
            	}
            	do{
            		error = utn_getNumero(&confirmacion,"\nDesea Salir? 1.Si 2.No : ","\nError ingrese una opcion valida.",1,2,1);
            	}while(error ==-1);
            	if(confirmacion==1){
            		printf("\nSaliendo...");
            	}else{
            		option=0;
            	}
            	break;
        }
    }while(option != 11);

    return 0;
}

