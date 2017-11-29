#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
int parserNumero(FILE* pFile, ArrayList* pArrayListNumero);
void listar(ArrayList* lista);
int completar_lista(ArrayList* lista);
int ordernar_lista(ArrayList* lista, ArrayList* lista_depurada);
#endif // FUNCIONES_H_INCLUDED
