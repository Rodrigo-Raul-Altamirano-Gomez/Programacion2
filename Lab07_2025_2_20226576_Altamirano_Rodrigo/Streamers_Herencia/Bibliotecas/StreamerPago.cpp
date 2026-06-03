//
// Created by hrodic on 2/06/2026.
//
#include <iomanip>
#include "StreamerPago.h"

StreamerPago::StreamerPago() {
    this->metricas_basicas=nullptr;
    this->cantidad_metricas_basicas=0;
    this->metricas_engagements=nullptr;
    this->cantidad_metricas_engagement=0;
    this->metricas_calidades=nullptr;
    this->cantidad_metricas_calidades=0;
}

StreamerPago::StreamerPago(const StreamerPago &streamer_pago) : StreamerPago() {
    *this=streamer_pago;
}

StreamerPago &StreamerPago::operator=(const StreamerPago &streamer_pago) {
    if (this!=&streamer_pago) {
        Streamer::operator=(streamer_pago);
        this->fecha_inicio_plan=streamer_pago.fecha_inicio_plan;
        this->setMetricasBasicas(streamer_pago.metricas_basicas,streamer_pago.cantidad_metricas_basicas);
        this->cantidad_metricas_basicas=streamer_pago.cantidad_metricas_basicas;
        this->setMetricasEngagement(streamer_pago.metricas_engagements,streamer_pago.cantidad_metricas_engagement);
        this->cantidad_metricas_engagement=streamer_pago.cantidad_metricas_engagement;
        this->setMetricasCalidad(streamer_pago.metricas_calidades,streamer_pago.cantidad_metricas_calidades);
        this->cantidad_metricas_calidades=streamer_pago.cantidad_metricas_calidades;
    }
    return *this;
}

void StreamerPago::setMetricasBasicas(const MetricaBasica * metricas_basicas,int cantidad_metricas_basicas) {
    delete[] this->metricas_basicas;
    this->metricas_basicas=new MetricaBasica[cantidad_metricas_basicas];
    for (int i=0;i<cantidad_metricas_basicas;i++) this->metricas_basicas[i]=metricas_basicas[i];
}

void StreamerPago::setMetricasEngagement(const MetricaEngagement *metricas_engagement, int cantidad_metricas_engagement) {
    delete[] this->metricas_engagements;
    this->metricas_engagements=new MetricaEngagement[cantidad_metricas_engagement];
    for (int i=0;i<cantidad_metricas_engagement;i++) this->metricas_engagements[i]=metricas_engagement[i];
}

void StreamerPago::setMetricasCalidad(const MetricaCalidad *metricas_calidad, int cantidad_metricas_calidad) {
    delete[] this->metricas_calidades;
    this->metricas_calidades=new MetricaCalidad[cantidad_metricas_calidad];
    for (int i=0;i<cantidad_metricas_calidad;i++) this->metricas_calidades[i]=metricas_calidad[i];
}

int StreamerPago::get_fecha_inicio_plan() const {
    return this->fecha_inicio_plan;
}

void StreamerPago::leer(ifstream &archStreamers) {
    char car;
    int dia_inicio_plan,mes_inicio_plan,anio_inicio_plan;
    Streamer::leer(archStreamers);
    archStreamers>>anio_inicio_plan>>car>>mes_inicio_plan>>car>>dia_inicio_plan;
    archStreamers.ignore();
    this->fecha_inicio_plan=dia_inicio_plan+mes_inicio_plan*100+anio_inicio_plan*10000;
}

void StreamerPago::imprimir(ofstream &archReporte) const {
    int activas_total=0,expiradas_total=0;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(55)<<"REPORTE DE STREAMERS"<<endl<<fixed<<setprecision(2);
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl<<endl;
    Streamer::imprimir(archReporte);
    archReporte<<"TIPO: StreamerPago"<<endl;
    this->imprimir_metricas_basicas(archReporte,activas_total,expiradas_total);
    this->imprimir_metricas_engagement(archReporte,activas_total,expiradas_total);
    this->imprimir_metricas_calidad(archReporte,activas_total,expiradas_total);
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<"[TOTAL] METRICAS ACTIVAS: "<<activas_total<<" | METREICAS EXPIRADAS: "<<expiradas_total;
    archReporte<<" | FECHA DE REPORTE: 2025-11-07"<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
}

