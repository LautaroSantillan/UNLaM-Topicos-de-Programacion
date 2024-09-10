#include "SecPal.h"

char* normalizarCadena(const char* cadANormalizar, char* cadNormalizada){
    SecPal secLect, secEscr;
    Palabra pal;

    secPalCrear(&secLect, cadANormalizar);
    secPalCrear(&secEscr, cadNormalizada);

    secPalLeer(&secLect, &pal);
    while(!secPalFin(&secLect)){
        palabraATitulo(&pal);
        secPalEscribir(&secEscr, &pal);
        secPalEscribirCar(&secEscr, ' ');
        secPalLeer(&secLect, &pal);
    }

    secPalCerrar(&secEscr);
    return cadNormalizada;
}
