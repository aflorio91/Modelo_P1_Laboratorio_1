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

void persona_print(ePersona* this)
{
    if(this !=NULL)
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
/*
void persona_block(ePersona* this)
{
    if (this != NULL)
    {
        this->black_listed = 1;
    }
}*/
