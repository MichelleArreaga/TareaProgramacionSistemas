#include <stdio.h>
#include <string.h>
#include "funciones.h"

Usuario usuarios[MAX_USUARIOS];
Producto productos[MAX_PRODUCTOS];
Venta ventas[MAX_PRODUCTOS];

int numUsuarios = 0;
int numProductos = 0;
int numVentas = 0;

void InicializarUsuarios() {
    // Inicialización del usuario administrador
      Usuario admin = {"Nathaly", ROL_ADMINISTRADOR};
      usuarios[0] = admin;
      numUsuarios = 1;

      // Inicialización del usuario bodeguero
      Usuario bodeguero = {"Juan", ROL_BODEGUERO};
      usuarios[1] = bodeguero;
      numUsuarios++;

      // Inicialización del usuario vendedor
      Usuario vendedor = {"Maria", ROL_VENDEDOR};
      usuarios[2] = vendedor;
      numUsuarios++;
}

void InicializarProductos() {
    // Inicializar la lista de productos

    Producto producto1 = {"Refrigeradora", "Electrónica", "Samsung", 1, 450.0, 10};
    productos[0] = producto1;

    Producto producto2 = {"Laptop", "Electrónica", "LG", 2, 1000.0, 15};
    productos[1] = producto2;

    numProductos = 2;
}

void InicializarVentas() {
    numVentas = 0;
}

void RealizarVenta() {
    if (numProductos == 0) {
        printf("No hay productos disponibles para la venta.\n");
        return;
    }

    // Mostrar los productos disponibles
    printf("Productos disponibles:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%d. %s\n", i + 1, productos[i].nombre);
    }

    int productoSeleccionado;
    printf("Seleccione un producto para la venta (1-%d): ", numProductos);
    scanf("%d", &productoSeleccionado);

    if (productoSeleccionado < 1 || productoSeleccionado > numProductos) {
        printf("Selección de producto no válida.\n");
        return;
    }

    int cantidadVendida;
    printf("Ingrese la cantidad vendida: ");
    scanf("%d", &cantidadVendida);

    if (cantidadVendida <= 0 || cantidadVendida > productos[productoSeleccionado - 1].bodega) {
        printf("Cantidad no válida o insuficiente en bodega.\n");
        return;
    }

    // Registrar la venta
    Venta venta;
    strcpy(venta.local, "Local1");  // Simulación de local
    strcpy(venta.vendedor, "Vendedor1");  // Simulación de vendedor
    venta.precioVenta = productos[productoSeleccionado - 1].precioCompra * 1.2; // Ejemplo de precio de venta
    venta.cantidadVendida = cantidadVendida;
    ventas[numVentas] = venta;
    numVentas++;

    // Actualizar la cantidad en bodega
    productos[productoSeleccionado - 1].bodega -= cantidadVendida;

    printf("Venta registrada con éxito.\n");
}

void AdministrarUsuarios(Usuario usuarioActual) {
    if (numUsuarios >= MAX_USUARIOS) {
        printf("Se ha alcanzado el límite de usuarios.\n");
        return;
    }
  if (strcmp(usuarioActual.rol, ROL_ADMINISTRADOR) != 0) {
      printf("No tienes permisos para crear usuarios de este tipo.\n");
      return;
  }

    Usuario nuevoUsuario;

    printf("Ingrese el nombre del nuevo usuario: ");
    scanf("%s", nuevoUsuario.nombre);
    printf("Ingrese el rol del usuario (Administrador, Bodeguero, Vendedor):");
    scanf("%s", nuevoUsuario.rol);

    if (strcmp(nuevoUsuario.rol,ROL_ADMINISTRADOR) == 0 || strcmp(nuevoUsuario.rol, ROL_BODEGUERO) == 0 || strcmp(nuevoUsuario.rol, ROL_VENDEDOR) == 0) {
        usuarios[numUsuarios] = nuevoUsuario;
        numUsuarios++;
        printf("Usuario Administrador registrado con éxito.\n");
    } else {
        printf("Por favor ingresar el rol adecuado.\n");
    }
}



void AdministrarProductos() {
    if (numProductos >= MAX_PRODUCTOS) {
        printf("Se ha alcanzado el límite de productos.\n");
        return;
    }

    Producto nuevoProducto;

    printf("Ingrese el nombre del nuevo producto: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Ingrese la categoría del producto: ");
    scanf("%s", nuevoProducto.categoria);
    printf("Ingrese la marca del producto: ");
    scanf("%s", nuevoProducto.marca);
    printf("Ingrese el código del producto: ");
    scanf("%d", &nuevoProducto.codigo);
    printf("Ingrese el precio de compra del producto: ");
    scanf("%f", &nuevoProducto.precioCompra);
    printf("Ingrese la cantidad en bodega del producto: ");
    scanf("%d", &nuevoProducto.bodega);

    productos[numProductos] = nuevoProducto;
    numProductos++;

    printf("Producto registrado con éxito.\n");
}
void ActualizarProducto(int codigo) {
// Buscar el producto por su código
for (int i = 0; i < numProductos; i++) {
    if (productos[i].codigo == codigo) {
        // Producto encontrado, permite actualizarlo
        printf("Producto encontrado:\n");
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Categoría: %s\n", productos[i].categoria);
        printf("Marca: %s\n", productos[i].marca);
        printf("Precio de Compra: %.2f\n", productos[i].precioCompra);
        printf("Cantidad en Bodega: %d\n", productos[i].bodega);

        // Solicitar la actualización de los campos del producto
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", productos[i].nombre);
        printf("Ingrese la nueva categoría del producto: ");
        scanf("%s", productos[i].categoria);
        printf("Ingrese la nueva marca del producto: ");
        scanf("%s", productos[i].marca);
        printf("Ingrese el nuevo precio de compra del producto: ");
        scanf("%f", &productos[i].precioCompra);
        printf("Ingrese la nueva cantidad en bodega del producto: ");
        scanf("%d", &productos[i].bodega);

        printf("Producto actualizado con éxito.\n");
        return;
    }
}
}

void ActualizarUsuario(const char *nombreUsuario) {
// Buscar el usuario por su nombre de usuario
for (int i = 0; i < numUsuarios; i++) {
    if (strcmp(usuarios[i].nombre, nombreUsuario) == 0) {
        // Usuario encontrado, permite actualizarlo
        printf("Usuario encontrado:\n");
        printf("Nombre de Usuario: %s\n", usuarios[i].nombre);
        printf("Rol: %s\n", usuarios[i].rol);

        // Solicitar la actualización de los campos del usuario
        printf("Ingrese el nuevo nombre de usuario: ");
        scanf("%s", usuarios[i].nombre);
        printf("Ingrese el nuevo rol del usuario: ");
        scanf("%s", usuarios[i].rol);

        printf("Usuario actualizado con éxito.\n");
        return;
    }
}
}