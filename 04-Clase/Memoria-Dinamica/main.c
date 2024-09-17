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
    int vec;
    size_t ce;
    size_t cap;
}T_Vector;

bool vectorCrear(T_Vector* vector); /// malloc
int vectorInsertarOrdenado(T_Vector* vector, int elem); /// realloc
int vectorBuscarOrdenado(T_Vector* vector, int elem);
bool vectorEliminarOrdenadoElemento(T_Vector* vector, int elem); /// realloc
void vectorEliminar(T_Vector* vector); /// free
void vectorVaciar(T_Vector* vector); /// realloc
bool redimensionarVector(T_Vector* vector, float factor); /// TIENE QUE IR EN EL .C PARA QUE EL USUARIO NO PUEDA VERLA (USO INTERNO Y PRIVADO)

int main()
{
    T_Vector miVector;

    // Crear vector
    if (!vectorCrear(&miVector)) {
        printf("Error al crear el vector.\n");
        return SIN_MEMORIA;
    }

    // Insertar elementos ordenados
    for (int i = 1; i <= CANT_ELEMENTOS; i++) {
        int status = vectorInsertarOrdenado(&miVector, i);
        if (status == TODO_OK) {
            printf("Elemento %d insertado correctamente.\n", i);
        } else if (status == DUPLICADO) {
            printf("Elemento %d duplicado.\n", i);
        } else {
            printf("Error al insertar el elemento %d.\n", i);
        }
    }

    // Probar la función de búsqueda
    int buscar = 5;
    int pos = vectorBuscarOrdenado(&miVector, buscar);
    if (pos != -1) {
        printf("Elemento %d encontrado en la posición %d.\n", buscar, pos);
    } else {
        printf("Elemento %d no encontrado.\n", buscar);
    }

    // Eliminar un elemento
    if (vectorEliminarOrdenadoElemento(&miVector, buscar)) {
        printf("Elemento %d eliminado correctamente.\n", buscar);
    } else {
        printf("Error al eliminar el elemento %d.\n", buscar);
    }

    // Vaciar el vector
    vectorVaciar(&miVector);
    printf("Vector vaciado.\n");

    // Eliminar el vector
    vectorEliminar(&miVector);
    printf("Vector eliminado.\n");

    return TODO_OK;
}

bool vectorCrear(T_Vector* vector){
    vector->ce = 0;
    vector->vec = malloc(sizeof(int) * CAP_INICIAL);
    if(vector->vec == NULL){
        vector->cap = 0;
        return false;
    }

    vector->cap = CAP_INICIAL;
    return true;
}

int vectorInsertarOrdenado(T_Vector* vector, int elem){
    int posIns = 0, i;
    if(vector->ce == vector->cap){
        if(!redimensionarVector(vector, FACTOR_INCREMENTO))
        return VEC_LLENO; /// En realidad nos estariamos quedadno sin memoria

    }
    while(posIns < vector->ce && elem > vector->vec[posIns])/// La posicion de insercion tiene que ser menor a la ce sino estaria comparando con basura
/// Y el elem tiene que ser mayor al que esta en el vector
        posIns++;

/// Sale del ciclo si encontre un duplicado (no tengo que insertar), si el elem a insertar es > a tods (inserto) o si el elem es menor a algun elemento del vector (inserto)
    if(posIns < vector->ce && elem == vector->vec[posIns])
        return DUPLICADO;

    for(i=vector->ce-1;i>=posIns;i--)
        vector->vec[i+1]=vector->vec[i];

    vector->vec[posIns]=elem;
    vector->ce++;
    return TODO_OK;
}

int vectorBuscarOrdenado(T_Vector* vector, int elem) {
    if (vector->ce == 0) {
        return -1; // El vector está vacío
    }

    int low = 0, high = vector->ce - 1;
    int mid;

    // Búsqueda binaria para encontrar el elemento
    while (low <= high) {
        mid = (low + high) / 2;
        if (vector->vec[mid] == elem) {
            return mid; // Elemento encontrado
        }
        else if (vector->vec[mid] < elem) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Elemento no encontrado
}

bool vectorEliminarOrdenadoElemento(T_Vector* vector, int elem){
    int *posElim=vector->vec;
    int *ult=vector->vec+vector->ce-1;
    int *i;

    if(vector->ce==0)
        return false;

    while(posElim<=ult&&elem>*posElim)
        posElim++;

    if(posElim>ult||elem<*posElim)
        return false;

    for(i=posElim+1;i<=ult;i++)
        *(i-1)=*i;

    vector->ce--;
    if(((float)vector->ce/vector->cap) <= FACTOR_OCUP)
        redimensionarVector(vector,FACTOR_DECREMENTO);

    return true;
}

void vectorEliminar(T_Vector* vector){
    free(vector->vec);
    vector->vec = NULL;
    vector->ce = 0;
    vector->cap = 0;
}

void vectorVaciar(T_Vector* vector){
    vector->vec = realloc(vector->vec, sizeof(int) * CAP_INICIAL);
    vector->ce = 0;
    vector->cap = CAP_INICIAL;
}

bool redimensionarVector(T_Vector* vector, float factor)
{
   size_t nCap = vector->cap*factor;
   int* nVec;
   if(nCap < CAP_INICIAL)
       return false;

    nVec=realloc(vector->vec, sizeof(int)*nCap);
    if(nVec == NULL)
        return false;

    vector->vec=nVec;
    printf("Redimension de %lu a %lu \n", vector->cap, nCap); /// Es un tipo de flag para ver cuando redimensiono
    vector->cap = nCap;
    return true;
}
