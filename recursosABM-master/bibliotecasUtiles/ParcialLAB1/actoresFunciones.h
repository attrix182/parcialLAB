#ifndef ACTORESFUNCIONES_H_INCLUDED
#define ACTORESFUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombreActor[51];
    char nacionalidad[51];
    int edad;
    int estado;
} eActor;

int inicializarActores(eActor[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/

int mostrarListadoActores(eActor[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int buscarActorPorID(eActor[], int len,int idPropietario);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */

int bajaPropietario(eActor listado[], int len, char nac[21]);

/** \brief modify a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int harcodeActores(eActor[], int len);



/** \brief
 *
 * \param list[] Employee
 * \param len int
 * \return int
 *
 */
int buscarLibreActores(eActor[], int len);

/** \brief
 *
 * \param listado[] eActor
 * \param len int
 * \return int
 *
 */
int listarActoresPorNacionalidad(eActor[], int len);


/** \brief
 *
 * \param listadoAct[] eActor
 * \param len
 * \return int
 *
 */
int altaActor(eActor listadoAct[], int len);


/** \brief
 *
 * \param listadoAct[] eActor
 * \param len int
 * \param id int
 * \return int
 *
 */
int modificarActores(eActor listadoAct[], int len, int id);
#endif // ACTORESFUNCIONES_H_INCLUDED
