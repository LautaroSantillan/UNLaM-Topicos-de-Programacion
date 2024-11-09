#include "funciones.h"

bool redimensionarVector(Vector* vector, float factor);

unsigned long long factorial(int n){
    if(n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int dcm(int x, int y){
    if(y == 0)
        return x;

    return dcm(y, x % y);
}

bool vectorCrear(Vector* vector, size_t tamElem){
    vector->ce = 0;
    vector->vec = malloc(tamElem * CAP_INI);

    if(vector->vec == NULL){
        vector->cap = 0;
        return false;
    }

    vector->cap = CAP_INI;
    vector->tamElem = tamElem;
    return true;
}

int vectorOrdInsertar(Vector* vector, const void* elem, Cmp cmp){
    if(vector->ce == vector->cap){
        if(!redimensionarVector(vector, FACTOR_INCR))
            return SIN_MEM;
    }

    void* posIns = vector->vec;
    void* ult = vector->vec + (vector->ce - 1) * vector->tamElem;

    while(posIns <= ult && cmp(elem, posIns) > 0)
        posIns += vector->tamElem;

    if(posIns <= ult && cmp(elem, posIns) == 0)
        return DUPLICADO;

    for(void* i = ult; i >= posIns; i -= vector->tamElem)
       memcpy(i + vector->tamElem, i, vector->tamElem); // *(i + 1) = *i;

    memcpy(posIns, elem, vector->tamElem);
    vector->ce++;
    return TODO_OK;
}

bool redimensionarVector(Vector* vector, float factor){
    size_t nCap = vector->cap * factor;

	if(nCap < CAP_INI)
		return false;

	void* nVec = realloc(vector->vec, vector->tamElem * nCap);

    if(!nVec)
		return false;

	vector->vec = nVec;
	printf("Redimension de %lu a %lu\n", (unsigned long)vector->cap, (unsigned long)nCap);
	vector->cap = nCap;
	return true;
}

/// Iterador

void vectorIteradorCrear(VectorIterador* it, Vector* vector){
    it->pri = vector->vec;
    it->ult = vector->vec + (vector->ce - 1) * vector->tamElem;
    it->act = NULL;
    it->tamElem = vector->tamElem;
    it->finIter = true;
}

void* vectorIteradorPrimero(VectorIterador* it){
    if(it->ult < it->pri) /// Está vacío
        return NULL;

    it->act = it->pri;
    it->finIter = false;
    return it->act;
}

void* vectorIteradorSiguiente(VectorIterador* it){
    if(it->finIter)
        return NULL;

    void* sig = it->act + it->tamElem;
    if(sig > it->ult){
        it->finIter = true;
        return NULL;
    }

    it->act = sig;
    return it->act;
}

void* vectorIteradorUltimo(VectorIterador* it){
    if(it->ult < it->pri) /// Está vacío
        return NULL;

    it->act = it->ult;
    it->finIter = false;
    return it->act;
}

void* vectorIteradorAnterior(VectorIterador* it){
    if(it->finIter)
        return NULL;

    void* ant = it->act - it->tamElem;

    if(ant < it->pri){
        it->finIter = true;
        return NULL;
    }

    it->act = ant;
    return it->act;
}

void* vectorIteradorActual(VectorIterador* it){
    return it->act;
}

bool vectorIteradorFinIter(const VectorIterador* it){
    return it->finIter;
}
