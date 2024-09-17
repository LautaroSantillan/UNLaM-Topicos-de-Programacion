#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP_INICIAL 10
#define CANT_ELEMENTOS 10

#define TODO_OK 0
#define VEC_LLENO 1
#define SIN_MEMORIA 2
#define DUPLICADO 3

#define FACTOR_INCREMENTO 1.5 /// Significa que vamos a redimensionar el vector con un 50% mas
#define FACTOR_OCUP 0.25
#define FACTOR_DECREMENTO 0.5

typedef struct{
    int* vec;  // Cambia int vec; por int* vec; para que sea un puntero a un arreglo dinámico
    size_t ce;  // cantidad de elementos
    size_t cap; // capacidad del vector
}T_Vector;

bool vectorCrear(T_Vector* vector); /// malloc
int vectorInsertarOrdenado(T_Vector* vector, int elem); /// realloc
int vectorBuscarOrdenado(T_Vector* vector, int elem);
bool vectorEliminarOrdenadoElemento(T_Vector* vector, int elem); /// realloc
void vectorEliminar(T_Vector* vector); /// free
void vectorVaciar(T_Vector* vector); /// realloc
