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
                mostrarListadoPeliculas(listadoPeliculas, TAM);
                break;
            case 2:
                mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
                break;
            case 3:
                listarPeliculasPorFecha(listadoPeliculas, TAM);
                break;
            case 4:
                listarActoresPorNacionalidad(listadoActores, TAM);
                break;
            case 5:
                printf("   Listado de Peliculas CON Actores Y Genero \n");
                mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
                printf("\n");
                break;

            case 6:
                listarPeliculasPorNacionalidad(listadoPeliculas, listadoActores, TAM, "EEUU");
                printf("\n");
                break;
            case 7:
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
                    printf("opcion invalida \n");
                    break;
                }

                listarPeliculasPorNacionalidadIngresada(listadoPeliculas, listadoActores, TAM, nacionalidad);
                break;
            case 8:
                peliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Accion");
                peliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Terror");
                peliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Comedia");
                peliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Romantica");
                peliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Otro");
                break;
            case 9:
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Accion");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Terror");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Comedia");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Romantica");
                cantidadpeliculasAgrupadasPorGenero(listadoPeliculas, TAM, "Otro");
                printf("\n");
                break;
            case 10:
                actoresMasParticipativos(listadoPeliculas, listadoActores, TAM);
                break;
            case 11:
                generoConMenosPeliculas(listadoPeliculas, TAM);
                break;
            case 12:
                actoresQueNoTrabajaron(listadoPeliculas, listadoActores, TAM);
                break;
            }
            break;
        case 3:
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
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
            mostrarPeliculasConActores(listadoPeliculas, listadoActores, TAM);
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
