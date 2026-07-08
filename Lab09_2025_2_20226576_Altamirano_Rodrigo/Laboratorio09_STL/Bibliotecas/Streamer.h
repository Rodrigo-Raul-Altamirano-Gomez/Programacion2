//
// Created by hrodic on 26/06/2026.
//

#ifndef LABORATORIO09_STL_STREAMER_H
#define LABORATORIO09_STL_STREAMER_H
#include <string>
#include <vector>
#include "Categoria.h"
#include "Etiqueta.h"
#include <fstream>
#include <list>
#include <map>
#include "Comentario.h"

class Streamer {
    std::string canal;
    int fecha;
    Categoria categoria;
    std::string etiquetasStr;
    std::vector<Etiqueta> etiquetasVector;
    std::string idioma;
    std::vector<std::string> comentarios;
    void imprimirFecha(std::ofstream&) const;
public:
    Streamer() = default;
    std::string getCanal() const;
    int getFecha() const;
    Categoria getCategoria() const;
    std::string getEtiquetasStr() const;
    std::string getIdioma() const;
    void leer(std::ifstream&);
    void imprimir(std::ofstream&) const;
    bool operator<(const Streamer&) const;
    void setCategoria(const Categoria&);
    void completarComentarios(const std::list<Comentario>&);
    void completarEtiquetas(const std::map<std::string,Etiqueta>&);
    ~Streamer() = default;
};

std::ifstream& operator>>(std::ifstream&,Streamer&);
std::ofstream& operator<<(std::ofstream&,const Streamer&);


#endif //LABORATORIO09_STL_STREAMER_H
