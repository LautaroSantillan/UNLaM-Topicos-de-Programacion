#include "funciones.h"

/// conversorBinATxt -- Empleados.dat B Empleados.txt (V or F) --> Pasar de .dat a .txt (tanto en ancho variable como fijo)
/// conversorTxtABin -- Empleados.txt (V or F) Empleados.dat B --> Pasar de .txt a .dat
    /// EmpleadosVariable.txt V Empleados.dat B
    /// EmpleadosFijo.txt F Empleados.dat B
int main(int argc, char* argv[]){
    int ret;
    /// Generar archivo binario
    //ret = generarArchivoEmpleados(argv[ARG_FILE_ENTER]);
    //mostrarEmpleados(argv[ARG_FILE_ENTER]);

    char typeFileEnter = argv[ARG_TYPE_FILE_ENTER][0];
    char typeFileExit = argv[ARG_TYPE_FILE_EXIT][0];

    switch(typeFileEnter){
        case 'B':
            switch(typeFileExit){
                case 'V': /// Variable
                    ret = conversorBinATxt(argv[ARG_FILE_ENTER], sizeof(T_Empleado), argv[ARG_FILE_EXIT], empleadoBinATxtVar);
                    break;
                case 'F': /// Fijo
                    ret = conversorBinATxt(argv[ARG_FILE_ENTER], sizeof(T_Empleado), argv[ARG_FILE_EXIT], empleadoBinATxtFijo);
                    break;
            }
        case 'V':
            ret = conversorTxtABin(argv[ARG_FILE_ENTER], argv[ARG_FILE_EXIT], sizeof(T_Empleado), empleadoTxtVarABin);
            mostrarEmpleados(argv[ARG_FILE_EXIT]);
            break;
        case 'F':
            ret = conversorTxtABin(argv[ARG_FILE_ENTER], argv[ARG_FILE_EXIT], sizeof(T_Empleado), empleadoTxtFijoABin);
            mostrarEmpleados(argv[ARG_FILE_EXIT]);
            break;
    }

    return ret;
}
