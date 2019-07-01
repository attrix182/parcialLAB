#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "funcionesGet.h"
//1 libre; 0 ocupado
int inicializarPeliculas(ePelicula listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}

int altaPeliculas(ePelicula listado[], eActor listadoActores[], int len)
{
    int id;
    int codigoPelicula;
    char titulo[51];
    int fechaDeEstreno;
    char genero[21];
    int idActor;
    int generoNumero;
    int idExiste;
    //int codigoPeliculaAverificar;

    id = buscarLibrePelicula(listado, len);

    codigoPelicula = getInt("Ingrese codigo pelicula\n");

    while(codigoPelicula < 100 || codigoPelicula > 999)
    {

        codigoPelicula = getInt("Reingrese un codigo valido 100/999 \n");

    }


    codigoPelicula = verificarCodigo(listado, len, codigoPelicula);
    while(codigoPelicula == -1)
    {
        codigoPelicula = getInt("Reingrese un codigo valido, ese ya existe 100/999 \n");
        codigoPelicula = verificarCodigo(listado, len, codigoPelicula);

    }


    getString(" Ingrese titulo \n", titulo);

    while(esNumerico(titulo)==1)
    {
        getString(" Ingrese nuevo titulo, debe ser texto \n", titulo);

    }

    fechaDeEstreno = getInt("Ingrese Año de estreno \n");
    while(fechaDeEstreno < 1984 || fechaDeEstreno > 2025)
    {
        fechaDeEstreno = getInt("Reingrese una fecha valida 1984/2025 a\n");
    }

    do
    {
        generoNumero = getInt(" Ingrese genero \n 1.Accion 2.Comedia 3.Terror 4.Otro 5.Romantica  \n");

        switch(generoNumero)
        {
        case 1:
            strcpy(genero, "accion");
            break;
        case 2:
            strcpy(genero, "comedia");
            break;
        case 3:
            strcpy(genero, "terror");
            break;
        case 4:
            strcpy(genero, "otro");
            break;
        case 5:
            strcpy(genero, "romantica");
            break;
        default:

            printf("Erroneo. Genero inexistente");
            break;
        }
    }
    while(generoNumero > 5);
    mostrarListadoActores(listadoActores, len);
    idActor = getInt("id de actor principal\n");
    idExiste = buscarActorPorID(listadoActores, len, idActor);
    while(idExiste == -1)
    {
        idActor = getInt("Reingrese una ID de Actor valida\n");
        idExiste = buscarActorPorID(listadoActores, len, idActor);;
    }

    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].estado == 1)
        {
            listado[i].id = id;
            listado[i].codigoPelicula= codigoPelicula;
            strcpy(listado[i].titulo, titulo);
            listado[i].fechaDeEstreno= fechaDeEstreno;
            strcpy(listado[i].genero, genero);
            listado[i].idActor= idActor;
            listado[i].estado = 0;
            return 0;
        }
    }
    return -1;
}

int mostrarListadoPeliculas(ePelicula listado[], int len)
{
    int i;
    printf("%s\t %s\t %s\t %s\t %s\t \n", "ID", "codigoPelicula", "titulo", "fechaDeEstreno", "genero");


    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%d\t  %d\t  %s\t %d\t %s\t \n", listado[i].id, listado[i].codigoPelicula, listado[i].titulo, listado[i].fechaDeEstreno, listado[i].genero);
        }


    }
    return 0;
}

int buscarPeliPorID(ePelicula listado[], int len,int id)
{
    int i;
    for(i = 0; i<len; i++)
    {
        if(listado[i].id == id)
        {
            return i;
        }
    }

    return -1;

}

int bajaPelicula(ePelicula listado[], int len, int id)
{

    int idAborrar = buscarPeliPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}



int harcodePeliculas(ePelicula listado[], int len)
{
    int i;

    int id[8]= {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007};
    int codigoPelicula[8]= {999, 666, 555, 777, 111, 222, 101, 202};
    char titulo[8][51]= {"terminator ", "   thor  ", "     it   ", "gladiador", "scary movie", "yo soy asi", "scary movie 2", "sexto sentido"};
    int fechaDeEstreno[8]= { 2020, 2019, 2018, 2018, 2012, 1990, 2015, 1999};
    char genero[8][21]= { "Accion", "Accion", "Terror", "Romantica", "Comedia", "Otro","Comedia", "Otro" };
    int idActor[8] = {1, 5, 4, 4, 4, 4, 1, 1};

    for(i=0; i<8; i++)
    {

        listado[i].id = id[i];
        listado[i].codigoPelicula= codigoPelicula[i];
        strcpy(listado[i].titulo, titulo[i]);
        listado[i].fechaDeEstreno= fechaDeEstreno[i];
        strcpy(listado[i].genero, genero[i]);
        listado[i].idActor = idActor[i];
        listado[i].estado = 0;


    }
    return -1;
}


int buscarLibrePelicula(ePelicula listado[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(listado[i].estado ==1)
        {
            id = i+1001;
            break;
        }
    }
    return id;
}



int modificacionPelicula(ePelicula listadoPeliculas[], eActor listadoActores[], int len, int id, int option)
{
    char titulo[51];
    int fechaDeEstreno;
    int idActor;
    int posAeditar = buscarPeliPorID(listadoPeliculas, len, id);
    int idExiste;
    if(posAeditar == -1)
    {
        return -1;
    }
    switch(option)
    {
    case 1:
        getString(" Ingrese nuevo titulo \n", titulo);

        while(esNumerico(titulo)==1)
        {
            getString(" Ingrese nuevo titulo, debe ser texto \n", titulo);

        }
        strcpy(listadoPeliculas[posAeditar].titulo, titulo);
        break;
    case 2:
        fechaDeEstreno = getInt("Ingrese Nueva Fecha de estreno \n");
        listadoPeliculas[posAeditar].fechaDeEstreno = fechaDeEstreno;
        break;
    case 3:
        idActor = getInt("id de actor principal\n");
        idExiste = buscarActorPorID(listadoActores, len, idActor);
        while(idExiste == -1)
        {
            idActor = getInt("Reingrese una ID de Actor valida\n");
            idExiste = buscarActorPorID(listadoActores, len, idActor);;
        }
        listadoPeliculas[posAeditar].idActor = idActor;
        break;
    }
    return 0;
}

int listarPeliculasPorFecha(ePelicula listadoPeliculas[], int len)
{
    int i;
    int j;
    ePelicula aux;


    for(i=0; i<len; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listadoPeliculas[i].fechaDeEstreno < listadoPeliculas[j].fechaDeEstreno)
            {
                aux =listadoPeliculas[i];
                listadoPeliculas[i] = listadoPeliculas[j];
                listadoPeliculas[j] = aux;


            }
        }
    }
    mostrarListadoPeliculas(listadoPeliculas, len);
    printf("\n");

    return 0;
}

int verificarCodigo(ePelicula listadoPeliculas[], int len, int codigoPelicula)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(codigoPelicula == listadoPeliculas[i].codigoPelicula)
        {

            return -1;
            break;
        }

    }
    return codigoPelicula;
}



