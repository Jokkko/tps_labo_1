#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/// \fn Jugador jug_new*()
/// \brief Crea un jugador nuevo
///
/// \return devuelve un puntero al jugador creado, o devuelve NULL si no se pudo crear
Jugador* jug_new();

/// \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// \brief Crea un jugador nuevo con los parametros ingresados
///
/// \param idStr establece el id del jugador
/// \param nombreCompletoStr establece el nombre del jugador
/// \param edadStr establece la edad del jugador
/// \param posicionStr establece la posicion del jugador
/// \param nacionalidadStr establece la nacionalidad del jugador
/// \param idSelccionStr establece el id de la seleccion jugador
/// \return
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/// \fn void jug_delete(Jugador*)
/// \brief borra a un jugador
///
/// \param this puntero al jugador a borrar
void jug_delete(Jugador* this);

/// \fn int jug_setId(Jugador*, int)
/// \brief establece el id de un jugador
///
/// \param this puntero al jugador
/// \param id valor a setear
/// \return  devuelve -1 en caso de error y 1 en caso de exito
int jug_setId(Jugador* this,int id);

/// \fn int jug_getId(Jugador*, int*)
/// \brief consigue el id de un jugador
///
/// \param this puntero al jugador
/// \param id puntero a donde se guardara la id
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getId(Jugador* this,int* id);

/// \fn int jug_setNombreCompleto(Jugador*, char*)
/// \brief establece el nombre de un jugador
///
/// \param this puntero al jugador
/// \param nombreCompleto valor a setear
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/// \fn int jug_getNombreCompleto(Jugador*, char*)
/// \brief consigue el nombre de un jugador
///
/// \param this puntero al jugador
/// \param nombreCompleto puntero a donde se guardara el nombre
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/// \fn int jug_setPosicion(Jugador*, char*)
/// \brief establece la posicion de un jugador
///
/// \param this puntero al jugador
/// \param posicion valor a setear
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_setPosicion(Jugador* this,char* posicion);

/// \fn int jug_getPosicion(Jugador*, char*)
/// \brief consigue la posicion de un jugador
///
/// \param this puntero al jugador
/// \param posicion puntero a donde se guardara la posicion
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getPosicion(Jugador* this,char* posicion);

/// \fn int jug_setNacionalidad(Jugador*, char*)
/// \brief establece la Nacionalidad de un jugador
///
/// \param this puntero al jugador
/// \param nacionalidad valor a setear
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/// \fn int jug_getNacionalidad(Jugador*, char*)
/// \brief consigue la Nacionalidad de un jugador
///
/// \param this puntero al jugador
/// \param nacionalidad puntero a donde se guardara la nacionalidad
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/// \fn int jug_setEdad(Jugador*, int)
/// \brief  establece la Edad de un jugador
///
/// \param this puntero al jugador
/// \param edad valor a setear
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_setEdad(Jugador* this,int edad);

/// \fn int jug_getEdad(Jugador*, int*)
/// \brief consigue la Edad de un jugador
///
/// \param this puntero al jugador
/// \param edad puntero a donde se guardara la edad
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getEdad(Jugador* this,int* edad);

/// \fn int jug_setIdSeleccion(Jugador*, int)
/// \brief  establece la id de la seleccion de un jugador
///
/// \param this puntero al jugador
/// \param idSeleccion valor a setear
/// \return  devuelve -1 en caso de error y 1 en caso de exito
///
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/// \fn int jug_getSIdSeleccion(Jugador*, int*)
/// \brief consigue la id de la seleccion de un jugador
///
/// \param this puntero al jugador
/// \param idSeleccion puntero a donde se guardara la id de la seleccion
/// \return devuelve -1 en caso de error y 1 en caso de exito
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

/// \fn int OrdenarPorNacionalidad(void*, void*)
/// \brief Ordena jugadores por nacionalidad
///
/// \param jugador1 puntero al primer jugador a ordenar
/// \param jugador2 puntero al segundo jugador a ordenar
/// \return devuelve 0 si son iguales, 1 si el primero es mas grande que el segundo y -1 si el segundo es mas chico que el primero
int OrdenarPorNacionalidad(void* jugador1 ,void* jugador2 );

/// \fn int OrdenarPorEdad(void*, void*)
/// \brief Ordena jugadores por Edad
///
/// \param jugador1 puntero al primer jugador a ordenar
/// \param jugador2 puntero al segundo jugador a ordenar
/// \return devuelve 0 si son iguales, 1 si el primero es mas grande que el segundo y -1 si el segundo es mas chico que el primero
int OrdenarPorEdad(void* jugador1 ,void* jugador2 );

/// \fn int OrdenarPorNombre(void*, void*)
/// \brief Ordena jugadores por Nombre
///
/// \param jugador1 puntero al primer jugador a ordenar
/// \param jugador2 puntero al segundo jugador a ordenar
/// \return devuelve 0 si son iguales, 1 si el primero es mas grande que el segundo y -1 si el segundo es mas chico que el primero
int OrdenarPorNombre(void* jugador1 ,void* jugador2);

#endif // jug_H_INCLUDED
