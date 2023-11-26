#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    int rol;
    int codigoProducto;
    char nombreUsuario[50];
    char contraseña[20];
    Usuario usuarioActual; 

    // Inicializar las estructuras de datos
    InicializarUsuarios();
    InicializarProductos();
    InicializarVentas();

    

    printf("Bienvenido al Sistema de Registro de Productos Electrónicos\n");

    // Solicitar al usuario que ingrese su rol
    printf("Por favor, seleccione su rol:\n");
    printf("1. Administrador\n");
    printf("2. Bodeguero\n");
    printf("3. Vendedor\n");
    printf("Seleccione su rol (1/2/3): ");
    scanf("%d", &rol);

    // Asignar el rol de acuerdo a la elección del usuario
    switch (rol) {
        case 1:
            strcpy(usuarioActual.rol, ROL_ADMINISTRADOR);
            break;
        case 2:
            strcpy(usuarioActual.rol, ROL_BODEGUERO);
            break;
        case 3:
            strcpy(usuarioActual.rol, ROL_VENDEDOR);
            break;
        default:
            printf("Rol no válido. Saliendo del programa...\n");
            return 1;
    }

    
   printf("Ingrese su  usuario: ");
   scanf("%s", usuarioActual.nombre);
   printf("Ingrese su  contraseña: ");
   scanf("%s", contraseña);

   if (strcmp(usuarioActual.rol, ROL_ADMINISTRADOR) == 0) {
       // Usuario con rol de Administrador
       while (1) {
           // Menú para el Administrador
           printf("\nMenú del Administrador:\n");
           printf("1. Crear Usuario\n");
           printf("2. Actualizar Usuario\n");
           printf("3. Salir\n");
           printf("Seleccione una opción: ");
           scanf("%d", &opcion);

           switch (opcion) {
               case 1:
                   AdministrarUsuarios(usuarioActual);
                   break;
               case 2:
                   printf("Ingrese el nombre de usuario que desea actualizar: ");
                   scanf("%s", nombreUsuario);

                   ActualizarUsuario(nombreUsuario);
                   break;
               case 3:
                   printf("Saliendo del programa...\n");
                   return 0;
               default:
                   printf("Opción no válida. Por favor, seleccione una opción válida.\n");
           }
       }
   } else if (strcmp(usuarioActual.rol, ROL_BODEGUERO) == 0) {
       // Usuario con rol de Bodeguero
       while (1) {
           // Menú para el Bodeguero
           printf("\nMenú del Bodeguero:\n");
           printf("1. Crear Producto\n");
           printf("2. Actualizar Producto\n");
           printf("3. Salir\n");
           printf("Seleccione una opción: ");
           scanf("%d", &opcion);

           switch (opcion) {
               case 1:
                   AdministrarProductos();
                   break;
               case 2:
                  
                  printf("Ingrese el código del producto que desea actualizar: ");
                  scanf("%d", &codigoProducto);

                  ActualizarProducto(codigoProducto);
                   break;
               case 3:
                   printf("Saliendo del programa...\n");
                   return 0;
               default:
                   printf("Opción no válida. Por favor, seleccione una opción válida.\n");
           }
       }
   } else if (strcmp(usuarioActual.rol, ROL_VENDEDOR) == 0) {
       // Usuario con rol de Vendedor
       while (1) {
           // Menú para el Vendedor
           printf("\nMenú del Vendedor:\n");
           printf("1. Realizar Venta\n");
           printf("2. Salir\n");
           printf("Seleccione una opción: ");
           scanf("%d", &opcion);

           switch (opcion) {
               case 1:
                   RealizarVenta();
                   break;
               case 2:
                   printf("Saliendo del programa...\n");
                   return 0;
               default:
                   printf("Opción no válida. Por favor, seleccione una opción válida.\n");
           }
       }
   }

    return 0;
}
