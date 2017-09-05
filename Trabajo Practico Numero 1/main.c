#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 'n';
    int opcion;
    float numeroUno = 0;
    float numeroDos = 0;
    float suma;
    float resta;
    float multiplicacion;

    while(seguir == 'n')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A= %.2f)\n", numeroUno);
        printf("2- Ingresar 2do operando (B= %.2f)\n", numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la multiplicacion (A*B)\n");
        printf("6- Calcular la division (A/B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        opcion = LeerEntero("Ingrese una opcion (1-9): ");
        opcion = ValidarEntero(opcion, 1, 9);

        switch(opcion)
        {
            case 1:
                system("cls");
                numeroUno = LeerFlotante("Ingrese el primer operando: ");
                break;
            case 2:
                system("cls");
                numeroDos = LeerFlotante("Ingrese el segundo operando: ");
                break;
            case 3:
                system("cls");
                suma = Sumar(numeroUno, numeroDos);
                printf("El resultado de la suma entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, suma);
                system("pause");
                break;
            case 4:
                system("cls");
                resta = Restar(numeroUno, numeroDos);
                printf("El resultado de la resta entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, resta);
                system("pause");
                break;
            case 5:
                system("cls");
                multiplicacion = Multiplicar(numeroUno, numeroDos);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, multiplicacion);
                system("pause");
                break;
            case 6:
                system("cls");
                Dividir(numeroUno, numeroDos);
                system("pause");
                break;
            case 7:
                system("cls");
                ValidarFactorial(numeroUno);
                system("pause");
                break;
            case 8:
                system("cls");
                suma = Sumar(numeroUno, numeroDos);
                printf("El resultado de la suma entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, suma);
                resta = Restar(numeroUno, numeroDos);
                printf("El resultado de la resta entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, resta);
                multiplicacion = Multiplicar(numeroUno, numeroDos);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es igual a: %.2f\n", numeroUno, numeroDos, multiplicacion);
                Dividir(numeroUno, numeroDos);
                ValidarFactorial(numeroUno);
                system("pause");
                break;
            case 9:
                seguir = LeerCaracter("Realmente desea salir? (s/n): ");
                seguir = ValidarCaracter(seguir);
                break;
        }

     }
    return 0;
}
