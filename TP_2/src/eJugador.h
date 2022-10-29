/*
 * eJugador.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */
#include "eConfederacion.h"
#ifndef EJUGADOR_H_
#define EJUGADOR_H_


typedef struct{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;


/// \fn int InicializarEstado(eJugador[], int)
/// \brief Funcion que se encarga de inicializar el estado de un array de estructura eJugador
///
/// \param jugadores
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo y -1 si no
int InicializarEstado(eJugador jugadores[],int SIZE);

/// \fn int BuscarIndiceVacio(eJugador[], int)
/// \brief Funcion que se encarga de encontrar el proximo indice vacio de un array de eJugador
///
/// \param jugadores
/// \param SIZE
/// \return devuelve el indice si pudo lograrlo y -1 si no
int BuscarIndiceVacio(eJugador jugadores[],int SIZE);

/// \fn int BuscarIdJugador(eJugador[], int, int)
/// \brief Busca un jugador por id en una estructura eJugador
///
/// \param jugadores
/// \param SIZE
/// \param indice
/// \return devuelve el indice si pudo lograrlo y -1 si no
int BuscarIdJugador(eJugador jugadores[],int SIZE,int indice);

/// \fn int AltaJugador(eJugador[], int, int, eConfederacion[], int)
/// \brief Funcion que da de alta un jugador en un array de eJugador
///
/// \param jugadores
/// \param SIZE
/// \param IdAutoincremental
/// \param confederacion
/// \param SIZE2
/// \return devuelve el indice donde se dio de alta si pudo lograrlo y -1 si no
int AltaJugador(eJugador jugadores[],int SIZE, int IdAutoincremental,eConfederacion confederacion[],int SIZE2);

/// \fn int BajaJugador(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que da de baja a un jugador ingresado
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int BajaJugador(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int ModificarConfederacion(eJugador[], int, int, eConfederacion[], int)
/// \brief Funcion que se encarga de modificar la confederacion de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarConfederacion(eJugador jugadores[],int indice,int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int ModificarNombre(eJugador[], int, int)
/// \brief Funcion que se encarga de modificar el nombre de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarNombre(eJugador jugadores[],int indice,int SIZE);

/// \fn int ModificarPosicion(eJugador[], int, int)
/// \brief Funcion que se encarga de modificar la posicion de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarPosicion(eJugador jugadores[],int indice,int SIZE);

/// \fn int ModificarNumeroCamiseta(eJugador[], int, int)
/// \brief Funcion que se encarga de modificar el numero de camiseta de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarNumeroCamiseta(eJugador jugadores[],int indice,int SIZE);

/// \fn int ModificarSalario(eJugador[], int, int)
/// \brief Funcion que se encarga de modificar el salario de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarSalario(eJugador jugadores[],int indice,int SIZE);

/// \fn int ModificarAniosContrato(eJugador[], int, int)
/// \brief Funcion que se encarga de modificar los anios de contrato de un jugador ingresado
///
/// \param jugadores
/// \param indice
/// \param SIZE
/// \return  devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarAniosContrato(eJugador jugadores[],int indice,int SIZE);

/// \fn int SwapJugador(eJugador[], int, int)
/// \brief Funcion que se encarga de hacer un swap de dos posiciones en un array de eJugador
///
/// \param jugadores
/// \param i
/// \param j
/// \return devuelve 1 si pudo lograrlo y -1 si no
int SwapJugador(eJugador jugadores[], int i,int j);

/// \fn float TotalDeSalarios(eJugador[], int, float*)
/// \brief Funcion que se encarga de calcular el total de salarios de los jugadores
///
/// \param jugadores
/// \param SIZE
/// \param pAcumulador
/// \return devuelve 1 si pudo lograrlo y -1 si no
float TotalDeSalarios(eJugador jugadores[],int SIZE,float *pAcumulador);

/// \fn int ContadorJugadores(eJugador[], int)
/// \brief Funcion que se encarga de contar el total de jugadores
///
/// \param jugadores
/// \param SIZE
/// \return devuelve la cantidad de jugadores contados
int ContadorJugadores(eJugador jugadores[],int SIZE);

/// \fn int PromedioSalarios(float, int, float*)
/// \brief Funcion que se encarga de hacer un promedio de todos los salarios
///
/// \param salarios
/// \param cantJugadores
/// \param pResultado
/// \return devuelve 1 si pudo lograrlo y -1 si no
int PromedioSalarios(float salarios, int cantJugadores,float *pResultado);

/// \fn int JugadoresArribaPromedio(eJugador[], int)
/// \brief Funcion que detecta la cantidad de jugadores por encima del salario promedio
///
/// \param jugadores
/// \param SIZE
/// \return devuelve la cantidad de jugadores por encima del promedio
int JugadoresArribaPromedio(eJugador jugadores[],int SIZE);

/// \fn int OrdenarAlfabetico(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de ordenar las posiciones de un array eJugador y un array eConfederacion de forma alfabetica
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve 1 si pudo lograrlo y -1 si no
int OrdenarAlfabetico(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int OrdenarJugadorPorID(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de ordenar por id un array de eJugadore
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve 1 si pudo lograrlo y -1 si no
int OrdenarJugadorPorID(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int IDConfeMasAnios(eJugador[], int, eConfederacion[], int)
/// \brief Funcion que se encarga de detectar el ID de la confederacion con mas anios de contrato
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \return devuelve el id de la confederacion con mas anios si salio bien o -1 si no lo logro
int IDConfeMasAnios(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2);

/// \fn int ContarJugadoresPorConfe(eJugador[], int, eConfederacion[], int*, int)
/// \brief Funcion que se encarga de contar la cantidad de jugadores que hay por confederacion
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param contador
/// \param indiceConfe
/// \return devuelve -1 si algo salio mal o 1 si salio bien
int ContarJugadoresPorConfe(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int *contador,int indiceConfe);

/// \fn int ContarJugadoresPorRegion(eJugador[], int, eConfederacion[], int, char[])
/// \brief Funcion que se encarga de contar los jugadores que hay por cada region y encontrar su id
///
/// \param jugadores
/// \param SIZE
/// \param confederacion
/// \param SIZE2
/// \param regionmax
/// \return Devuelve el id de la region con mas jugadores, sino devuelve -1
int ContarJugadoresPorRegion(eJugador jugadores[],int SIZE,eConfederacion confederacion[],int SIZE2,char regionmax[]);

#endif /* EJUGADOR_H_ */
