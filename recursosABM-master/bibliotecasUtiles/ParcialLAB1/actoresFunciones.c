#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "funcionesGet.h"
#include "menu.h"

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
    printf("%s\t - %s\t - %s\t - %s\t \n", "ID", "nombre y apellido", "Nacionalidad","Edad");

    for(i = 0; i < len; i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%d\t  %s\t  %s\t %d\t \n", listado[i].id, listado[i].nombreActor, listado[i].nacionalidad, listado[i].edad);

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

int bajaPropietario(eActor listado[], int len, char nac[21])
{

    int i;
    int existe = 0;
    for(i=0; i<len; i++)
    {
        if(stricmp(listado[i].nacionalidad, nac)== 0)
        {
            listado[i].estado = 1;
        }
        existe = 1;
    }

    if(existe == 0)
    {
        printf("%s", "no hay");
    }

    return 0;


}


int harcodeActores(eActor listado[], int len)
{
    int i;

    int id[5]= {1, 2, 3, 4, 5};
    char nombreActor[5][50]= {"Julieta roberto", "Richar darin", "Nicole Kidman", "Tita merello", "Natalia Oreiro"};
    char nacionalidad[5][13]= {"EEUU", "Argentina", "Australiana ", "Argentina", "Uruguay"};
    int estado[5]= { 0, 0, 0, 0};
    int edad[5] = {33, 77, 11, 18, 33};

    for(i=0; i<5; i++)
    {
        listado[i].id=id[i];
        strcpy(listado[i].nombreActor,nombreActor[i]);
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].estado = estado[i];
        listado[i].edad = edad[i];

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
            id = i+1;
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

int altaActor(eActor listadoAct[], int len)
{

    int id;
    int edad;
    char nombre[51];
    char nacionalidad[21];

    id = buscarLibreActores(listadoAct, len);


    getString(" Ingrese nombre del actor \n", nombre);

    getString(" Ingrese nacionalidad del actor \n", nacionalidad);

    edad = getInt("Ingrese edad\n");

    while(edad < 1 || edad > 120)
    {

        edad = getInt("Reingrese una edad valida 1/120 \n");
    }



    int i;
    for(i = 0; i<len; i++)
    {
        if(listadoAct[i].estado == 1)
        {
            listadoAct[i].id = id;
            listadoAct[i].edad= edad;
            strcpy(listadoAct[i].nombreActor, nombre);
            strcpy(listadoAct[i].nacionalidad, nacionalidad);
            listadoAct[i].estado = 0;
            return 0;
        }
    }
    return -1;
}


int modificarActores(eActor listadoAct[], int len, int id)
{
    char nombre[51];
    char nacionalidad[51];
    int edad;

    int posAeditar = buscarActorPorID(listadoAct, len, id);
    int opcion;
    if(posAeditar == -1)
    {
        return -1;
    }
    opcion = pedirOpcionModificacionActor();
    switch(opcion)
    {
    case 1:
        getString(" Ingrese nuevo nombre del actor \n", nombre);
        strcpy(listadoAct[posAeditar].nombreActor, nombre);
        break;
    case 2:
        getString(" Ingrese nueva nacionalidad del actor \n", nacionalidad);
        strcpy(listadoAct[posAeditar].nacionalidad, nacionalidad);
        break;
    case 3:
        edad = getInt("Ingrese nueva edad\n");

        while(edad < 1 || edad > 120)
        {
            edad = getInt("Reingrese una edad valida 1/120 \n");
        }
        break;

        listadoAct[posAeditar].edad = edad;
    }
    return 0;

}
