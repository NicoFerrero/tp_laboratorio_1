#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide por consola el ingreso de un numero entero y lo devuelve
 *
 * \param msg Es el mensaje para que el usuario sepa que va a ingresar
 * \return Devuelve el numero entero ingresado por el usuario
 *
 */
int LeerEntero(char msg[]);

/** \brief Pide por consola el ingreso de un caracter y lo devuelve
 *
 * \param msg Es el mensaje para que el usuario sepa que va a ingresar
 * \return Devuelve el caracter ingresado por el usuario
 *
 */
char LeerCaracter(char msg[]);

/** \brief Pide por consola el ingreso de un numero flotante y lo devuelve
 *
 * \param msg Es el mensaje para que el usuario sepa que va a ingresar
 * \return Devuelve el numero flotante ingresado por el usuario
 *
 */
float LeerFlotante(char msg[]);

/** \brief Verifica que un numero entero este dentro del rango permitidio
 *
 * \param entero Es el entero que queremos validar
 * \param inf Es el limite inferior del rango de validacion del entero
 * \param sup Es el limite superior del rango de validacion del entero
 * \return Devuelve el entero validado
 *
 */
int ValidarEntero(int entero, int inf, int sup);

/** \brief Verifica que se haya ingresado uno de los dos caracteres posibles (s o n)
 *
 * \param caracter Es el caracter que queremos validar
 * \return Devuelve el caracter validado
 *
 */
char ValidarCaracter(char caracter);

/**
*\brief Valida el numero a calcular el factorial, lo calcula e imprime el resultado
*\param num1 Es el numero a calcular el factorial
*\return No devuelve ningun valor, imprime por pantalla el resultado del factorial
*
*/
void ValidarFactorial(float num1);

/** \brief Realiza la suma de dos numeros y devuelve el resultado
 *
 * \param num1 Es el primer operando de la suma
 * \param num2 Es el segundo operando de la suma
 * \return Devuelve la suma de los dos numeros
 *
 */
float Sumar(float num1, float num2);

/** \brief Realiza la resta de dos numeros y devuelve el resultado
 *
 * \param num1 Es el primer operando de la resta
 * \param num2 Es el segundo operando de la resta
 * \return Devuelve la resta de los dos numeros
 *
 */
float Restar(float num1, float num2);

/** \brief Realiza la multiplicacion de dos numeros y devuelve el resultado
 *
 * \param num1 Es el primer operando de la multiplicacion
 * \param num2 Es el segundo operando de la multiplicacion
 * \return Devuelve la multiplicacion de los dos numeros
 *
 */
float Multiplicar(float num1, float num2);

/** \brief Realiza la division de dos numeros y devuelve el resultado
 *
 * \param num1 Es el primer operando de la division
 * \param num2 Es el segundo operando de la division
 * \return Devuelve la division de los dos numeros
 *
 */

/**
*\brief Realiza la division de dos numeros y devuelve el resultado
*\param num1 Es el numero a dividir
*\param num2 Es el numero por el cual se va a dividir, este nuero debe ser distinto a 0
*\return No devuelve ningun valor, imprime por pantalla el resultado de la division
*
*/
void Dividir(float num1, float num2);

/**
*\brief Calcula el factorial de un numero y devuelve por return
*\param num1 Es el numero a calcular el factorial
*\return Devuelve el factorial del numero ingresado
*
*/
float Factorial(float num1);




#endif // FUNCIONES_H_INCLUDED
