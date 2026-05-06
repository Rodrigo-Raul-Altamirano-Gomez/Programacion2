//
// Created by hrodic on 17/04/2026.
//

#ifndef PROYECTO_ESTRUCTURAS_H
#define PROYECTO_ESTRUCTURAS_H

struct Conductores {
    int *dnis;
    char **nombres;
    int cantidad;
};

struct Infracciones {
    int *codigos;
    char **descripciones;
    char **tipos;
    double *valores;
    int cantidad;
};

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;

    char ***placas;
    int *capacidades;
};

#endif //PROYECTO_ESTRUCTURAS_H
