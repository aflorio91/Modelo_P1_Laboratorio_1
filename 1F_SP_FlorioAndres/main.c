#include <stdio.h>
#include <stdlib.h>
#include "numeroNatural.h"
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int flag;

    ArrayList* lista_numeros = al_newArrayList();
    ArrayList* lista_ordenada = al_newArrayList();

    if (lista_numeros == NULL && lista_ordenada != NULL)
    {
        printf("\nNo se pudo reservar memoria...");
        exit(1);
    }
    FILE* f = fopen("datos2.csv","r");

    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit(1);
    }
    while( seguir == 's' )
    {
        printf("1- LEER\n");
        printf("2- COMPLETAR\n");
        printf("3- ORDENAR\n");
        printf("4- INFORMAR\n");
        printf("5- Salir\n");
        printf("6- Listar lista_numeros\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n***CARGAR DATOS***\n");
            flag = parserNumero(f,lista_numeros);
            if(flag)
            {
                printf("\nError al parsear archivo numeros\n\n");
            }
            else
            {
                printf("\nArchivo numeros cargado con exito\n\n");
            }
            fflush(stdin);
            break;
        case 2:
            system("cls");
            flag = completar_lista(lista_numeros);
            if (flag)
            {
                printf("\nError al completar lista de numeros\n\n");
            }
            else
            {
                printf("\nLista completada con exito\n\n");
            }
            fflush(stdin);
            break;
        case 3:
            system("cls");
            printf("\n***ORDENAR***\n");
            lista_ordenada = ordernar_lista(lista_numeros, lista_ordenada);

            listar(lista_ordenada);
            fflush(stdin);
            break;
        case 4:
            system("cls");
            fflush(stdin);
            break;
        case 5:
            system("cls");
            printf("***Saliendo...***\n");
            seguir = 'n';
            fflush(stdin);
            break;
        case 6:
            system("cls");

            fflush(stdin);
            break;
        }
    }
    return 0;
}
