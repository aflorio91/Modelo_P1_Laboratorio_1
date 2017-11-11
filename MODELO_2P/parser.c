#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"

int parser_destinatarios(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[20];
    char auxEMail[40];
    char auxBlack_listed;

    ePersona* nuevaPersona;

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        fscanf(pFile,"%s[^,],%s\n",auxName, auxEMail);
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            strcpy(nuevaPersona->name, auxName);
            strcpy(nuevaPersona->eMail, auxEMail);
            nuevaPersona->black_listed = 0;
        }
        pArrayListPersona->add(pArrayListPersona, nuevaPersona);
    }
    return 0;
}

int parser_lista_negra(FILE* pFile, ArrayList* pArrayListPersona)
{
    char auxName[20];
    char auxEMail[40];
    char auxBlack_listed;

    ePersona* nuevaPersona;

    if (pFile == NULL || pArrayListPersona == NULL)
    {
        return -1;
    }

    while(!feof(pFile))
    {
        fscanf(pFile,"%s[^,],%s\n",auxName, auxEMail);
        nuevaPersona = persona_new();
        if (nuevaPersona != NULL)
        {
            strcpy(nuevaPersona->name, auxName);
            strcpy(nuevaPersona->eMail, auxEMail);
            nuevaPersona->black_listed = 1;
        }
        pArrayListPersona->add(pArrayListPersona, nuevaPersona);
    }
    return 0;
}
/*
ArrayList* depurar_lista(ArrayList* pArrayListPersona, ArrayList* black_list)
{

}*/


















