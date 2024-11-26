#include "funciones.h"

bool vectorCrear(MiVectorVoid* vec, size_t tamElem)
{
    vec->vec = malloc(CAP_INI * tamElem);
    if(!vec->vec)
        return false;
    vec->ce = 0;
    vec->cap = CAP_INI;
    vec->tamElem = tamElem;

    return TODO_OK;
}

int vectorInsertarAlFinal(MiVectorVoid* vec, const void* elem)
{
    if(vec->ce == vec->cap)
    {
        if()
    }
    void* posIns = vec->vec + vec->ce * vec->tamElem;
    memcpy(posIns, elem, vec->tamElem);
    vec->ce++;

    return TODO_OK;
}
