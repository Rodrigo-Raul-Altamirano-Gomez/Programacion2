#include "PunterosYPunteroGenericos.h"

int main() {
    void* libros;
    char *tipo,**nombre;
    int* carne;
    cargaDeLibros(libros);
    reporteDeLibros(libros);
    cargaDeUsuarios(carne,tipo,nombre);
    reporteDeUsuarios(carne,tipo,nombre);
    reporteUsuariosInhabilitados(libros,carne,tipo,nombre);
    return 0;
}
