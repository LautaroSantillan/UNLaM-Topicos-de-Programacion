#include "Palabra.h"

void palabraATitulo(Palabra* pal)
{
    char* actPal = pal->vPal;

    *actPal = toUpper(*actPal);
    actPal++;
    while(*actPal)
    {
        *actPal = toLower(*actPal);
        actPal++;
    }
}

char toUpper(char c){
    if(c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char toLower(char c){
    if(c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
