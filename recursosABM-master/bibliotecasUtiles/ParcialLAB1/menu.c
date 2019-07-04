#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionesGet.h"
int pedirOpcionMenu()
{
    int opcion;
    printf("            |A B M   PELICULAS|          \n\n");
    opcion = getInt(" 1.ALTAS  \n 2.LISTAR \n 3.MODIFICAR PELICULA\n 4.BAJA PELICULAS\n 5.Salir\n");
    return opcion;

}
int pedirOpcionModificacionPelicula()
{
    int opcionAmodificar;
    printf("%s","             MODIFICACION            \n");
    printf("%10s - %10s - %10s \n", "1.Titulo", "2.Anio de estreno", "3.Actor");
    opcionAmodificar = getInt("\nQue desea modificar?\n");

    while(opcionAmodificar != 1 && opcionAmodificar != 2 && opcionAmodificar != 3)
    {
        opcionAmodificar = getInt("ERROR. 1.Titulo 2.Anio de estreno 3.Actor\n");
    }

    return opcionAmodificar;
}

int getOptionShow()
{
    int optionShow;
    printf("%s","                   INFORMES                 \n");
    printf("%s %s %s %s %s %s %s %s %s %s %s %s \n"," 1.Listar los datos de Peliculas sin actores\n", "2.Listar los datos de Peliculas con actores\n", "3.Peliculas ordenadas por anio de estreno\n", "4.Actores ordenados por pais de origen\n", "5.Todas las peliculas con genero y actor. \n", "6.Peliculas cuya nacionalidad del actor sea EEUU. \n","7.Peliculas nacionalidad del actor ingresada por consola. \n","8.Por cada genero el titulo de las peliculas que pertenecen a ese genero. \n", "9.Por cada genero cantidad de peliculas. \n", "10.Actores que mas peliculas protagonizaron. \n","11.Genero/s con menos peliculas.\n", "12.Actor/es que no trabajaron en ninguna pelicula.\n");
    optionShow = getInt("");

    return optionShow;
}

int pedirOpcionNacionalidad()
{
    int optionShow;
    printf("%s","                   Ingrese nacionaliad a listar                 \n");
    optionShow = getInt("1.EEUU \n 2.Argentina \n 3.Australia\n 4.Uruguay\n");

    return optionShow;
}

int pedirOrden()
{
    int opcion;
    printf("%s","               Ingrese sentido de ordenamiento                \n");
    opcion = getInt(" 1.Ascendente \n 2.Descendente \n ");

    while(opcion != 1 && opcion != 2)
    {
        opcion = getInt("ERROR. 1.Ascendente \n 2.Descendente \n ");
    }

    return opcion;
}
