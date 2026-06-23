//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA01_ALUMNO_H
#define PREGUNTA01_ALUMNO_H
#include "Persona.h"


class Alumno : public Persona {
    int escala;
    std::string especialidad;
    std::string facultad;
protected:
    void leer(std::ifstream &) override;
    void imprimir(std::ofstream &) const override;
public:
    Alumno();
    Alumno(const Alumno&) = default;
    Alumno& operator=(const Alumno&) = default;
    int getEscala() const;
    std::string getEspecialidad() const;
    std::string getFacultad() const;
    ~Alumno() override = default;
};


#endif //PREGUNTA01_ALUMNO_H
