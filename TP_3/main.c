#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int opcionListados;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    puts("funciona ok");

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
            	break;
            case 3:
            	controller_editarJugador(listaJugadores);
            	break;
            case 4:
            	controller_removerJugador(listaJugadores);
            	break;
            case 5:
            	do{
                	printf("MENU LISTADOS\n"
                			"1.TODOS LOS JUGADORES.\n"
                			"2.TODAS LAS SELECCIONES.\n"
                			"3.JUGADORES CONVOCADOS\n"
                			"4.Salir\n");
                	utn_getNumero(&opcionListados,"\nIngrese Opcion:\n","Ingrese opcion valida",1,4,3);
                	switch(opcionListados){
                	case 1:
                		controller_listarJugadores(listaJugadores);
                		break;
                	case 2:
                		controller_listarSelecciones(listaSelecciones);
                		break;
                	case 3:
                		break;
                	case 4:
                		break;

                	}
            	}while(opcionListados!=4);
            	break;
        }
    }while(option != 11);

    return 0;
}

