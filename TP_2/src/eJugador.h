/*
 * eJugador.h
 *
 *  Created on: 14 oct. 2022
 *      Author: vazzr
 */

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


int InicializarEstado(eJugador *jugadores,int SIZE);



#endif /* EJUGADOR_H_ */
