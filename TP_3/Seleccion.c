#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "input.h"
//------------------C O N S T R U C T O R E S---------------------------------
Seleccion* selec_new(){
	Seleccion* pSeleccion;
		pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
		if(pSeleccion!=NULL){
			pSeleccion->id=0;
			strcpy(pSeleccion->pais,"0");
			strcpy(pSeleccion->confederacion,"0");
			selec_setConvocados(pSeleccion,0);
		}
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
			if(id>0 && ( convocados >-1 && convocados <= 22)){
				pSeleccion->id = id;
				strcpy(pSeleccion->pais,paisStr);
				strcpy(pSeleccion->confederacion,confederacionStr);
				selec_setConvocados(pSeleccion,convocados);
			}
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
//------------------O R D E N A M I E N T O---------------------------------
int OrdenarPorConfederacion(void* seleccion1,void* seleccion2){
	int retorno=0;

	Seleccion* pSeleccion1;
	Seleccion* pSeleccion2;

	char confederacion1[100];
	char confederacion2[100];
	pSeleccion1=(Seleccion*) seleccion1;
	pSeleccion2=(Seleccion*) seleccion2;
	selec_getConfederacion(pSeleccion1,confederacion1);
	selec_getConfederacion(pSeleccion2,confederacion2);
	if(strcmpi(confederacion1,confederacion2)>0){
		retorno =1;
	}else{
		if(strcmpi(confederacion1,confederacion2)<0){
			retorno = -1;
		}
	}
	return retorno;
}

