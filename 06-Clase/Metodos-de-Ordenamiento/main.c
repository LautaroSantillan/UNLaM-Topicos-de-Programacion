#include "funciones.h"

int main()
{
    T_Vector mainVec;
    vectorCrear(&mainVec);

    cargarVectorRandom(&mainVec, CANT_ELEMENTOS);

    puts("\nAntes de ordenar:\n");
    imprimirVectorConComparativa(&mainVec);

    clock_t startTime = clock();
    vectorOrdenar(&mainVec, SELECCION);
    clock_t endTime = clock();
    double fnTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    puts("\nDespues de ordenar:\n");
    imprimirVectorConComparativa(&mainVec);
    printf("\nEl tiempo de ejecucion del metodo de ordenamiento es: %f\n", fnTime);

    vectorEliminar(&mainVec);
    return TODO_OK;
}
