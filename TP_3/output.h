/*
 * output.h
 *
 *  Created on: 12 nov. 2022
 *      Author: vazzr
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

/// \fn int MostrarOpcion(char*)
/// \brief funcion que se encarga de mostrar una opcion
///
/// \param opcion opcion a mostrar
/// \return devuelve 1 si se puede mostrar
int MostrarOpcion(char *opcion);

/// \fn int MostrarMenu11Opc(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, char*, char*)
/// \brief crea un menu de 11 opciones
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param opcion4
/// \param opcion5
/// \param opcion6
/// \param opcion7
/// \param opcion8
/// \param opcion9
/// \param opcion10
/// \param opcion11
/// \param menu nombre del menu
/// \return devuelve 1 si se puede mostrar
int MostrarMenu11Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *opcion6,char *opcion7,char *opcion8,char *opcion9,char *opcion10,char *opcion11,char *menu);

/// \fn int MostrarMenu4Opc(char*, char*, char*, char*, char*)
/// \brief  crea un menu de 4 opciones
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param opcion4
/// \param menu nombre del menu
/// \return devuelve 1 si se puede mostrar
int MostrarMenu4Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *menu);

/// \fn int MostrarMenu3Opc(char*, char*, char*, char*)
/// \brief  crea un menu de 3 opciones
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param menu nombre del menu
/// \return devuelve 1 si se puede mostrar
int MostrarMenu3Opc(char *opcion1,char *opcion2,char *opcion3,char *menu);

/// \fn int MostrarMenu5Opc(char*, char*, char*, char*, char*, char*)
/// \brief crea un menu de 5 opciones
///
/// \param opcion1
/// \param opcion2
/// \param opcion3
/// \param opcion4
/// \param opcion5
/// \param menu nombre del menu
/// \return devuelve 1 si se puede mostrar
int MostrarMenu5Opc(char *opcion1,char *opcion2,char *opcion3,char *opcion4,char *opcion5,char *menu);

#endif /* OUTPUT_H_ */
