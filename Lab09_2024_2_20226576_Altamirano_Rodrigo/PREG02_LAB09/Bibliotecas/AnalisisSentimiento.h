//
// Created by hrodic on 23/06/2026.
//

#ifndef PREG01_LAB09_ANALISISSENTIMIENTO_H
#define PREG01_LAB09_ANALISISSENTIMIENTO_H
#include <map>
#include <string>
#include <vector>
#include "Oracion.h"

class AnalisisSentimiento {
    std::map<std::string,std::vector<Oracion>> comentarios;
    std::map<std::string,int> lexicon;
public:
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void imprimir_analisis() const;
    std::string procesar_oracion(const std::string&) const;
    void contarPalabras(const std::vector<Oracion>&,int&,int&,int&) const;
    void ordenar_comentarios();
    void imprimirOraciones(std::ofstream&,const std::vector<Oracion>&) const;
};


#endif //PREG01_LAB09_ANALISISSENTIMIENTO_H
