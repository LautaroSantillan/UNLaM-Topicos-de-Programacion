#include "funciones.h"

int main()
{
    /// Memoria Dinamica
    //int (*matriz)[ORDEN] = malloc(sizeof(int) * ORDEN * ORDEN);
    int** matriz = crearMatriz(ORDEN, ORDEN, sizeof(int));
    if(!matriz)
        return ERROR_MEMORIA;

    cargarMatriz(matriz, ORDEN, ORDEN);
    mostrarMatriz(matriz, ORDEN, ORDEN);

    int sumaDP = sumaDiagonalPrincipal(matriz, ORDEN);
    printf("Suma de la Diagonal Principal: %d\n", sumaDP);

    int sumaDS = sumaDiagonalSecundaria(matriz, ORDEN);
    printf("Suma de la Diagonal Secundaria: %d\n", sumaDS);

    int sumaTrianguloInfDP = sumaTrianguloInferiorDP(matriz, ORDEN);
    printf("Suma del Triangulo Inferior con respecto a la Diagonal Principal: %d\n", sumaTrianguloInfDP);

    int sumaTrianguloSupDS = sumaTrianguloSuperiorDS(matriz, ORDEN);
    printf("Suma del Triangulo Superior con respecto a la Diagonal Secundaria: %d\n", sumaTrianguloSupDS);

    destruirMatriz(matriz, ORDEN);

    return TODO_OK;
}
