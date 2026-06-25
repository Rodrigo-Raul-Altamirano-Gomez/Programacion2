//
// Created by hrodic on 23/06/2026.
//
#include <fstream>
#include <iomanip>
using namespace std;
#include "AnalisisSentimiento.h"

void AnalisisSentimiento::cargar_lexicon() {
    ifstream archLexicon("ArchivosDeDatos/lexicon.csv",ios::in);
    std::string texto;
    int polaridad;
    while (true) {
        getline(archLexicon,texto,',');
        if (archLexicon.eof()) break;
        archLexicon>>polaridad;
        archLexicon.ignore();
        this->lexicon[texto]=polaridad;
    }
}

void AnalisisSentimiento::cargar_comentarios_restaurantes() {
    ifstream archComentarios("ArchivosDeDatos/comentarios.csv",ios::in);
    while (true) {
        std::string restaurante,comentario,comentario_procesado;
        getline(archComentarios,restaurante,',');
        if (archComentarios.eof()) break;
        Oracion oracion;
        getline(archComentarios,comentario);
        comentario_procesado=this->procesar_oracion(comentario);
        oracion.tokenizar(comentario_procesado,this->lexicon);
        this->comentarios[restaurante].push_back(oracion);
    }
}

std::string AnalisisSentimiento::procesar_oracion(const std::string &comentario) const {
    std::string comentario_procesado;
    char carActual,carAnterior='.';
    for (auto iterador=comentario.begin();iterador!=comentario.end();iterador++) {
        carActual=*iterador;
        if (isalpha(carActual) or (carActual==' ' and carAnterior!=' ')) {
            if (isalpha(carActual) and isupper(carActual)) carActual=tolower(carActual);
            comentario_procesado.push_back(carActual);
        }
        carAnterior=carActual;
    }
    return comentario_procesado;
}

void AnalisisSentimiento::imprimir_analisis() const {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    for (auto iterador=this->comentarios.begin();iterador!=this->comentarios.end();iterador++) {
        int cantidadPositivos=0,cantidadNegativos=0,cantidadNeutros=0;
        this->contarPalabras((*iterador).second,cantidadPositivos,cantidadNegativos,cantidadNeutros);
        archReporte<<"Restaurante: "<<(*iterador).first<<endl;
        archReporte<<"Cantidad Positivos: "<<cantidadPositivos<<endl;
        archReporte<<"Cantidad Negativos: "<<cantidadNegativos<<endl;
        archReporte<<"Cantidad Neutros: "<<cantidadNeutros<<endl;
        archReporte<<setfill('-')<<setw(30)<<" "<<setfill(' ')<<endl;
    }
}

void AnalisisSentimiento::contarPalabras(const vector<Oracion>& oraciones,int &cantidadPositivos, int &cantidadNegativos,
    int &cantidadNeutros) const {
    for (auto iterador=oraciones.begin();iterador!=oraciones.end();iterador++) {
        int polaridadTotal=(*iterador).getPolardadTotal();
        if (polaridadTotal>0) cantidadPositivos++;
        else if (polaridadTotal<0) cantidadNegativos++;
        else cantidadNeutros++;
    }
}
