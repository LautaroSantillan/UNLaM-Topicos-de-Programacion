#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///TDA: Tipo de Dato Abstracto
typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;

/// Primitivas
Fecha ingresarFecha();
bool esFechaValida(const Fecha* f);
void mostrarFecha(const Fecha* f);
int cantDiasMes(int mes, int anio);
bool esBisiesto(int anio);

/// Funciones a realizar
Fecha sumarDiasAFecha(const Fecha* f, int dias);
Fecha restarDiasAFecha(const Fecha* f, int dias);
int difEntreFechas(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* f);
Fecha diaDelAnioAFecha(int diaAnio, int anio);
int diaDeLaSemana(const Fecha* f);
void determinarDiaSemana (int dia);
