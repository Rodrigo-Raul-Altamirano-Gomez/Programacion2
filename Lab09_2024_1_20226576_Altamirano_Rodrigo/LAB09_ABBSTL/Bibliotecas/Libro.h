//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_LIBRO_H
#define LAB09_ABBSTL_LIBRO_H
#include <string>
#include <fstream>

class Libro {
    std::string nombre;
    int paginas;
    double peso;
public:
    double getPeso() const;
    virtual Libro* clonar() const = 0;
    virtual void leer(std::ifstream&);
    virtual void imprimir(std::ofstream&) const;
    virtual ~Libro() = default;
};


#endif //LAB09_ABBSTL_LIBRO_H
