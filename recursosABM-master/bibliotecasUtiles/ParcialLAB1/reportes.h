#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

/** \brief
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \param generoAlistar[21] char
 * \return int
 *
 */
int listarActoresPorGenero(ePelicula[], eActor[], int len, char generoAlistar[21]);

/** \brief
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \return int
 *
 */
int mostrarPeliculasConActores(ePelicula[], eActor[], int len);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \param nacionalidadAlistar[21] char
 * \return int
 *
 */
int listarPeliculasPorNacionalidad(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);

/** \brief
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \param nacionalidadAlistar[21] char
 * \return int
 *
 */
int listarPeliculasPorNacionalidadIngresa(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);


/** \brief
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \return int
 *
 */
int peliculasAgrupadasPorGenero(ePelicula[], eActor[], int len, char generoAlistar[21]);

#endif // REPORTES_H_INCLUDED
