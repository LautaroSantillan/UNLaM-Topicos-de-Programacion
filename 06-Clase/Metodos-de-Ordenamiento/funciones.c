#include "funciones.h"

bool redimensionarVector(T_Vector* vector, float factor); /// TIENE QUE IR EN EL .C PARA QUE EL USUARIO NO PUEDA VERLA (USO INTERNO Y PRIVADO)
void intercambiar(int* a, int* b);
int* buscarMenor(int* inicial, int* fin);

/// PRIMITIVAS
bool vectorCrear(T_Vector* vec){
    vec->ce = 0;
    vec->vec = malloc(sizeof(int) * CAP_INICIAL);
    if(vec->vec == NULL){
        vec->cap = 0;
        return false;
    }

    vec->cap = CAP_INICIAL;
    return true;
}

void imprimirVectorConComparativa(T_Vector* vec){
     int* ult = vec->vec + vec->ce -1;
     for(int* i = vec->vec; i <= ult; i++)
        printf("[%ld] = %d\n", (long)(i - vec->vec), *i);
}

void vectorEliminar(T_Vector* vec){
    free(vec->vec);
    vec->vec = NULL;
    vec->ce = 0;
    vec->cap = 0;
}

void cargarVectorRandom(T_Vector* vec, size_t cantElems){
    srand(time(NULL)); /// Semilla de secuencia de numeros randoms
    int rta;

    for(int i = 0; i < cantElems; i++)
        rta = vectorInsertarAlFinal(vec, rand() % 10);
}

int vectorInsertarAlFinal(T_Vector* vec, int elem){
    if(vec->ce == vec->cap){
        if(!redimensionarVector(vec, FACTOR_INCREMENTO))
            return SIN_MEMORIA;
    }

    int* ult = vec->vec + vec->ce -1;
    int* posIns = ult + 1;
    *posIns = elem;
    vec->ce++;

    return TODO_OK;
}

bool redimensionarVector(T_Vector* vec, float factor){
    size_t nCap = vec->cap * factor;
    if(nCap < CAP_INICIAL)
        return ERROR;

    int* nVec = realloc(vec->vec, sizeof(int) * vec->cap * factor);
    if(!nVec)
        return ERROR;

    vec->vec = nVec;
    printf("Redimension de %d a %d\n", vec->cap, nCap);

    vec->cap = nCap;
    return TODO_OK;
}
/// METODO DE ORDENAMIENTO
int vectorOrdenar(T_Vector* vec, int metodo){
    switch(metodo){
    case BURBUJEO:
        ordenarBurbujeo(vec);
        return TODO_OK;
    case SELECCION:
        ordenarSeleccion(vec);
        return TODO_OK;
    case INSERCION:
        ordenarInsercion(vec);
        return TODO_OK;
    default:
        return ERROR;
    }
}
/// BURBUJEO
void ordenarBurbujeo(T_Vector* vec){
    for(int i = 1, *limJ = vec->vec + vec->ce - 2; i < vec->ce; i++, limJ--){
        for(int *j = vec->vec; j <= limJ; j++){
            if(*j > *(j+1))
                intercambiar(j, j+1);
        }
    }
}

void intercambiar(int* a, int* b){
    int aTemp = *a;
    *a = *b;
    *b = aTemp;
}
/// SELECCION
void ordenarSeleccion(T_Vector* vec){
    int* ult = vec->vec + vec->ce -1;
    for(int* i = vec->vec; i < ult; i++){
        int m = buscarMenor(i, ult);
        intercambiar(i, m);
    }
}

int* buscarMenor(int* inicial, int* fin){
    int* m = inicial;
    for(int* j = inicial + 1; j <= fin; j++){
        if(*j < *m)
            m = j;
    }

    return m;
}
/// INSERCION
void ordenarInsercion(T_Vector* vec){
    int* ult = vec->vec + vec->ce -1;
    int elementoAInsertar;
    int* j;
    for(int* i = vec->vec + 1; i <= ult; i++){
        elementoAInsertar = *i;
        j = i + 1;

        while(j >= vec->vec && elementoAInsertar < *j)
            *(j + 1) = *j;

        *(j+1) = elementoAInsertar;
    }
}
