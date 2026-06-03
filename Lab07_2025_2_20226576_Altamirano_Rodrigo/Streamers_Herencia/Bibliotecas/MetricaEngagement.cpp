//
// Created by hrodic on 1/06/2026.
//
#include <iomanip>
#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement(const MetricaEngagement &metricaEngagement) : MetricaEngagement() {
    *this=metricaEngagement;
}

MetricaEngagement &MetricaEngagement::operator=(const MetricaEngagement &metricaEngagement) {
    if (this!=&metricaEngagement) {
        Metrica::operator=(metricaEngagement);
        this->mensajes_chat=metricaEngagement.mensajes_chat;
        this->usuarios_unicos_chat=metricaEngagement.usuarios_unicos_chat;
        this->clips_generados=metricaEngagement.clips_generados;
    }
    return *this;
}

void MetricaEngagement::setMensajesChat(int mesnajesChat) {
    this->mensajes_chat=mesnajesChat;
}

void MetricaEngagement::setUsuariosUnicos(int usuariosUnicos) {
    this->usuarios_unicos_chat=usuariosUnicos;
}

void MetricaEngagement::setClipsGenerados(int clipsGenerados) {
    this->clips_generados=clipsGenerados;
}

int MetricaEngagement::getMensajesChat() const {
    return this->mensajes_chat;
}

int MetricaEngagement::getUsuariosUnicos() const {
    return this->usuarios_unicos_chat;
}

int MetricaEngagement::getClipsGenerados() const {
    return this->clips_generados;
}

void MetricaEngagement::leer(ifstream &archMetricas) {
    char car;
    Metrica::leer(archMetricas);
    archMetricas>>this->mensajes_chat>>car>>this->usuarios_unicos_chat>>car>>this->clips_generados;
    archMetricas.ignore();
}

void MetricaEngagement::imprimir(ofstream &archReporte) const {
    char* descripcion=this->getDescripcion();
    Metrica::imprimir(archReporte);
    archReporte<<setw(10)<<this->mensajes_chat<<setw(7)<<this->usuarios_unicos_chat;
    archReporte<<setw(7)<<this->clips_generados<<descripcion<<endl;
    delete[] descripcion;
}

ifstream& operator>>(ifstream& archMetricas,MetricaEngagement& metrica_engagement) {
    metrica_engagement.leer(archMetricas);
    return archMetricas;
}

ofstream& operator<<(ofstream& archReporte,const MetricaEngagement& metrica_engagement) {
    metrica_engagement.imprimir(archReporte);
    return archReporte;
}