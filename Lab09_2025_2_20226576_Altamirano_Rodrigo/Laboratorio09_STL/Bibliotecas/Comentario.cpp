#include <iomanip>
//
// Created by hrodic on 26/06/2026.
//
using namespace std;
#include "Comentario.h"

std::string Comentario::getCanal() const {
    return this->canal;
}

std::string Comentario::getComentario() const {
    return this->comentario;
}

void Comentario::leer(std::ifstream& input) {
    std::string canal;
    getline(input,canal,',');
    if (input) {
        this->canal=canal;
        getline(input,this->comentario);
    }
}

void Comentario::imprimir(std::ofstream& output) const {
    output<<left<<setw(15)<<this->canal<<this->comentario<<endl;
}

bool Comentario::operator<(const Comentario &comentario) const {
    return this->canal<comentario.canal;
}

std::ifstream& operator>>(std::ifstream& input,Comentario& comentario) {
    comentario.leer(input);
    return input;
}

std::ofstream& operator<<(std::ofstream& output,const Comentario& comentario) {
    comentario.imprimir(output);
    return output;
}