#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

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

int esDNI(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if( str[i] < '0' || str[i] > '9' || strlen(str) > 8)
            return 0;
        i++;
    }
    return 1;
}

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
void precargar_arrays(eCliente clientes[], eAlquiler alquileres[], eRelacion relaciones[])
{
    for ( int i=0; i<10; i++)
    {
        clientes[i].id = 0;
        clientes[i].flag_estado = 0;
        alquileres[i].flag_estado = 0;
        relaciones[i].flag_estado = 0;
    }

    int id_cliente[5] = {{1},{2},{3},{4},{5}};
    int dni[5] = {{28937021},{29476098},{26924712},{25998546},{22998323}};
    char nombre[5][15] = {{"Eliana"},{"Ludmila"},{"Lucas"},{"Mariana"},{"Hernan"}};
    char apellido[5][15] = {{"Behrens"},{"Ribles"},{"Manoukian"},{"Torrado"},{"Diaz"}};
    int flag_estado[5] = {{1},{1},{1},{1},{0}};

    int id_equipo[5] = {{1345},{332},{5433},{874},{25}};
    char equipo[5][15] = {{"TALADRO NEUMATICO"},{"SIERRA ELECTRICA"},{"MARTILLO"},{"CUCHARA"},{"BOLEADORA"}};
    int tiempo_est[5] = {{3},{2},{3},{5},{88}};
    int tiempo_real[5] = {{4},{4},{5},{6},{99}};
    char operador[5][15] = {{"Ivana"},{"Mirtha"},{"Carla"},{"Maria"},{"Angela"}};

    for (int j=0; j<10; j++)
    {
        clientes[j].id = id_cliente[j];
        clientes[j].dni = dni[j];
        strcpy(clientes[j].nombre, nombre[j]);
        strcpy(clientes[j].apellido, apellido[j]);
        clientes[j].flag_estado = flag_estado[j];
    }
    for (int k=0; k<10; k++)
    {
        alquileres[k].id_equipo = id_equipo[k];
        strcpy(alquileres[k].equipo, equipo[k]);
        alquileres[k].tiempo_est = tiempo_est[k];
        alquileres[k].tiempo_real = tiempo_real[k];
        strcpy(alquileres[k].operador, operador[k]);
        alquileres[k].flag_estado = flag_estado[k];
    }
    for (int h=0; h<10; h++)
    {
        relaciones[h].id_cliente = id_cliente[h];
        relaciones[h].id_equipo = id_equipo[h];
        relaciones[h].flag_estado = flag_estado[h];
    }
}

