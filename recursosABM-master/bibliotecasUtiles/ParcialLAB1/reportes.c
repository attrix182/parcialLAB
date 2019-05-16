#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int listarActoresPorGenero(ePelicula listadoPel[], eActor listadoAct[], int len,  char generoAlistar[21])
{
    int i;
    int posActorDeGenero;
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

