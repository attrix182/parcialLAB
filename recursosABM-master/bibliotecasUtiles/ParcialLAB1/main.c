#include <stdio.h>
#include <stdlib.h>
#include "actoresFunciones.h"
#include "peliculasFunciones.h"
#include "menu.h"
#include "funcionesGet.h"
#include "string.h"
#include "reportes.h"
#define TAM 50

int main()
{
    eActor listadoActores[TAM];
    ePelicula listadoPeliculas[TAM];

    inicializarActores(listadoActores, TAM);
    harcodeActores(listadoActores, TAM);

    inicializarPeliculas(listadoPeliculas, TAM);
    harcodePeliculas(listadoPeliculas, TAM);

    int opcion;
    int opcionMod;
    char seguir = 's';
    int idExiste;
    int id;


    do
    {
        opcion = pedirOpcionMenu();

        switch(opcion)
        {
        case 1:

            altaPeliculas(listadoPeliculas, listadoActores, TAM);

            break;
        case 2:
            printf("   Listado de Peliculas SIN Actores  \n");
            mostrarListadoPeliculas(listadoPeliculas, TAM);
            printf("\n");
            printf("   Listado de Peliculas CON Actores  \n");
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
            printf("\n");
            printf("   Listado de Peliculas por FECHA  \n");
            listarPeliculasPorFecha(listadoPeliculas, TAM);

            printf("   Listado de Actores por nacionalidad  \n");
            listarActoresPorNacionalidad(listadoActores, TAM);

            printf("   Listado de Actores por genero  \n");
            listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "accion");

            break;
        case 3:

            id = getInt("Ingrese ID de Pelicula a modificar \n");
            idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);

            }
            opcionMod = pedirOpcionModificacionPelicula();
            modificacionPelicula(listadoPeliculas, listadoActores, TAM, id, opcionMod);
            break;
        case 4:
            id = getInt("Ingrese ID de pelicula a remover\n");
            idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);
            while(idExiste == -1)
            {
                id = getInt("Reingrese una ID valida\n");
                idExiste = buscarPeliPorID(listadoPeliculas, TAM, id);

            }
            bajaPelicula(listadoPeliculas, TAM, id);

            break;
        case 5:
            seguir = 'n';
            break;

        default:
            printf("opcion invlaida \n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}
