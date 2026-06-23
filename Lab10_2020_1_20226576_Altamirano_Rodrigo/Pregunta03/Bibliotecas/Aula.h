//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA03_AULA_H
#define PREGUNTA03_AULA_H
#include <string>
#include <fstream>

class Aula {
    std::string clave;
    int capacidad;
    int codigo;
    std::string nombre;
    char tipo;
protected:
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    friend std::ifstream& operator>>(std::ifstream&,Aula&);
    friend std::ofstream& operator<<(std::ofstream&,const Aula&);
public:
    Aula();
};


#endif //PREGUNTA03_AULA_H
