#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

/** \brief Lista actores pertenecientes a un genero ingresado por parametro
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \param generoAlistar[21] char
 * \return void
 *
 */
void listarActoresPorGenero(ePelicula[], eActor[], int len, char generoAlistar[21]);

/** \brief Muestra peliculas con actores
 *
 * \param ePelicula[]
 * \param eActor[]
 * \param len int
 * \return int
 *
 */
int mostrarPeliculasConActores(ePelicula[], eActor[], int len);

/** \brief Lista peliculas pertenecientes a una nacionalidad de actor ingresada por parametro
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \param nacionalidadAlistar[21] char
 * \return int
 *
 */
int listarPeliculasPorNacionalidad(ePelicula[], eActor[], int len,  char nacionalidadAlistar[21]);

/** \brief Lista peliculas pertenecientes a una nacionalidad de actor ingresada por parametro
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
 * \param len int
 * \param idAcontar int
 * \return void
 *
 */
int participaciones(ePelicula listadoPel[], int len, int idAcontar);

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
 * \return void
 *
 */
int cantidadPeliculasPorGenero(ePelicula listadoPel[], int len, char generoAcontar[21]);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param len int
 * \return void
 *
 */
void generoConMenosPeliculas(ePelicula listadoPel[], int len);


/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \param fecha int
 * \return void
 *
 */
void actoresAntesDeFecha(ePelicula listadoPel[], eActor listadoAct[], int len, int fecha);

/** \brief
 *
 * \param listadoPel[] ePelicula
 * \param listadoAct[] eActor
 * \param len int
 * \param idDeActor int
 * \return void
 *
 */
void peliculasAgrupadasPorActor(ePelicula listadoPel[], eActor listadoAct[], int len, int idDeActor);
#endif // REPORTES_H_INCLUDED
