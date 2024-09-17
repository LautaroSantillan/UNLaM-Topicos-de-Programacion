#include "funciones.h"

bool redimensionarVector(T_Vector* vector, float factor); /// TIENE QUE IR EN EL .C PARA QUE EL USUARIO NO PUEDA VERLA (USO INTERNO Y PRIVADO)

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
    int posIns = 0;

    // Verificar si es necesario redimensionar el vector
    if (vector->ce == vector->cap){
        if (!redimensionarVector(vector, FACTOR_INCREMENTO))
            return VEC_LLENO;  // En realidad nos estaríamos quedando sin memoria
    }

    // Buscar la posición donde insertar el nuevo elemento
    while (posIns < vector->ce && elem > vector->vec[posIns]){
        posIns++;
    }

    // Si encontramos un duplicado, no insertamos
    if (posIns < vector->ce && elem == vector->vec[posIns]){
        return DUPLICADO;
    }

    // Mover los elementos hacia la derecha para hacer espacio
    for (int i = vector->ce - 1; i >= posIns; i--){
        vector->vec[i + 1] = vector->vec[i];
    }

    // Insertar el nuevo elemento en la posición correcta
    vector->vec[posIns] = elem;
    vector->ce++;  // Incrementar el contador de elementos

    return TODO_OK;
}

int vectorBuscarOrdenado(T_Vector* vector, int elem){
    if (vector->ce == 0){
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
        } else
            high = mid - 1;
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

bool redimensionarVector(T_Vector* vector, float factor){
   size_t nCap = vector->cap * factor;
   int* nVec;

   if(nCap < CAP_INICIAL)
       return false;

    nVec = realloc(vector->vec, sizeof(int) * nCap);
    if(nVec == NULL)
        return false;

    vector->vec = nVec;
    printf("Redimension de %zu a %zu \n", vector->cap, nCap); /// %zu para size_t
    vector->cap = nCap;
    return true;
}
