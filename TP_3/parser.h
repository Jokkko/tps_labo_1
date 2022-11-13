
#ifndef PARSER_H_
#define PARSER_H_


/// \fn int parser_JugadorFromText(FILE*, LinkedList*)
/// \brief Funcion que se encarga de crear un jugador desde el archivo csv de jugadores
///
/// \param pFile puntero al archivo
/// \param pArrayListJugador lista donde se va a guardar el jugador
/// \return devuelve -1 en caso de error y 1 en caso de exito
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/// \fn int parser_JugadorFromBinary(FILE*, LinkedList*)
/// \brief Funcion que se encarga de crear un jugador desde el archivo binario de jugadores
///
/// \param pFile puntero al archivo
/// \param pArrayListJugador lista donde se va a guardar el jugador
/// \return devuelve -1 en caso de error y 1 en caso de exito
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/// \fn int parser_SeleccionFromText(FILE*, LinkedList*)
/// \brief Funcion que se encarga de crear una seleccion desde el archivo csv de seleccion
///
/// \param pFile puntero al archivo
/// \param pArrayListSeleccion lista donde se va a guardar la seleccion
/// \return devuelve -1 en caso de error y 1 en caso de exito
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
