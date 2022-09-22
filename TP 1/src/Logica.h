/*
 * Logica.h
 *
 *  Created on: 12 sep. 2022
 *      Author: vazzr
 */

#ifndef LOGICA_H_
#define LOGICA_H_
/**
 * \fn int CalcularPromedio(float*, int, int)
 * \brief Funcion que calcula un promedio
 *
 * \param pPromedio Puntero a la direccion de memoria donde se guardara el resultado del promedio
 * \param divisor Numero que va a divir
 * \param dividendo Numero que se divide
 * \return Retorna 1 (EXITO) si el divisor es distinto de 0 y -1 (ERROR) si no
 */
int CalcularPromedio(float *pPromedio,int divisor, int dividendo );

/**
 * \fn int CalcularPorcentaje(int*, int, float)
 * \brief Funcion que calcula un porcentaje
 *
 * \param pPorcentaje Puntero a la direccion de memoria donde se guardara el resultado del calculo
 * \param numero	Numero al cual sacar el porcentaje
 * \param porcentaje	Porcentaje a calcular
 * \return
 */
int CalcularPorcentaje(int *pPorcentaje, int numero, float porcentaje);

#endif /* LOGICA_H_ */
