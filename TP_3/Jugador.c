#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "input.h"
//------------------C O N S T R U C T O R E S---------------------------------

Jugador* jug_new(){
	Jugador* pJugador;

		pJugador = (Jugador*) malloc(sizeof(Jugador));


    return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){
	Jugador* pJugador;
	int id;
	int edad;
	int idSeleccion;
	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL){

		if(esNumerica(idStr) == 1 && esNumerica(edadStr) == 1 && esNumerica(idSelccionStr) == 1 ){
			pJugador = jug_new();
			if(pJugador!=NULL){
				id = atoi(idStr);
				edad = atoi(edadStr);
				idSeleccion = atoi(idSelccionStr);

				jug_setId(pJugador,id);
				jug_setNombreCompleto(pJugador,nombreCompletoStr);
				jug_setPosicion(pJugador,posicionStr);
				jug_setNacionalidad(pJugador,nacionalidadStr);
				jug_setEdad(pJugador,edad);
				jug_setIdSeleccion(pJugador,idSeleccion);
			}
		}
	}
	return pJugador;
}

//------------------D E S T R U C T O R---------------------------------
void jug_delete(Jugador* this){
    if(this != NULL)
    {
        free(this);
    }
}

//------------------S E T T E R S---------------------------------
int jug_setId(Jugador* this,int id){
	int retorno=-1;

	if(this!=NULL && id > 0){
		this->id = id;
		retorno =1;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno=-1;

	if(this!=NULL && nombreCompleto != NULL){
			strcpy(this->nombreCompleto,nombreCompleto);
			retorno =1;
		}
		return retorno;

}

int jug_setPosicion(Jugador* this,char* posicion){
	int retorno=-1;

	if(this!=NULL && posicion != NULL){
			strcpy(this->posicion,posicion);
			retorno =1;
		}
		return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno=-1;

	if(this!=NULL && nacionalidad != NULL){
			strcpy(this->nacionalidad,nacionalidad);
			retorno =1;
		}
		return retorno;
}


int jug_setEdad(Jugador* this,int edad){
	int retorno=-1;

	if(this!=NULL && edad >= 18){
			this->edad = edad;
			retorno =1;
		}
		return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno=-1;

	if(this!=NULL && idSeleccion > -1){
			this->idSeleccion = idSeleccion;
			retorno =1;
		}
		return retorno;
}

//------------------G E T T E R S---------------------------------
int jug_getId(Jugador* this,int* id){
	int retorno= -1;

	if(this !=  NULL && id !=NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno= -1;

	if(this !=  NULL && nombreCompleto !=NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion){
	int retorno= -1;

	if(this !=  NULL && posicion !=NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno= -1;

	if(this !=  NULL && nacionalidad !=NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad){
	int retorno= -1;

	if(this !=  NULL && edad !=NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion){
	int retorno= -1;

	if(this !=  NULL && idSeleccion !=NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}
