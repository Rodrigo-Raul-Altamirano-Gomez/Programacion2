#include "Funciones.h"

int main() {
    Tabla tabla;
    cargar_tabla_infracciones(tabla);
    recorrerCursor(tabla);
    return 0;
}
