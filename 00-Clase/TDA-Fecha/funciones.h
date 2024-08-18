#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///TDA: TIPO de DATO ABSTRACTO
typedef struct{
    int day;
    int month;
    int year;
}Fecha;

///PRIMITIVAS

Fecha getIntoDate();
bool isValidDate(Fecha f);
void showDate(Fecha f);
Fecha addDaysDate(Fecha f, int days);
Fecha subDaysDate(Fecha f, int days);
int difBetweenDates(Fecha f1, Fecha f2);
int dayOfYear(Fecha f);
Fecha dayOfYearDate(int dayOfYear, int year);
int dayOfTheWeek(Fecha f);
int cantDaysMonth(int m, int y);
bool isLeap(int y);
