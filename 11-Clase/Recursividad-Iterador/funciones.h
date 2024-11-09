#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TODO_OK 0
#define VEC_LLENO 1
#define DUPLICADO 2
#define SIN_MEM 3
#define CAP_INI 5
#define CANT_ELEMS 25
#define FACTOR_INCR 1.5 /// Significa que vamos a redimensionar el vector con un 50% mas

typedef struct{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}Vector;

typedef struct{
    void* pri;
    void* ult;
    void* act;
    size_t tamElem;
    bool finIter;
}VectorIterador;

unsigned long long factorial(int n);
int dcm(int x, int y);

typedef int (*Cmp)(const void* e1, const void* e2);

bool vectorCrear(Vector* vector, size_t tamElem); // malloc
int vectorOrdInsertar(Vector* vector, const void* elem, Cmp cmp); // realloc

/// ITERADOR
void vectorIteradorCrear(VectorIterador* it, Vector* vector);
void* vectorIteradorPrimero(VectorIterador* it);
void* vectorIteradorSiguiente(VectorIterador* it);
void* vectorIteradorUltimo(VectorIterador* it);
void* vectorIteradorAnterior(VectorIterador* it);
void* vectorIteradorActual(VectorIterador* it);
bool vectorIteradorFinIter(const VectorIterador* it);
