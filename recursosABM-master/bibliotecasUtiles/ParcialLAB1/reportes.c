#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int listarActoresPorGenero(ePelicula listadoPel[], eActor listadoAct[], int len,  char generoAlistar[21])
{
    int i;
    int posActorDeGenero;
    printf("Actores que trabajaron en peliculas de %s \n", generoAlistar);
    for(i = 0; i<len; i++)
    {
        if(listadoPel[i].estado == 0 && stricmp(generoAlistar, listadoPel[i].genero)==0)
        {
            posActorDeGenero = buscarActorPorID(listadoAct, len, listadoPel[i].idActor);
            printf("%10s \n",listadoAct[posActorDeGenero].nombreActor);

        }


    }
    return 0;
}

int mostrarPeliculasConActores(ePelicula listadoPeliculas[], eActor listadoActores[], int len)
{
    int i;
    int posActor;
    printf("%s\t %s\t %s\t\t %s\t %s\t %s\t \n", "ID", "Codigo", "titulo", "Fecha", "Genero", "Actor");


    for(i = 0; i < len; i++)
    {
        if(listadoPeliculas[i].estado == 0)
        {

            posActor = buscarActorPorID(listadoActores, len, listadoPeliculas[i].idActor);


            printf("%d\t %d\t %s\t %d\t %s\t %s\t \n", listadoPeliculas[i].id, listadoPeliculas[i].codigoPelicula, listadoPeliculas[i].titulo, listadoPeliculas[i].fechaDeEstreno, listadoPeliculas[i].genero, listadoActores[posActor].nombreActor);

        }

    }


    return 0;
}


int listarPeliculasPorNacionalidad(ePelicula listadoPel[], eActor listadoAct[], int len,  char nacionalidadAlistar[21])
{
    int i;
    int j;

    printf("Peliculas que trabajaron actores de de %s \n", nacionalidadAlistar);

    for(i = 0; i<len; i++)
    {
        if(listadoAct[i].estado == 0 && stricmp(nacionalidadAlistar, listadoAct[i].nacionalidad)==0)
        {
            for(j = 0; j<len; j++)
            {
                if(listadoPel[j].idActor == listadoAct[i].id)
                    printf("%10s \n",listadoPel[j].titulo);
            }


        }

    }
    return 0;
}

int listarPeliculasPorNacionalidadIngresada(ePelicula listadoPel[], eActor listadoAct[], int len,  char nacionalidadAlistar[21])
{
    int i;
    int j;
    int existen = 0;

    //printf("Peliculas que trabajaron actores de %s \n", nacionalidadAlistar);

    for(i = 0; i<len; i++)
    {

        if(listadoAct[i].estado == 0 && stricmp(nacionalidadAlistar, listadoAct[i].nacionalidad)==0)
        {
            for(j = 0; j<len; j++)
            {
                if(listadoPel[j].idActor == listadoAct[i].id)
                printf("%2s \n",listadoPel[j].titulo);

            }

           existen = 1;
        }
        printf("\n");
    }

    if(existen == 0)
    {
         printf("\n No hay peliculas con actores de esa nacionalidad\n\n");
    }



    return 0;
}

void peliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21])
{
    printf(" %s %s  \n", "Peliculas del genero: ", generoAlistar);
    int i;
    for(i = 0; i<len; i++)
        if(listadoPel[i].estado == 0 && stricmp(generoAlistar, listadoPel[i].genero)==0)
        {
            printf("%s  \n", listadoPel[i].titulo);
        }
    printf("\n");

}

void cantidadpeliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21])
{
    int i;
    int cont = 0;
    for(i = 0; i<len; i++)
    {
        if(listadoPel[i].estado == 0 && stricmp(generoAlistar, listadoPel[i].genero)==0)
        {
            cont++;
        }
    }
    printf("%s  %d %s %s \n", "Hay", cont, " peliculas de ", generoAlistar);
    printf("\n");
}
