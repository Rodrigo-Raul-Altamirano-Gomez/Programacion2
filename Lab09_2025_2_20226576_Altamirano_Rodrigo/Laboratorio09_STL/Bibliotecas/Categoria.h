//
// Created by hrodic on 26/06/2026.
//

#ifndef LABORATORIO09_STL_CATEGORIA_H
#define LABORATORIO09_STL_CATEGORIA_H
#include <string>
#include <fstream>

class Categoria {
    std::string codigo;
    std::string nombre;
    std::string descripcion;
public:
    Categoria()= default;
    Categoria(const Categoria&) = default;
    Categoria& operator=(const Categoria&) = default;
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    void setCodigo(const std::string&);
    bool operator<(const Categoria&) const;
    bool operator==(const Categoria&) const;
    ~Categoria() = default;
};

std::ifstream& operator>>(std::ifstream&,Categoria&);
std::ofstream& operator<<(std::ofstream&,const Categoria&);


#endif //LABORATORIO09_STL_CATEGORIA_H
