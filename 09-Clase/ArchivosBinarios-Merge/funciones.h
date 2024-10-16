#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_DESCR 20
#define CANT_PRODS 9
#define CANT_MOVS 14

#define ARG_PRODS 1
#define ARG_MOVS 2

#define TODO_OK 0
#define ERR_ARCHIVO 1
#define NOM_IDX "Productos.idx"

typedef struct{
    int codigo;
    char descripcion[TAM_DESCR + 1];
    float precio;
    int stock;
}Producto;

typedef struct{
	int codigo;
	int cantidad;
}Movimiento;

typedef struct{
	int codigo;
	unsigned nroReg;
}IndProducto;

/// DEFINES DE VECTOR
#define VEC_LLENO 1
#define DUPLICADO 2
#define SIN_MEM 3
#define CAP_INICIAL 10
#define FACTOR_INCR 1.5

typedef struct{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}T_Vector;

typedef int (*Cmp)(const void* e1, const void* e2);

void imprimirArgs(int argc, char* argv[]);
int generarProductos(const char* nomArchProds);
int generarMovimientos(const char* nomArchMovi);
int mostrarProductos(const char* nomArchProds);
int cmpIndProd(const void* e1, const void* e2);
int actualizarStockProductos(const char* nomArchProds, const char* nomArchMovi);
void procesarProductoNuevo(Movimiento* mov, FILE* archMov, FILE* archProdTmp);
/// VECTOR.C
bool vectorCrear(T_Vector* vec, size_t tamElem);
int vectorGrabar(T_Vector* vec, const char* nomFile);
bool vectorCrearDesdeArchivo(T_Vector* vec, size_t tamElem, const char* nomFile);
int vectorOrdInsertar(T_Vector* vec, const void* elem, Cmp cmp);
bool redimensionarVector(T_Vector* vec, float factor);
int vectorOrdBuscar(const T_Vector* vec, void* elem, Cmp cmp);
void vectorEliminar(T_Vector* vec);