void StreamerPago::imprimir_metricas_basicas(ofstream &archReporte,int& activas_total,int& expiradas_total) const {
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

void StreamerPago::obtener_metricas_basicas_general(double &horas_totales, int &viewers_promedio_global,
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

void StreamerPago::imprimir_metricas_engagement(ofstream &archReporte,int& activas_total,int& expiradas_total) const {
    int chat_msgs,activas,expiradas,chatters_unicos,clips;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    this->obtener_metricas_engagement_general(chat_msgs,chatters_unicos,clips,activas,expiradas);
    archReporte<<"[ENGAGE] CHAT_MSGS: "<<setw(5)<<chat_msgs<<" | CHATTERS_UNICOS: ";
    archReporte<<right<<setw(5)<<chatters_unicos<<" | CLIPS: "<<setw(4)<<clips<<" | ACTIVAS. "<<activas;
    archReporte<<" | EXPIRADAS: "<<expiradas<<endl;
    archReporte<<setw(5)<<" "<<left<<setw(12)<<"ID"<<setw(12)<<"Fecha Calc."<<setw(12)<<"Expira";
    archReporte<<setw(10)<<"Estado"<<setw(7)<<"Msgs"<<setw(10)<<"Chatters"<<setw(7)<<"Clips"<<"Descripcion";
    archReporte<<endl;
    for (int i=0;i<this->cantidad_metricas_engagement;i++) archReporte<<this->metricas_engagements[i];
    activas_total+=activas;
    expiradas_total+=expiradas;
}

void StreamerPago::obtener_metricas_engagement_general(int &chat_msgs, int &chatters_unicos, int &clips, int &activas,
    int &expiradas) const {
    chat_msgs=0,chatters_unicos=0,clips=0,activas=0,expiradas=0;
    for (int i=0;i<this->cantidad_metricas_engagement;i++) {
        chat_msgs+=this->metricas_engagements[i].getMensajesChat();
        chatters_unicos+=this->metricas_engagements[i].getUsuariosUnicos();
        clips+=this->metricas_engagements[i].getClipsGenerados();
        if (this->metricas_engagements[i].getEstado()) activas++;
        else expiradas++;
    }
}

void StreamerPago::imprimir_metricas_calidad(ofstream &archReporte,int& activas_total,int& expiradas_total) const {
    int bitrate_prom,activas,expiradas,fps_prom;
    double drop_prom;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    this->obtener_metricas_calidad_general(bitrate_prom,drop_prom,fps_prom,activas,expiradas);
    archReporte<<"[QUALITY] BITRATE_PROM: "<<setw(5)<<bitrate_prom<<" kbps | DROP%_PROM: ";
    archReporte<<right<<setw(5)<<drop_prom<<" | FPS_PROM: "<<setw(4)<<fps_prom<<" | ACTIVAS. "<<activas;
    archReporte<<" | EXPIRADAS: "<<expiradas<<endl;
    archReporte<<setw(5)<<" "<<left<<setw(12)<<"ID"<<setw(12)<<"Fecha Calc."<<setw(12)<<"Expira";
    archReporte<<setw(10)<<"Estado"<<setw(10)<<"Bitrate"<<setw(7)<<"Drop%"<<setw(7)<<"FPS"<<"Descripcion";
    archReporte<<endl;
    for (int i=0;i<this->cantidad_metricas_calidades;i++) archReporte<<this->metricas_calidades[i];
    activas_total+=activas;
    expiradas_total+=expiradas;
}

void StreamerPago::obtener_metricas_calidad_general(int &bitrate_prom, double &drop_prom, int &fps_prom, int &activas,
    int &expiradas) const {
    bitrate_prom=0,drop_prom=0,fps_prom=0,activas=0,expiradas=0;
    for (int i=0;i<this->cantidad_metricas_calidades;i++) {
        bitrate_prom+=this->metricas_calidades[i].getBitratePromedio();
        drop_prom+=this->metricas_calidades[i].getPorcentajePerdidaFrames();
        fps_prom+=this->metricas_calidades[i].getFpsPormedio();
        if (this->metricas_engagements[i].getEstado()) activas++;
        else expiradas++;
    }
    if (bitrate_prom>0) bitrate_prom/=this->cantidad_metricas_calidades;
    if (drop_prom>0) drop_prom/=this->cantidad_metricas_calidades;
    if (fps_prom>0) fps_prom/=this->cantidad_metricas_calidades;
}

void StreamerPago::insertarMetricaBasica(const MetricaBasica &metrica_basica) {
    MetricaBasica metricas_basicas_new[this->cantidad_metricas_basicas+1];
    for (int i=0;i<this->cantidad_metricas_basicas;i++) metricas_basicas_new[i]=this->metricas_basicas[i];
    metricas_basicas_new[this->cantidad_metricas_basicas]=metrica_basica;
    this->setMetricasBasicas(metricas_basicas_new,this->cantidad_metricas_basicas+1);
    this->cantidad_metricas_basicas++;
}

void StreamerPago::insertar_metrica_engagement(const MetricaEngagement &metrica_engagement) {
    MetricaEngagement metricas_engagement_new[this->cantidad_metricas_engagement+1];
    for (int i=0;i<this->cantidad_metricas_engagement;i++) metricas_engagement_new[i]=this->metricas_engagements[i];
    metricas_engagement_new[this->cantidad_metricas_engagement]=metrica_engagement;
    this->setMetricasEngagement(metricas_engagement_new,this->cantidad_metricas_engagement+1);
    this->cantidad_metricas_engagement++;
}

void StreamerPago::insertar_metrica_calidad(const MetricaCalidad &metrica_calidad) {
    MetricaCalidad metricas_calidad_new[this->cantidad_metricas_calidades+1];
    for (int i=0;i<this->cantidad_metricas_calidades;i++) metricas_calidad_new[i]=this->metricas_calidades[i];
    metricas_calidad_new[this->cantidad_metricas_calidades]=metrica_calidad;
    this->setMetricasCalidad(metricas_calidad_new,this->cantidad_metricas_calidades+1);
    this->cantidad_metricas_calidades++;
}

ifstream& operator>>(ifstream& archStreamers,StreamerPago& streamer_pago) {
    streamer_pago.leer(archStreamers);
    return archStreamers;
}

ofstream& operator<<(ofstream& archReporte,const StreamerPago& streamer_pago) {
    streamer_pago.imprimir(archReporte);
    return archReporte;
}

StreamerPago::~StreamerPago() {
    delete[] this->metricas_basicas;
    delete[] this->metricas_basicas;
    delete[] this->metricas_basicas;
}