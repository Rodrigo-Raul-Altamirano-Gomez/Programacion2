#include "Funciones.h"

int main() {
    Alumno* arrAlumnos;
    int cantAlumnos;
    cargarAlumnos(arrAlumnos,cantAlumnos);
    procesarNotas(arrAlumnos,cantAlumnos);
    actualizarAlumnos(arrAlumnos,cantAlumnos);
    emitirReporte(arrAlumnos,cantAlumnos);
    return 0;
}
