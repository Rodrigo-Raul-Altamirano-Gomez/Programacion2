//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_LIBRO_H
#define LAB08_POLITAD_LIBRO_H
#include <fstream>
using namespace std;

class Libro {
    char* nombre;
    int paginas;
    double peso;
public:
    Libro();
    void setNombre(const char*);
    double getPeso() const;
    virtual void lee(ifstream&);
    virtual void actualiza() = 0;
    virtual void imprime(ofstream&) const;
    virtual ~Libro();
};


#endif //LAB08_POLITAD_LIBRO_H
