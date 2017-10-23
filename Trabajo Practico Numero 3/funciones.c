#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int leercantidad()
{
    int cantidad = 0;
    FILE* miArchivo;

	miArchivo = fopen("cantidad.bin","rb");
	fread(&cantidad,sizeof(int),1,miArchivo);
	fclose(miArchivo);
	return cantidad;
}

void guardarCantidad(int cantidad)
{
    FILE* miArchivo;

	miArchivo = fopen("cantidad.bin", "wb");
	if(miArchivo == NULL)
	{
		printf("No se puede abrir el archivo");
	}
	fwrite(&cantidad,sizeof(int),1,miArchivo);
	fclose(miArchivo);
}

void cargarDesdeArchivo(eMovie* pelicula, int cantidad)
{
	FILE* miArchivo;

	miArchivo=fopen("peliculas.bin", "rb");
	if(miArchivo==NULL)
	{
            printf("No se puede abrir el archivo\n");
	}
	fread(pelicula,sizeof(eMovie),cantidad,miArchivo);
	fclose(miArchivo);
}

void intercambiar(eMovie* peliculaUno, eMovie* PeliculaDos)
{
    eMovie aux;

    aux = *peliculaUno;
    *peliculaUno = *PeliculaDos;
    *PeliculaDos = aux;
}

int agregarPelicula(eMovie* pelicula, int cantidad)
{
    int respuesta;

    pelicula = (eMovie*)realloc(pelicula,(cantidad+1)*sizeof(eMovie));

    if(pelicula == NULL)
    {
        printf("No se pudo asignar memoria\n");
        return 1;
    }

    respuesta = getStringValidado((pelicula+cantidad)->titulo,"Ingrese el titulo de la pelicula: ","\nEl titulo debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return 1;
    }

    respuesta = getStringLetras((pelicula+cantidad)->genero,"\nIngrese el genero de la pelicula: ","\nEl genero debe contener entre 1 y 20 caracteres",1,20);
    if(respuesta == -1)
    {
        return 1;
    }

    respuesta = getInt(&(pelicula+cantidad)->duracion,"\nIngrese la duracion de la pelicula (en minutos): ","\nLa duracion debe estar comprendida en entre 60 y 240 minutos",60,240);
    if(respuesta == -1)
    {
        return 1;
    }

    respuesta = getStringValidado((pelicula+cantidad)->descripcion,"\nIngrese una breve descripcion de la pelicula: ","\nLa descripcion debe contener entre 1 y 300 caracteres",1,300);
    if(respuesta == -1)
    {
        return 1;
    }

    respuesta = getFloat(&(pelicula+cantidad)->puntaje,"\nIngrese el puntaje de la pelicula: ","\nEl puntaje debe estar comprendido entre 1 y 10 puntos",1,10);
    if(respuesta == -1)
    {
        return 1;
    }

    respuesta = getStringValidado((pelicula+cantidad)->linkImagen,"\nIngrese el link de la imagen para la pelicula: ","\nEl link debe contener entre 1 y 300 caracteres",1,500);
    if(respuesta == -1)
    {
        return 1;
    }

    return 0;
}

int borrarPelicula(eMovie* pelicula, int cantidad)
{
    int i;
    int respuesta;
    char aux[50];
    char seguir;

    printf("\t\tPELICULAS EN CARTELERA\n\n");
    for(i=0;i<cantidad;i++)
    {
        printf((pelicula+i)->titulo);
        printf("\n");
    }

    respuesta = getStringValidado(aux,"\nIngrese el titulo de la pelicula que desea borrar: ","\nEl titulo debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return 1;
    }

    for(i=0;i<cantidad;i++)
    {
        if(strcmpi(aux,(pelicula+i)->titulo) == 0)
        {
            respuesta = getSN(&seguir,"Realmente desea borrar la pelicula? (s/n): ","\nLa opcion ingresada no es valida");
            if(respuesta == -1)
            {
                return 1;
            }
            if(seguir == 's')
            {
                intercambiar((pelicula+i),(pelicula+cantidad));
                pelicula = (eMovie*)realloc(pelicula,(cantidad-1)*sizeof(eMovie));
                cantidad--;
                return 0;
            }
            else
            {
                printf("\nEl usuario cancelo la elimiancion de la pelicula");
                return 1;
            }
        }
    }
    printf("La pelicula no se encuentra el listado de peliculas");
    return 1;
}

