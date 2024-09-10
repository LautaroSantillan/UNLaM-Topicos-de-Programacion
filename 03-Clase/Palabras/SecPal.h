#ifndef SECPAL_H
#define SECPAL_H

#include <stdbool.h>
#include "Palabra.h"

typedef struct{
    char* cursor;
    bool finSec;
}SecPal; /// Secuencia Palabra

bool esLetra(char c);
void secPalCrear(SecPal* secPal, const char* cad);
bool secPalLeer(SecPal* secPal, Palabra* pal);
void secPalEscribir(SecPal* secPal, const Palabra* pal);
void secPalEscribirCar(SecPal* secPal, char c);
bool secPalFin(const SecPal* secPal);
void secPalCerrar(SecPal* secPal);

#endif // SECPAL_H
