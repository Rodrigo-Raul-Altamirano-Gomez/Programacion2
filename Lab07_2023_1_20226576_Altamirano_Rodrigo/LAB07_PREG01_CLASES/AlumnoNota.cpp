//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxliares.h"
#include "AlumnoNota.h"

#include "Nota.h"

ifstream& operator>>(ifstream& archNotas,AlumnoNota& notaAlumno) {
    char car;
    if (archNotas>>notaAlumno.codigo) {
        archNotas.ignore();
        notaAlumno.codCurso=LeerCadenaExacta(archNotas);
        archNotas>>notaAlumno.ciclo>>car>>notaAlumno.nota;
        return archNotas;
    }
    return archNotas;
}

void AlumnoNota::operator&(Nota& nota) {
    nota.setCodigoCurso(this->codCurso);
    nota.setCiclo(this->ciclo);
    nota.setNota(this->nota);
}
