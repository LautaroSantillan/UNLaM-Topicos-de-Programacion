#include "funciones.h"

/// FECHA

Fecha getIntoDate(){
    Fecha fecha;
    puts("Ingrese una fecha (D/M/Y): ");
    scanf("%d/%d/%d", &fecha.day, &fecha.month, &fecha.year);
    while(!isValidDate(fecha)){
        puts("Fecha invalida. Ingresa de nuevo (D/M/Y): ");
        scanf("%d/%d/%d", &fecha.day, &fecha.month, &fecha.year);
    }
    return fecha;
}
/// esFechaValida
bool isValidDate(Fecha f){
    if(f.year < 1601)
        return false;

    if(f.month < 1 || f.month > 12)
        return false;

    if(f.day < 1 || f.day > cantDaysMonth(f.month, f.year))
        return false;

    return true;
}

int cantDaysMonth(int month, int year){
    int cmd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && isLeap(year)) ///Es Bisiesto
        return 29;

    return cmd[month];
}

bool isLeap(int year){
    return year % 4 == 0  && (year % 100 != 0 || year % 400 == 0);
}

/// LOCALES
int generarArchivoEmpleados(const char* nameFile){
    FILE* pf = fopen(nameFile, "wb");
    if(!pf)
        return ERROR_FILE;

    T_Empleado vecEmpl[CANT_EMPL] = {
        {3, "Juan Minio", 'M', {12, 8, 2019}, 13000},
        {9, "Pedro Gonzalez", 'M', {2, 5, 2001}, 14000},
        {1, "Lautaro Santillan", 'M', {15, 12, 2003}, 10000},
        {7, "Daniela Dado", 'M', {12, 9, 2001}, 15000},
        {5, "Nazareno Perez", 'M', {8, 8, 2018}, 12000},
        {8, "Veronica Bernabeu", 'F', {21, 10, 2009}, 10000},
        {2, "Arsenio Paredes", 'M', {30, 3, 2020}, 17000},
        {4, "Julio Copernico", 'M', {11, 8, 1995}, 11000},
        {6, "Ignacio Lopez", 'M', {20, 1, 1999}, 18000}
    };
    fwrite(vecEmpl, sizeof(T_Empleado), CANT_EMPL, pf);
    fclose(pf);
    return TODO_OK;
}

int mostrarEmpleados(const char* nameFile){
    FILE* pf = fopen(nameFile, "rb");
    if(!pf)
        return ERROR_FILE;

    T_Empleado empl;
    fread(&empl, sizeof(T_Empleado), 1, pf);
    while(!feof(pf)){
        printf("%02d, %-20s, %c, %02d/%02d/%04d, %9.2f\n", empl.legajo, empl.nombre, empl.sexo, empl.fechaIngr.day, empl.fechaIngr.month, empl.fechaIngr.year, empl.sueldo);
        fread(&empl, sizeof(T_Empleado), 1, pf);
    }

    putchar('\n');
    fclose(pf);
    return TODO_OK;
}

/// conversorBinATxt
int conversorBinATxt(const char* nomFileBin, size_t tamReg, const char* nomFileTxt, BinATxt binATxt){
    void* reg = malloc(tamReg);
    if(!reg)
        return ERROR_MEMORIA;

    FILE* fileBin = fopen(nomFileBin, "rb");
    if(!fileBin)
        return ERROR_FILE;

    FILE* fileTxt = fopen(nomFileTxt, "wt");
    if(!fileTxt){
        fclose(fileBin);
        return ERROR_FILE;
    }

    fread(reg, tamReg, 1, fileBin);
    while(!feof(fileBin)){
        binATxt(reg, fileTxt);
        fread(reg, tamReg, 1, fileBin);
    }

    free(reg);
    fclose(fileBin);
    fclose(fileTxt);
    return TODO_OK;
}

void empleadoBinATxtVar(const void* reg, FILE* fileTxt){
    const T_Empleado* empl = reg;
    fprintf(fileTxt, "%d|%s|%c|%d/%d/%d|%.2f\n", empl->legajo, empl->nombre, empl->sexo, empl->fechaIngr.day, empl->fechaIngr.month, empl->fechaIngr.year, empl->sueldo);
}

void empleadoBinATxtFijo(const void* reg, FILE* fileTxt){
    const T_Empleado* empl = reg;
    fprintf(fileTxt, "%08d%-20s%c%02d%02d%04d%08.2f\n", empl->legajo, empl->nombre, empl->sexo, empl->fechaIngr.day, empl->fechaIngr.month, empl->fechaIngr.year, empl->sueldo);
}

/// conversorTxtABin
int conversorTxtABin(const char* nomFileTxt, const char* nomFileBin, size_t tamReg, TxtABin txtABin){
    void* reg = malloc(tamReg);
    if(!reg)
        return ERROR_MEMORIA;

    FILE* fileTxt = fopen(nomFileTxt, "rt");
    if(!fileTxt)
        return ERROR_FILE;

    FILE* fileBin = fopen(nomFileBin, "wb");
    if(!fileBin){
        fclose(fileTxt);
        return ERROR_FILE;
    }

    char linea[TAM_LINEA];
    int ret = TODO_OK;

    fgets(linea, TAM_LINEA, fileTxt);
    while(!feof(fileTxt) && !errorFatal(ret)){
        ret = txtABin(linea, reg);
        if(ret == TODO_OK)
            fwrite(reg, tamReg, 1, fileBin);
        fgets(linea, TAM_LINEA, fileTxt);
    }

    free(reg);
    fclose(fileTxt);
    fclose(fileBin);
    return TODO_OK;
}

int empleadoTxtVarABin(char* linea, void* reg){
    char* posActual = strchr(linea, '\n');
    if(!posActual)
        return ERROR_LINEA_LARGA;
    T_Empleado* empl = reg;

    *posActual = '\0';
    posActual = strrchr(linea, '|');
    sscanf(posActual + 1, "%f", &empl->sueldo);

    *posActual = '\0';
    posActual = strrchr(linea, '|');
    sscanf(posActual + 1, "%d/%d/%d", &empl->fechaIngr.day, &empl->fechaIngr.month, &empl->fechaIngr.year);

    *posActual = '\0';
    posActual = strrchr(linea, '|');
    empl->sexo = *(posActual + 1);

    *posActual = '\0';
    posActual = strrchr(linea, '|');
    strncpy(empl->nombre, posActual + 1, TAM_NOMBRE - 1);
    *(empl->nombre + TAM_NOMBRE - 1) = '\0';

    *posActual = '\0';
    sscanf(linea, "%d", &empl->legajo);
    return TODO_OK;
}

int empleadoTxtFijoABin(char* linea, void* reg){
    char* posActual = strchr(linea, '\n');
    if(!posActual)
        return ERROR_LINEA_LARGA;
    T_Empleado* empl = reg;

    *posActual = '\0';
    posActual -= 8;
    sscanf(posActual, "%f", &empl->sueldo);

    *posActual = '\0';
    posActual -= 8;
    sscanf(posActual, "%2d%2d%4d", &empl->fechaIngr.day, &empl->fechaIngr.month, &empl->fechaIngr.year);

    *posActual = '\0';
    posActual--;
    empl->sexo = *posActual;

    *posActual = '\0';
    posActual -= 20;
    strcpy(empl->nombre, posActual);

    *posActual = '\0';
    sscanf(linea, "%d", &empl->legajo);
    return TODO_OK;
}

bool errorFatal(int codigo){
    return codigo == ERROR_LINEA_LARGA;
}
