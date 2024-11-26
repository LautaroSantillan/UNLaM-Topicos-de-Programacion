#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP_INI 10
#define TODO_OK 1

typedef struct{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}MiVectorVoid;
