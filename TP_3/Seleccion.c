#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "input.h"
//------------------C O N S T R U C T O R E S---------------------------------
Seleccion* selec_new(){
	Seleccion* pSeleccion;
		pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

    return pSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* pSeleccion = NULL;
	int id;
	int convocados;
	if(idStr != NULL && idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr){
		pSeleccion = selec_new();
		if(pSeleccion != NULL && esNumerica(idStr) == 1 && esNumerica(convocadosStr) == 1){
			convocados = atoi(convocadosStr);
			id = atoi(idStr);
			selec_setId(pSeleccion,id);
			selec_setConvocados(pSeleccion,convocados);
			selec_setPais(pSeleccion,paisStr);
			selec_setConfederacion(pSeleccion,confederacionStr);
		}
	}
	return pSeleccion;
}
//------------------D E S T R U C T O R---------------------------------
void selec_delete(Seleccion* this){
    if(this != NULL)
    {
        free(this);
    }
}

//------------------G E T T E R S---------------------------------
int selec_getId(Seleccion* this,int* id){
	int retorno= -1;

	if(this !=  NULL && id !=NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais){
	int retorno= -1;

	if(this !=  NULL && pais !=NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno= -1;

	if(this !=  NULL && confederacion !=NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno = 0;
	}

	return retorno;
}


int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno= -1;

	if(this !=  NULL && convocados !=NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}
//------------------S E T T E R S---------------------------------
int selec_setConvocados(Seleccion* this,int convocados){
	int retorno=-1;

	if(this!=NULL && convocados >= 0){
		this->convocados = convocados;
		retorno =1;
	}
	return retorno;
}

int selec_setId(Seleccion* this,int id){
	int retorno=-1;

	if(this!=NULL && id > 0){
		this->id = id;
		retorno =1;
	}
	return retorno;
}

int selec_setPais(Seleccion* this,char* pais){
	int retorno=-1;

	if(this!=NULL && pais != NULL){
			strcpy(this->pais,pais);
			retorno =1;
		}
		return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion){
	int retorno=-1;

	if(this!=NULL && confederacion != NULL){
			strcpy(this->confederacion,confederacion);
			retorno =1;
		}
		return retorno;
}
