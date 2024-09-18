#include "funciones.h"

int main()
{
    int matriz[ORDEN][ORDEN];

    cargarMatriz(ORDEN, ORDEN, matriz);
    mostrarMatriz(ORDEN, ORDEN, matriz);

    int sumaDP = sumaDiagonalPrincipal(ORDEN, matriz);
    printf("Suma de la Diagonal Principal: %d\n", sumaDP);

    int sumaDS = sumaDiagonalSecundaria(ORDEN, matriz);
    printf("Suma de la Diagonal Secundaria: %d\n", sumaDS);

    int sumaTrianguloInfDP = sumaTrianguloInferiorDP(ORDEN, matriz);
    printf("Suma del Triangulo Inferior con respecto a la Diagonal Principal: %d\n", sumaTrianguloInfDP);

    int sumaTrianguloSupDS = sumaTrianguloSuperiorDS(ORDEN, matriz);
    printf("Suma del Triangulo Superior con respecto a la Diagonal Secundaria: %d\n", sumaTrianguloSupDS);

    /// Realizar las dos sumas triangulares que faltan
    /// Recorrer una matriz en forma de espiral

    return TODO_OK;
}
