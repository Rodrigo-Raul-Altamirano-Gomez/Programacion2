//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA04_RESERVA_H
#define PREGUNTA04_RESERVA_H
#include <vector>

#include "Alumno.h"
#include "Aula.h"
#include "PlCola.h"
#include "Profesor.h"


class Reserva {
    std::vector<Aula> vAula;
    PlCola<Persona*> alumnos;
    PlCola<Persona*> profesores;
public:
    void carga(std::string,std::string);
    void asigna(int);
    void imprime(std::string) const;
};


#endif //PREGUNTA04_RESERVA_H
