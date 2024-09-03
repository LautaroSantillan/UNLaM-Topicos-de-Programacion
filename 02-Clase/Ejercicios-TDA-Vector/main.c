#include "funciones.h"

int main() {
    T_Vector miVec;

    // Crear el vector
    vectorCrear(&miVec);

    // --- PRUEBAS CON VECTOR ORDENADO ---
    printf("PRUEBAS CON VECTOR ORDENADO\n");

    vectorOrdenadoInsertar(&miVec, 5);
    vectorOrdenadoInsertar(&miVec, 10);
    vectorOrdenadoInsertar(&miVec, 3);
    vectorOrdenadoInsertar(&miVec, 7);
    vectorOrdenadoInsertar(&miVec, 1);

    printf("Vector despues de inserciones ordenadas: ");
    mostrar(&miVec);

    vectorOrdenadoEliminarElemento(&miVec, 3);
    printf("\nVector despues de eliminar el elemento 3: ");
    mostrar(&miVec);

    int pos = vectorOrdenadoBuscarElemento(&miVec, 7);
    if (pos != ERROR) {
        printf("\nElemento 7 encontrado en la posicion: %d\n", pos);
    } else {
        printf("\nElemento 7 no encontrado.\n");
    }

    // --- PRUEBAS CON VECTOR DESORDENADO ---
    printf("\n\nPRUEBAS CON VECTOR DESORDENADO\n");

    vectorDesordenadoInsertarPrimero(&miVec, 20);
    vectorDesordenadoInsertarUltimo(&miVec, 30);
    vectorDesordenadoInsertarCualquierPosicion(&miVec, 2, 25);

    printf("Vector despues de inserciones desordenadas: ");
    mostrar(&miVec);

    vectorDesordenadoEliminarPrimero(&miVec);
    printf("\nVector despues de eliminar el primer elemento: ");
    mostrar(&miVec);

    vectorDesordenadoEliminarUltimo(&miVec);
    printf("\nVector despues de eliminar el ultimo elemento: ");
    mostrar(&miVec);

    vectorDesordenadoEliminarPosicion(&miVec, 3);
    printf("\nVector despues de eliminar el elemento en la posicion 3: ");
    mostrar(&miVec);

    vectorDesordenadoEliminarElementos(&miVec, 25);
    printf("\nVector despues de eliminar el elemento 25: ");
    mostrar(&miVec);

    pos = vectorDesordenadoBuscarElemento(&miVec, 10);
    if (pos != ERROR) {
        printf("\nElemento 10 encontrado y eliminado.\n");
    } else {
        printf("\nElemento 10 no encontrado.\n");
    }

    return TODO_OK;
}
