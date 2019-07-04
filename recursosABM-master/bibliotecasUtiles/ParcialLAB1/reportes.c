#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void listarActoresPorGenero(ePelicula listadoPel[], eActor listadoAct[], int len,  char generoAlistar[21])
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

}

int mostrarPeliculasConActores(ePelicula listadoPeliculas[], eActor listadoActores[], int len)
{
    int i;
    int posActor;
    printf("%s\t %s\t %15s  %s\t\t %s\t\t %15s \n", "ID", "Codigo", "titulo", "Fecha", "Genero", "Actor");


    for(i = 0; i < len; i++)
    {
        if(listadoPeliculas[i].estado == 0)
        {

            posActor = buscarActorPorID(listadoActores, len, listadoPeliculas[i].idActor);


            printf("%d\t %d\t %15s %d\t\t %s %30s\t \n", listadoPeliculas[i].id, listadoPeliculas[i].codigoPelicula, listadoPeliculas[i].titulo, listadoPeliculas[i].fechaDeEstreno, listadoPeliculas[i].genero, listadoActores[posActor].nombreActor);

        }

    }


    return 0;
}


int listarPeliculasPorNacionalidad(ePelicula listadoPel[], eActor listadoAct[], int len,  char nacionalidadAlistar[21])
{
    int i;
    int j;

    printf("Peliculas que trabajaron actores de %s \n", nacionalidadAlistar);

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

    printf("Peliculas que trabajaron actores de %s :\n", nacionalidadAlistar);

    for(i = 0; i<len; i++)
    {

        if(listadoAct[i].estado == 0 && stricmp(nacionalidadAlistar, listadoAct[i].nacionalidad)==0)
        {
            for(j = 0; j<len; j++)
            {
                if(listadoPel[j].idActor == listadoAct[i].id)
                {
                    printf("%s \n",listadoPel[j].titulo);
                }


            }

            existen = 1;
        }
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



int participaciones(ePelicula listadoPel[], int len, int idAcontar)
{
    int i;
    int participaciones = 0;

    for(i = 0; i<len; i++)
    {
        if(listadoPel[i].estado == 0 && listadoPel[i].idActor == idAcontar)
        {
            participaciones++;

        }

    }

    return participaciones;

}

void actoresMasParticipativos(ePelicula listadoPel[], eActor listadoAct[], int len)
{
    int i;
    int j;
    int cantidad;
    int auxCantidad;


    for(i=0; i<len; i++)
    {
        auxCantidad = participaciones(listadoPel, len, listadoAct[i].id);


        if(i == 0 || auxCantidad > cantidad)
        {
            cantidad = auxCantidad;
        }
    }

    printf("%s \n","Actores con mas participaciones:");

    for(j = 0; j<len; j++)
    {
        auxCantidad = participaciones(listadoPel, len, listadoAct[j].id);

        if(listadoAct[j].estado == 0 && auxCantidad == cantidad)
        {
            printf("%s \n",listadoAct[j].nombreActor);
        }
    }


}


int cantidadPeliculasPorGenero(ePelicula listadoPel[], int len, char generoAcontar[21])
{
    int i;
    int cant = 0;
    for(i = 0; i<len; i++)
    {
        if(listadoPel[i].estado == 0 && stricmp(generoAcontar, listadoPel[i].genero)==0)
        {
            cant++;
        }
    }

    return cant;
}

void generoConMenosPeliculas(ePelicula listadoPel[], int len)
{
    int a[5];
    char b[5][21] = { "Accion", "Terror", "Romantica", "Comedia", "Otro" };
    int i,j;
    int cantidad;

    for(i=0; i<5; i++)
    {
        a[i] = cantidadPeliculasPorGenero(listadoPel, len, b[i]);
    }

    for(i = 0; i<5; i++)
    {
        if(i == 0|| cantidad > a[i])
        {
            cantidad = a[i];
        }
    }

    printf("%s \n", "Generos con menos peliculas: ");

    for(j = 0; j<5; j++)

    {
        if(a[j] == cantidad)
        {
            printf("%s \n", b[j]);
        }
    }




}

void actoresQueNoTrabajaron(ePelicula listadoPel[], eActor listadoAct[], int len)
{
    int i;
    int auxCantidad = 0;

    printf("%s \n","Actores sin participacion: ");

    for(i=0; i<len; i++)
    {
        auxCantidad = participaciones(listadoPel, len, listadoAct[i].id);

        if(listadoAct[i].estado == 0 && auxCantidad == 0)
        {
            printf("%s \n", listadoAct[i].nombreActor);
        }

    }



}

void actoresAntesDeFecha(ePelicula listadoPel[], eActor listadoAct[], int len, int fecha)
{
    int i;
    int posActor;

    printf("%s %d\n", "Actores de antes del ", fecha);

    for(i = 0; i<len; i++)
    {
        if(listadoPel[i].estado == 0 && listadoPel[i].fechaDeEstreno < fecha)
        {
            posActor = buscarActorPorID(listadoAct, len, listadoPel[i].idActor);

            printf("%s \n", listadoAct[posActor].nombreActor);

        }
    }

}



void peliculasAgrupadasPorActor(ePelicula listadoPel[], eActor listadoAct[], int len, int idDeActor)
{

    int actorSub = buscarActorPorID(listadoAct, len, idDeActor);
    int i;
    int existen = 0;
    printf(" %s %s  \n", "Peliculas del actor: ", listadoAct[actorSub].nombreActor);

    for(i = 0; i<len; i++)
    {


        if(listadoPel[i].estado == 0 && listadoPel[i].idActor == idDeActor)
        {
            printf("%s  \n", listadoPel[i].titulo);
            existen = 1;
        }
    }
    if(existen == 0)
    {
        printf("\n No hay peliculas con ese actor\n");
    }

    printf("\n");

}


void actoresViejoAjoven(eActor listadoAct[], int len)
{
    int i, j;
    eActor aux;
    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listadoAct[i].edad < listadoAct[j].edad)
            {
                aux = listadoAct[i];
                listadoAct[i] = listadoAct[j];
                listadoAct[j] = aux;
            }
        }
    }
    mostrarListadoActores(listadoAct, len);
}

void actoresMayoresDeEdad(eActor listadoAct[], int len)
{

    int i;
    int edadMax;

    printf("%s \n","Actores con mayoria de edad:");
    for(i=0; i<len; i++)
    {
        if(i == 0 || listadoAct[i].edad >= 18)
        {
            edadMax = i;

            if(listadoAct[i].estado == 0)
            {
                printf("%s \n",listadoAct[edadMax].nombreActor);
            }

        }
    }
}

int listarActoresPorNacionalidadIngresada(eActor listado[], int len, char nacionalidad[21])
{
    int i;
    int existen= 0 ;

    for(i=0; i<len-1; i++)
    {
        if(stricmp(listado[i].nacionalidad, nacionalidad)==0)
        {
            printf("%s  \n", listado[i].nombreActor);
            existen = 1;
        }
    }


    if(existen == 0)
    {
        printf("\n No hay actores de ese pais\n");
    }

    return 0;

}

