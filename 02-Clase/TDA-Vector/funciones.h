#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 100
#define TODO_OK 0
#define VECTOR_LLENO 1
#define ELEMENTO_DUPLICADO 2

typedef struct{
    int vec[CAP];
    int ce;
}T_Vector;

bool vectorCrear(T_Vector* miVec);
void imprimirVector(T_Vector* miVec);
int vectorOrdenadoInsertar(T_Vector* miVec, int elem);
bool vectorOrdenadoEliminarElemento(T_Vector* miVec, int elem);
int vectorOrdenadoBuscar(T_Vector* miVec, int elem);
