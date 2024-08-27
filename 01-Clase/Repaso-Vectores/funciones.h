#include <stdio.h>
#include <stdlib.h>

void insertarEnPosicion(int vec[], int *n, int elem, int pos);
void insertarOrdenado(int vec[], int *n, int elem);
void insertarDesordenado(int vec[], int *n, int elem);
void insertarInicio(int vec[], int *n, int elem);
void insertarFinal(int vec[], int *n, int elem);

void eliminarPorPosicion(int vec[], int *n, int pos);
void eliminarPorValorOrdenado(int vec[], int *n, int elem);
void eliminarPorValorDesordenado(int vec[], int *n, int elem);

int buscarSecuencial(int vec[], int n, int elem);
int buscarBinaria(int vec[], int n, int elem);

void imprimirVector(int vec[], int n);
