#include <stdio.h>
#include <stdlib.h> /// Para el rand tambien
#include <stdbool.h>
#include <time.h>

#define CAP 100
#define CAP_INICIAL 10

#define TODO_OK 0
#define ERROR 1
#define VECTOR_LLENO 2
#define ELEMENTO_DUPLICADO 3
#define SIN_MEMORIA 4

//Sorting
#define BURBUJEO 1
#define SELECCION 2
#define INSERCION 3

#define CANT_ELEMENTOS 500
#define FACTOR_INCREMENTO 1.5 /// Significa que vamos a redimensionar el vector con un 50% mas
#define FACTOR_OCUP 0.25
#define FACTOR_DESCREMENTO 0.5

typedef struct{
    int vec;
    size_t ce;
    size_t cap;
}T_Vector;

///PRIMITIVAS
bool vectorCrear(T_Vector* vec); /// malloc
void vectorEliminar(T_Vector* vec); /// free
void imprimirVectorConComparativa(T_Vector* miVec);
void cargarVectorRandom(T_Vector* vec, size_t cantElems);
bool redimensionarVector(T_Vector* vec, float factor);
/// ORDENAMIENTO
int vectorOrdenar(T_Vector* vec, int metodo);
/// BURBUJEO
void ordenarBurbujeo(T_Vector* vec);
/// SELECCION
void ordenarSeleccion(T_Vector* vec);
/// INSERCION
void ordenarInsercion(T_Vector* vec);

