#include "funciones.h"

int main()
{
    T_Vector miVector;

    /// Crear vector
    if (!vectorCrear(&miVector)) {
        printf("Error al crear el vector.\n");
        return SIN_MEMORIA;
    }

    /// Insertar elementos ordenados
    for (int i = 1; i <= CANT_ELEMENTOS; i++) {
        int status = vectorInsertarOrdenado(&miVector, i);

        if (status == TODO_OK)
            printf("Elemento %d insertado correctamente.\n", i);
        else if (status == DUPLICADO)
            printf("Elemento %d duplicado.\n", i);
        else
            printf("Error al insertar el elemento %d.\n", i);
    }

    /// Probar la función de búsqueda
    int buscar = 5;
    int pos = vectorBuscarOrdenado(&miVector, buscar);

    if (pos != -1)
        printf("Elemento %d encontrado en la posicion %d.\n", buscar, pos);
    else
        printf("Elemento %d no encontrado.\n", buscar);

    /// Eliminar un elemento
    if (vectorEliminarOrdenadoElemento(&miVector, buscar))
        printf("Elemento %d eliminado correctamente.\n", buscar);
    else
        printf("Error al eliminar el elemento %d.\n", buscar);

    /// Vaciar el vector
    vectorVaciar(&miVector);
    printf("Vector vaciado.\n");

    /// Eliminar el vector
    vectorEliminar(&miVector);
    printf("Vector eliminado.\n");

    return TODO_OK;
}
