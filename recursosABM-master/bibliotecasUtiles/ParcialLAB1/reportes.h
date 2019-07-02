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
int listarPeliculasPorNacionalidadIngresada(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);


/** \brief
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \return int
 *
 */
void peliculasAgrupadasPorGenero(ePelicula[], int len, char generoAlistar[21]);


/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param len int
 * \param generoAlistar[21] char
 * \return void
 *
 */
void cantidadpeliculasAgrupadasPorGenero(ePelicula listadoPel[], int len, char generoAlistar[21]);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \return void
 *
 */
void actoresMasParticipativos(ePelicula listadoPel[], eActor listadoAct[], int len);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param len int
 * \return void
 *
 */
void generoConMasPeliculas(ePelicula listadoPel[], int len);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \return void
 *
 */
void actoresQueNoTrabajaron(ePelicula listadoPel[], eActor listadoAct[], int len);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param len int
 * \param idAcontar int
 * \return void
 *
 */
int partActores(ePelicula listadoPel[], int len, int idAcontar);

#endif // REPORTES_H_INCLUDED
