#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
#include "lista.h"

int parser_destinatarios(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[100];
    char auxEMail[100];
    ePersona* nuevaPersona;

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return 1;
    }
    while(!feof(pFile))
    {
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            fscanf(pFile,"%s[^,],%s\n",auxName, auxEMail);
            //fscanf(pFile,"%s[^,],%s[^\n]",auxName, auxEMail);
            strcpy(nuevaPersona->name, auxName);
            strcpy(nuevaPersona->eMail, auxEMail);
            pArrayListPersona->add(pArrayListPersona, nuevaPersona);
        }
    }
    return 0;
}

void listar(ArrayList* lista)
{
    printf("\n***Listando***\n");
    ePersona* unaPersona;
    for(int i=0; i < lista->len(lista); i++)
    {
        unaPersona = (ePersona*)lista->get(lista, i);
        persona_print(unaPersona);
    }
}

int parser_lista_negra(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[100];
    char auxEMail[100];
    ePersona* nuevaPersona;

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return 1;
    }
    while(!feof(pFile))
    {
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            fscanf(pFile,"%s[^,],%s\n",auxName, auxEMail);
            strcpy(nuevaPersona->name, auxName);
            strcpy(nuevaPersona->eMail, auxEMail);
            pArrayListPersona->add(pArrayListPersona, nuevaPersona);
        }
    }
    return 0;
}

void depurar_listas(ArrayList* lista, ArrayList* lista_negra, ArrayList* lista_depurada)
{
    char auxName[100];
    char auxEMail[100];
    char auxName2[100];
    char auxEMail2[100];
    ePersona* auxPersona;

    for (int i = 0; i<lista->len(lista); i++)
    {
        strcpy(auxName,((ePersona*)lista->get(lista,i))->name );
        strcpy(auxEMail,((ePersona*)lista->get(lista,i))->eMail );

        for (int j = 0; j<lista_negra->len(lista_negra); j++)
        {
            strcpy(auxName2,((ePersona*)lista_negra->get(lista_negra,j))->name );
            strcpy(auxEMail2,((ePersona*)lista_negra->get(lista_negra,j))->eMail );

            if ( strcmp(auxName,auxName2)==0 && strcmp(auxEMail,auxEMail2)==0 )
            {
                break;
            }
            else
            {
                if (auxPersona != NULL)
                {
                    auxPersona = persona_new();
                    auxPersona = (ePersona*)lista->get(lista,i);
                    lista_depurada->set(lista_depurada,i,auxPersona);
                }
            }
        }
    }
}

void quitar_repetidos(ArrayList* lista_depurada)
{
    char auxName[100];
    char auxEMail[100];
    char auxName2[100];
    char auxEMail2[100];

    for (int i = 0; i<lista_depurada->len(lista_depurada); i++)
    {
        strcpy(auxName,((ePersona*)lista_depurada->get(lista_depurada,i))->name );
        strcpy(auxEMail,((ePersona*)lista_depurada->get(lista_depurada,i))->eMail );

        for (int j = i+1; j<lista_depurada->len(lista_depurada); j++)
        {
            strcpy(auxName2,((ePersona*)lista_depurada->get(lista_depurada,j))->name );
            strcpy(auxEMail2,((ePersona*)lista_depurada->get(lista_depurada,j))->eMail );

            if ( strcmp(auxName,auxName2)==0 && strcmp(auxEMail,auxEMail2)==0 )
            {
                al_remove(lista_depurada, j);
            }
        }
    }
}
