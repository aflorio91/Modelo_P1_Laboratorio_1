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
int ordernar_lista(ArrayList* lista, ArrayList* lista_depurada)
{
    int retorno = 1;
    eNumero* auxNumero;
    eNumero* numero_mayor;
    int numero1,numero2;
    int flag = 0;

    if ( lista != NULL && lista_depurada != NULL )
    {
        for(int i=0; i<lista->len(lista); i++)
        {
            auxNumero = lista->get(lista,i);
            if (flag == 0)
            {
                numero_mayor = auxNumero;
            }
            if(auxNumero != NULL)
            {
                //printf("\nLLEGA");
                numero1 = numero_getNumero(auxNumero);
                numero2 = numero_getNumero(numero_mayor);
                if ( numero1 < numero2 || flag == 0)
                {
                    numero_mayor == auxNumero;
                    flag = 1;
                }
            }
            lista->add(lista_depurada,numero_mayor);
            if (i == lista->len(lista) - 1)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}


















