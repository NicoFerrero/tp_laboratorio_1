#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int duracion;
    float puntaje;
    char titulo[51];
    char genero[21];
    char descripcion[301];
    char linkImagen[501];
}eMovie;

/**
 * \brief Se encarga de ver cuantas peliculas hay guardadas y devolver la cantidad
 * \return Devueve la cantidad de peliculas que hay cargadas
 */
int leercantidad();

/**
 * \brief Se encarga de guardar la cantidad de peliculas en un archivo binario
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 * \return Void No devuelve nada
 */
void guardarCantidad(int cantidad);

/**
 * \brief Se encarga de guardar la cartelera en un archico binario
 * \param pelicula Es el puntero que apunta a la estrutura emovie
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 * \return Void No devuelve nada
 */
void guardarPelicula(eMovie* pelicula,int cantidad);

/**
 * \brief Trae las peliculas del archivo binario
 * \param pelicula Es el puntero que apunta a la estrutura emovie
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 * \return Void No devuelve nada
 */
void cargarDesdeArchivo(eMovie* pelicula, int cantidad);

/**
 * \brief Se encarga de intercambiar dos memorias de lugar
 * \param peliculaUno Recibe el primer valor a intercambiar
 * \param PeliculaDos Recibe el segundo valor a intercambiar
 * \return Void No devuelve nada
 */
void intercambiar(eMovie* peliculaUno, eMovie* PeliculaDos);

/**
 *  \brief Agrega una pelicula
 *  \param pelicula La estructura a ser agregada al archivo
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 *  \return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie* pelicula, int cantidad);

/**
 *  \brief Borra una pelicula
 *  \param pelicula La estructura a ser agregada al archivo
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 *  \return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie* pelicula, int cantidad);

/**
 * \brief Se encarga de modificar una de las peliculas ingresadas
 *  \param pelicula La estructura a ser agregada al archivo
 * \param cantidad Es la cantidad de peliculas que hay guardadas
 *  \return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(eMovie* pelicula, int cantidad);

/**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param pelicula La estructura a ser agregada al archivo
 *  \param nombre Es el nombre que va a tener el archivo
 *  \return Void No devuelve nada
 */
void generarPagina(eMovie* pelicula, char nombre[], int cantidad);

/**
 * \brief Muestra el menu por pantalla
 * \param listado Es el listado de opciones que mostrara
 * \return Devuelve la opcion seleccionada por el usuario
 */
int menu(char listado[]);

/**
* \brief Solicita s o n al usuario y la valida
* \param input Se carga el caracter validado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \return Si obtuvo un caracter valido 0 si no -1
*/
int getSN(char* input, char message[], char eMessage[]);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getFloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getStringLetras(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getStringValidado(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit);

/**
 * \brief Solicita una cadena de caracteres al usuario
 * \param mensaje Es el mensaje a  ser mostrado
 * \param input Array donde se cargara la cadena
 * \return Void No devuelve nada
 */
void getString(char mensaje[], char input[]);

/**
 * \brief Verifica si el valor recibido es numerico entero
 * \param string Es el array con la cadena a ser analizada
 * \return Si es numerico devuelve "0" si no lo es devuelve "-1"
 */
int esNumerico(char string[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param string Es el array con la cadena a ser analizada
 * \return Si contiene solo letras devuelbe "0" en caso contrario devuelve "-1"
 */
int esSoloLetras(char string[]);

#endif // FUNCIONES_H_INCLUDED
