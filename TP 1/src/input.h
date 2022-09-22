/*
 * FuncionesEntradaYSalida.h
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */

#ifndef FUNCIONESENTRADAYSALIDA_H_
#define FUNCIONESENTRADAYSALIDA_H_

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int *pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
int esNumerica(char *cadena);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char *cadena, int longitud);

/**
 * \fn int utn_getPositivo(int*, char*, char*, int)
 * \brief Pide un numero al usuario y verifica que sea positivo
 *
 * \param pResultado Puntero a el espacio de memoria donde se guardara el numero positivo ingresado
 * \param mensaje Mensaje a mostrar a la hora de pedir el numero
 * \param mensajeError Mensaje a mostrar en caso de error
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 (EXITO) si se obtiene un numero positivo y -1 (ERROR) si no
 */
int utn_getPositivo(int *pResultado, char *mensaje, char *mensajeError,	int reintentos);

/**
 * \fn int utn_getChar(char*, char*, char*, char, char, int)
 * \brief Pide al usuario un caracter y verifica que este entre los valores maximos y minimos dados por parametros
 *
 * \param pResultado puntero a la direccion  de memoria donde se guardara el caracter obtenido
 * \param mensaje Mensaje a mostrar a la hora de pedir el caracter
 * \param mensajeError Mensaje a mostrar en caso de error
 * \param minimo Numero del caracter en codigo ascii minimo
 * \param maximo Numero del caracter en codigo ascii maximo
 * \param reintentos Cantidad de reintentos
 * \return Retorna 1 (EXITO) si se obtiene un caracter entre los rangos y -1 (ERROR) si no
 */
int utn_getChar(char *pResultado, char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos);

/**
 * \fn int ContarConfederacion(int*, int*, int*, int*, int*, int*)
 * \brief Pide al usuario ingresar una confederacion y suma al contador de la misma 1 en caso de coincidir
 *
 * \param pContadorAFC Puntero a la direccion de memoria para guardar el aumento al contador
 * \param pContadorCAF Puntero a la direccion de memoria para guardar el aumento al contador
 * \param pContadorCONCACAF Puntero a la direccion de memoria para guardar el aumento al contador
 * \param pContadorCONMEBOL Puntero a la direccion de memoria para guardar el aumento al contador
 * \param pContadorUEFA Puntero a la direccion de memoria para guardar el aumento al contador
 * \param pContadorOFC Puntero a la direccion de memoria para guardar el aumento al contador
 * \return Retorna 1 (EXITO) si el usuario ingresa una confederacion valida en 3 intentos y -1 (ERROR) si no
 */
int ContarConfederacion( int *pContadorAFC, int *pContadorCAF, int *pContadorCONCACAF, int *pContadorCONMEBOL, int *pContadorUEFA, int *pContadorOFC);


#endif /* FUNCIONESENTRADAYSALIDA_H_ */
