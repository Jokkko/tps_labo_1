#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/// \fn Seleccion selec_new*()
/// \brief Crea una seleccion nueva
///
/// \return devuelve un puntero a la seleccion creada, o devuelve NULL si no se pudo crear
Seleccion* selec_new();

/// \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// \brief  Crea una seleccion nueva con los parametros ingresados
///
/// \param idStr establece el id
/// \param paisStr establece el pais
/// \param confederacionStr establece la confederacion
/// \param convocadosStr establece la cantidad de convocados
/// \return devuelve un puntero a la seleccion creada o NULL
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/// \fn void selec_delete(Seleccion*)
/// \brief borra una seleccion
///
/// \param this puntero a la seleccion a borrar
void selec_delete(Seleccion* this);

/// \fn int selec_getId(Seleccion*, int*)
/// \brief consigue el id de una seleccion
///
/// \param this puntero a la seleccion
/// \param id puntero a donde se guardara el id
/// \return  devuelve -1 en caso de error y 1 en caso de exito
int selec_getId(Seleccion* this,int* id);

/// \fn int selec_getPais(Seleccion*, char*)
/// \brief consigue el pais de una seleccion
///
/// \param this puntero a la seleccion
/// \param pais puntero a donde se guardara el pais
/// \return  devuelve -1 en caso de error y 1 en caso de exito
int selec_getPais(Seleccion* this,char* pais);

/// \fn int selec_getConfederacion(Seleccion*, char*)
/// \brief consigue la Confederacion de una seleccion
///
/// \param this puntero a la seleccion
/// \param confederacion puntero a donde se guardara la confederacion
/// \return  devuelve -1 en caso de error y 1 en caso de exito
int selec_getConfederacion(Seleccion* this,char* confederacion);

/// \fn int selec_setConvocados(Seleccion*, int)
/// \brief  establece la cantidad de convocados
///
/// \param this puntero a la seleccion
/// \param convocados valor a establecer
/// \return  devuelve -1 en caso de error y 1 en caso de exito
int selec_setConvocados(Seleccion* this,int convocados);

/// \fn int selec_getConvocados(Seleccion*, int*)
/// \brief consigue la cantidad de convocados
///
/// \param this puntero a la seleccion
/// \param convocados puntero a donde se guardara la cantidad de convocados
/// \return devuelve -1 en caso de error y 1 en caso de exito
int selec_getConvocados(Seleccion* this,int* convocados);

/// \fn int OrdenarPorConfederacion(void*, void*)
/// \brief ordena dos selecciones por confederacion
///
/// \param seleccion1 puntero a la seleccion
/// \param seleccion2 puntero a la seleccion
/// \return devuelve 0 si son iguales, 1 si el primero es mas grande que el segundo y -1 si el segundo es mas chico que el primero
int OrdenarPorConfederacion(void* seleccion1,void* seleccion2);

#endif // selec_H_INCLUDED
