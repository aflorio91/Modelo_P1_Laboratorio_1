#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
/*
int persona_isBlackListed(void* ePersonaA,void* ePersonaB)
{
    int retorno = 1;
    if(ePersonaA != NULL && ePersonaB != NULL)
    {
        if ( strcmp( ePersonaA->name, ePersonaB->name)==0 && strcmp( ePersonaA->eMail, ePersonaB->eMail )==0 )
            ePersonaA->black_listed = 1;
        retorno = 0;
    }
    return retorno;
}*/

char* persona_getName(ePersona* this)
{
    if(this != NULL)
    {
        return this->name;
    }
}
void persona_setName(ePersona* this, char* nombre)
{
    if(this != NULL)
    {
        strcpy(this->name, nombre);
    }
}
char* persona_getEMail(ePersona* this)
{
    if(this != NULL)
    {
        return this->eMail;
    }
}
void persona_setEMail(ePersona* this, char* correo)
{
    if(this != NULL)
    {
        strcpy(this->eMail, correo);
    }
}
void persona_print(ePersona* this)
{
    if(this !=NULL)
    {
        printf("%s %s\n", this->name, this->eMail);
    }
}

ePersona* persona_new(void)
{
    ePersona* returnAux;
    returnAux = (ePersona*)malloc(sizeof(ePersona));
    if (returnAux != NULL)
    {
        strcpy(returnAux->name, "");
        strcpy(returnAux->eMail, "");
    }
    return returnAux;
}
