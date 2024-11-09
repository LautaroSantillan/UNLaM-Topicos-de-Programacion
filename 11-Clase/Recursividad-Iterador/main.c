#include "funciones.h"

int cmpInt(const void* e1, const void* e2);

int main(int argc, char* argv[]) /// FACTORIAL: 6 --- DMC: 24 - 16
{
    /// TEST FACTORIAL - C/ Recursividad
    /*int n = atoi(argv[1]);
    unsigned long long fact = factorial(n);
    printf("Factorial de %d: %I64u\n", n, fact);*/

    /// TEST DE DIVISOR COMUN DENOMINADOR - C/ Recursividad
    /*int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    int divCM = dcm(x, y);
    printf("DCM(%d, %d): %d\n", x, y, divCM);*/

    /// TEST VECTOR ITERADOR
    Vector mainVec;
    vectorCrear(&mainVec, sizeof(int));

    for(int i = CANT_ELEMS; i >= 1; i--)
        vectorOrdInsertar(&mainVec, &i, cmpInt);

    VectorIterador it;
    vectorIteradorCrear(&it, &mainVec);
    int* entero;

    entero = vectorIteradorPrimero(&it);
    while(!vectorIteradorFinIter(&it)){
        printf("%d\n", *entero);
        entero = vectorIteradorSiguiente(&it);
    }

    return 0;
}

int cmpInt(const void* e1, const void* e2){
    const int* int1 = e1;
    const int* int2 = e2;

    return *int1 - *int2;
}
