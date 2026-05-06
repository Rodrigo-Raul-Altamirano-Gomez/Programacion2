//
// Created by hrodic on 23/04/2026.
//

#ifndef PUNTEROSGENERICOS_TABLA_H
#define PUNTEROSGENERICOS_TABLA_H

struct Tabla {
    void* columnas;
    void* filas;
    int cantidad_columnas;
    int cantidad_filas;
    int capacidad_columnas;
    int capacidad_filas;
};

#endif //PUNTEROSGENERICOS_TABLA_H
