#include "funciones.h"

void cargarMatriz(size_t filas, size_t columnas, int mat[][columnas]){
    int cont = 1;

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++)
            mat[i][j] = cont++;
    }
}

void mostrarMatriz(size_t filas, size_t columnas, int mat[][columnas]){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++)
            printf("%3d", mat[i][j]);

        putchar('\n');
    }
}

int sumaDiagonalPrincipal(size_t orden, int mat[][orden]){
    int acum = 0;

    for(int i = 0; i < orden; i++)
        acum += mat[i][i];

    return acum;
}

int sumaDiagonalSecundaria(size_t orden, int mat[][orden]){
    int acum = 0;

    for(int i = 0, j = orden -1; i < orden; i++, j--)
        acum += mat[i][j];

    return acum;
}

int sumaTrianguloInferiorDP(size_t orden, int mat[][orden]){
    int acum = 0;

    for(int i = 1; i < orden; i++){
        for(int j = 0; j < i; j++)
            acum += mat[i][j];
    }

    return acum;
}

int sumaTrianguloSuperiorDS(size_t orden, int mat[][orden]){
    int acum = 0;

    for(int i = 0, limJ = orden - 2; i < orden - 2; i++, limJ--){
        for(int j = 0; j <= limJ; j++)
            acum += mat[i][j];
    }

    return acum;
}
