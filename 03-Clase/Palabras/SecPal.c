#include "SecPal.h"

bool esLetra(char c){
    if(c >= 'a' && c <= 'z') /// Minuscula
        return true;

    if(c >= 'A' && c <= 'Z') /// Mayuscula
        return true;

    return false;
}
///
void secPalCrear(SecPal* secPal, const char* cad){
    secPal->cursor = cad;
    secPal->finSec = false;
}

bool secPalLeer(SecPal* secPal, Palabra* pal){
    while(*secPal->cursor != '\0' && !esLetra(*secPal->cursor))
        secPal->cursor++;

    if(*secPal->cursor == '\0'){
        secPal->finSec = true;
        return false;
    }

    char* actPal = pal->vPal;
    while(*secPal->cursor != '\0' && esLetra(*secPal->cursor)){
        *actPal = *secPal->cursor;
        actPal++;
        secPal->cursor++;
    }

    *actPal = '\0';
    return true;
}

void secPalEscribir(SecPal* secPal, const Palabra* pal){
    const char* actPal = pal->vPal;

    while(*actPal != '\0'){
        *secPal->cursor = *actPal;
        secPal->cursor++;
        actPal++;
    }
}

void secPalEscribirCar(SecPal* secPal, char c){
    *secPal->cursor = c;
    secPal->cursor++;
}

bool secPalFin(const SecPal* secPal){
    return secPal->finSec;
}


void secPalCerrar(SecPal* secPal){
    *secPal->cursor = '\0';
}
