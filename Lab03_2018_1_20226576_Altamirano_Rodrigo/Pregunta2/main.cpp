#include <iostream>
#include "Bib_Func_Preg1.h"
#include "Bib_Func_Preg2.h"

int main() {
    void* usuarios;
    leerUsuario(usuarios);
    imprimirUsuarios(usuarios);
    leerPrestamos(usuarios);
    imprimirPrestamos(usuarios);
    return 0;
}
