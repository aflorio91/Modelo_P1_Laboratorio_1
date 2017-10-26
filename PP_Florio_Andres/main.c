#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    char seguir = 's';
    int opcion = 0;

    eCliente array_clientes[10];
    eAlquiler array_alquileres[10];
    eRelacion array_relaciones[10];

    precargar_arrays(array_clientes,array_alquileres,array_relaciones);

    while( seguir == 's' )
    {
        printf("1- Alta de Cliente.\n");
        printf("2- Modificar Datos del Cliente.\n");
        printf("3- Baja del Cliente.\n");
        printf("4- Nuevo Alquiler.\n");
        printf("5- Terminar Alquiler.\n");
        printf("6- Informar.\n");
        printf("7- Listar clientes.\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            alta_cliente(array_clientes);
            printf("\n");
            fflush(stdin);
            break;
        case 2:
            system("cls");
            modificar_cliente(array_clientes);
            printf("\n");
            fflush(stdin);
            break;
        case 3:
            system("cls");
            baja_cliente(array_clientes);
            printf("\n");
            fflush(stdin);
            break;
        case 4:
            system("cls");
            nuevo_alquiler(array_clientes, array_alquileres, array_relaciones);
            printf("\n");
            break;
        case 5:
            system("cls");
            terminar_alquiler(array_alquileres);
            printf("\n");
            break;
        case 6:
            system("cls");
            informar(array_relaciones);
            printf("\n");
            break;
        case 7:
            system("cls");
            listar_clientes(array_clientes);
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
