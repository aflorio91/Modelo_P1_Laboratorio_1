#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "persona.h"
#include "parser.h"
#include "listar.h"
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









