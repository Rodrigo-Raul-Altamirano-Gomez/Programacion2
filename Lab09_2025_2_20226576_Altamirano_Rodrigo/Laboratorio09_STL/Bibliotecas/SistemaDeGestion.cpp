//
// Created by hrodic on 26/06/2026.
//
using namespace std;
#include <algorithm>
#include <iomanip>
#include "SistemaDeGestion.h"

void SistemaDeGestion::cargarCategorias(const std::string &nombreArchivoCategorias) {
    ifstream archCategorias(nombreArchivoCategorias,ios::in);
    Categoria categoria;
    while (archCategorias>>categoria) {
        this->categorias.push_back(categoria);
    }
    this->categorias.sort();
}

void SistemaDeGestion::cargaComentarios(const std::string &nombreArchivoCometarios) {
    ifstream archCometarios(nombreArchivoCometarios,ios::in);
    Comentario comentario;
    while (archCometarios>>comentario) {
        this->comentarios.push_back(comentario);
    }
    this->comentarios.sort();
}

void SistemaDeGestion::cargaEtiquetas(const std::string &nombreArchivoEtiquetas) {
    ifstream archEtiquetas(nombreArchivoEtiquetas,ios::in);
    Etiqueta etiqueta;
    while (archEtiquetas>>etiqueta) {
        this->etiquetas[etiqueta.getCodigo()]=etiqueta;
    }
}

void SistemaDeGestion::cargaStreamers(const std::string &nombreArchivoStreamers) {
    ifstream archStreamers(nombreArchivoStreamers,ios::in);
    Streamer streamer;
    while (archStreamers>>streamer) {
        this->Streamers.push_back(streamer);
    }
    this->Streamers.sort();
}

void SistemaDeGestion::completarStreamers() {
    for (auto streamer=this->Streamers.begin();streamer!=this->Streamers.end();streamer++) {
        auto categoria=find(this->categorias.begin(),this->categorias.end(),(*streamer).getCategoria());
        if (categoria!=this->categorias.end()) (*streamer).setCategoria((*categoria));
        (*streamer).completarComentarios(this->comentarios);
        (*streamer).completarEtiquetas(this->etiquetas);
    }
}

void SistemaDeGestion::reporteDeStreamers(const std::string &nombreArchivoReporte) const {
    ofstream archReporte(nombreArchivoReporte,ios::out);
    SistemaDeGestion::rellenarLinea('=',archReporte);
    archReporte<<setw(45)<<"RELACION DE STREAMERS"<<endl;
    for (auto streamer=this->Streamers.begin();streamer!=this->Streamers.end();streamer++) {
        SistemaDeGestion::rellenarLinea('-',archReporte);
        archReporte<<(*streamer);
    }
    SistemaDeGestion::rellenarLinea('=',archReporte);
}

void SistemaDeGestion::rellenarLinea(char carRelleno, std::ofstream &output) {
    output<<setfill(carRelleno)<<setw(100)<<carRelleno<<setfill(' ')<<endl;
}

void SistemaDeGestion::eliminaStreamers(const std::string &idioma) {
    auto streamer=this->Streamers.begin();
    while (streamer!=this->Streamers.end()) {
        if ((*streamer).getIdioma()==idioma) streamer=this->Streamers.erase(streamer);
        else streamer++;
    }
}
