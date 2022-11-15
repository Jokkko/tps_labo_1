/// \fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
/// \brief Abre el archivo csv de los jugadores
///
/// \param path ruta al archivo
/// \param pArrayListJugador lista donde se van a cargar los archivos
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/// \fn int controller_cargarJugadoresDesdeBinario(char*, LinkedList*)
/// \brief Abre el archivo bin de los jugadores
///
/// \param path ruta al archivo
/// \param pArrayListJugador lista donde se van a cargar los archivos
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/// \fn int controller_agregarJugador(LinkedList*)
/// \brief Funcion que se encarga de agregar un jugador a la linkedlist a partir de los datos ingresados por el usuario
///
/// \param pArrayListJugador lista donde se van a cargar los datos ingresados
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_agregarJugador(LinkedList* pArrayListJugador);

/// \fn int controller_editarJugador(LinkedList*)
/// \brief Funcion que se encarga de editar un jugador de la lista
///
/// \param pArrayListJugador lista donde se busca al jugador para editar los datos
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_editarJugador(LinkedList* pArrayListJugador);

/// \fn int controller_removerJugador(LinkedList*, LinkedList*)
/// \brief Funcion que se encarga de dar de baja un jugador de la lista
///
/// \param pArrayListJugador lista donde se busca al jugador para dar de baja los datos
/// \param pArrayListSeleccion lista donde se busca a la seleccion para bajar el contador de convocados de la seleccion
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// \fn int controller_listarJugadores(LinkedList*)
/// \brief Funcion que se encarga de mostrar los jugadores que hay en la lista
///
/// \param pArrayListJugador lista donde se buscan los jugadores.
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_listarJugadores(LinkedList* pArrayListJugador);

/// \fn int controller_ordenarJugadores(LinkedList*)
/// \brief
///
/// \param pArrayListJugador
/// \return
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/// \fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
/// \brief Funcion que se encarga de guardar la lista de jugadores en un archivo .csv
///
/// \param path ruta al archivo
/// \param pArrayListJugador lista donde se encuentran los jugadores a guardar
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/// \fn int controller_guardarJugadoresModoBinario(char*, LinkedList*)
/// \brief  Funcion que se encarga de guardar la lista de jugadores convocados en un archivo .bin
///
/// \param path ruta al archivo
/// \param pArrayListJugador lista donde se encuentran los jugadores a guardar
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/// \fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)
/// \brief Abre el archivo .csv de selecciones
///
/// \param path ruta al archivo
/// \param pArrayListSeleccion lista donde se van a guardar las selecciones
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/// \fn int controller_editarSeleccion(LinkedList*)
/// \brief
///
/// \param pArrayListSeleccion
/// \return
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/// \fn int controller_listarSelecciones(LinkedList*)
/// \brief Funcion que se encarga de mostrar las selecciones
///
/// \param pArrayListSeleccion lista de las selecciones a mostrar
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/// \fn int controller_ordenarSelecciones(LinkedList*)
/// \brief
///
/// \param pArrayListSeleccion
/// \return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/// \fn int controller_guardarSeleccionesModoTexto(char*, LinkedList*)
/// \brief Funcion que se encarga de guardar las selecciones en el archivo .csv
///
/// \param path ruta al archivo
/// \param pArrayListSeleccion lista de selecciones a guardar en el archivo
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/// \fn int controller_listarJugadoresYSeleccion(LinkedList*, LinkedList*)
/// \brief Funcion que se encarga de mostrar a los jugadores con su seleccion
///
/// \param pArrayListJugador lista de donde se sacan los jugadores
/// \param pArrayListSeleccion lista de donde se sacan las selecciones
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_listarJugadoresYSeleccion(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// \fn int controller_convocarJugadores(LinkedList*, LinkedList*)
/// \brief Funcion que permite convocar a un jugador a una seleccion
///
/// \param pArrayListJugador lista de los jugadores disponibles
/// \param pArrayListSeleccion lista de las selecciones disponibles
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_convocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// \fn int controller_desconvocarJugadores(LinkedList*, LinkedList*)
/// \brief Funcion que permite DesConvocar a un jugador de una seleccion
///
/// \param pArrayListJugador lista de los jugadores disponibles
/// \param pArrayListSeleccion lista de las selecciones disponibles
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_desconvocarJugadores(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// \fn int controller_listarJugadoresConvocados(LinkedList*, LinkedList*)
/// \brief Funcion que se encarga de listar los jugadores convocados
///
/// \param pArrayListJugador lista de los jugadores disponibles
/// \param pArrayListSeleccion lista de las selecciones disponibles
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/// \fn int controller_filtrarJugadoresConvocados(LinkedList*, LinkedList*, LinkedList*)
/// \brief Funcion que filtra jugadores convocados para una confederacion especifica
///
/// \param pArrayListJugador lista de los jugadores disponibles
/// \param pArrayListSeleccion lista de las selecciones disponibles
/// \param pArrayListConvocados lista de los jugadores convocados
/// \return devuelve -1 en caso de error y 1 en caso de exito
int controller_filtrarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados );

/// \fn int controller_detectarConvocados(LinkedList*)
/// \brief Funcion que se encarga de detectar si hay jugadores convocados
///
/// \param pArrayListSeleccion lista de las selecciones disponibles
/// \return devuelve -1 en caso de error, 0 en caso de que no haya jugadores convocados, o 1 si hay jugadores convocados en almenos una seleccion
int controller_detectarConvocados(LinkedList* pArrayListSeleccion);
