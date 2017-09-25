#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{
    int codigo;
    char descripcion[100];
    int importe;
    int cantidad;
    int codigoProveedor;
    int flag_estado;
} eProducto;
typedef struct
{
    int codigo;
    char descripcion[100];
    int flag_estado;
} eProveedor;
typedef struct
{
    int codigoProducto;
    int codigoProveedor;
} eRelacion;

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
int esAlfaNumerico(char str[]);

/**
 * \brief Le carga al los arrays valores de productos y proveedores respetivamente
 * \param array de productos
 * \param array de proveedores
 * \return VOID
 */
void inicializar_arrays(eProducto productos[], eProveedor proveedores[]);

/**
 * \brief Pide por pantalla los datos de un producto a ser ingresado por teclado
 * \param array de productos
 * \return VOID
 */
void alta_producto(eProducto productos[]);

/**
 * \brief modifica los datos de un producto en un array
 * \param array de productos
 * \return VOID
 */
void modificar_producto(eProducto productos[]);

/**
 * \brief deshabilita un producto del array
 * \param array de productos
 * \return VOID
 */
void baja_producto(eProducto productos[]);

/**
 * \brief muestra los productos del array que mas stock tiene y el que menos stock tiene
 * \param array de productos
 * \return void
 */
void informar_stock(eProducto productos[]);


#endif // HEADER_H_INCLUDED