int modificarPelicula(eMovie* pelicula, int cantidad)
{
    int i;
    int flag = 1;
    int respuesta;
    char aux[50];
    int opcion;

    printf("\t\tPELICULAS EN CARTELERA\n\n");
    for(i=0;i<cantidad;i++)
    {
        printf((pelicula+i)->titulo);
        printf("\n");
    }

    respuesta = getStringValidado(aux,"Ingrese el titulo de la pelicula que desea modificar: ","\nEl titulo debe contener entre 1 y 50 caracteres",1,50);
    if(respuesta == -1)
    {
        return 1;
    }

    for(i=0;i<cantidad;i++)
    {
        if(strcmpi(aux,(pelicula+i)->titulo) == 0)
        {
            system("cls");
            printf("\t\tMENU DE MODIFICACION\n");
            opcion = menu("\n1- Titulo \n2- Genero \n3- Duracion \n4- Descripcion \n5- Puntaje \n6- Link de la caratula \nIngrese una opcion: ");

            switch(opcion)
            {
                case 1:
                    system("cls");
                    respuesta = getStringValidado((pelicula+i)->titulo,"Ingrese el nuevo titulo de la pelicula: ","\nEl titulo debe contener entre 1 y 50 caracteres",1,50);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                case 2:
                    system("cls");
                    respuesta = getStringLetras((pelicula+i)->genero,"Ingrese el nuevo genero de la pelicula: ","\nEl genero debe contener entre 1 y 20 caracteres",1,20);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                case 3:
                    system("cls");
                    respuesta = getInt(&(pelicula+i)->duracion,"Ingrese la nueva duracion de la pelicula (en minutos): ","\nLa duracion debe estar comprendida en entre 60 y 240 minutos",60,240);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                case 4:
                    system("cls");
                    respuesta = getStringValidado((pelicula+i)->descripcion,"Ingrese la nueva descripcion de la pelicula: ","\nLa descripcion debe contener entre 1 y 300 caracteres",1,300);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                case 5:
                    system("cls");
                    respuesta = getFloat(&(pelicula+i)->puntaje,"Ingrese el nuevo puntaje de la pelicula: ","\nEl puntaje debe estar comprendido entre 1 y 10 puntos",1,10);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                case 6:
                    system("cls");
                    respuesta = getStringValidado((pelicula+i)->linkImagen,"Ingrese el link de la imagen para la pelicula: ","\nEl link debe contener entre 1 y 300 caracteres",1,500);
                    if(respuesta == -1)
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                    break;

                default:
                    system("cls");
                    printf("Ingreso una opcion que no es valida\n");
                    system("pause");
                    break;
            }
        }
    }
    if(flag == 1)
    {
            printf("La pelicula no se encuentra el listado de peliculas");
    }
    return flag;
}

void generarPagina(eMovie* pelicula, char nombre[], int cantidad)
{
    FILE* miArchivo;
    char aux[100];
    int i=0;
    strcpy(aux,nombre);
    strcat(aux,".html");
    miArchivo=fopen(aux,"w");
    if(miArchivo==NULL)
    {
        printf("No se pudo generar pagina\n");
    }
    fprintf(miArchivo,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for(i=0;i<cantidad;i++)
    {
       fprintf(miArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=' '></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%.2f</li><li>Duracion:%d</li></ul><p>%s</p></article>",(pelicula+i)->linkImagen,(pelicula+i)->titulo,(pelicula+i)->genero,(pelicula+i)->puntaje,(pelicula+i)->duracion,(pelicula+i)->descripcion);
    }
    fprintf(miArchivo,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
}

void guardarPelicula(eMovie* pelicula,int cantidad)
{
	FILE* miArchivo;
	miArchivo = fopen("peliculas.bin","wb");
	if(miArchivo == NULL)
	{
		printf("No se pudo crear el archivo\n");
	}
	fwrite(pelicula, sizeof(eMovie),cantidad,miArchivo);
	guardarCantidad(cantidad);
	printf("\nPelicula guardada con exito\n");
	fclose(miArchivo);
}

int menu(char listado[])
{
    int opcion;
    char aux[50];

    printf("%s", listado);
    fflush(stdin);
    gets(aux);
    if(!esNumerico(aux))
    {
        opcion = atoi(aux);
        return opcion;
    }
    else
    {
        system("cls");
        printf("El menu solo admite numeros enteros\n");
        system("pause");
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getInt(int* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    int aux;
    char auxChar[500];

    getString(mensaje,auxChar);
    if(esNumerico(auxChar) == -1)
    {
        printf("\nEste campo debe contener solo numeros");
        return -1;
    }
    aux = atoi(auxChar);
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

int getFloat(float* input,char mensaje[],char eMensaje[],float lowLimit,float hiLimit)
{
    float aux;
    char auxChar[500];

    getString(mensaje,auxChar);
    if(esNumerico(auxChar) == -1)
    {
        printf("\nEste campo debe contener solo numeros");
        return -1;
    }
    aux = atof(auxChar);
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

int getStringLetras(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    char aux[50];
    char auxLetras[256];

    getString(mensaje,auxLetras);
    if(esSoloLetras(auxLetras) == -1)
    {
        printf("\nEste campo debe contener solo letras");
        return -1;
    }
    strcpy(aux,auxLetras);
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

int getStringValidado(char* input,char mensaje[],char eMensaje[],int lowLimit,int hiLimit)
{
    char aux[500];

    printf("%s",mensaje);
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

void getString(char mensaje[], char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getSN(char* input, char mensaje[], char eMensaje[])
{
    char aux;
    printf("%s", mensaje);
    aux = tolower(getche());
    if(aux != 's' && aux != 'n')
    {
        printf("%s", eMensaje);
        return 1;
    }
    else
    {
        *input = aux;
        return 0;
    }
}

int esNumerico(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        if((string[i] != '.') && (string[i] < '0' || string[i] > '9'))
        {
            return -1;
        }
        i++;
    }
    return 0;
}

int esSoloLetras(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            return -1;
        }
        i++;
    }
    return 0;
}
