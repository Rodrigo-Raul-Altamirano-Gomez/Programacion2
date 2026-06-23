//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA01_PROFESOR_H
#define PREGUNTA01_PROFESOR_H
#include "Persona.h"


class Profesor : public Persona {
    std::string categoria;
    std::string dedicacion;
    std::string seccion;
    std::string grado;
protected:
    void leer(std::ifstream &) override;
    void imprimir(std::ofstream &) const override;
public:
    Profesor() = default;
    Profesor(const Profesor&) = default;
    Profesor& operator=(const Profesor&) = default;
    std::string getCategoria() const;
    std::string getDedicacion() const;
    std::string getSeccion() const;
    std::string getGrado() const;
    ~Profesor() override = default;
};


#endif //PREGUNTA01_PROFESOR_H
