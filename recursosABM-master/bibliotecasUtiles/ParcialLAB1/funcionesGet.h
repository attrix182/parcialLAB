
/** \brief Solicita un valor numerico de tipo Entero
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el dato validado ingresado por el usuario.
 */
int getInt(char mensaje[]);

/** \brief Solicita un valor numerico de tipo Flotante
 *
 * \param mensaje Es el mensaje que será mostrado al usuario
 * \return Es el dato validado ingresado por el usuario.
 *
 */
float getFloat (char mensaje[]);




/** \brief Solicita un texto al usuario.
 *
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargara el texto ingresado.
 * \return void.
 */
void getString(char mensaje[], char input[]);

/** \brief recorre caracter a caracter verificando si es solo letras
 *
 * \param str[] char
 * \return int retorna 1 si es solo letras
 *
 */
int esSoloLetras(char str[]);

/** \brief recorre caracter a caracter verificando si es solo numeros
 *
 * \param str[] char
 * \return int retorna 1 si es solo numeros
 *
 */
int esNumerico(char str[]);
