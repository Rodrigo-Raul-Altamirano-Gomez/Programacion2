//
// Created by hrodic on 26/06/2026.
//

#ifndef LABORATORIO09_STL_COMENTARIO_H
#define LABORATORIO09_STL_COMENTARIO_H
#include <string>
#include <fstream>

class Comentario {
    std::string canal;
    std::string comentario;
public:
    Comentario() = default;
    Comentario(const Comentario&) = default;
    Comentario& operator=(const Comentario&) = default;
    std::string getCanal() const;
    std::string getComentario() const;
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    bool operator<(const Comentario&) const;
    ~Comentario() = default;
};

std::ifstream& operator>>(std::ifstream&,Comentario&);
std::ofstream& operator<<(std::ofstream&,const Comentario&);


#endif //LABORATORIO09_STL_COMENTARIO_H
