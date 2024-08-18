#include "funciones.h"

int main()
{
    ///Sumar dias a la fecha

    /*int dias;
    Fecha fechaIng = ingresarFecha();
    mostrarFecha(&fechaIng);
    puts("\nIngresar la cantidad de dias a sumar: ");
    scanf("%d",&dias);
    Fecha nFecha = sumarDiasAFecha(&fechaIng, dias);
    mostrarFecha(&nFecha);*/

// ------------------------------------------------------------------------------------

    ///Restas dias a la fecha

    /*int dias;
    Fecha fechaIng = ingresarFecha();
    mostrarFecha(&fechaIng);
    puts("\nIngresar la cantidad de dias a restar: ");
    scanf("%d",&dias);
    Fecha nFecha = restarDiasAFecha(&fechaIng, dias);
    mostrarFecha(&nFecha);*/

// ------------------------------------------------------------------------------------

    ///Diferencia entre fechas (en dias)

    /*Fecha fecha1 = ingresarFecha();
    mostrarFecha(&fecha1);
    Fecha fecha2 = ingresarFecha();
    mostrarFecha(&fecha2);
    int dif = difEntreFechas(&fecha1, &fecha2);
    printf("\nLa diferencia en dias entre las dos fechas es: %d\n", dif);*/


// ------------------------------------------------------------------------------------

    ///Obtener dia del año (en cantidad)

    /*Fecha fechaIng = ingresarFecha();
    mostrarFecha(&fechaIng);
    int diaAnio = diaDelAnio(&fechaIng);
    printf("\nLa cantidad de dias del anio es: %d", diaAnio);*/


// ------------------------------------------------------------------------------------

    ///Obtener la Fecha dependiendo del anio y la cantidad de dias

    /*int diaAnio, anio;
    puts("Ingresar la cantidad de dias del anio: ");
    scanf("%d",&diaAnio);
    while(diaAnio < 0 && diaAnio > 366)
    {
        puts("\nCantidad de dias del anio incorrecto. Ingrese nuevamente");
        puts("Ingresar la cantidad de dias del anio: ");
        scanf("%d",&diaAnio);
    }
    puts("Ingresar el anio: ");
    scanf("%d",&anio);
    Fecha fechaAnio = diaDelAnioAFecha(diaAnio, anio);
    mostrarFecha(&fechaAnio);*/

// -----------------------------------------------------------------------------------

    ///Obtener el dia de la semana

    Fecha fechaIng = ingresarFecha();
    mostrarFecha(&fechaIng);
    puts("\n");
    int diaSemana = diaDeLaSemana(&fechaIng);
    determinarDiaSemana(diaSemana);

    return 0;
}
