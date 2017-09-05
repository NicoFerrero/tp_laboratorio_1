#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include "funciones.h"

int LeerEntero(char msg[])
{
    int entero;
    printf("%s", msg);
    scanf("%d", &entero);
    return entero;
}

char LeerCaracter(char msg[])
{
    char caracter;
    printf("%s", msg);
    caracter = tolower(getche());
    return caracter;
}

float LeerFlotante(char msg[])
{
    float flotante;
    printf("%s", msg);
    scanf("%f", &flotante);
    return flotante;
}

int ValidarEntero(int entero, int inf, int sup)
{
    while(entero < inf || entero > sup)
    {
        printf("Error! Ingreso una opcion que no es valida, intentelo nuevamente: ");
        scanf("%d", &entero);
    }
    return entero;
}

char ValidarCaracter(char caracter)
{
    while(caracter != 's' && caracter != 'n')
    {
        printf("\nError! Ingreso una opcion que no es valida, intentelo nuevamente: ");
        caracter = tolower(getche());
    }
    return caracter;
}

void ValidarFactorial(float num1)
{
    float fact;
    if(num1 < 0)
    {
        printf("Error. No existe el factorial de un numero negativo\n");
    }
    else if(floor(num1) != num1)
    {
        printf("Error. Debe ingresar un numero natural para poder calcular el factorial.\n");
    }
    else
    {
        fact = Factorial(num1);
        printf("El factorial de %0.f es %0.f\n", num1, fact);
    }
}

float Sumar(float num1, float num2)
{
    float suma;
    suma = num1 + num2;
    return suma;
}

float Restar(float num1, float num2)
{
    float resta;
    resta = num1 - num2;
    return resta;
}

float Multiplicar(float num1, float num2)
{
    float multiplicacion;
    multiplicacion = num1 * num2;
    return multiplicacion;
}

void Dividir(float num1, float num2)
{
    float division;
    if(num2 == 0)
    {
        printf("Error. No existe la division por cero\n");
    }
    else
    {
        division = num1 / num2;
        printf("El resultado de la division entre %.2f y %.2f es igual a: %.2f\n", num1, num2, division);
    }
}

float Factorial(float num1)
{
    float auxiliar;
    if(num1 == 0)
        return 1;
    auxiliar = (float) num1 * Factorial(num1 - 1);
    return auxiliar;
}










