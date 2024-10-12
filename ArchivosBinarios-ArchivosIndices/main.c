#include "funciones.h"

int main(int argc, char* argv[]){ /// ARGV[1]: "Productos.dat" --- ARGV[2]: "10"
    imprimirArgs(argc, argv);

    generarProductos(argv[ARG_PRODS]);
    generarIndiceProductos(argv[ARG_PRODS], NOMBRE_IDX);
    puts("\nLista de productos:");
    mostrarProductos(argv[ARG_PRODS]);

    float porcentaje = atof(argv[ARG_PORCENTAJE]); // sscanf(argv[ARG_PORCENTAJE])
    actualizarPrecioProductos(argv[ARG_PRODS], porcentaje);
    puts("\nProductos Actualizados con un 10%:");
    mostrarProductos(argv[ARG_PRODS]);

    actualizarPrecio1Producto(argv[ARG_PRODS], 3, 15);
    puts("\nProducto 3 actualizado con un 15%:");
	mostrarProductos(argv[ARG_PRODS]);

    return TODO_OK;
}
