#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char salir = 'n';
    char guardar;
    int opcion;
    int respuesta;
    int cantidad;
    char nombre[50];
    eMovie* peliculas;

    cantidad = leercantidad();

    peliculas = (eMovie*)malloc((cantidad+1)*sizeof(eMovie));
    if(peliculas == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
    }
    if(cantidad != 0)
    {
        cargarDesdeArchivo(peliculas,cantidad);
        printf("Se cargaron las peliculas con exito\n");
        system("pause");
    }

    while(salir=='n')
    {
        system("cls");
        opcion = menu("1- Agregar pelicula \n2- Borrar pelicula \n3- Modificar pelicula \n4- Generar pagina web \n5- Guardar \n6- Salir \nIngrese una opcion: ");

        switch(opcion)
        {
            case 1:
                system("cls");
                respuesta = agregarPelicula(peliculas,cantidad);
                if(respuesta == 0)
                {
                    printf("\nLa pelicula ha sido agregada con exito\n");
                    cantidad++;
                }
                else
                {
                    printf("\nLa pelicula no ha sido agregada\n");
                }
                system("pause");
                break;

            case 2:
                system("cls");
                if(cantidad != 0)
                {
                    if(borrarPelicula(peliculas,cantidad) == 0)
                    {
                        printf("\nLa pelicula ha sido borrada con exito\n");
                        cantidad--;
                    }
                    else
                    {
                        printf("\nLa pelicula no ha sido borrada\n");
                    }
                }
                else
                {
                    printf("\nNo hay peliculas en cartelera. Realice un ingreso primero\n");
                }
                system("pause");
                break;

            case 3:
                system("cls");
                if(cantidad!=0)
                {
                   if(modificarPelicula(peliculas,cantidad) == 0)
                    {
                        printf("\nLa pelicula ha sido modificada con exito\n");
                    }
                    else
                    {
                        printf("\nLa pelicula no ha sido modificada\n");
                    }
                }
                else
                {
                    printf("\nNo hay peliculas en cartelera. Realice un ingreso primero\n");
                }
                system("pause");
               break;

            case 4:
                system("cls");
                if(cantidad!=0)
                {
                    getString("Ingrese el titulo del archivo html: ",nombre);
                    generarPagina(peliculas,nombre,cantidad);
                }
                else
                {
                    printf("No hay peliculas en cartelera. Realice un ingreso primero\n");
                }
                system("pause");
                break;

            case 5:
                system("cls");
                respuesta = getSN(&guardar,"Desea guardar los cambios realizados? s/n: ","ERROR. Opcion no valida");
                if(guardar == 's')
                {
                    guardarPelicula(peliculas,cantidad);
                }
                system("pause");
                break;

            case 6:
                system("cls");
                respuesta = getSN(&guardar,"Desea guardar los cambios realizados? s/n: ","ERROR. Opcion no valida");
                if(guardar == 's')
                {
                    guardarPelicula(peliculas,cantidad);
                    free(peliculas);
                }
                respuesta = getSN(&salir,"\nRealmente desea salir? s/n: ","ERROR. Opcion no valida");
                break;

            default:
                system("cls");
                printf("Ingreso una opcion que no es valida\n");
                system("pause");
                break;
        }
    }

    return 0;
}
