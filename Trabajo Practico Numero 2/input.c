#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    int aux;

    printf("%s", mensaje);
    scanf("%d", &aux);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}


/**
* \brief Solicita un numero al usuario y lo valida
* \param input se carga el numero ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit limite inferior a validar
* \param hiLimit limite superior a validar
* \return si obtuvo el numero devuelve "0", en caso contrario devuelve "-1"
*/
int getfloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit)
{
    float aux;

    printf("%s", mensaje);
    scanf("%f", &aux);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}


/**
* \brief Solicita una cadena de caracteres al usuario y lo valida
* \param input se carga el string ingresado
* \param mensaje es el mensaje a ser mostrado
* \param eMensaje es el mensaje a ser mostrado en caso de error
* \param lowLimit longitud minima de la cadena
* \param hiLimit longitud maxima de la cadena
* \return si obtuvo la cadena devuelve "0", en caso contrario devuelve "-1"
*/
int getString(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    char aux[50];

    printf("%s", mensaje);
    fflush(stdin);
    gets(aux);
    if(strlen(aux) < lowLimit || strlen(aux) > hiLimit)
    {
        printf("%s", eMensaje);
        return -1;
    }
    else
    {
        strcpy(input,aux);
        return 0;
    }
}

/**
* \brief Solicita S o N al usuario y la valida
* \param input Se carga el caracter validado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \return Si obtuvo un caracter valido [0] si no [-1]
*
*/
int getSN(char* input, char message[], char eMessage[])
{
    char aux;
    printf("%s", message);
    aux = tolower(getche());
    if(aux != 's' && aux != 'n')
    {
        printf("%s", eMessage);
        return -1;
    }
    else
    {
        *input = aux;
        return 1;
    }
}
