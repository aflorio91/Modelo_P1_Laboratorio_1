#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "ArrayList.h"
int parser_lista(FILE* pFile, ArrayList* pArrayListPersona);
void listar(ArrayList* lista);
int isBlackListed(ePersona* unaPersona, ArrayList* lista_negra);
ArrayList* depurar_lista(ArrayList* lista_destinatarios, ArrayList* lista_negra, ArrayList* lista_depurada);
void quitar_repetidos(ArrayList* lista_depurada);
int crear_archivo_lista_depurada(ArrayList* lista_depurada);
#endif // LISTA_H_INCLUDED
