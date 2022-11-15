#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "output.h"

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
    int banderaCase8=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaConvocados = ll_newLinkedList();
    do{
    	option = MostrarMenu11Opc("\n1. CARGA DE ARCHIVOS:","\n2. ALTA DE JUGADOR:","\n3. MODIFICACIÓN DE JUGADOR:","\n4. BAJA DE JUGADOR:","\n5. LISTADOS:","\n6. CONVOCAR JUGADORES:","\n7. ORDENAR Y LISTAR:","\n8. GENERAR ARCHIVO BINARIO:","\n9. CARGAR ARCHIVO BINARIO:","\n10. GUARDAR ARCHIVOS .CSV:","\n11. SALIR:","\nMenu Principal\n");
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
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 ){
                	do{
                		opcionListados = MostrarMenu4Opc("\n1.TODOS LOS JUGADORES.","\n2.TODAS LAS SELECCIONES.","\n3.JUGADORES CONVOCADOS","\n4.SALIR","\nMENU LISTADOS\n");
                    	switch(opcionListados){
                    	case 1:
                    		controller_listarJugadoresYSeleccion(listaJugadores,listaSelecciones);
                    		break;
                    	case 2:
                    		controller_listarSelecciones(listaSelecciones);
                    		break;
                    	case 3:
                    		if(controller_detectarConvocados(listaSelecciones)==1){
                    			controller_listarJugadoresConvocados(listaJugadores,listaSelecciones);
                    		}else{
                    			printf("\nNo hay jugadores convocados\n");
                    		}
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
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 ){
                	do{
                		opcionConvocar = MostrarMenu3Opc("\n1.CONVOCAR.","\n2.QUITAR DE LA SELECCIÓN.","\n3.Salir","\nMENU CONVOCACION\n");
                    	switch(opcionConvocar){
                    	case 1:
                    		controller_convocarJugadores(listaJugadores,listaSelecciones);
                    		banderaCambios=1;
                    		break;
                    	case 2:
                    		if(controller_detectarConvocados(listaSelecciones)==1){
                        		controller_desconvocarJugadores(listaJugadores,listaSelecciones);
                        		banderaCambios=1;
                    		}else{
                    			printf("\nNo hay jugadores convocados\n");
                    		}
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
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 ){
                	do{
                		opcionOrdenar = MostrarMenu5Opc("1.JUGADORES POR NACIONALIDAD.\n","2.SELECCIONES POR CONFEDERACIÓN.\n","3.JUGADORES POR EDAD.\n","4.JUGADORES POR NOMBRE.\n","5.Salir.","MENU ORDENAR\n");
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
            	if(ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 ){
            		controller_filtrarJugadoresConvocados(listaJugadores,listaSelecciones,listaConvocados);
            		banderaCase8=1;
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}
            	break;
            case 9:
            	if((ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 && ll_isEmpty(listaConvocados)==0) && banderaCase8==1){
					controller_cargarJugadoresDesdeBinario("JugadoresConvocados.bin",listaConvocados);
					controller_listarJugadoresYSeleccion(listaConvocados,listaSelecciones);
            	}else{
            		printf("\nError, no hay jugadores para cargar al archivo\n");
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
            		ll_deleteLinkedList(listaSelecciones);
            		ll_deleteLinkedList(listaJugadores);
            		ll_deleteLinkedList(listaConvocados);
            		printf("\nSaliendo...");
            	}else{
            		option=0;
            	}
            	break;
        }
    }while(option != 11);

    return 0;
}

