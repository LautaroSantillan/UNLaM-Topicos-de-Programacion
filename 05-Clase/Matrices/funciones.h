#include <stdio.h> /// Podria ir en el .c ya que es utilizado ahi (hace que el programa sea mas ligero y menos pesado)
#include <stdlib.h>
#include <stddef.h>

#define ORDEN 4

#define TODO_OK 0

void cargarMatriz(size_t filas, size_t columnas, int mat[][columnas]);
void mostrarMatriz(size_t filas, size_t columnas, int mat[][columnas]);
int sumaDiagonalPrincipal(size_t orden, int mat[][orden]);
int sumaDiagonalSecundaria(size_t orden, int mat[][orden]);
int sumaTrianguloInferiorDP(size_t orden, int mat[][orden]);
int sumaTrianguloSuperiorDS(size_t orden, int mat[][orden]);
