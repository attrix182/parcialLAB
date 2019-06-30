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
    int opcionListar;
    char seguir = 's';
    int opcionNacionalidad;
    char nacionalidad[21];
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
            opcionListar = getOptionShow();
            switch(opcionListar)
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
                opcionNacionalidad = pedirOpcionNacionalidad();

                switch(opcionNacionalidad)
                {
                case 1:
                    strcpy(nacionalidad, "EEUU");
                    break;
                case 2:
                    strcpy(nacionalidad, "Argentina");
                    break;
                case 3:
                    strcpy(nacionalidad, "Australia");
                    break;
                case 4:
                    strcpy(nacionalidad, "Uruguay");
                    break;
                default:
                    printf("opcion invlaida \n");
                    break;
                }

                listarPeliculasPorNacionalidadIngresada(listadoPeliculas, listadoActores, TAM, nacionalidad);
                break;
            case 4:
                listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "Accion");
                printf("\n");
                listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "Terror");
                printf("\n");
                listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "Comedia");
                printf("\n");
                listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "Romantica");
                printf("\n");
                listarActoresPorGenero(listadoPeliculas, listadoActores, TAM, "Otro");
                printf("\n");
                break;
            case 5:
                printf("5");
                break;
            case 6:
                printf("6");
                break;
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
