#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"

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
    if(this != NULL)
    {
        printf("%s %s", this->name, this->eMail);
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

int comparar_persona(ePersona* pPersonaAlfa, ePersona* pPersonaBravo)
{
    int retorno = -2;

    if ( pPersonaAlfa != NULL && pPersonaBravo != NULL )
    {
        if ( stricmp(pPersonaAlfa->name, pPersonaBravo->name) == 0  &&  stricmp(pPersonaAlfa->name, pPersonaBravo->name) == 0 )
            {
                retorno = 0;
            }
    }
    return retorno;
}
