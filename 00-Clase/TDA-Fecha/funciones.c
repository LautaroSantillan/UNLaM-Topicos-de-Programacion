#include "funciones.h"

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

bool isValidDate(Fecha f){ // esFechaValida
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
    if(month == 2 && isLeap(year)) //Es Bisiesto
        return 29;

    return cmd[month];
}

bool isLeap(int year){
    return year % 4 == 0  && (year % 100 != 0 || year % 400 == 0);
}

void showDate(Fecha f){
    printf("%02d/%02d/%d", f.day, f.month, f.year);
}
