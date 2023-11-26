#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 50
#define MAX_USUARIOS 10

#define ROL_ADMINISTRADOR "Administrador"
#define ROL_BODEGUERO "Bodeguero"
#define ROL_VENDEDOR "Vendedor"

typedef struct {
    char nombre[20];
    char rol[20]; // Campo para el rol
} Usuario;

typedef struct {
    char nombre[50];
    char categoria[50];
    char marca[50];
    int codigo;
    float precioCompra;
    int bodega;
} Producto;

typedef struct {
    char local[50];
    char vendedor[50];
    char fecha[20];
    float precioVenta;
    int cantidadVendida;
} Venta;

void InicializarUsuarios();
void InicializarProductos();
void InicializarVentas();
void RealizarVenta();
void AdministrarUsuarios(Usuario usuarioActual);
void AdministrarProductos();
void ActualizarUsuario(const char *nombreUsuario);

#endif
