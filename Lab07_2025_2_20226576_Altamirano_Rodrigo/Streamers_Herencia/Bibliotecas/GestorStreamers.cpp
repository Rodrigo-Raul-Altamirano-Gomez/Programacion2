//
// Created by hrodic on 2/06/2026.
//
#include <cstring>
#include "GestorStreamers.h"

GestorStreamers::GestorStreamers() {
    this->streamers_gratuitos=nullptr;
    this->streamers_pagados=nullptr;
    this->cantidad_gratuitos=0;
    this->cantidad_pagados=0;
}

void GestorStreamers::setStreamersGratuitos(StreamerGratuito* streamersGratuitos,int cantidad_gratuitos) {
    delete[] this->streamers_gratuitos;
    this->streamers_gratuitos=new StreamerGratuito[cantidad_gratuitos];
    for (int i=0;i<cantidad_gratuitos;i++) this->streamers_gratuitos[i]=streamersGratuitos[i];
}

void GestorStreamers::setStreamersPagados(StreamerPago* streamersPagados,int cantidad_pagados) {
    delete[] this->streamers_pagados;
    this->streamers_pagados=new StreamerPago[cantidad_pagados];
    for (int i=0;i<cantidad_pagados;i++) this->streamers_pagados[i]=streamersPagados[i];
}

void GestorStreamers::setCantidadGratuitos(int cantidadGratuitos) {
    this->cantidad_gratuitos=cantidadGratuitos;
}

void GestorStreamers::setCantidadPagados(int cantidadPagados) {
    this->cantidad_pagados=cantidadPagados;
}

StreamerGratuito* GestorStreamers::getStreamersGratuitos() const {
    StreamerGratuito* streamersGratuitosCopia;
    streamersGratuitosCopia=new StreamerGratuito[this->cantidad_gratuitos];
    for (int i=0;i<this->cantidad_gratuitos;i++) streamersGratuitosCopia[i]=this->streamers_gratuitos[i];
    return streamersGratuitosCopia;
}

StreamerPago *GestorStreamers::getStreamersPagados() const {
    StreamerPago* streamers_pagados_copia;
    streamers_pagados_copia=new StreamerPago[this->cantidad_pagados];
    for (int i=0;i<this->cantidad_pagados;i++) streamers_pagados_copia[i]=this->streamers_pagados[i];
    return streamers_pagados_copia;
}

int GestorStreamers::getCantidadGratuitos() const {
    return this->cantidad_gratuitos;
}

int GestorStreamers::getCantidadPagados() const {
    return this->cantidad_pagados;
}

void GestorStreamers::cargar_datos_streamers(const char *nombreArchStreamers) {
    ifstream archStreamers(nombreArchStreamers,ios::in);
    char tipoStreamer[20];
    StreamerGratuito streamers_gratuitos[100];
    StreamerPago streamers_pagados[100];
    int cantidad_streamers_gratuitos=0,cantidad_streamers_pagados=0;
    while (true) {
        archStreamers.getline(tipoStreamer,20,',');
        if (archStreamers.eof()) break;
        if (strcmp(tipoStreamer,"Gratuito")==0) {
            archStreamers>>streamers_gratuitos[cantidad_streamers_gratuitos];
            cantidad_streamers_gratuitos++;
        } else {
            archStreamers>>streamers_pagados[cantidad_streamers_pagados];
            cantidad_streamers_pagados++;
        }
    }
    this->setStreamersGratuitos(streamers_gratuitos,cantidad_streamers_gratuitos);
    this->setStreamersPagados(streamers_pagados,cantidad_streamers_pagados);
    this->cantidad_gratuitos=cantidad_streamers_gratuitos;
    this->cantidad_pagados=cantidad_streamers_pagados;
}

