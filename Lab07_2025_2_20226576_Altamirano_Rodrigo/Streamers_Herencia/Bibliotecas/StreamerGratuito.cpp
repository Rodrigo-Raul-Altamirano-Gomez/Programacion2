//
// Created by hrodic on 2/06/2026.
//
#include <iomanip>
#include "StreamerGratuito.h"

StreamerGratuito::StreamerGratuito() {
    this->metricas_basicas=nullptr;
    this->cantidad_metricas_basicas=0;
}

StreamerGratuito::StreamerGratuito(const StreamerGratuito &streamer_gratuito) : StreamerGratuito() {
    *this=streamer_gratuito;
}

StreamerGratuito &StreamerGratuito::operator=(const StreamerGratuito &streamer_gratuito) {
    if (this!=&streamer_gratuito) {
        Streamer::operator=(streamer_gratuito);
        this->fecha_fin_trial=streamer_gratuito.fecha_fin_trial;
        this->setMetricasBasicas(streamer_gratuito.metricas_basicas,streamer_gratuito.cantidad_metricas_basicas);
        this->cantidad_metricas_basicas=streamer_gratuito.cantidad_metricas_basicas;
    }
    return *this;
}

void StreamerGratuito::setMetricasBasicas(const MetricaBasica * metricas_basicas,int cantidad_metricas_basicas) {
    delete[] this->metricas_basicas;
    this->metricas_basicas=new MetricaBasica[cantidad_metricas_basicas];
    for (int i=0;i<cantidad_metricas_basicas;i++) this->metricas_basicas[i]=metricas_basicas[i];
}

int StreamerGratuito::get_fecha_fin_trial() const {
    return this->fecha_fin_trial;
}

void StreamerGratuito::leer(ifstream &archStreamers) {
    char car;
    int dia_fin_trial,mes_fin_trial,anio_fin_trial;
    Streamer::leer(archStreamers);
    archStreamers>>anio_fin_trial>>car>>mes_fin_trial>>car>>dia_fin_trial;
    archStreamers.ignore();
    this->fecha_fin_trial=dia_fin_trial+mes_fin_trial*100+anio_fin_trial*10000;
}

void StreamerGratuito::imprimir(ofstream &archReporte) const {
    int activasTotal=0,expiradas_total=0;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(55)<<"REPORTE DE STREAMERS"<<endl<<fixed<<setprecision(2);
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl<<endl;
    Streamer::imprimir(archReporte);
    archReporte<<"TIPO: StreamerGratuito"<<endl;
    this->imprimir_metricas_basicas(archReporte,activasTotal,expiradas_total);
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<"[UPSELL] Funcionalidad Pro. Adquiere la licencia para ver estadisticas avanzadas."<<endl;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<"[TOTAL] METRICAS ACTIVAS: "<<activasTotal<<" | METREICAS EXPIRADAS: "<<expiradas_total;
    archReporte<<" | FECHA DE REPORTE: 2025-11-07"<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
}

void StreamerGratuito::imprimir_metricas_basicas(ofstream &archReporte,int& activas_total,int& expiradas_total) const {
    int viewers_promedio,activas,expiradas;
    double horas_totales;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    this->obtener_metricas_basicas_general(horas_totales,viewers_promedio,activas,expiradas);
    archReporte<<"[BASIC] HORAS_TOT: "<<setw(5)<<horas_totales<<" | VIEWERS_PROM_GLOBAL: ";
    archReporte<<right<<setw(5)<<viewers_promedio<<" | ACTIVAS. "<<activas<<" | EXPIRADAS: "<<expiradas<<endl;
    archReporte<<setw(5)<<" "<<left<<setw(12)<<"ID"<<setw(12)<<"Fecha Calc."<<setw(12)<<"Expira";
    archReporte<<setw(10)<<"Estado"<<setw(7)<<"Horas"<<setw(10)<<"Viewers"<<"Descripcion"<<endl;
    for (int i=0;i<this->cantidad_metricas_basicas;i++) archReporte<<this->metricas_basicas[i];
    activas_total+=activas;
    expiradas_total+=expiradas;
}

void StreamerGratuito::obtener_metricas_basicas_general(double &horas_totales, int &viewers_promedio_global,
    int &activas, int &expiradas) const {
    horas_totales=0,viewers_promedio_global=0,activas=0,expiradas=0;
    for (int i=0;i<this->cantidad_metricas_basicas;i++) {
        horas_totales+=this->metricas_basicas[i].getHorasTrans();
        viewers_promedio_global+=this->metricas_basicas[i].getEspecProm();
        if (this->metricas_basicas[i].getEstado()) activas++;
        else expiradas++;
    }
    if (this->cantidad_metricas_basicas>0) viewers_promedio_global/=this->cantidad_metricas_basicas;
}

void StreamerGratuito::insertarMetricaBasica(const MetricaBasica &metrica_basica) {
    MetricaBasica metricas_basicas_new[this->cantidad_metricas_basicas+1];
    for (int i=0;i<this->cantidad_metricas_basicas;i++) metricas_basicas_new[i]=this->metricas_basicas[i];
    metricas_basicas_new[this->cantidad_metricas_basicas]=metrica_basica;
    this->setMetricasBasicas(metricas_basicas_new,this->cantidad_metricas_basicas+1);
    this->cantidad_metricas_basicas++;
}

ifstream& operator>>(ifstream& archStreamers,StreamerGratuito& streamer_gratuito) {
    streamer_gratuito.leer(archStreamers);
    return archStreamers;
}

ofstream& operator<<(ofstream& archReporte,const StreamerGratuito& streamer_gratuito) {
    streamer_gratuito.imprimir(archReporte);
    return archReporte;
}

StreamerGratuito::~StreamerGratuito() {
    delete[] this->metricas_basicas;
}
