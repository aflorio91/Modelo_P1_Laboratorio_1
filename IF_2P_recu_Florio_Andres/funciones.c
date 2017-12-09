#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Electra.h"
#include "ArrayList.h"
int parser_Letra(FILE* pFile, ArrayList* lista)
{
    int retorno = 1;
    char auxLetra[10];
    char auxNombre[51];
    char auxVocal[10];
    char auxConsonante[10];
    eLetra* nuevaLetra;

    if(pFile == NULL || lista == NULL)
    {
        return retorno;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxLetra,auxNombre,auxVocal,auxConsonante);

    while(!feof(pFile))
    {
        nuevaLetra = letra_new();

        if(nuevaLetra != NULL)
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxLetra,auxNombre,auxVocal,auxConsonante);
            strcpy(nuevaLetra->letra, auxLetra);
            strcpy(nuevaLetra->nombre, auxNombre);
            nuevaLetra->vocal = atoi(auxVocal);
            nuevaLetra->consonante = atoi(auxConsonante);

            /*
                        nuevaLetra->letra = auxLetra[0];
                        strcpy(nuevaLetra->nombre, auxNombre);
                        nuevaLetra->vocal = atoi(auxVocal);
                        nuevaLetra->consonante = atoi(auxConsonante);*/

            if ( lista->add(lista, nuevaLetra) == -1 )
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
    eLetra* unaLetra;
    if ( lista != NULL)
    {
        printf("\nletra, nombre, vocal, consonante\n");
        for(int i=0; i < al_len(lista); i++)
        {
            //printf("\nINDICE: %d ",i);
            unaLetra = (eLetra*)lista->get(lista, i);
            letra_print(unaLetra);
            printf("\n");
        }
    }
}
int completar_lista(ArrayList* lista)
{
    int retorno = 1;
    eLetra* auxLetra;
    char letter;

    if (lista != NULL)
    {
        for (int i = 0; i<lista->len(lista); i++)
        {
            auxLetra = lista->get(lista,i);

            if (auxLetra != NULL)
            {
                letter = letra_getLetra(auxLetra);

                if (esVocal(letter)==0)
                {
                    letra_setVocal(auxLetra,1);
                    letra_setConsonante(auxLetra,0);
                }
                else
                {
                    letra_setVocal(auxLetra,0);
                    letra_setConsonante(auxLetra,1);
                }

                lista->set(lista, i, auxLetra);
            }
        }
        retorno = 0;
    }
    return retorno;
}
void ordenar_lista_ascendente(ArrayList* lista)
{
    if ( lista != NULL )
    {
        lista->sort(lista,letra_compare,1);
    }
}
void ordenar_lista_descendente(ArrayList* lista)
{
    if ( lista != NULL )
    {
        lista->sort(lista,letra_compare,0);
    }
}/*
void quitar_repetidos(ArrayList* lista)
{
    eLetra* auxLetra;
    int largo = lista->len(lista);

    if ( lista != NULL  )
    {
        for (int i = 0; i<largo; i++)
        {
            auxLetra = lista->get(lista,i);
            for (int j = i+1; j<largo; )
            {
                if ( letra_compare(auxLetra,lista+j) == 0)
                {
                     lista->remove(lista,j);
                }
                else
                {
                    j++;
                }
            }
            lista->add(lista,auxLetra);
        }
    }
}*/
void quitar_repetidos(ArrayList* lista) //version Mage
{
    eLetra* auxLetra;
    eLetra* auxLetra2;
    int i,j;

    if ( lista != NULL  )
    {
        for (i = 0; i<lista->len(lista); i++)
        {
            auxLetra = lista->get(lista,i);
            for ( j = i+1; j<lista->len(lista);)
            {
                auxLetra2 = lista->get(lista,j);
                if ( letra_compare(auxLetra,auxLetra2) == 0)
                {
                    lista->remove(lista,j);
                }
                else
                {
                    j++;
                }
            }
        }
    }
}



