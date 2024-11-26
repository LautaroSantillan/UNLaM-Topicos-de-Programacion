#include "funciones.h"

bool vectorCrear(T_Vector vec, size_t tamElem){
    vec->ce = 0;
    vec->vec = malloc(tamElem * CAP_INI);

    if(vec->vec == NULL){
        vec->cap = 0;
        return false;
    }

    vec->cap = CAP_INI;
    vec->tamElem = tamElem;
    return true;
}

