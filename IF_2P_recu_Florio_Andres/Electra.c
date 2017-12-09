#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Electra.h"

int esSoloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            retorno = 0;
        i++;
    }
    return retorno;
}
eLetra* letra_new(void)
{
    eLetra* returnAux;
    returnAux = (eLetra*)malloc(sizeof(eLetra));
    if (returnAux != NULL)
    {
        strcpy(returnAux->letra, "");
        /*returnAux->letra = '\0';*/
        strcpy(returnAux->nombre, "");
        returnAux->vocal = 0;
        returnAux->consonante = 0;
    }
    return returnAux;
}
void letra_print(eLetra* this)
{
    if(this != NULL)
    {
        printf("%s %s %d %d", this->letra, this->nombre, this->vocal, this->consonante);
    }
}
char* letra_getLetra(eLetra* this)
{
    if(this != NULL)
    {
        return this->letra;
    }
}
void letra_setVocal(eLetra* this, int* binario)
{
    if(this != NULL)
    {
        this->vocal = binario;
    }
}
void letra_setConsonante(eLetra* this, int* binario)
{
    if(this != NULL)
    {
        this->consonante = binario;
    }
}
int esVocal(char letra)
{
    int retorno = 1;
    if( letra != '\0')
    {
        switch( letra )
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int letra_compare(eLetra* letra_Alfa, eLetra* letra_Beta)
{
    if ( ((eLetra*)letra_Alfa)->letra >((eLetra*)letra_Beta)->letra )
    {
        return 1;
    }
    if ( ((eLetra*)letra_Alfa)->letra < ((eLetra*)letra_Beta)->letra )
    {
        return -1;
    }
    return 0;
}











