#include "Alumnos.h"
#include "AlumnoNota.h"

int main() {
    Alumno alumno;
    AlumnoNota notaAlumno;
    Nota nota;
    ifstream archAlumnos("Alumnos.csv",ios::in);
    ifstream archNotas("Notas.csv",ios::in);
    ofstream archReportePrueba("ReportePrueba.txt",ios::out);
    archAlumnos>>alumno;
    archNotas>>notaAlumno;
    notaAlumno&nota;
    alumno+=nota;
    archReportePrueba<<alumno;
    return 0;
}
