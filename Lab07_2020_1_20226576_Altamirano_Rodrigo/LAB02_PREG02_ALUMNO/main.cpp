#include "Alumno.h"

int main() {
    ifstream archAlumnos("Alumnos.txt",ios::in);
    ifstream archCursos("Cursos.txt",ios::in);
    ofstream archReportePrueba("ReportePrueba.txt",ios::out);
    Alumno alumno;
    Acurso cursoAlumno;
    archAlumnos>>alumno;
    return 0;
}
