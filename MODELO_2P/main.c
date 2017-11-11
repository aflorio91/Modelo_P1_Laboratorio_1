#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "persona.h"
#include "parser.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int flag;

    //ArrayList* subLista;
    //ePersona* auxPersona;
    ArrayList* lista = al_newArrayList();
    ArrayList* lista_negra = al_newArrayList();

    if (lista == NULL || lista_negra == NULL)
    {
        printf("\nNo se pudo reservar memoria...");
        exit(1);
    }
    FILE* f = fopen("destinatarios.csv","r");
    FILE* f_blackList = fopen("black_list.csv","r");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo");
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
            for (int i=0; i<1000; i++)
            {
                for(int h=0; h<1000; h++)
                {
                    if ( strcmp( lista->get(lista,i)), lista->get(lista,j)  )
                    }
            }

            fflush(stdin);
            break;
        }
    }
    return 0;
}
