#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{

    char seguir = 's';
    int opcion = 0;

    eProducto array_Productos[10];
    eProveedor array_Proveedores[10];
    eRelacion array_Relacion[100];
    inicializar_arrays(array_Productos, array_Proveedores);

    while( seguir == 's' )
    {
        printf("1- Alta de Producto.\n");
        printf("2- Modificar Datos de Producto.\n");
        printf("3- Baja del Producto.\n");
        printf("4- Informar Stock.\n");
        printf("5- Listar Productos");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            alta_producto(array_Productos);
            printf("\n");
            fflush(stdin);
            break;
        case 2:
            system("cls");
            modificar_producto(array_Productos);
            printf("\n");
            fflush(stdin);
            break;
        case 3:
            system("cls");
            baja_producto(array_Productos);
            printf("\n");
            fflush(stdin);
            break;
        case 4:
            system("cls");
            informar_stock(array_Productos);
            printf("\n");
            break;
        case 5:
            system("cls");
            printf("\n");
            break;
        case 9:
            printf("Saliendo...");
            seguir = 'n';
            printf("\n");
            break;
        }
    }
    return 0;
}

