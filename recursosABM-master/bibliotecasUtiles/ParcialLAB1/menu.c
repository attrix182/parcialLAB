#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionesGet.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("            A B M                  \n\n");
    printf(" 1.ALTAS  \n 2.LISTAR \n 3.MODIFICAR PELICULA\n 4.BAJA PELICULAS\n 5.Salir\n");
    scanf("%d", &opcion);

    return opcion;

}
int pedirOpcionModificacionPelicula()
{
    int opcionAmodificar;
    printf("%s","             MODIFICACION            \n");
    printf("%10s - %10s - %10s \n", "1.Titulo", "2.Anio de estreno", "3.Actor");
    opcionAmodificar = getInt("Que desea modificar?");

    return opcionAmodificar;
}

int getOptionShow()
{
    int optionShow;
    printf("%s","                   INFORMES                 \n");
    printf("%s %s %s \n", " 1. Todas las peliculas con genero y actor. \n", "2.Peliculas cuya nacionalidad del actor sea EEUU.\n", "3.Por cada genero el titulo de las películas que pertenecen a ese genero");
    scanf("%d", &optionShow);

    return optionShow;
}

int pedirOpcionNacionalidad()
{
    int optionShow;
    printf("%s","                   ingrese nacionaliad a listar                 \n");
    printf( "%s \n", " 1. EEUU \n 2.Argentina \n 3.Australia\n 4.Uruguay\n");
    scanf("%d", &optionShow);

    return optionShow;
}
