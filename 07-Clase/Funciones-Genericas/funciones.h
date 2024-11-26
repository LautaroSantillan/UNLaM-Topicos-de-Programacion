#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP_INI 10

typedef struct{
    int vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}T_Vector;

bool vectorCrear(T_Vector vec, size_t tamElem);
