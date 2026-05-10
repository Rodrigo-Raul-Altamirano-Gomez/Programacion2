#include "Funciones.h"

int main() {
    Usuario* arrUsuarios;
    Libro* arrLibros;
    cargarUsuarios(arrUsuarios);
    cargarLibros(arrLibros);
    procesarPrestamos(arrUsuarios,arrLibros);
    determinarDeudas(arrUsuarios);
    emitirReporteUsuarios(arrUsuarios);
    emitirReporteLibros(arrLibros);
    return 0;
}
