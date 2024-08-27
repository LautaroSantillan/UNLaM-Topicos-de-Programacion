#include "funciones.h"
/*
Repaso de Vectores  (Desarrollar una funci�n por cada punto):

Funci�n que inserte un elemento en un vector
    En vector ordenado
    En vector desordenado
        Al inicio
        Al final
        En posici�n pasada por argumento
Funci�n que elimine un elemento de un vector
    Por valor
        En vector ordenado
        En vector desordenado
    Por posici�n
Funci�n que busque un elemento de un vector (Debe retornar la posici�n, o -1 en el caso de que no exista)
    En vector ordenado
        Secuencial
        Binaria / Dicot�mica
    En vector desordenado

En cualquier caso:
No puede perder elementos producto de una inserci�n (Debe desplazar elementos).
No pueden quedar posiciones libres, o con cero, en el caso de una eliminaci�n (Debe desplazar elementos).
*/

int main() {
    int vec[100] = {1, 3, 5, 7, 9};
    int n = 5;

    printf("Vector inicial: ");
    imprimirVector(vec, n);

    // Prueba de inserciones
    insertarOrdenado(vec, &n, 4);
    printf("Despues de insertar 4 (ordenado): ");
    imprimirVector(vec, n);

    insertarInicio(vec, &n, 0);
    printf("Despues de insertar 0 (al inicio): ");
    imprimirVector(vec, n);

    insertarFinal(vec, &n, 10);
    printf("Despues de insertar 10 (al final): ");
    imprimirVector(vec, n);

    insertarEnPosicion(vec, &n, 6, 4);
    printf("Despues de insertar 6 (en posicion 4): ");
    imprimirVector(vec, n);

    insertarDesordenado(vec, &n, 8);
    printf("Despues de insertar 8 (desordenado): ");
    imprimirVector(vec, n);

    // Prueba de eliminaciones
    eliminarPorValorOrdenado(vec, &n, 5);
    printf("Despues de eliminar 5 (ordenado): ");
    imprimirVector(vec, n);

    eliminarPorPosicion(vec, &n, 3);
    printf("Despues de eliminar en posicion 3: ");
    imprimirVector(vec, n);

    eliminarPorValorDesordenado(vec, &n, 8);
    printf("Despues de eliminar 8 (desordenado): ");
    imprimirVector(vec, n);

    // Prueba de b�squedas
    int pos = buscarSecuencial(vec, n, 7);
    printf("Posicion de 7 (busqueda secuencial): %d\n", pos);

    pos = buscarBinaria(vec, n, 9);
    printf("Posicion de 9 (busqueda binaria): %d\n", pos);

    return 0;
}
