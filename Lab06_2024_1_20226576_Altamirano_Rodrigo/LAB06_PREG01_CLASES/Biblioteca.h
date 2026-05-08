//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_BIBLIOTECA_H
#define LAB06_PREG01_CLASES_BIBLIOTECA_H

#include "Estante.h"
#include "Libro.h"

class Biblioteca {
    Estante estantes[20];
    int cantidad_estantes;
    Libro libros[100];
    int cantidad_libros;
};


#endif //LAB06_PREG01_CLASES_BIBLIOTECA_H
