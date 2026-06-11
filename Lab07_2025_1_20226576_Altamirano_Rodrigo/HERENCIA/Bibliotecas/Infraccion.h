//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_INFRACCION_H
#define HERENCIA_INFRACCION_H

#include <fstream>
using namespace std;

class Infraccion {
    int fecha_evento;
    char* tipo_infraccion;
    double monto;
    int fecha_pago_limite;
    char* placa;
public:
    Infraccion();
    Infraccion(const Infraccion&);
    Infraccion& operator=(const Infraccion&);
    void set_tipo_infraccion(const char*);
    void set_placa(const char*);
    int get_fecha_evento() const;
    char* get_tipo_infraccion() const;
    double get_monto() const;
    int get_fecha_pago_limite() const;
    char* get_placa() const;
    void completar_infraccion(char,int,int);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Infraccion();
};

ifstream& operator>>(ifstream&,Infraccion&);
ofstream& operator<<(ofstream&,const Infraccion&);

#endif //HERENCIA_INFRACCION_H
