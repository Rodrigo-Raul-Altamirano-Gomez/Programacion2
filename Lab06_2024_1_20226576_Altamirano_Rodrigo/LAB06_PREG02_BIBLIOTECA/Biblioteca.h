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
    Libro libros[20];
    int cantidad_libros;
public:
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
};


#endif //LAB06_PREG01_CLASES_BIBLIOTECA_H
