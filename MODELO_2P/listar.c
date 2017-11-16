#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "persona.h"
void listar(ArrayList* lista)
{
    printf("\n");
    for (int i = 0; i<lista->len(lista); i++)
    {
        printf( "%s %s \n",((ePersona*)lista->get(lista,i))->name, ((ePersona*)lista->get(lista,i))->eMail );
        //persona_print( (ePersona*)lista->get(lista,i) );
    }
}
