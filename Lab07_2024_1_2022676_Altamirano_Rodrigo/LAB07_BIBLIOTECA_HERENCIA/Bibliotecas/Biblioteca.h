//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_H
#define LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_H

#include "EstanteVertical.h"
#include "EstanteHorizontal.h"

class Biblioteca {
    EstanteVertical estantesVerticales[5];
    int cantidad_estantes_verticales;
    EstanteHorizontal estantesHorizontales[5];
    int cantidad_estantes_horizontales;
    Enciclopedia enciclopedias[20];
    int cantidad_total_enciclopedias;
    Novela novelas[20];
    int cantidad_total_novelas;
    void posicionarEnciclopedias();
    void posicionarNovelas();
    void rellenarLinea(char,ofstream&) const;
    void imprimirEstantes(ofstream&) const;
    void imprimirLibros(ofstream&) const;
public:
    Biblioteca();
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos() const;
};


#endif //LAB07_BIBLIOTECA_HERENCIA_BIBLIOTECA_H
