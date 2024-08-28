#include "funciones.h"

bool vectorCrear(T_Vector* miVec){
    miVec->ce = 0;
    return true;
}

void imprimirVector(T_Vector* miVec){
    printf("Vector: ");
    for (int i = 0; i < miVec->ce; i++)
        printf("%d ", miVec->vec[i]);
    printf("\n");
}

/*int vectorOrdenadoInsertar(T_Vector* miVec, int elem){
    if(miVec->ce == CAP)
        return VECTOR_LLENO;
    int posIns = 0;
    while(posIns < miVec->ce && elem > miVec->vec[posIns])
        posIns++;
    ///CASO DE DUPLICADO
    if(posIns < miVec->ce && elem == miVec->vec[posIns])
        return ELEMENTO_DUPLICADO;
    ///CASO DE ELEM < -1 VEC
    for(int i = miVec->ce-1; i >= posIns; i--)
        miVec->vec[i+1] = miVec->vec[i];
    miVec->vec[posIns] = elem;
    miVec->ce++;
    return TODO_OK;
}*/

///CON ARITMETRICA DE PUNTEROS
int vectorOrdenadoInsertar(T_Vector* miVec, int elem){
    if(miVec->ce == CAP)
        return VECTOR_LLENO;
    int* posIns = miVec->vec; // Puntero de enteros (4 bytes)
    int* ult = miVec->vec + miVec->ce - 1; // Ultimo elemento del vector
    while(posIns <= ult && elem > *posIns)
        posIns++;
    ///REALIZAR CASO DE ELEM > A TODOS
    ///CASO DE DUPLICADO
    if(posIns <= ult && elem == *posIns)
        return ELEMENTO_DUPLICADO;
    ///CASO DE ELEM < -1 VEC
    for(int* i = ult; i >= posIns; i--)
        *(i+1) = *i;
    *posIns = elem;
    miVec->ce++;
    return TODO_OK;
}

bool vectorOrdenadoEliminarElemento(T_Vector* miVec, int elem){
    if(miVec->ce == 0)
        return false; //Esta vacio el vector
    int* ult = miVec->vec + miVec->ce - 1; // Ultimo elemento del vector
    int* posElim = miVec->vec;
    while(posElim <= ult && elem > *posElim)
        posElim++;
    if(posElim > ult || elem < *posElim) /// No se encontro el elem
        return false;
    for(int* i = posElim + 1; i <= ult; i++)
        *(i-1) = *i;
    miVec->ce--;
    return TODO_OK;
}

int vectorOrdenadoBuscar(T_Vector* miVec, int elem){
    int comp;
    int* li = miVec->vec; /// Limite Inferior
    int* ls = miVec->vec + miVec->ce - 1; /// Limite Superior -> Ultimo elem del vector
    int* m; /// Mitad
    while(li<ls){
        m = li + (ls-li)/2; // Dividir a la mitad el vector
        comp = elem - *m;
        if(comp == 0)
            return m - miVec->vec;
        if(comp < 0) // Se descarta la parte derecha
            ls = m - 1;
        if(comp > 0) // Se descarta la parte izquierda
            li = m + 1;
    }
    return TODO_OK;
}

// realizar los demas tipos de insertar y de eliminar
// realizar eliminarDuplicado (para vectores ordenados y desordenados)
