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
            	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)==-1){
            		printf("\nOcurrio un error al cargar los jugadores desde el csv\n");
            	}
            	if(controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones)==-1){
            		printf("\nOcurrio un error al cargar las selecciones desde el csv\n");
            	}
                break;
            case 2:
            	if(controller_agregarJugador(listaJugadores)==-1){
            		printf("\nOcurrio un error al dar de alta al jugador\n");
            	}else{
            		banderaCambios=1;
            	}
            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_editarJugador(listaJugadores)==-1){
            			printf("\nOcurrio un error al editar al jugador\n");
            		}else{
            			banderaCambios=1;
            		}
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores cargados.\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores)==0){
            		if(controller_removerJugador(listaJugadores,listaSelecciones)==-1){
            			printf("\nOcurrio un error al remover al jugador\n");
            		}else{
            			banderaCambios=1;
            		}
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
                    		if(controller_listarJugadoresYSeleccion(listaJugadores,listaSelecciones)==-1){
                    			printf("\nOcurrio un error al listar los jugadores y sus selecciones\n");
                    		}
                    		break;
                    	case 2:
                    		if(controller_listarSelecciones(listaSelecciones)==-1){
                    			printf("\nOcurrio un error al listar las selecciones\n");
                    		}
                    		break;
                    	case 3:
                    		if(controller_detectarConvocados(listaSelecciones)==1){
                    			if(controller_listarJugadoresConvocados(listaJugadores,listaSelecciones)==-1){
                        			printf("\nOcurrio un error al listar los jugadores convocados\n");
                        		}
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
                    		if(controller_convocarJugadores(listaJugadores,listaSelecciones)==-1){
                    			printf("\nOcurrio un error al convocar jugadores\n");
                    		}else{
                    			banderaCambios=1;
                    		}
                    		break;
                    	case 2:
                    		if(controller_detectarConvocados(listaSelecciones)==1){
                        		if(controller_desconvocarJugadores(listaJugadores,listaSelecciones)==-1){
                        			printf("\nOcurrio un error al desconvocar el jugador\n");
                        		}else{
                        		banderaCambios=1;
                        		}
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
                    		if(ll_sort(listaJugadores, OrdenarPorNacionalidad, 1)==-1){
                    			printf("\nOcurrio un error al ordenar la lista de jugadores\n");
                    		}else{
                    			if(controller_listarJugadores(listaJugadores)==-1){
                        			printf("\nOcurrio un error al listar los jugadores\n");
                        		}
                    		}
                    		break;
                    	case 2:
                    		if(ll_sort(listaSelecciones, OrdenarPorConfederacion, 1)==-1){
                    			printf("\nOcurrio un error al ordenar la lista de jugadores\n");
                    		}else{
                    			if(controller_listarJugadores(listaJugadores)==-1){
                        			printf("\nOcurrio un error al listar los jugadores\n");
                        		}
                    		}
                    		break;
                    	case 3:
                    		if(ll_sort(listaJugadores, OrdenarPorEdad, 1)==-1){
                    			printf("\nOcurrio un error al ordenar la lista de jugadores\n");
                    		}else{
                    			if(controller_listarJugadores(listaJugadores)==-1){
                        			printf("\nOcurrio un error al listar los jugadores\n");
                        		}
                    		}
                    		break;
                    	case 4:
                    		if(ll_sort(listaJugadores, OrdenarPorNombre, 1)==-1){
                    			printf("\nOcurrio un error al ordenar la lista de jugadores\n");
                    		}else{
                    			if(controller_listarJugadores(listaJugadores)==-1){
                        			printf("\nOcurrio un error al listar los jugadores\n");
                        		}
                    		}
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
            		if(controller_filtrarJugadoresConvocados(listaJugadores,listaSelecciones,listaConvocados)==-1){
            			printf("\nOcurrio un error al ordenar la lista de jugadores\n");
            		}else{
            			banderaCase8=1;
            		}
            	}else{
            		printf("\nError, no se puede acceder si no hay jugadores y selecciones cargadas.\n");
            	}
            	break;
            case 9:
            	if((ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0 && ll_isEmpty(listaConvocados)==0) && banderaCase8==1){
					if(controller_cargarJugadoresDesdeBinario("JugadoresConvocados.bin",listaConvocados)==-1){
						printf("\nOcurrio un error al cargar la lista de jugadores desde el archivo binario\n");
					}
					if(controller_listarJugadoresYSeleccion(listaConvocados,listaSelecciones)==-1){
						printf("\nOcurrio un error al listar los jugadores y sus selecciones\n");
					}
            	}else{
            		printf("\nError, no hay jugadores para cargar al archivo\n");
            	}

            	break;
            case 10:
            	if(banderaCambios==1){
					if(controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones)==-1){
						printf("\nOcurrio un error al guardar los datos de las selecciones en el archivo\n");
					}else{
						if(controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores)==1){
							printf("\nnOcurrio un error al guardar los datos de los jugadores en el archivo\n");
						}else{
							banderaCambios=0;
						}
					}
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

