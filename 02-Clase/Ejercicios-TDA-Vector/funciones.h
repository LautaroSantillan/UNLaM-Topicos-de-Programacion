#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100
#define TODO_OK 0
#define DUPLICADO 1
#define VEC_LLENO 2
#define ERROR 3

typedef struct{
    int vec[TAM];
    int ce;
}T_Vector;

/// INICIALES
bool vectorCrear(T_Vector* miVec);
void mostrar(T_Vector *miVec);
/// VECTOR ORDENADO
int vectorOrdenadoInsertar(T_Vector* miVec, int elem);
int vectorOrdenadoBuscarElemento(T_Vector* miVec, int elem);
bool vectorOrdenadoEliminarElemento(T_Vector* miVec, int elem);
int vectorOrdenadoEliminarDuplicado(T_Vector* miVec, int elem);
/// VECTOR DESORDENADO
int vectorDesordenadoInsertarPrimero(T_Vector* miVec, int elem);
int vectorDesordenadoInsertarUltimo(T_Vector* miVec, int elem);
int vectorDesordenadoInsertarCualquierPosicion(T_Vector* miVec, int pos, int elem);
int vectorDesordenadoEliminarPosicion(T_Vector* miVec, int pos);
int vectorDesordenadoEliminarPrimero(T_Vector* miVec);
int vectorDesordenadoEliminarUltimo(T_Vector* miVec);
int vectorDesordenadoEliminarElementos(T_Vector* miVec, int elem); /// Funciona tambien para eliminar más de una ocurrencia
int vectorDesordenadoBuscarElemento(T_Vector* miVec, int elem);
