//
// Created by hrodic on 1/06/2026.
//

#ifndef STREAMERS_HERENCIA_METRICAENGAGEMENT_H
#define STREAMERS_HERENCIA_METRICAENGAGEMENT_H

#include "Metrica.h"

class MetricaEngagement : public Metrica {
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    MetricaEngagement() = default;
    MetricaEngagement(const MetricaEngagement&);
    MetricaEngagement& operator=(const MetricaEngagement&);
    void setMensajesChat(int);
    void setUsuariosUnicos(int);
    void setClipsGenerados(int);
    int getMensajesChat() const;
    int getUsuariosUnicos() const;
    int getClipsGenerados() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~MetricaEngagement() = default;
};

ifstream& operator>>(ifstream&,MetricaEngagement&);
ofstream& operator<<(ofstream&,const MetricaEngagement&);

#endif //STREAMERS_HERENCIA_METRICAENGAGEMENT_H
