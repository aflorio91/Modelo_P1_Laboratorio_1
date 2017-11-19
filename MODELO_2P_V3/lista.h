#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "ArrayList.h"
int parser_destinatarios(FILE* pFile, ArrayList* pArrayListPersona);
void listar(ArrayList* lista);
int parser_lista_negra(FILE* pFile, ArrayList* pArrayListPersona);
void depurar_listas(ArrayList* lista, ArrayList* lista_negra, ArrayList* lista_depurada);
void quitar_repetidos(ArrayList* lista_depurada);


#endif // LISTA_H_INCLUDED
