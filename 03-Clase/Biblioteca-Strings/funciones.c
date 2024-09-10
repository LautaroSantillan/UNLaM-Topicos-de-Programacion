#include "funciones.h"

size_t myStrlen(const char* cad)
{
    size_t cant = 0;

    while(*cad++) /// *cad != '/0'
        cant++;

    return cant;
}

char* myStrcpy(char* cadDest, const char* cadOrig)
{
    char* aux = cadDest;

    while(*cadOrig)
    {
        *cadDest = *cadOrig;
        cadDest++;
        cadOrig++;
    }
    cadDest = '\0';

    return aux;
}

char* myStrcat(char* cad1, const char* cad2)
{
    char* aux = cad1;
    int i = 0;

    while(*cad1)
    {
        printf("%c\t", cad1[i]);
        i++;
    }

    return aux;
}

int myStrcmp(const char* cad1, const char* cad2)
{
    while(*cad1 || *cad2)
    {
        if(*cad1 == *cad2)
        {
            cad1++;
            cad2++;
        }
        else
            return (*cad1 - *cad2);
    }

    return (*cad1 - *cad2);
}

char* myStrtit(char *cad)
{
    int capitalize = 1;

    while(*cad)
    {
        if(isspace(*cad) || *cad == '\t')
            capitalize = 1;
        else
        {
            if(capitalize)
            {
                *cad = toUpper(*cad);
                capitalize = 0;
            } else
                *cad = toLower(*cad);
        }
        cad++;
    }

    return cad;
}

char toUpper(char c)
{
    if(c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char toLower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

char* myStrrev(char* cad)
{
    int len = myStrlen(cad);
    char* start = cad;
    char* end = cad + len - 1;

    while(start < end)
    {
        char aux = *start;
        *start = *end;
        *end = aux;
        start++;
        end--;
    }

    return cad;
}
