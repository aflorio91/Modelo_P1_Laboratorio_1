#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "persona.h"
#include "parser.h"
#include "listar.h"
#include "depurar.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int flag;

    ArrayList* lista = al_newArrayList();
    ArrayList* lista_negra = al_newArrayList();
    ArrayList* lista_depurada = al_newArrayList();

    if (lista == NULL || lista_negra == NULL)
    {
        printf("\nNo se pudo reservar memoria...");
        exit(1);
    }
    FILE* f = fopen("destinatarios.csv","r");
    FILE* f_blackList = fopen("black_list.csv","r");
    if(f == NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit(1);
    }
    while( seguir == 's' )
    {
        printf("1- CARGAR DESTINATARIOS\n");
        printf("2- CARGAR LISTA NEGRA\n");
        printf("3- DEPURAR\n");
        printf("4- LISTAR\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            flag = parser_destinatarios(f, lista);
            if(flag)
            {
                printf("\nError al parsear archivo destinatarios\n\n");
            }
            else
            {
                printf("\nArchivo destinatarios cargado con exito\n\n");
            }
            printf("\n");
            fflush(stdin);
            break;
        case 2:
            system("cls");
            flag = parser_lista_negra(f_blackList, lista_negra);
            if(flag)
            {
                printf("\nError al parsear archivo black_list\n\n");
            }
            else
            {
                printf("\nArchivo black_list cargado con exito\n\n");
            }
            printf("\n");
            fflush(stdin);
            break;
        case 3:
            system("cls");
            depurar_listas(lista,lista_negra,lista_depurada);
            //quitar_repetidos(lista_depurada);
            fflush(stdin);
            break;
        case 4:
            system("cls");
            listar(lista_depurada);
            fflush(stdin);
            break;
        case 5:
            system("cls");
            printf("\nSaliendo...\n");
            seguir = 'n';
            fflush(stdin);
            break;
        }
    }
    return 0;
}
