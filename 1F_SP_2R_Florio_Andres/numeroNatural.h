#ifndef NUMERONATURAL_H_INCLUDED
#define NUMERONATURAL_H_INCLUDED

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
} eNumero;
int* numero_getNumero(eNumero* this);
void numero_setNumero(eNumero* this, int* unNumero);
char* numero_getNombre(eNumero* this);
void numero_setNombre(eNumero* this, char* unNombre);
int* numero_getPar(eNumero* this);
void numero_setPar(eNumero* this, int* paridad);
int numero_getImpar(eNumero* this);
void numero_setImpar(eNumero* this, int* paridad);
int numero_getPrimo(eNumero* this);
void numero_setPrimo(eNumero* this, int* es_primo);
eNumero* numero_new(void);
void numero_print(eNumero* this);
int esPar(int unNumero);
int esPrimo(int unNumero);
int numero_compare(eNumero* numeroAlfa, eNumero* numeroBeta);
#endif // NUMERONATURAL_H_INCLUDED
