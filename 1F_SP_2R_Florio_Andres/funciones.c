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
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%s\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);
    //%[^,],%[^,],%[^,],%s[^\n]\n
    while(!feof(pFile))
    {
        nuevoNumero = numero_new();

        if(nuevoNumero != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%s\n",auxNumero,auxNombre,auxPar,auxImpar,auxPrimo);
            //%[^,],%[^,],%[^,],%s[^\n]\n
            nuevoNumero->numero = atoi(auxNumero);//GETTERS Y SETTERS
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
    int i;
    printf("\nNumero | Nombre | Par | Impar | Primo\n");
    for( i=0; i < al_len(lista); i++)
    {
        unNumero = (eNumero*)lista->get(lista, i);
        numero_print(unNumero);
        printf("\n");
    }
    printf("\n");
}
int completar_lista(ArrayList* lista)
{
    fflush(stdin);
    int retorno = 1;
    eNumero* auxNumero;
    int valor,i;

    if (lista != NULL)
    {
        for ( i = 0; i<lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);

            if (auxNumero != NULL)
            {
                valor = numero_getNumero(auxNumero);

                if (esPar(valor) == 0 && numero_getNumero(auxNumero) != 0)
                {
                    numero_setPar(auxNumero,1);
                }
                else
                {
                    numero_setImpar(auxNumero,1);
                }
                if (esPrimo(valor) == 1 && numero_getNumero(auxNumero) != 0)
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
            j = i+1;
            printf("\ni:%d",i);
            auxNumero = lista->get(lista, i );
            auxNumero2 = lista->get(lista, j );
            if ( auxNumero2 != NULL )
            {
                if ( numero_compare(auxNumero,auxNumero2) == 0 )
                {
                    lista->remove(lista, j );
                }
                else
                {
                    i++;
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
    int numero;
    int par;
    int impar;
    int primo;
    int i;
    eNumero* auxNumero;

    if (lista != NULL)
    {
        for ( i = 0; i< lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);

            if (auxNumero != NULL)
            {
                numero = numero_getNumero(auxNumero);
                par = numero_getPar(auxNumero);
                impar = numero_getImpar(auxNumero);
                primo = numero_getPrimo(auxNumero);

                if ( numero == 0)
                {
                    contCeros++;
                }
                else
                {
                    if ( par == 1 && impar == 0 )
                    {
                        contPares++;
                    }
                    else if (par == 0 && impar == 1)
                    {
                        contImpares++;
                    }
                    if ( primo == 1  )
                    {
                        contPrimos++;
                    }
                }
            }
        }
    }
    printf("\nCANTIDAD DE CEROS: %d",contCeros);
    printf("\nCANTIDAD DE PARES: %d",contPares);
    printf("\nCANTIDAD DE IMPARES: %d",contImpares);
    printf("\nCANTIDAD DE PRIMOS: %d\n",contPrimos);
    printf("\nTOTAL: %d\n\n",contCeros + contPares + contImpares);
}

