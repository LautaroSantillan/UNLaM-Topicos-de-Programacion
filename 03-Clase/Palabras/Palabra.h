#ifndef PALABRA_H
#define PALABRA_H

#define TAM_PAL 51

typedef struct{
    char vPal[TAM_PAL];
}Palabra;

void palabraATitulo(Palabra* pal);
char toUpper(char c);
char toLower(char c);

#endif // PALABRA_H