void GestorStreamers::actualizar_datos_metricas(const char *nombreArchMetricas) {
    ifstream archMetricas(nombreArchMetricas,ios::in);
    char tipoMetrica[30],car,tipoStreamer;
    int id_streamer,posStreamer;
    MetricaBasica metrica_basica;
    MetricaEngagement metrica_engagement;
    MetricaCalidad metrica_calidad;
    while (true) {
        archMetricas.getline(tipoMetrica,30,',');
        if (archMetricas.eof()) break;
        archMetricas>>id_streamer>>car;
        this->buscarStreamer(id_streamer,posStreamer,tipoStreamer);
        if (posStreamer>=0) {
            if (strcmp(tipoMetrica,"BASIC")==0) {
                archMetricas>>metrica_basica;
                if (tipoStreamer=='G') this->streamers_gratuitos[posStreamer].insertarMetricaBasica(metrica_basica);
                else this->streamers_pagados[posStreamer].insertarMetricaBasica(metrica_basica);
            } else if (strcmp(tipoMetrica,"ENGAGEMENT")==0) {
                archMetricas>>metrica_engagement;
                this->streamers_pagados[posStreamer].insertar_metrica_engagement(metrica_engagement);
            } else {
                archMetricas>>metrica_calidad;
                this->streamers_pagados[posStreamer].insertar_metrica_calidad(metrica_calidad);
            }
        } else archMetricas.ignore(200,'\n');
    }
}

void GestorStreamers::buscarStreamer(int id_streamer, int &posStreamer, char &tipoStreamer) {
    for (int i=0;i<this->cantidad_gratuitos or i<this->cantidad_pagados;i++) {
        if (i<this->cantidad_pagados and this->streamers_pagados[i].getID()==id_streamer) {
            posStreamer=i;
            tipoStreamer='P';
            return;
        }
        if (i<this->cantidad_gratuitos and this->streamers_gratuitos[i].getID()==id_streamer) {
            posStreamer=i;
            tipoStreamer='G';
            return;
        }
    }
    posStreamer=-1;
}

void GestorStreamers::generar_reporte() {
    char *cuentaStreamer,*categoria_streamer;
    for (int i=0;i<this->cantidad_gratuitos or i<this->cantidad_pagados;i++) {
        char nombreArchGratuitos[200]="ArchivosDeReporte/Gratuito/",nombreArchPagados[200]="ArchivosDeReporte/Pagado/";
        if (i<this->cantidad_gratuitos) {
            cuentaStreamer=this->streamers_gratuitos[i].getCuenta();
            categoria_streamer=this->streamers_gratuitos[i].getCategoria();
            strcat(nombreArchGratuitos,cuentaStreamer), strcat(nombreArchGratuitos,"_");
            strcat(nombreArchGratuitos,categoria_streamer), strcat(nombreArchGratuitos,"_");
            strcat(nombreArchGratuitos,to_string(this->streamers_gratuitos[i].get_fecha_fin_trial()).c_str());
            strcat(nombreArchGratuitos,".txt");
            ofstream archReporteStreamerGratuito(nombreArchGratuitos,ios::out);
            archReporteStreamerGratuito<<this->streamers_gratuitos[i];
            delete[] cuentaStreamer, delete[] categoria_streamer;
        }
        if (i<this->cantidad_pagados) {
            cuentaStreamer=this->streamers_pagados[i].getCuenta();
            categoria_streamer=this->streamers_pagados[i].getCategoria();
            strcat(nombreArchPagados,cuentaStreamer), strcat(nombreArchPagados,"_");
            strcat(nombreArchPagados,categoria_streamer), strcat(nombreArchPagados,"_");
            strcat(nombreArchPagados,to_string(this->streamers_pagados[i].get_fecha_inicio_plan()).c_str());
            strcat(nombreArchPagados,".txt");
            ofstream archReporteStreamerPagado(nombreArchPagados,ios::out);
            archReporteStreamerPagado<<this->streamers_pagados[i];
            delete[] cuentaStreamer, delete[] categoria_streamer;
        }
    }
}