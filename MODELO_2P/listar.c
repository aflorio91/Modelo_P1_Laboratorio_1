#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
void listar(ArrayList* pArrayListPersona)
{
    for (int i = 0; i<pArrayListPersona->len(pArrayListPersona); i++)
    {
        printf("\n%s %s",((ePersona*)pArrayListPersona->get(pArrayListPersona,i))->name, ((ePersona*)pArrayListPersona->get(pArrayListPersona,i))->eMail );

    }
}
