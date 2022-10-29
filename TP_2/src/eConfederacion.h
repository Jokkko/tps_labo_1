/*
 * eConfederacion.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_


typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;

}eConfederacion;
/// \fn int HardcodeoConfederacion(eConfederacion[], int)
/// \brief Funcion que harcodea valores en un array de eConfederacion
///
/// \param confederaciones
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo y -1 si no
int HardcodeoConfederacion(eConfederacion confederaciones[],int SIZE);

/// \fn int SwapConfederacion(eConfederacion[], int, int)
/// \brief Funcion que se encarga de hacer un swapeo de lugares en un array de eConfederacion
///
/// \param confederacion
/// \param i
/// \param j
/// \return devuelve 1 si pudo lograrlo y -1 si no
int SwapConfederacion(eConfederacion confederacion[], int i,int j);

/// \fn int BuscarIndiceConf(eConfederacion[], int, int)
/// \brief Funcion que devuelve la posicion en la que se encuentra un id en un array de eConfederacion
///
/// \param confederacion
/// \param SIZE
/// \param id
/// \return devuelve 1 si pudo lograrlo y -1 si no
int BuscarIndiceConf(eConfederacion confederacion[],int SIZE,int id);

/// \fn int InicializarEstadoConf(eConfederacion[], int)
/// \brief Funcion que se encarga de inicializar los isEmpty de un array de eConfederacion
///
/// \param confederacion
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo y -1 si no
int InicializarEstadoConf(eConfederacion confederacion[],int SIZE);

/// \fn int AltaConfederacion(int, eConfederacion[], int)
/// \brief Funcion que se encarga de dar de alta una confederacion y sus datos
///
/// \param IdAutoincremental
/// \param confederacion
/// \param SIZE
/// \return devuelve el indice donde se dio de alta si pudo lograrlo y -1 si no
int AltaConfederacion(int IdAutoincremental,eConfederacion confederacion[],int SIZE);

/// \fn int BuscarIdMaximo(eConfederacion[], int)
/// \brief Funcion que se encarga de encontrar el id maximo de un array de eConfederacion
///
/// \param confederacion
/// \param SIZE
/// \return devuelve el id maximo si pudo lograrlo y -1 si no
int BuscarIdMaximo(eConfederacion confederacion[],int SIZE);

/// \fn int BuscarIndiceVacioConf(eConfederacion[], int)
/// \brief Busca el proximo indice vacio dentro de un array de eConfederacion
///
/// \param confederacion
/// \param SIZE
/// \return devuelve el indice si pudo lograrlo y -1 si no
int BuscarIndiceVacioConf(eConfederacion confederacion[],int SIZE);

/// \fn int BajaConfederacion(eConfederacion[], int)
/// \brief Funcion que da de baja una confederacion cambiando su isEmpty
///
/// \param confederacion
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int BajaConfederacion(eConfederacion confederacion[],int SIZE);

/// \fn int ModificarNombreConfe(eConfederacion[], int, int)
/// \brief Funcion que se encarga de modificar el nombre de una confederacion cargada
///
/// \param confederacion
/// \param indice
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarNombreConfe(eConfederacion confederacion[],int indice,int SIZE);

/// \fn int ModificarRegionConfe(eConfederacion[], int, int)
/// \brief  Funcion que se encarga de modificar la region de una confederacion cargada
///
/// \param confederacion
/// \param indice
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarRegionConfe(eConfederacion confederacion[],int indice,int SIZE);

/// \fn int ModificarAnio(eConfederacion[], int, int)
/// \brief Funcion que se encarga de modificar el anio de creacion de una confederacion cargada
///
/// \param confederacion
/// \param indice
/// \param SIZE
/// \return devuelve 1 si pudo lograrlo, 0 si cancelan la operacion y -1 si no se logro
int ModificarAnio(eConfederacion confederacion[],int indice,int SIZE);

/// \fn int BuscarIdMaximo(eConfederacion[], int)
/// \brief Funcion que se encarga de encontrar el id minimo de un array de eConfederacion
///
/// \param confederacion
/// \param SIZE
/// \return devuelve el id maximo si pudo lograrlo y -1 si no
int BuscarIdMin(eConfederacion confederacion[],int SIZE);

#endif /* ECONFEDERACION_H_ */
