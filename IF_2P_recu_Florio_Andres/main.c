#include <stdio.h>
#include <stdlib.h>
#include "Electra.h"
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int flag;

    ArrayList* lista_letras = al_newArrayList();
    ArrayList* lista_repetidos = al_newArrayList();
    ArrayList* lista_unicos = al_newArrayList();

    if (lista_letras == NULL  )
    {
        printf("\nNo se pudo reservar memoria...");
        exit(1);
    }
    FILE* f = fopen("datos.csv","r");

    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit(1);
    }

    while( seguir == 's' )
    {
        printf("1.- LEER\n");
        printf("2.- COMPLETAR\n");
        //se ingresa un string y se comprueba q las letras esten en la lista
        printf("3.- COMPROBAR\n");
        //printf("4.- LISTA ORDENADA DE MANERA DESCENDENTE CON SOLO REPETIDOS\n");
        printf("5.- LISTA ORDENADA DE MANERA ASCENDENTE SIN REPETIDOS\n");
        printf("6.- LISTAR\n");
        printf("9.- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("***CARGAR DATOS***\n");
            flag =  parser_Letra(f,lista_letras);
            if(flag)
            {
                printf("\nError al parsear archivo letras\n\n");
            }
            else
            {
                printf("\nArchivo letras cargado con exito\n\n");
            }
            listar(lista_letras);
            fflush(stdin);
            break;
        case 2:
            system("cls");
            printf("***COMPLETAR DATOS***\n");
            flag = completar_lista( lista_letras );
            if(flag)
            {
                printf("\nError al completar la lista\n\n");
            }
            else
            {
                printf("\nLista completada con exito\n\n");
            }
            listar(lista_letras);
            fflush(stdin);
            break;
        case 3:
            system("cls");
            printf("***COMPROBAR***\n");

            fflush(stdin);
            break;
        case 4:
            system("cls");
            printf("***LISTA NUEVA ORDENADA DE MANERA DESCENDENTE CON REPETIDOS***\n");
            lista_repetidos = lista_letras->clone(lista_letras);
            ordenar_lista_descendente(lista_repetidos);
            listar(lista_repetidos);
            fflush(stdin);
            break;
        case 5:
            system("cls");
            printf("***LISTA ORDENADA DE MANERA ASCENDENTE SIN REPETIDOS***");
            lista_unicos = lista_letras->clone(lista_letras);
            ordenar_lista_ascendente(lista_unicos);
            quitar_repetidos(lista_unicos);
            listar(lista_unicos);
            fflush(stdin);
            break;
        case 6:
            system("cls");
            printf("***LISTAR***\n");
            listar(lista_letras);
            fflush(stdin);
            break;
        case 9:
            system("cls");
            printf("***Saliendo...***\n");
            seguir = 'n';
            fflush(stdin);
            break;
        }
    }
    return 0;
}
