#ifndef ELECTRA_H_INCLUDED
#define ELECTRA_H_INCLUDED
typedef struct
{
    char letra;
    char nombre[21];
    int vocal;
    int consonante;
} eLetra;
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);
/** \brief asigna memoria a un puntero de letra
 * \return puntero eLetra
 */
eLetra* letra_new(void);
/** \brief imprime los datos de un puntero a estructura por pantalla
 * \param puntero a estructura eLetra
 * \return void
 */
void letra_print(eLetra* this);
/** \brief getter de letra para estructura eLetra
 * \param puntero a estructura eLetra
 * \return un puntero carater
 */
char* numero_getLetra(eLetra* this);
/** \brief setea un valor binario al campo vocal
 * \param puntero a estructura eLetra
 * \param 0 o 1
 * \return void
 */
void letra_setVocal(eLetra* this, int* binario);
/** \brief setea un valor al campo consonante
 * \param puntero a estructura
 * \param 0 o 1
 * \return void
 */
void letra_setConsonante(eLetra* this, int* binario);
/** \brief verifica que el valor ingresado sea un carater vocal
 * \param caracter
 * \param
 * \return 0 es vocal / 1 no es vocal
 */
int esVocal(char letra);
/** \brief compara dos punteros de eLetras
 * \param puntero
 * \param puntero
 * \return 1 el primer puntero tiene una letra mayor / 0 caso contrario
 */
int letra_compare(eLetra* letra_Alfa, eLetra* letra_Beta);
#endif // ELECTRA_H_INCLUDED
