#include "funciones.h"
/// INICIALES
bool vectorCrear(T_Vector* miVec){
    miVec->ce = 0;
    return true;
}

void mostrar(T_Vector *miVec){
    int *ini = miVec->vec;
    int *fin = miVec->vec + miVec->ce -1;
    while(ini<=fin){
        printf("%d \t",*ini);
        ini++;
    }
}

/// VECTOR ORDENADO
int vectorOrdenadoInsertar(T_Vector* miVec, int elem) {
    if (miVec->ce == TAM)
        return VEC_LLENO;

    int* posIns = miVec->vec;
    int* ult = miVec->vec + miVec->ce - 1;

    // Buscar la posición donde insertar el nuevo elemento
    while (posIns <= ult && elem > *posIns)
        posIns++;

    /// CASO DE DUPLICADO
    if (posIns <= ult && elem == *posIns)
        return DUPLICADO;

    /// CASO DE ELEM < -1 VEC (Se ajusta el vector para insertar el elemento en la posición correcta)
    for (int* i = ult; i >= posIns; i--)
        *(i + 1) = *i;

    // Insertar el elemento en la posición determinada
    *posIns = elem;
    miVec->ce++;

    return TODO_OK;
}

int vectorOrdenadoBuscarElemento(T_Vector* miVec, int elem){
    int comp;
    int* li = miVec->vec;
    int* ls = miVec->vec + miVec->ce - 1;
    int* m;
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

bool vectorOrdenadoEliminarElemento(T_Vector* miVec, int elem){
    if(miVec->ce == 0)
        return false; //Esta vacio el vector

    int* ult = miVec->vec + miVec->ce - 1;
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

int vectorOrdenadoEliminarDuplicado(T_Vector* miVec, int elem){
    for(int i = 0; miVec->vec[i] <= elem; i++){
        if(miVec->vec[i] == elem)
            return TODO_OK;
    }
    return ERROR;
}

/// VECTOR DESORDENADO
int vectorDesordenadoInsertarPrimero(T_Vector* miVec, int elem){
    if(miVec->ce == TAM)
        return VEC_LLENO;

    int posIns = 0;
    for(int i = miVec->ce-1; i >= posIns; i--)
        miVec->vec[i+1] = miVec->vec[i];

    miVec->vec[posIns] = elem;
    miVec->ce++;
    return TODO_OK;
}

int vectorDesordenadoInsertarUltimo(T_Vector* miVec, int elem){
    if(miVec->ce == TAM)
        return VEC_LLENO;

    int posIns = miVec->ce;
    miVec->vec[posIns] = elem;
    miVec->ce++;
    return TODO_OK;
}

int vectorDesordenadoInsertarCualquierPosicion(T_Vector* miVec, int pos, int elem){
    if(miVec->ce == TAM)
        return VEC_LLENO;

    for(int i = miVec->ce-1; i >= pos; i--)
        miVec->vec[i+1] = miVec->vec[i];

    miVec->vec[pos] = elem;
    miVec->ce++;
    return TODO_OK;
}

int vectorDesordenadoEliminarPosicion(T_Vector* miVec, int pos){
    if(pos > miVec->ce-1)
        return ERROR;

    miVec->vec[pos] = 0;
    for(int i = pos; i <= miVec->ce-1; i++)
        miVec->vec[i] = miVec->vec[i+1];

    miVec->ce--;
    return TODO_OK;
}

int vectorDesordenadoEliminarPrimero(T_Vector* miVec){
    int pos = 0;
    if(pos > miVec->ce-1)
        return ERROR;

    miVec->vec[pos] = 0;
    for(int i = pos; i <= miVec->ce-1; i++)
        miVec->vec[i] = miVec->vec[i+1];

    miVec->ce--;
    return TODO_OK;
}

int vectorDesordenadoEliminarUltimo(T_Vector* miVec){
    int pos = miVec->ce-1;
    if(pos > miVec->ce-1)
        return ERROR;

    miVec->ce--;
    return TODO_OK;
}

int vectorDesordenadoEliminarElementos(T_Vector* miVec, int elem){
    int posElim = 0;
    bool eliminado = false;

    for(int i = 0; i < miVec->ce; i++)
    {
        if(miVec->vec[i] == elem)
        {
            miVec->vec[i] = 0;
            posElim = i;
                for(int j = posElim; j <= miVec->ce-1; j++)
                    miVec->vec[j] = miVec->vec[j+1];
            eliminado = true;
            miVec->ce--;
        }
    }

    if(eliminado)
        return TODO_OK;
    else
        return ERROR;
}

int vectorDesordenadoBuscarElemento(T_Vector* miVec, int elem){
    for(int i = 0; i < miVec->ce; i++)
    {
        if(miVec->vec[i] == elem)
        {
            for(int j = i; j < miVec->ce; j++)
                miVec->vec[j] = miVec->vec[j+1];
        }
        miVec->ce--;
        return TODO_OK;
    }

    return ERROR;
}
