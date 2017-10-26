#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[15];
    char apellido[15];
    int flag_estado;
} eCliente;

typedef struct
{
    int id_equipo;
    char equipo[15];
    int tiempo_est;
    int tiempo_real;
    char operador[15];
    int flag_estado;
}eAlquiler;

typedef struct
{
    int id_cliente;
    int id_equipo;
    int flag_estado;
}eRelacion;


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido es numérico valido para un DNI
 * \param str Array con la cadena a ser analizada
 * \return 1 si es apto para DNI y 0 si no lo es
 *
 */
int esDNI(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
int esAlfaNumerico(char str[]);

/**
 * \brief hardcodea valores a los arrays para facilitar testeo
* \param array de clientes
* \param array de alquileres
* \param array de relaciones
 * \return void
 */
void precargar_arrays(eCliente array_clientes[], eAlquiler array_alquileres[], eRelacion relaciones[]);

/**
 * \brief busca la ultima ID valida
 * \param array de clientes
 * \return numero ID en formato interger
 */
int ultimaID(eCliente clientes[]);

/**
 * \brief pide por pantalla los datos del cliente a ser ingresados por teclado
 * \param array de clientes
 * \return void
 */
void alta_cliente(eCliente clientes[]);

/**
 * \brief pide por pantalla los datos del cliente a ser modificados
 * \param array de clientes
 * \return void
 */
void modificar_cliente(eCliente clientes[]);

/**
* \brief lista por pantalla los clientes
* \param array de clientes
* \return void
*/
void listar_clientes(eCliente clientes[]);

/**
* \brief Da de baja un cliente del array
* \param array de clientes
* \return void
*/
void baja_cliente(eCliente clientes[]);

/**
* \brief se piden los datos de un alquiler nuevo y se cargan al array
* \param array de clientes
* \param array de alquileres
* \param array de relaciones
* \return void
*/
void nuevo_alquiler(eCliente clientes[], eAlquiler alquileres[],eRelacion relaciones[]);

/**
* \brief se marca el fin del alquiler pidiendo el tiempo en dias reales
* \param array de alquileres
* \return void
*/
void terminar_alquiler(eAlquiler alquileres[]);

/**
* \brief informa
* \param array de alquileres
* \param array de relaciones
* \return void
*/
void informar(eRelacion relaciones[]);
#endif // LIB_H_INCLUDED
