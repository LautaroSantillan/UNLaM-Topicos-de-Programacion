#include <stdio.h> /// Podria ir en el .c ya que es utilizado ahi (hace que el programa sea mas ligero y menos pesado)
#include <stdlib.h>
#include <stddef.h>

#define ORDEN 4

#define TODO_OK 0
#define ERROR_MEMORIA 1

void** crearMatriz(size_t filas, size_t columnas, size_t tamElem);
void destruirMatriz(void** mat, size_t filas);

void cargarMatriz(int** mat, size_t filas, size_t columnas);
void mostrarMatriz(int** mat, size_t filas, size_t columnas);

int sumaDiagonalPrincipal(int** mat, size_t orden);
int sumaDiagonalSecundaria(int** mat, size_t orden);
int sumaTrianguloInferiorDP(int** mat, size_t orden);
int sumaTrianguloSuperiorDS(int** mat, size_t orden);
int** productoMatrices(int** mat, int** mat2, size_t filM1, size_t colM1FilM2, size_t colM2);
