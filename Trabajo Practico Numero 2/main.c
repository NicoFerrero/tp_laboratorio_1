#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"
#define TAM 5


int main()
{
    char salir = 'n';
    int opcion = 0;
    int respuesta;
    ePersona alumnos[TAM];

    inicializarEstado(alumnos, TAM, 0);

    while(salir == 'n')
    {
        system("cls");
        opcion = menu("1 - Agregar persona \n2 - Borrar persona \n3 - Imprimir lista ordenada por nombre \n4 - Imprimir grafico de edades \n5 - Salir \nIngrese una opcion: ");

        switch(opcion)
        {
            case 1:
                system("cls");
                respuesta = agregarPersona(alumnos, TAM);
                if(respuesta == 0)
                {
                    printf("\nPersona agregada con exito\n");
                    system("pause");
                }
                else
                {
                    printf("\nPersona no agregada\n");
                    system("pause");
                }
                break;

            case 2:
                system("cls");
                respuesta = borrarPersona(alumnos,TAM);
                if(respuesta == 0)
                {
                    printf("\nPersona borrada con exito\n");
                    system("pause");
                }
                else
                {
                    printf("\nPersona no fue borrada\n");
                    system("pause");
                }
                break;

            case 3:
                ordenaMostrar(alumnos, TAM);
                system("pause");
                break;
            case 4:
                graficoEdades(alumnos, TAM);
                system("pause");
                break;

            case 5:
                system("cls");
                respuesta = getSN(&salir,"Esta seguro que desea salir? s/n ","\nError. Debe ingresar s/n\n");
                if(respuesta == -1)
                {
                    system("pause");
                }
                break;

            default:
                system("cls");
                printf("Error. Opcion no valida");
                printf("\nIngrese una opcion entre 1 y 5\n");
                system("pause");
                break;
        }
    }
    return 0;
}
