/*
 * output.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include "eJugador.h"
#include "eConfederacion.h"
/// \fn int MostrarOpcion(char*)
/// \brief Funcion que se encarga de mostrar una opcion ingresada por parametros
///
/// \param opcion
/// \return Devuelve -1 en caso de error y 1 en caso de exito
int MostrarOpcion(char *opcion);

/// \fn int MostrarMenu(char*, char*, char*, char*, char*, char*, char*, char*)
/// \brief Funcion que se encarga de mostrar un menu y pedir opcion
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param opcion4
/// \param opcion5
/// \param opcion6
/// \param opcion7
/// \param menu
/// \return devuelve la opcion elegida y -1 en caso de error
int MostrarMenu(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *menu);

/// \fn void MensajeError(int)
/// \brief Funcion que se encarga atravez de un switch, de dar aviso si la funcion funciono correcta o incorrectamente
///
/// \param caso
void MensajeError(int caso);

/// \fn int MostrarJugador(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de reccorer un array eJugador y mostrarlo
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve -1 en caso de error y 1 en caso de exito
int MostrarJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int MostrarConfederacion(eConfederacion[], int)
/// \brief funcion que se encarga de recorrer un array eConfederacion y mostrarlo
///
/// \param confederacion
/// \param SIZE
/// \return devuelve 1 en caso de exito y -1 en caso de error
int MostrarConfederacion(eConfederacion confederacion[],int SIZE);

/// \fn int MostrarConfederacionesYJugadores(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de mostrar a los jugadores con sus respectivas confederaciones
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return Devuelve 1 en caso de exito y -1 en caso de error
int MostrarConfederacionesYJugadores(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int MostrarPromedioYSalarios(eJugador[], int)
/// \brief Funcion que se encarga de mostrar los promedios de salarios de los jugadores la cantidad total de salarios y de jugadores por encima del promedio de slarios
///
/// \param jugadores
/// \param SIZE
/// \return devuelve 1 en caso de exito y -1 en caso de error
int MostrarPromedioYSalarios(eJugador jugadores[],int SIZE);

/// \fn int MostrarConfeMasAnios(eJugador[], int, eConfederacion[], int)
/// \brief Se encarga de mostrar la confederacion con mas anios de contrato total
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve 1 en caso de exito y -1 en caso de error
int MostrarConfeMasAnios(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int MostrarPorcentajeConfe(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de mostrar el porcentaje de jugadores jugando en cada confederacion
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve 1 en caso de exito y -1 en caso de error
int MostrarPorcentajeConfe(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int MostrarRegionMax(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de mostrar la region con mas jugadores y sus jugadpres
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve 1 en caso de exito y -1 en caso de error
int MostrarRegionMax(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);
#endif /* OUTPUT_H_ */
