#include <iomanip>

#include "Enciclopedia.h"
#include "Novela.h"
#include "Revista.h"
using namespace std;
#include "Biblioteca.h"

void Biblioteca::carga() {
    ifstream archEstantes("ArchivosDeDatos/Estantes3.csv",ios::in);
    ifstream archLibros("ArchivosDeDatos/Libros31.csv",ios::in);
    Estante estante;
    char tipoLibro,car;
    while (estante.leer(archEstantes)) {
        estante.vaciar();
        for (int i=0;i<10;i++) {
            NLibro nlibro;
            archLibros>>tipoLibro>>car;
            if (tipoLibro=='E') *nlibro=new Enciclopedia;
            else if (tipoLibro=='N') *nlibro=new Novela;
            else *nlibro=new Revista;
            (*nlibro)->leer(archLibros);
            estante.cargar(nlibro);
        }
        this->AEstante.insertABB(estante);
    }
}

void Biblioteca::muestra() {
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2);
    this->AEstante.printABB(archReporte);
}

void Biblioteca::prueba(double peso) {
    ofstream archPrueba("ArchivosDeReporte/Prueba.txt",ios::out);
    Estante estantePrueba;
    estantePrueba.setDisponible(peso);
    this->AEstante.findABB(archPrueba,estantePrueba);
}
