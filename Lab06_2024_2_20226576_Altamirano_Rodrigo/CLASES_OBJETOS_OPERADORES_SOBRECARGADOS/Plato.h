//
// Created by hrodic on 14/05/2026.
//

#ifndef CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_PLATO_H
#define CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_PLATO_H

#include <fstream>
using namespace std;

class Plato {
    char* codigo;
    char* nombre;
    double precio;
    char* categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;
public:
    Plato();
    Plato(const Plato&);
    const char* getCodigo() const;
    const char* getNombre() const;
    double getPrecio() const;
    const char* getCategoria() const;
    int getPreparados() const;
    double getDescuento() const;
    int getAtendidos() const;
    int getNoAtendidos() const;
    double getTotalEsperado() const;
    double getTotalBruto() const;
    double getTotalNeto() const;
    Plato& operator=(const Plato&);
    void setCodigo(const char*);
    void setNombre(const char*);
    void setPrecio(double);
    void setCategoria(const char*);
    void setPreparados(int);
    void setDescuento(double);
    void incrementarAntendidos(int);
    void setTotalEsperado(double);
    void incrementarTotalBruto(double);
    void incrementarTotalNeto(double);
    void incrementarNoAntendidos(int);
    ~Plato();
};

ifstream& operator>>(ifstream&,Plato&);
ofstream& operator<<(ofstream&,const Plato&);

#endif //CLASES_OBJETOS_OPERADORES_SOBRECARGADOS_PLATO_H
