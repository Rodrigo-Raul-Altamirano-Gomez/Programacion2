//
// Created by hrodic on 3/06/2026.
//

#ifndef HERENCIA_MINISTERIODETRANSPORTES_H
#define HERENCIA_MINISTERIODETRANSPORTES_H

#include "CentralDeMonitoreo.h"

class MinisterioDeTransportes {
    CentralDeMonitoreo centros[10];
    char* zonas[10];
    int cantidad_centros;
public:
    MinisterioDeTransportes();
    void apertura_archivo_leer(ifstream&,const char*);
    void apertura_archivo_imprimir(ofstream&,const char*);
    int obtener_ruta(const char*,const char*,const char*,char*) const;
    void cargar_drones(const char*);
    void procesar_todos_los_eventos(const char*);
    void imprimir(const char*);
    ~MinisterioDeTransportes();
};


#endif //HERENCIA_MINISTERIODETRANSPORTES_H
