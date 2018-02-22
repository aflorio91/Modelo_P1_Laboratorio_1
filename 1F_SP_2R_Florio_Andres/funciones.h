#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"
int parserNumero(FILE* pFile, ArrayList* pArrayListNumero);
void listar(ArrayList* lista);
int completar_lista(ArrayList* lista);
ArrayList* ordernar_lista(ArrayList* lista);
void quitarRepetidos_lista(ArrayList* lista_ordenada);
void nueva_funcion_deQuitarRepetidos(ArrayList* lista_vieja, ArrayList* lista_nueva);
void informar(ArrayList* lista);
int grabar_CSV(ArrayList* list);
int grabar_BIN(ArrayList* list);
int leer_BIN();
#endif // FUNCIONES_H_INCLUDED
