#include <vector>
#include "Bibliotecas/Aula.h"
using namespace std;

int main() {
    vector<Aula> vAula;
    Aula aula;
    ifstream archAulas("ArchivosDeDatos/Aulas.csv",ios::in);
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    while (archAulas>>aula) vAula.push_back(aula);
    for (vector<Aula>::const_iterator iterador=vAula.begin();iterador!=vAula.end();iterador++) {
        archReporte<<*iterador<<endl;
    }
    return 0;
}