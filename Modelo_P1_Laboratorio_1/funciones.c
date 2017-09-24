#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int validarString(char palabra[]) // = 0 => mal
{
    char name[100];
    strcpy(palabra,name);
    int retorno = 1;

    for(int i=0; i<100; i++)
    {
        if(isalpha(name[i] == 1))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int validar_entero(int unEntero)
{
    int result = 0;

    if (unEntero > 0  )
    {
        result = 1;
    }
    return result;
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
    int codigo;
    char descripcion[100];
    int importe;
    int cantidad;
    int codigoProveedor;
    int flag_estado;

    printf("ALTA DE PRODUCTO...");
    printf("\nIngrese codigo de producto:");
    scanf("%d",&codigo);
    while ( codigo <=0 || isalpha(codigo)==1 )
    {
        printf("\nIngrese un codigo de producto valido: ");
        scanf("%d",&codigo);
    }
    printf("\nIngrese descripcion:");
    gets(descripcion);
    while ( validarString(descripcion) == 0 )
    {
        printf("\nIngrese una descripcion valida: ");
        gets(descripcion);
    }
    printf("\nIngrese importe:");
    scanf("%d",&importe);
    while ( importe <=0 || isalpha(importe)==1)
    {
        printf("\nIngrese un importe valido:");
        scanf("%d",&importe);
    }
    printf("\nIngrese cantidad:");
    scanf("%d",&cantidad);
    while ( cantidad <0 || isalpha(cantidad)==1)
    {
        printf("\nIngrese una cantidad valida:");
        scanf("%d",&cantidad);
    }
    printf("\nIngrese codigo de proveedor:");
    scanf("%d",&codigoProveedor);
    while ( codigoProveedor <=0)
    {
        printf("\nIngrese un codigo de proveedor valido:");
        scanf("%d",&codigoProveedor);
    }

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

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese nueva descripcion:");
                    gets(descripcion);
                    while ( validarString(descripcion) == 1 )
                    {
                        printf("\nIngrese una  descripcion valida: ");
                        gets(descripcion);
                    }
                    strcpy(productos[j].descripcion, descripcion);
                    break;
                case 2:
                    printf("\nIngrese nuevo codigo de proveedor:");
                    scanf("%d",&codigoProveedor);
                    while ( codigoProveedor <=0)
                    {
                        printf("\nIngrese un codigo de proveedor valido:");
                        scanf("%d",&codigoProveedor);
                    }
                    printf("\n");
                    productos[j].codigoProveedor = codigoProveedor;
                    break;
                case 3:
                    printf("\nIngrese nuevo importe:");
                    scanf("%d",&importe);
                    while ( importe <=0 || isalpha(importe)==1)
                    {
                        printf("\nIngrese un importe valido:");
                        scanf("%d",&importe);
                    }
                    productos[j].importe = importe;
                    break;
                case 4:
                    printf("\nIngrese nueva cantidad:");
                    scanf("%d",&cantidad);
                    while ( cantidad <0 || isalpha(cantidad)==1)
                    {
                        printf("\nIngrese una cantidad valida:");
                        scanf("%d",&cantidad);
                    }
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
    eProducto prod_mayor;
    eProducto prod_menor;

    for (int i=0; i<10; i++)
    {
        for (int j=i+1; i<10; j++)
        {
            if (productos[i].cantidad < productos[j].cantidad)
            {
                prod_mayor = productos[j];
                productos[j] = productos[i];
                productos[i] = prod_mayor;
            }
        }
    }

    for (int i=0; i<10; i++)
    {
        if (productos[i].flag_estado == 1)
        {
            printf("\nCodigo: %d",productos[0].codigo);
            printf("\nDescripcion: %s",productos[0].descripcion);
            printf("\nImporte: %d",productos[0].importe);
            printf("\Cantidad: %d",productos[0].cantidad);
            printf("\nCodigo de proveedor: %s",productos[0].codigoProveedor);
            break;
        }
    }
    for (int h=10; h>=0; h++)
    {
        if (productos[h].flag_estado == 1)
        {
            printf("\nCodigo: %d",productos[h].codigo);
            printf("\nDescripcion: %s",productos[h].descripcion);
            printf("\nImporte: %d",productos[h].importe);
            printf("\Cantidad: %d",productos[h].cantidad);
            printf("\nCodigo de proveedor: %s",productos[h].codigoProveedor);
            break;
        }
    }
}



















