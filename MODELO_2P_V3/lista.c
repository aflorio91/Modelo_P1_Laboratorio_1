#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
#include "lista.h"

int parser_lista(FILE* pFile, ArrayList* pArrayListPersona)
{
    int retorno = 1;
    ePersona* nuevaPersona;

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return retorno;
    }
    while(!feof(pFile))
    {
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            fscanf(pFile,"%[^,],%[^\n]\n",nuevaPersona->name,nuevaPersona->eMail);
            if ( pArrayListPersona->add(pArrayListPersona, nuevaPersona) == -1 )
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
    ePersona* unaPersona;
    for(int i=0; i < al_len(lista); i++)
    {
        unaPersona = (ePersona*)lista->get(lista, i);
        persona_print(unaPersona);
        printf("\n");
    }
}

int isBlackListed(ePersona* unaPersona, ArrayList* lista_negra)
{
    int retorno = -1;
    ePersona* auxPersona = (ePersona*) unaPersona;
    ArrayList* listaNegra = (ArrayList*) lista_negra;

    if(auxPersona != NULL && listaNegra != NULL)
    {
        retorno = 1; //no esta en la lista negra
        for (int i = 0; i<al_len(listaNegra); i++)
        {
            ePersona* auxPersonaListaNegra = al_get(listaNegra,i);
            if ( strcmp(auxPersonaListaNegra->eMail, auxPersona->eMail) ==0 )
            {
                retorno = 0; //Devuelve 0 si esta en la lista negra y no hay que agregarlo a la lista depurada
                break;
            }
        }
    }
    return retorno;
}

ArrayList* depurar_lista(ArrayList* lista_destinatarios, ArrayList* lista_negra, ArrayList* lista_depurada )
{
    ePersona* auxPersona;
    ArrayList* destinatarios = (ArrayList*) lista_destinatarios;
    ArrayList* listaNegra = (ArrayList*) lista_negra;
    ArrayList* listaDepurada = (ArrayList*) lista_depurada;

    for ( int i=0; i<al_len(destinatarios); i++)
    {
        auxPersona = al_get(destinatarios,i);
        if ( isBlackListed(auxPersona,listaNegra) == 1 )
        {
            al_add(listaDepurada,auxPersona);
        }
    }
    return listaDepurada;
}

void quitar_repetidos(ArrayList* lista_depurada)
{
    return;
}

int crear_archivo_lista_depurada(ArrayList* lista_depurada)
{
    int i, retorno = 1;
    ePersona* pPersona = NULL;

    FILE* LISTA_DEPURADAtxt = fopen ("LISTA_DEPURADA.txt", "w");

    if( LISTA_DEPURADAtxt != NULL )
    {
        for(i=0; i<al_len(lista_depurada); i++)
        {
            pPersona = al_get(lista_depurada, i);
            fprintf(LISTA_DEPURADAtxt,"%s,%s\n", pPersona->name, pPersona->eMail);
            retorno = 0;
        }
    }
    fclose (LISTA_DEPURADAtxt);
    return retorno;
}
