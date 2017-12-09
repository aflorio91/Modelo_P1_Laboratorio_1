#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
/** \brief lee los datos del archivo apuntado por un puntero y los carga al arraylist
 * \param puntero a FILE
 * \param puntero arraylist
 * \return 0 en caso exitoso / != 0 en caso de q falle
 */
int parser_Letra(FILE* pFile, ArrayList* lista);
/** \brief lista por pantalla los datos cargados en el arraylist
 * \param puntero arraylist
 * \return void
 */
void listar(ArrayList* lista);
/** \brief completa los campos restantes de cada elemento del arraylist
 * \param puntero arraylist
 * \return 0 en caso exitoso / 1 en caso de falla
 */
int completar_lista(ArrayList* lista);
/** \brief ordena la lista de manera ascendente
 * \param puntero arraylist
 * \return void
 */
void ordenar_lista_ascendente(ArrayList* lista);
/** \brief ordena la lista de manera descendente
 * \param puntero arraylist
 * \return void
 */
void ordenar_lista_descendente(ArrayList* lista);
/** \brief quita todos los numeros repetidos de la lista dejando solo uno de cada uno
 * \param puntero arraylist
 * \return
 */
void quitar_repetidos(ArrayList* lista);
void comprobar_lista(ArrayList* lista);
#endif // FUNCIONES_H_INCLUDED
