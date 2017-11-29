#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "numeroNatural.h"

int* numero_getNumero(eNumero* this)
{
    if(this != NULL)
    {
        return this->numero;
    }
}
void numero_setNumero(eNumero* this, int* unNumero)
{
    if(this != NULL)
    {
        this->numero = unNumero;
    }
}
char* numero_getNombre(eNumero* this)
{
    if(this != NULL)
    {
        return this->nombre;
    }
}
void numero_setNombre(eNumero* this, char* unNombre)
{
    if(this != NULL)
    {
        strcpy(this->nombre, unNombre);
    }
}
int* numero_getPar(eNumero* this)
{
    if(this != NULL)
    {
        return this->par;
    }
}
void numero_setPar(eNumero* this, int* paridad)
{
    if(this != NULL)
    {
        this->par = paridad;
    }
}
int numero_getImpar(eNumero* this)
{
    if(this != NULL)
    {
        return this->impar;
    }
}
void numero_setImpar(eNumero* this, int* paridad)
{
    if(this != NULL)
    {
        this->impar = paridad;
    }
}
int numero_getPrimo(eNumero* this)
{
    if(this != NULL)
    {
        return this->primo;
    }
}
void numero_setPrimo(eNumero* this, int* es_primo)
{
    if(this != NULL)
    {
        this->primo = es_primo;
    }
}
eNumero* numero_new(void)
{
    eNumero* returnAux;
    returnAux = (eNumero*)malloc(sizeof(eNumero));
    if (returnAux != NULL)
    {
        returnAux->numero = 0;
        strcpy(returnAux->nombre, "");
        returnAux->par = 0;
        returnAux->impar = 0;
        returnAux->primo = 0;
    }
    return returnAux;
}
void numero_print(eNumero* this)
{
    if(this != NULL)
    {
        printf("%d %s %d %d %d", this->numero, this->nombre, this->par, this->impar, this->primo);
    }
}
int esPar(int unNumero)
{
    int retorno;

    if ( unNumero % 2 == 0 )
    {
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}
int esPrimo(int unNumero )
{
    int a = 0;
    int retorno;

    for(int i=1; i<=unNumero; i++)
    {
        if(unNumero%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
            a++;
    }
    if(a==2) //Si al final del bucle, a vale 2, el número es primo, porque tiene solamente 2 divisores.
    {
        retorno = 1; //"El número es primo"
    }
    else
    {
        retorno = 0; //"El número no es primo"
    }
    return retorno;
}
int numero_compare(eNumero* numero1, eNumero* numero2)
{
    int retorno = -2;
    if (numero1 != NULL && numero2 != NULL)
    {
        if (numero_getNumero(numero1) < numero_getNumero(numero2) )
        {
            retorno = -1;
        }
        else
        {
            retorno = 1;
        }
        if (numero_getNumero(numero1) == numero_getNumero(numero2) )
        {
            retorno = 0;
        }
    }
    return retorno;
}












