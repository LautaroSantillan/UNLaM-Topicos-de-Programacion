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
bool isValidDate(const Fecha* f);
void showDate(const Fecha* f);
int cantDaysMonth(int m, int y);
bool isLeap(int y);

///A desarrollar
//Fecha addDaysDate(const Fecha* f, int days);
//Fecha subDaysDate(const Fecha* f, int days);
//int difBetweenDates(const Fecha* f1, const Fecha* f2);
//int dayOfYear(const Fecha* f);
//Fecha dayOfYearDate(int dayOfYear, int year);
//int dayOfTheWeek(const Fecha* f);
