//
// Created by hrodic on 14/05/2026.
//

#ifndef CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_CLIENTE_H
#define CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_CLIENTE_H

#include <fstream>
using namespace std;

class Cliente {
    int dni;
    char* nombre;
    char* distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    Cliente(const Cliente&);
    int getDni() const;
    const char* getNombre() const;
    const char* getDistrito() const;
    double getDescuento() const;
    double getTotalPagado() const;
    Cliente& operator=(const Cliente&);
    void setDni(int);
    void setNombre(const char*);
    void setDistrito(const char*);
    void setDescuento(double);
    void incrementarTotal(double);
    ~Cliente();
};

ifstream& operator>>(ifstream&,Cliente&);
ofstream& operator<<(ofstream&,const Cliente&);

#endif //CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_CLIENTE_H
