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

int validarString(char palabra[]);
int validar_entero(int unEntero);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void inicializar_arrays(eProducto productos[], eProveedor proveedores[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void alta_producto(eProducto productos[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modificar_producto(eProducto productos[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void baja_producto(eProducto productos[]);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void informar_stock(eProducto productos[]);
#endif // HEADER_H_INCLUDED
