#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
int parser_destinatarios(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[100];
    char auxEMail[100];

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return 1;
    }

    while(!feof(pFile))
    {
        ePersona* nuevaPersona;

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
int parser_lista_negra(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[20];
    char auxEMail[40];

    ePersona* nuevaPersona;
    /*
        if (pFile == NULL || pArrayListPersona == NULL)
        {
            return -1;
        }*/

    while(!feof(pFile))
    {
        fscanf(pFile,"%s[^,],%s\n",auxName, auxEMail);
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            strcpy(nuevaPersona->name, auxName);
            strcpy(nuevaPersona->eMail, auxEMail);

        }
        pArrayListPersona->add(pArrayListPersona, nuevaPersona);
    }
    return 0;
}
