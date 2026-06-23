#include <fstream>
#include "Bibliotecas/Alumno.h"
#include "Bibliotecas/Persona.h"
#include "Bibliotecas/Profesor.h"
using namespace std;

int main() {
    ifstream archMiembros("ArchivosDeDatos/Miembros.csv",ios::in);
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    Persona* persona;
    char tipoPersona,car;
    archMiembros>>tipoPersona>>car;
    if (tipoPersona=='A') persona=new Alumno;
    else persona=new Profesor;
    archMiembros>>persona;
    archReporte<<persona<<endl;
    return 0;
}
