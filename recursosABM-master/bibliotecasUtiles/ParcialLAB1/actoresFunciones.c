#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "actoresFunciones.h"
#include "peliculasFunciones.h"

// 1 = libre ; 0 = ocupado

int inicializarActores(eActor listado[], int len)
{
    int i;

    for(i = 0; i<len; i++ )
    {
        listado[i].estado = 1;

    }

    return 0;

}



int mostrarListadoActores(eActor listado[], int len)
{
    int i;
    printf("%s\t - %s\t - %s\t \n", "ID", "nombre y apellido", "Nacionalidad");

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%d\t  %s\t  %s\t \n", listado[i].id, listado[i].nombreActor, listado[i].nacionalidad);

        }

    }
    return 0;
}

int buscarActorPorID(eActor listado[], int len,int id)
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

int bajaPropietario(eActor listado[], int len, int id)
{

    int idAborrar = buscarActorPorID(listado, len, id);
    if(idAborrar == -1)
    {
        return -1;
    }
    listado[idAborrar].estado = 1;
    return 0;
}


int harcodeActores(eActor listado[], int len)
{
    int i;

    int id[5]= {1, 2, 3, 4, 5};
    char nombreActor[5][50]= {"Julieta roberto", "Richar darin", " Nicole Kidman", "Tita merello", "Natalia Oreiro"};
    char nacionalidad[5][13]= {"EEUU", "Argentina ", "Australiana ", "Argentina", "Uruguay"};
    int estado[5]= { 0, 0, 0, 0};

    for(i=0; i<5; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombreActor,nombreActor[i]);
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].estado = estado[i];

    }
    return -1;
}


int buscarLibreActores(eActor listado[], int len)
{
    int i;
    int id;

    for(i=0; i<len; i++)
    {
        if(listado[i].estado ==1)
        {
            id = i+1000;
            break;
        }
    }
    return id;
}

int listarActoresPorNacionalidad(eActor listado[], int len)
{
    int i;
    int j;
    eActor aux;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(listado[i].estado==0 && listado[j].estado==0)
            {
                if(stricmp(listado[i].nacionalidad, listado[j].nacionalidad)>0)
                {
                    aux =listado[i];
                    listado[i] = listado[j];
                    listado[j] = aux;
                }


            }
        }

}
        mostrarListadoActores(listado, len);
        printf("\n");
        return 0;
}

