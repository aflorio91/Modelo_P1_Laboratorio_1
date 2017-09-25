#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

void inicializar_arrays(eProducto productos[], eProveedor proveedores[])
{

    for ( int i = 0; i<10; i++)
    {
        productos[i].flag_estado = 0;
        proveedores[i].flag_estado = 0;
    }

    int codigo[3] = {{4523},{1478},{5546}};
    char descripcion[3][100] = {{"queso"},{"jamon"},{"fideos"}};
    int importe[3] = {{125},{30},{70}};
    int cantidad[3] = {{30},{15},{50}};
    int codigoProveedor[3] = {{33},{65},{88}};
    int flag_estado[3] = {{1},{1},{1}};

    int prov_codigo[3] = {{1},{2},{3}};
    char prov_descripcion[3][100] = {{"proveedor primero"},{"segundo proveedor"},{"tercer proveedor"}};
    int prov_flag_estado[3] = {{1},{1},{1}};

    for ( int j = 0; j<3; j++)
    {
        productos[j].codigo = codigo[j];
        strcpy(productos[j].descripcion, descripcion[j]);
        productos[j].importe = importe[j];
        productos[j].cantidad = cantidad[j];
        productos[j].codigoProveedor = codigoProveedor[j];
        productos[j].flag_estado = flag_estado[j];
    }
    for (int k = 0; k<3; k++)
    {
        proveedores[k].codigo = prov_codigo[k];
        strcpy(proveedores[k].descripcion, prov_descripcion[k]);
        proveedores[k].flag_estado = prov_flag_estado[k];
    }
}

void alta_producto(eProducto productos[])
{
    char input[30];
    int codigo;
    char descripcion[100];
    int importe;
    int cantidad;
    int codigoProveedor;
    int flag_estado;

    printf("ALTA DE PRODUCTO...");
    fflush(stdin);
    printf("\nIngrese codigo de producto:");
    gets(input);
    while ( esNumerico(input) == 0 || atoi(input) <=0  )
    {
        printf("\nIngrese un codigo de producto valido: ");
        gets(input);
    }
    codigo = atoi(input);

    printf("\nIngrese descripcion:");
    fflush(stdin);
    gets(descripcion);
    while ( esSoloLetras(descripcion) == 0 )
    {
        printf("\nIngrese una descripcion valida:");
        gets(descripcion);
    }

    printf("\nIngrese importe:");
    gets(input);
    while ( esNumerico(input) == 0 || atoi(input) < 0 )
    {
        printf("\nIngrese un importe valido:");
        gets(input);
    }
    importe = atoi(input);

    printf("\nIngrese cantidad:");
    gets(input);
    while ( atoi(input) <0 || esNumerico(input) == 0  )
    {
        printf("\nIngrese una cantidad valida:");
        gets(input);
    }
    cantidad = atoi(input);

    printf("\nIngrese codigo de proveedor:");
    gets(input);
    while ( esNumerico(input) == 0 || atoi(input) < 0 )
    {
        printf("\nIngrese un codigo de proveedor valido:");
        gets(input);
    }
    codigoProveedor = atoi(input);

    for (int i=0; i<10; i++)
    {
        if ( productos[i].flag_estado == 0)
        {
            productos[i].codigo = codigo;
            strcpy(productos[i].descripcion, descripcion);
            productos[i].importe = importe;
            productos[i].cantidad = cantidad;
            productos[i].codigoProveedor = codigoProveedor;
            productos[i].flag_estado = 1;
            break;
        }
    }
}