void alta_cliente(eCliente clientes[])
{
    char input[20];
    int i_id = 0;
    int ultima_id = 0;
    int i_dni;
    char i_nombre[15];
    char i_apellido[15];


    for (int i=0; i<10; i++)
    {
        if ( clientes[i].id > ultima_id && clientes[i].flag_estado == 1)
        {
            ultima_id  = clientes[i].id;
        }
    }
    i_id = ultima_id +1;
    printf("\n***Alta de cliente ID=%d***\n",i_id);
    fflush(stdin);
    printf("Ingrese DNI: ");
    gets(input);
    while (esDNI(input) == 0 || atoi(input) ==0 )
    {
        printf("\nIngrese un numero entero valido para DNI...");
        gets(input);
    }
    i_dni = atoi(input);

    fflush(stdin);
    printf("\nIngrese APELLIDO: ");
    gets(input);
    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
    {
        printf("\nINgrese un apellido valido de cliente: ");
        gets(input);
    }
    strcpy(i_apellido, input);

    fflush(stdin);
    printf("\nIngrese NOMBRE: ");
    gets(input);
    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
    {
        printf("\nINgrese un nombre valido de cliente: ");
        gets(input);
    }
    strcpy(i_nombre, input);

    for (int j=0; j<10; j++)
    {
        if ( clientes[j].flag_estado == 0)
        {
            clientes[j].id = i_id;
            clientes[j].flag_estado = 1;
            clientes[j].dni = i_dni;
            strcpy(clientes[j].nombre, i_nombre);
            strcpy(clientes[j].apellido, i_apellido);
            break;
        }
    }
}
void modificar_cliente(eCliente clientes[])
{
    char input[5];
    int id;

    printf("\n***MODIFCAR CLIENTE***\n");
    fflush(stdin);
    printf("\nIngrese la ID del cliente a modificar...");
    gets(input);
    while( esNumerico(input) == 0)
    {
        printf("\nIngrese una ID valida...");
        gets(input);
    }
    id = atoi(input);

    char seguir = 's';
    int opcion = 0;

    for(int i=0; i<10; i++)
    {
        if (clientes[i].id == id && clientes[i].flag_estado == 1 )
        {

            while( seguir == 's' )
            {
                //system("cls");
                printf("\n***Que desea modificar?***\n");
                printf("1- NOMBRE.\n");
                printf("2- APELLIDO.\n");
                printf("3- DNI.\n");
                printf("4- Volver.\n");

                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    fflush(stdin);
                    printf("\nIngrese nuevo NOMBRE: ");
                    gets(input);
                    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
                    {
                        printf("\nINgrese un nombre valido de cliente: ");
                        gets(input);
                    }
                    strcpy(clientes[i].nombre, input);
                    printf("\n");
                    fflush(stdin);
                    break;
                case 2:
                    fflush(stdin);
                    printf("\nIngrese nuevo APELLIDO: ");
                    gets(input);
                    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
                    {
                        printf("\nINgrese un apellido valido de cliente: ");
                        gets(input);
                    }
                    strcpy(clientes[i].apellido, input);
                    printf("\n");
                    fflush(stdin);
                    break;
                case 3:
                    fflush(stdin);
                    printf("Ingrese nuevo DNI: ");
                    gets(input);
                    while (esDNI(input) == 0 || atoi(input) ==0 )
                    {
                        printf("\nIngrese un numero entero valido para DNI...");
                        gets(input);
                    }
                    clientes[i].dni = atoi(input);
                    printf("\n");
                    fflush(stdin);
                    break;
                case 4:
                    printf("Saliendo...");
                    seguir = 'n';
                    printf("\n");
                    break;
                }
            }
        }
    }
}
void listar_clientes(eCliente clientes[])
{
    printf("\n***LISTADO DE CLIENTES***\n");
    for (int i=0; i<10; i++)
    {
        if ( clientes[i].flag_estado == 1)
        {
            printf("\n---\n");
            printf("\Identificacion: %d",clientes[i].id);
            printf("\nDNI: %d",clientes[i].dni);
            printf("\nApellido: %s",clientes[i].apellido);
            printf("\nNombre : %s",clientes[i].nombre);
            printf("\n---\n");
        }
    }
}
void baja_cliente(eCliente clientes[])
{
    int id;
    char input[5];
    int flag = 0;

    printf("\n***BAJA CLIENTE***\n");
    fflush(stdin);
    printf("\nIngrese ID de cliente a dar de baja...");
    gets(input);
    while( esNumerico(input) == 0)
    {
        printf("\nIngrese una ID valida...");
        gets(input);
    }
    id = atoi(input);
    fflush(stdin);
    for (int i=0; i<10; i++)
    {
        if (clientes[i].id == id && clientes[i].flag_estado !=0)
        {
            clientes[i].flag_estado = 0;
            flag = 1;
            break;
        }
    }
    if ( flag == 0)
    {
        printf("\nNo hubo coincidencias...\n");
    }
    else
    {
        printf("\nID %d fue dado de baja exitosamente...\n",id);
    }
}

