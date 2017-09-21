#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "funciones.h"

void inicializarEstado(ePersona lista[], int tam, int valor)
{
    int i;

    for(i=0;i<tam;i++)
    {
        lista[i].estado = valor;
    }
}

int obtenerEspacioLibre(ePersona lista[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorDni(ePersona lista[],int tam,int dni)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].dni == dni)
        {
            return i;
        }
    }
    printf("\nDNI no encontrado");
    return -1;
}

int agregarPersona(ePersona lista[], int tam)
{
    int i;
    int respuesta;

    i = obtenerEspacioLibre(lista,tam);
    if(i == -1)
    {
        printf("Error. Lista llena");
        return -1;
    }

    respuesta = getString(lista[i].nombre,"Ingrese el nombre: ","\nError. El nombre debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return -1;
    }

    respuesta = getInt(&lista[i].edad,"Ingrese la edad: ","\nError. La edad debe estar comprendida entre 1 y 100",1,100);
    if(respuesta == -1)
    {
        return -1;
    }

    respuesta = getInt(&lista[i].dni,"Ingrese el DNI (sin puntos): ","\nError. DNI incorrecto",1000000,99999999);
    if(respuesta == -1)
    {
        return -1;
    }
    lista[i].estado = 1;
    return 0;
}

int borrarPersona(ePersona lista[], int tam)
{
    int i;
    int dni;
    char respuesta;

    printf("Ingrese el DNI de la persona a borrar: ");
    scanf("%d", &dni);
    i = buscarPorDni(lista,tam,dni);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        system("cls");
        printf("Nombre: %s",lista[i].nombre);
        printf("\nDNI: %d",lista[i].dni);
        printf("\nEdad: %d",lista[i].edad);
        getSN(&respuesta,"\nEsta seguro que desea eliminar? s/n","\nError. Opcion no valida");
        if(respuesta == 's')
        {
            lista[i].estado = 0;
            return 0;
        }
        return 1;

    }
}

int menu(char listado[])
{
    int opcion;

    printf("%s", listado);
    scanf("%d", &opcion);
    return opcion;
}

void ordenaMostrar(ePersona lista[], int tam)
 {
     int i;
     int j;
     ePersona listaAux;

     for(i=0;i<tam-1;i++)
     {
         for(j=i+1;j<tam;j++)
         {
             if(strcmpi(lista[i].nombre,lista[j].nombre) > 0)
             {
                 listaAux = lista[i];
                 lista[i] = lista[j];
                 lista[j] = listaAux;
             }
         }
     }
    system("cls");
    printf("%-50s %10s %5s\n","Nombre","Edad","DNI");
     for(i=0;i<tam;i++)
     {
         if(lista[i].estado == 1)

         printf("%-50s %10d %5d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
     }
 }

void graficoEdades(ePersona lista[],int tam)
{
    int i;
    int max;
    int contMenores=0;
    int contHastaTC=0;
    int contMasTC=0;

    system("cls");
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado != 0 && lista[i].edad < 18)
        {
            contMenores++;
        }
        if(lista[i].estado != 0 && lista[i].edad >= 18 && lista[i].edad <= 35)
        {
            contHastaTC++;
        }
        if(lista[i].estado != 0 && lista[i].edad > 35)
        {
            contMasTC++;
        }
    }

    if(contMenores > contHastaTC && contMenores > contMasTC) //Calcula que rango de edades tiene mayor cantidad de pèrsonas
    {
        max = contMenores;
    }
    else if(contHastaTC > contMasTC)
    {
        max = contHastaTC;
    }
    else
    {
        max = contMasTC;
    }

    for(i=max;i>0;i--)
    {
        if(i <= contMenores)
        {
            printf("  *");
        }

        if(i <= contHastaTC)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t");
        }

        if(i <= contMasTC)
        {
            printf("\t  *");
        }

        printf("\n");
    }
    printf(" <18 \t18-35\t>35\n");
}
