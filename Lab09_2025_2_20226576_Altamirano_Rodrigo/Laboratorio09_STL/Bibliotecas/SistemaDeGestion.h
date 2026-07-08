//
// Created by hrodic on 26/06/2026.
//

#ifndef LABORATORIO09_STL_SISTEMADEGESTION_H
#define LABORATORIO09_STL_SISTEMADEGESTION_H
#include <list>
#include "Comentario.h"
#include "Categoria.h"
#include <map>
#include <fstream>
#include "Etiqueta.h"
#include "Streamer.h"

class SistemaDeGestion {
    std::list<Categoria> categorias;
    std::list<Comentario> comentarios;
    std::map<std::string,Etiqueta> etiquetas;
    std::list<Streamer> Streamers;
    static void rellenarLinea(char,std::ofstream&);
public:
    void cargarCategorias(const std::string&);
    void cargaComentarios(const std::string&);
    void cargaEtiquetas(const std::string&);
    void cargaStreamers(const std::string&);
    void completarStreamers();
    void reporteDeStreamers(const std::string&) const;
    void eliminaStreamers(const std::string&);
};


#endif //LABORATORIO09_STL_SISTEMADEGESTION_H
