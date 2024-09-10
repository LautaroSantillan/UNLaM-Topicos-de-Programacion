#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 100

size_t myStrlen(const char* cad);
char* myStrcpy(char* cadDest, const char* cadOrig);
char* myStrcat(char* cad1, const char* cad2); /// TERMINARLA
//char* myStrstr(const char* cad, const char* subCad);
//char* myStrchr(char* cad, int car);
//char* myStrrchr(char* cad, int car);
int myStrcmp(const char* cad1, const char* cad2);
char* myStrtit(char* cad);
char toUpper(char c);
char toLower(char c);
char* myStrrev(char* cad);
