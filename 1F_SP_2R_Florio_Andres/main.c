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
    char binario;

    ArrayList* lista_numeros = al_newArrayList();

    if (lista_numeros == NULL  )
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
        printf("1.- LEER (parser ArrayList)\n");
        printf("2.- COMPLETAR\n");
        printf("3.- ORDENAR y QUITAR REPETIDOS\n");
        printf("4.- INFORMAR\n");
        printf("5.- Salir\n");
        printf("6.- Grabar archivo .csv con la lista\n");
        printf("7.- Grabar archivo .bin con la lista\n");
        printf("8.- Mostrar el contenido de la lista actual por pantalla\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("***CARGAR DATOS***\n");
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
            printf("***COMPLETAR CAMPOS (par, impar, primo)***\n");
            flag = al_isEmpty(lista_numeros);
            if (flag)
            {
                printf("\nERROR: la lista cargada esta vacia! \nNo se puede realizar el autocompletado sin antes haber parseado el archivo al ArrayList!\n\n");
                break;
            }
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
            printf("***ORDENAR y QUITAR REPETIDOS***\n"); //no muestro por pantalla si funcionan. Evitar uso de funciones tipadas en VOID.
            ordernar_lista(lista_numeros);
            quitarRepetidos_lista(lista_numeros);
            printf("\n");
            fflush(stdin);
            break;
        case 4:
            system("cls");
            printf("***INFORMAR***\n");
            informar(lista_numeros);
            fflush(stdin);
            break;
        case 5:
            system("cls");
            printf("Saliendo...\n");
            seguir = 'n';
            fflush(stdin);
            break;
        case 6:
            system("cls");
            printf("***GRABAR ARCHIVO .CSV CON LA LISTA***\n");
            flag = grabar_CSV(lista_numeros);
            if (flag)
            {
                printf("\nError al guardar el archivo SALIDA.csv\n");
            }
            else
            {
                printf("\nArchivo de lista SALIDA.csv generado con exito\n\n");
            }
            break;
        case 7:
            system("cls");
            printf("***GRABAR ARCHIVO .BIN CON LA LISTA***\n");
            flag = grabar_BIN(lista_numeros);
            if (flag)
            {
                printf("\nError al grabar el archivo SALIDA.bin\n");
            }
            else
            {
                printf("\nArchivo de lista SALIDA.bin generado con exito\n\n");
                printf("\nDesea abrirlo?\nY/N\n\n");
                scanf("%c",&binario);
                if ( binario == 'y' || binario == 'Y')
                {
                    leer_BIN();
                }
                else
                {
                    break;
                }
            }
            break;
        case 8:
            system("cls");
            printf("***MOSTRAR LISTA POR PANTALLA***");
            flag = al_isEmpty(lista_numeros);
            if (flag)
            {
                printf("\nERROR: la lista cargada esta vacia!\n\n");
                break;
            }
            else
            {
                listar(lista_numeros);
                break;
            }
        }
    }
    return 0;
}