void nuevo_alquiler(eCliente clientes[], eAlquiler alquileres[],eRelacion relaciones[])
{
    int id_cliente;
    int id_equipo;
    char equipo[15];
    int tiempo_est;
    char operador[15];
    int flag_estado;
    char input[15];

    printf("\n***NUEVO ALQUILER***\n");
    fflush(stdin);
    printf("\nIngrese ID de CLIENTE: ");
    gets(input);
    while( esNumerico(input) == 0 || atoi(input) == 0 )
    {
        printf("\nIngrese un numero de ID valido...\n");
        gets(input);
    }
    id_cliente = atoi(input);
    fflush(stdin);
    printf("\nIngrese nombre del equipo: ");
    gets(input);
    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
    {
        printf("\nIngrese un nombre de equipo valido...");
        gets(input);
    }
    strcpy(equipo,input);
    fflush(stdin);
    printf("\nIngrese un codigo para identificar este equipo:");
    gets(input);
    while( esNumerico(input) == 0 || atoi(input) == 0 )
    {
        printf("\nIngrese un numero de ID de equipo valido...\n");
        gets(input);
    }
    id_equipo = atoi(input);
    fflush(stdin);
    printf("\nIngrese un tiempo estimado en dias (entero): ");
    gets(input);
    while(esNumerico(input) == 0 || atoi(input) <= 0 )
    {
        printf("\nIngrese un tiempo estimado en dias valido...");
        gets(input);
    }
    tiempo_est = atoi(input);
    fflush(stdin);
    printf("\nIngrese  nombre del operador a cargo del %s: ",equipo);
    gets(input);
    while ( esSoloLetras(input) == 0 || strlen(input) < 2 )
    {
        printf("\nIngrese un nombre valido...");
        gets(input);
    }
    strcpy(operador, input);
    fflush(stdin);
    for (int i=0; i<10; i++)
    {
        if ( relaciones[i].flag_estado == 0)
        {
            relaciones[i].id_cliente = id_cliente;
            relaciones[i].id_equipo = id_equipo;
            break;
        }
    }
    for (int i=0; i<10; i++)
    {
        if ( alquileres[i].flag_estado == 0)
        {
            alquileres[i].id_equipo = id_equipo;
            strcpy(alquileres[i].equipo,equipo);
            alquileres[i].tiempo_est = tiempo_est;
            alquileres[i].flag_estado = 1;
            strcpy(alquileres[i].operador,operador);
            break;
        }
    }
    printf("\nEl equipo %s se guardo como ALQUILADO...",equipo);
}


void terminar_alquiler(eAlquiler alquileres[])
{
    int id,t;

    printf("\nElija una id para terminar el alquiler...\n");

    for (int i=0;i<10;i++)
    {
        if ( alquileres[i].flag_estado == 1)
        {
            printf("\n---\n");
            printf("\nId: %d",alquileres[i].id_equipo);
            printf("\nNombre %s", alquileres[i].equipo);
            printf("\nTiempo estimado %d",alquileres[i].tiempo_est);
            printf("\n operador a cargo: %s", alquileres[i].operador);
            printf("\n---\n");
        }
    }
    scanf("%d",&id);
    printf("\nIngrese tiempo real...");
    scanf("%d",&t);

    for (int i=0;i<10;i++)
    {
        if ( alquileres[i].id_equipo == id && alquileres[i].flag_estado != 0)
        {
            alquileres[i].tiempo_real = t;
            alquileres[i].flag_estado = 0;
            break;
        }
    }
}

void informar(eRelacion relaciones[])
{
    int mayor;
    int id;

    for (int i=0; i<10; i++)
    {
        for ( int j=0; j<10; j++)
        {
            if ( (relaciones[i].id_cliente > relaciones[j].id_cliente) && relaciones[i].flag_estado !=0 && relaciones[j].flag_estado !=0  )
            {
               mayor = relaciones[i].id_cliente;
               relaciones[i].id_cliente = relaciones[j].id_cliente;
               relaciones[j].id_cliente = mayor;
            }
        }
    }
    printf("\nCliente con mas alquileres %d:", relaciones[0].id_cliente);
}





















