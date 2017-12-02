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

    if (lista != NULL)
    {
        for (int i = 0; i<lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);

            if (auxNumero != NULL)
            {
                valor = numero_getNumero(auxNumero);

                if (esPar(valor) == 0)
                {
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
void quitarRepetidos_lista(ArrayList* lista)
{
    eNumero* auxNumero;
    eNumero* auxNumero2;
    int i,j;

    if ( lista != NULL  )
    {
        for (i = 0; i<lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);
            for ( j = i+1; j<lista->len(lista); j++ )
            {
                auxNumero2 = lista->get(lista,j);
                if ( numero_compare(auxNumero,auxNumero2) == 0)
                {
                    lista->remove(lista,j);
                    //j--;
                }
            }
        }
    }
}
void informar(ArrayList* lista)
{
    int contCeros = 0;
    int contPares = 0;
    int contImpares = 0;
    int contPrimos = 0;
    int par;
    int impar;
    int primo;
    eNumero* auxNumero;

    if (lista != NULL)
    {
        for (int i = 0; i< lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);

            if (auxNumero != NULL)
            {
                par = numero_getPar(auxNumero);
                impar = numero_getImpar(auxNumero);
                primo = numero_getPrimo(auxNumero);

                if ( par == 1)
                {
                    contPares++;
                }
                else
                {
                    contImpares++;
                }
                if ( primo == 1)
                {
                    contPrimos++;
                }
            }
        }
    }
    printf("\nCANTIDAD DE PARES: %d",contPares);
    printf("\nCANTIDAD DE IMPARES: %d",contImpares);
    printf("\nCANTIDAD DE PRIMOS: %d\n",contPrimos);
}

