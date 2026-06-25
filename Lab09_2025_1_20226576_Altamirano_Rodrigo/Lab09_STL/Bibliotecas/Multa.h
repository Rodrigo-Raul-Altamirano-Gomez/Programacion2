//
// Created by hrodic on 25/06/2026.
//

#ifndef LAB09_STL_MULTA_H
#define LAB09_STL_MULTA_H
#include <string>
#include <fstream>

class Multa {
    int fecha;
    std::string placa;
    std::string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
public:
    Multa() = default;
    Multa(const Multa&) = default;
    void setMulta(double);
    int getFecha() const;
    std::string getPlaca() const;
    std::string getCodMulta() const;
    double getMulta() const;
    bool getPagada() const;
    int getFechaDePago() const;
    Multa& operator= (const Multa&) = default;
    bool leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    static void imprimirFecha(std::ofstream&,int);
    ~Multa() = default;
};

std::ifstream& operator>> (std::ifstream&, Multa&);
std::ofstream& operator<< (std::ofstream&, const Multa&);

#endif //LAB09_STL_MULTA_H
