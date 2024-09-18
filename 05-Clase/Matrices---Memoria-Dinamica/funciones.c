#include "funciones.h"

void** crearMatriz(size_t filas, size_t columnas, size_t tamElem){
    void** mat = malloc(sizeof(void*) * filas);
    if(!mat)
        return NULL;

    void** ult = mat + filas - 1;
    for(void** i = mat; i <= ult; i++){
        *i = malloc(tamElem * columnas);
        if(!*i){
            destruirMatriz(mat, *i);
            return NULL;
        }
    }

    return mat;
}

void destruirMatriz(void** mat, size_t filas){
    void** ult = mat + filas - 1;
    for(void** i = mat; i <= ult; i++)
        free(*i);

    free(mat);
}

void cargarMatriz(int** mat, size_t filas, size_t columnas){
    int cont = 1;

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++)
            mat[i][j] = cont++;
    }
}

void mostrarMatriz(int** mat, size_t filas, size_t columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++)
            printf("%3d", mat[i][j]);

        putchar('\n');
    }
}

int sumaDiagonalPrincipal(int** mat, size_t orden){
    int acum = 0;

    for(int i = 0; i < orden; i++)
        acum += mat[i][i];

    return acum;
}

int sumaDiagonalSecundaria(int** mat, size_t orden){
    int acum = 0;

    for(int i = 0, j = orden -1; i < orden; i++, j--)
        acum += mat[i][j];

    return acum;
}

int sumaTrianguloInferiorDP(int** mat, size_t orden){
    int acum = 0;

    for(int i = 1; i < orden; i++){
        for(int j = 0; j < i; j++)
            acum += mat[i][j];
    }

    return acum;
}

int sumaTrianguloSuperiorDS(int** mat, size_t orden){
    int acum = 0;

    for(int i = 0; i < orden - 1; i++){
        for(int j = 0; j < orden - i - 1; j++)
            acum += mat[i][j];
    }

    return acum;
}
