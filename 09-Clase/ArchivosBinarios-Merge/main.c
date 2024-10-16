#include "funciones.h"

int main(int argc, char* argv[]){ /// ARGV[1]: "Productos.dat" --- ARGV[2]: "Movimientos.dat"
	imprimirArgs(argc, argv);

	generarProductos(argv[ARG_PRODS]);
	mostrarProductos(argv[ARG_PRODS]);
	generarMovimientos(argv[ARG_MOVS]);

	actualizarStockProductos(argv[ARG_PRODS], argv[ARG_MOVS]);

	puts("\nProductos actualizados:");
	mostrarProductos(argv[ARG_PRODS]);
    return TODO_OK;
}
