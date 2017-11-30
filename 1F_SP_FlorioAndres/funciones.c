#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeroNatural.h"
#include "ArrayList.h"

int parserNumero(FILE* pFile, ArrayList* pArrayListNumero)
{
    int retorno = 1;
    char auxNumero[10];
    char auxNombre[51];
    char auxPar[10];
    char auxImpar[10];
    char auxPrimo[10];
    eNumero* nuevoNumero;

    if(pFile == NULL || pArrayListNumero == NULL)
    {
        return retorno;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);

    while(!feof(pFile))
    {
        nuevoNumero = numero_new();

        if(nuevoNumero != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);

            nuevoNumero->numero = atoi(auxNumero);
            strcpy(nuevoNumero->nombre, auxNombre);
            nuevoNumero->par = atoi(auxPar);
            nuevoNumero->impar = atoi(auxImpar);
            nuevoNumero->primo = atoi(auxPrimo);

            if ( pArrayListNumero->add(pArrayListNumero, nuevoNumero) == -1 )
            {
                retorno = 1;
                break;
            }
            else
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}
void listar(ArrayList* lista)
{
    eNumero* unNumero;
    for(int i=0; i < al_len(lista); i++)
    {
        unNumero = (eNumero*)lista->get(lista, i);
        numero_print(unNumero);
        printf("\n");
    }
}
int completar_lista(ArrayList* lista)
{
    int retorno = 1;
    eNumero* auxNumero;
    int valor;

    //printf("\nprincipio");
    if (lista != NULL)
    {
        //printf("\ndentro del if");
        for (int i = 0; i<lista->len(lista); i++)
        {
            //printf("\ndentro while iteracion %d",i);
            //printf("\nlen %d",lista->len(lista));
            auxNumero = lista->get(lista,i);

            if (auxNumero != NULL)
            {
                valor = numero_getNumero(auxNumero);

                if (esPar(valor) == 0)
                {
                    //printf("\nVALOR: %d", valor);
                    numero_setPar(auxNumero,1);
                    numero_setImpar(auxNumero,0);
                }
                else
                {
                    numero_setPar(auxNumero,0);
                    numero_setImpar(auxNumero,1);
                }
                if (esPrimo(valor) == 1)
                {
                    //printf("\nLLEGA");
                    numero_setPrimo(auxNumero,1);
                }
                else
                {
                    numero_setPrimo(auxNumero,0);
                }
                lista->set(lista, i, auxNumero);
            }
        }
        retorno = 0;
    }
    return retorno;
}
void ordernar_lista(ArrayList* lista )
{
    if ( lista != NULL )
    {
        lista->sort(lista,numero_compare,1);
    }
}


