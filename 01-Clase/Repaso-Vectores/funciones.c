#include "funciones.h"

void imprimirVector(int vec[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    printf("\n");
}
// INSERTAR UN VALOR
void insertarEnPosicion(int vec[], int *n, int elem, int pos) {
    for (int i = *n; i > pos; i--)
        vec[i] = vec[i - 1];
    vec[pos] = elem;
    (*n)++;
}

void insertarOrdenado(int vec[], int *n, int elem) {
    int pos = 0;
    while (pos < *n && vec[pos] < elem) {
        pos++;
    }
    insertarEnPosicion(vec, n, elem, pos);
}

void insertarDesordenado(int vec[], int *n, int elem) {
    vec[*n] = elem;
    (*n)++;
}

void insertarInicio(int vec[], int *n, int elem) {
    insertarEnPosicion(vec, n, elem, 0);
}

void insertarFinal(int vec[], int *n, int elem) {
    vec[*n] = elem;
    (*n)++;
}
// ELIMINAR UN VALOR
void eliminarPorPosicion(int vec[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        vec[i] = vec[i + 1];
    }
    (*n)--;
}

void eliminarPorValorOrdenado(int vec[], int *n, int elem) {
    int pos = -1;
    for (int i = 0; i < *n; i++) {
        if (vec[i] == elem) {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        eliminarPorPosicion(vec, n, pos);
}

void eliminarPorValorDesordenado(int vec[], int *n, int elem) {
    int pos = -1;
    for (int i = 0; i < *n; i++) {
        if (vec[i] == elem) {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        eliminarPorPosicion(vec, n, pos);
}
// BUSCAR UN VALOR
int buscarSecuencial(int vec[], int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (vec[i] == elem)
            return i;
    }
    return -1;
}

int buscarBinaria(int vec[], int n, int elem) {
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (vec[medio] == elem) {
            return medio;
        } else if (vec[medio] < elem) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}
