#include "Funciones.h"
#include "Alumno.h"
#include "AlumnoNota.h"

int main() {
    Alumno arrAlumnos[100]{};
    AlumnoNota arrNotasAlumnos[200];

    CargarAlumnos(arrAlumnos);
    CargarNotas(arrNotasAlumnos);
    ActualizarNotas(arrAlumnos,arrNotasAlumnos);
    ImprimirAlumnos(arrAlumnos);

    return 0;
}
