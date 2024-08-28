#include "funciones.h"

int main()
{
    T_Vector miVec;

    // Crear el vector
    vectorCrear(&miVec);

    // Insertar elementos
    vectorOrdenadoInsertar(&miVec, 5);
    vectorOrdenadoInsertar(&miVec, 10);
    vectorOrdenadoInsertar(&miVec, 3);
    vectorOrdenadoInsertar(&miVec, 8);

    printf("Despues de insertar elementos:\n");
    imprimirVector(&miVec);

    // Intentar insertar un duplicado
    int resultado = vectorOrdenadoInsertar(&miVec, 10);
    if (resultado == ELEMENTO_DUPLICADO)
        printf("Elemento duplicado no insertado.\n");

    // Buscar un elemento
    int posicion = vectorOrdenadoBuscar(&miVec, 8);
    if (posicion != -1) {
        printf("Elemento 8 encontrado en la posicion %d\n", posicion);
    } else {
        printf("Elemento 8 no encontrado.\n");
    }

    // Eliminar un elemento
    vectorOrdenadoEliminarElemento(&miVec, 5);
    printf("Despues de eliminar el elemento 5:\n");
    imprimirVector(&miVec);

    // Buscar un elemento que no existe
    posicion = vectorOrdenadoBuscar(&miVec, 2);
    if (posicion != -1) {
        printf("Elemento 2 encontrado en la posicion %d\n", posicion);
    } else {
        printf("Elemento 2 no encontrado.\n");
    }

    return 0;
}
