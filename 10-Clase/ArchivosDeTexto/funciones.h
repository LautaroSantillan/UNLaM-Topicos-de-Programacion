#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARG_FILE_ENTER 1
#define ARG_TYPE_FILE_ENTER 2
#define ARG_FILE_EXIT 3
#define ARG_TYPE_FILE_EXIT 4
#define NAM_FILE_EMPL "Empleados.dat"
#define NAM_FILE_EMPL_IDX "Empleados.idx"
#define PORC_INCR_SUELDO 10

#define TODO_OK 0
#define ERROR_FILE 1
#define ERROR_MEMORIA 2
#define ERROR_LINEA_LARGA 3

#define TAM_NOMBRE 51
#define CANT_EMPL 9
#define TAM_LINEA 501

typedef void (*BinATxt)(const void* reg, FILE* fileTxt);
typedef int (*TxtABin)(char* linea, void* reg);

///TDA: TIPO de DATO ABSTRACTO
typedef struct{
    int day;
    int month;
    int year;
}Fecha;

typedef struct{
    int legajo;
    char nombre[TAM_NOMBRE];
    char sexo;
    Fecha fechaIngr;
    float sueldo;
}T_Empleado;

typedef struct{
    int legajo;
    unsigned long nroReg;
}T_EmplIdx;

/// PRIMITIVAS FECHA
Fecha getIntoDate();
bool isValidDate(Fecha f);
int cantDaysMonth(int month, int year);
bool isLeap(int year);

/// LOCALES
int generarArchivoEmpleados(const char* nameFile);
int mostrarEmpleados(const char* nameFile);

/// conversorBinATxt
int conversorBinATxt(const char* nomFileBin, size_t tamReg, const char* nomFileTxt, BinATxt binATxt);
void empleadoBinATxtVar(const void* reg, FILE* fileTxt);
void empleadoBinATxtFijo(const void* reg, FILE* fileTxt);
/// conversorTxtABin
int conversorTxtABin(const char* nomFileTxt, const char* nomFileBin, size_t tamReg, TxtABin txtABin);
int empleadoTxtVarABin(char* linea, void* reg);
int empleadoTxtFijoABin(char* linea, void* reg);
bool errorFatal(int codigo);
