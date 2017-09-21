#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * \brief Inicializa el estado del array de estructura con el valor pasado como parametro
 * \param lista Es el array que se pasa como parametro
 * \param tam Es el tamaño del array
 * \param valor Es el valor que queremos cargar en el array
 * \return Void No devuelve nada
 */
void inicializarEstado(ePersona lista[], int tam, int valor);

/**
* \brief Obtiene el primer indice libre del array
* \param lista el array se pasa como parametro
* \param tam el tamaño del array que se paso como parametro
* \return el primer indice disponible
*/
int obtenerEspacioLibre(ePersona lista[],int tam);

/**
* \brief Obtiene el indice que coincide con el dni pasado por parametro
* \param lista el array se pasa como parametro
* \param tam tamaño del array pasado anteriormente
* \param dni el dni a ser buscado en el array
* \return el indice en donde se encuentra el elemento que coincide con el parametro 0 "-1" si no lo encuentra
*/
int buscarPorDni(ePersona lista[],int tam,int dni);

/**
 * \brief Agrega una persona al array
 * \param lista Es el array que se pasa como parametro
 * \param tam Es el tamaño del array
 * \return Devuelve "1" si dio de alta a una persona, "-1" si no dio de alta a una persona
 */
int agregarPersona(ePersona lista[], int tam);

/**
 * \brief Borra una persona del array
 * \param lista Es el array que se pasa como parametro
 * \param tam Es el tamaño del array
 * \return Devuelve "0" en caso de borrar exitosamente a la persona, "-1" si no logra borrar a la persona
 */
int borrarPersona(ePersona lista[], int tam);

/**
 * \brief Muestra el menu por pantalla
 * \param listado Es el listado de opciones que mostrara
 * \return Devuelve la opcion seleccionada por el usuario
 */
int menu(char listado[]);

/**
 *  \brief Ordena el array de estructura pasado como parametro y lo muestra por pantalla
 * \param lista Es el array que se pasa como parametro
 * \param tam Es el tamaño del array
 * \return Void No devuelve nada
 */
void ordenaMostrar(ePersona lista[], int tam);

/**
* \brief Imprime por pantalla un grafico segun las edades (menor de 18 años, entre 18 y 35 años y mayor de 35 años)
* \param lista Array de estructura EPersona pasado como parametro
* \param tam Tamaño del array lista
* \return Void No devuelve nada
*/
void graficoEdades(ePersona lista[],int tam);

#endif // FUNCIONES_H_INCLUDED