void modificar_producto(eProducto productos[])
{
    char input[30];
    int codigo;
    char descripcion[100];
    int importe;
    int cantidad;
    int codigoProveedor;
    int flag_estado;

    char seguir = 's';
    int opcion = 0;

    printf("MODIFICAR PRODUCTO...");
    printf("\nIngrese codigo de producto:");
    scanf("%d",&codigo);
    while ( codigo <=0 || isalpha(codigo)==1 )
    {
        printf("\nIngrese un codigo de producto valido: ");
        scanf("%d",&codigo);
    }
    for (int j=0; j<10; j++)
    {
        if (productos[j].codigo == codigo && productos[j].flag_estado == 1 )
        {
            while( seguir == 's' ) //podria haber anidado esto
            {
                printf("\n1.-Modificar descripcion.");
                printf("\n2.-Modificar codigo de proveedor.");
                printf("\n3.-Modificar importe.");
                printf("\n4.-Modificar cantidad.");
                printf("\n5.-Terminar");

                scanf("%d",&opcion);
                fflush(stdin);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese nueva descripcion:");
                    gets(descripcion);
                    while ( esSoloLetras(descripcion) == 0 )
                    {
                        printf("\nIngrese una  descripcion valida: ");
                        gets(descripcion);
                    }
                    strcpy(productos[j].descripcion, descripcion);
                    break;
                case 2:
                    printf("\nIngrese nuevo codigo de proveedor:");
                    gets(input);
                    while ( esNumerico(input) == 0 || atoi(input) < 0 )
                    {
                        printf("\nIngrese un codigo de proveedor valido:");
                        gets(input);
                    }
                    codigoProveedor = atoi(input);
                    printf("\n");
                    productos[j].codigoProveedor = codigoProveedor;
                    break;
                case 3:
                    printf("\nIngrese nuevo importe:");
                    gets(input);
                    while ( esNumerico(input) == 0 || atoi(input) < 0 )
                    {
                        printf("\nIngrese un importe valido:");
                        gets(input);
                    }
                    importe = atoi(input);
                    productos[j].importe = importe;
                    break;
                case 4:
                    printf("\nIngrese nueva cantidad:");
                    gets(input);
                    while ( atoi(input) <0 || esNumerico(input) == 0  )
                    {
                        printf("\nIngrese una cantidad valida:");
                        gets(input);
                    }
                    cantidad = atoi(input);
                    productos[j].cantidad = cantidad;
                    break;
                case 5:
                    printf("Saliendo...");
                    seguir = 'n';
                    printf("\n");
                    break;
                }
            }
        }
        else
        {
            printf("\nNo hubo coincidencias...");
        }
    }
}

void baja_producto(eProducto productos[])
{
    int codigo;
    printf("\nIngrese Codigo de producto a dar de baja:");
    scanf("%d",&codigo);

    for (int i=0; i<10; i++)
    {
        if ( productos[i].codigo == codigo)
        {
            productos[i].flag_estado = 0;
        }
    }
}

void informar_stock(eProducto productos[])
{
    eProducto mayor;
    eProducto menor;

    for (int i=0; i<10; i++)
    {
        for (int j=i+1; j<9; j++)
        {
            if ( productos[i].cantidad > productos[j].cantidad && productos[i].flag_estado == 1 && productos[j].flag_estado == 1 )
            {
                mayor = productos[i];
            }
        }
    }

    for (int i=0; i<10; i++)
    {
        for (int j=i+1; j<9; j++)
        {
            if ( productos[i].cantidad < productos[j].cantidad && productos[i].flag_estado == 1 && productos[j].flag_estado == 1  )
            {
                menor = productos[i];
            }
        }
    }
    printf("\n****Producto con menor cantidad:****");
    printf("\nCANTIDAD: %d", menor.cantidad );
    printf("\nCODIGO: %d", menor.codigo);
    printf("\nDESCRIPCION: %s", menor.descripcion);
    printf("\nIMPORTE: %d", menor.importe);
    printf("\nCODIGO PROVEEDOR: %d\n", menor.codigoProveedor);
    printf("\n****Producto con mayor cantidad:****");
    printf("\nCANTIDAD: %d", mayor.cantidad );
    printf("\nCODIGO: %d", mayor.codigo);
    printf("\nDESCRIPCION: %s", mayor.descripcion);
    printf("\nIMPORTE: %d", mayor.importe);
    printf("\nCODIGO PROVEEDOR: %d\n", mayor.codigoProveedor);
}
