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
    int opcionMenu;
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
            opcionMenu = getOptionShow();
            switch(opcionMenu)
            {

            case 1:
                printf("   Listado de Peliculas CON Actores Y Genero \n");
                mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
                printf("\n");
                break;

            case 2:
                listarPeliculasPorNacionalidad(listadoPeliculas, listadoActores, TAM, "EEUU");
                printf("\n");
                break;
            case 3:
                listarActoresPorGenero(listadoPeliculas, listadoActores, len, "Accion");
                listarActoresPorGenero(listadoPeliculas, listadoActores, len, "Terror");
                listarActoresPorGenero(listadoPeliculas, listadoActores, len, "Comedia");
            break

            }
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
