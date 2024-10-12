#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define TAM_DESCRIP 20
#define CANT_PROD 10

#define ARG_PRODS 1
#define ARG_PORCENTAJE 2

#define TODO_OK 0
#define ERROR 1
#define ERROR_ARCHIVO 2

#define NOMBRE_IDX "Productos.idx"

/// DEFINES DE VECTOR
#define VEC_LLENO 1
#define DUPLICADO 2
#define SIN_MEM 3
#define CAP_INICIAL 10
#define FACTOR_INCR 1.5

typedef struct{
  int codigo;
  char descripcion[TAM_DESCRIP + 1];
  float precio;
  int stock;
}T_Producto;

typedef struct{
  int codigo;
  unsigned nroReg;
}T_IndProducto;

typedef struct{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}T_Vector;

typedef int (*Cmp)(const void* e1, const void* e2);

void imprimirArgs(int argc, char* argv[]);
int generarProductos(const char* nomFileProd);
int generarIndiceProductos(const char* nomFileProd, const char* nomFileIdx);
int mostrarProductos(const char* nomFileProd);
int actualizarPrecioProductos(const char* nomFileProd, float porcentaje);
int actualizarPrecio1Producto(const char* nomFileProd, int codProd, float porcentaje);
int cmpIndProd(const void* e1, const void* e2);
/// PRIMITIVAS DE T_VECTOR
bool vectorCrear(T_Vector* vec, size_t tamElem);
int vectorGrabar(T_Vector* vec, const char* nomFile);
bool vectorCrearDesdeArchivo(T_Vector* vec, size_t tamElem, const char* nomFile);
int vectorOrdInsertar(T_Vector* vec, const void* elem, Cmp cmp);
bool redimensionarVector(T_Vector* vec, float factor);
int vectorOrdBuscar(const T_Vector* vec, void* elem, Cmp cmp);
void vectorEliminar(T_Vector* vec);
