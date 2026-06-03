#include "Estante.h"

int main() {
    ifstream archLibros("libros.csv",ios::in);
    ifstream archEstantes("estantes.csv",ios::in);
    ofstream archReportePrubea("reportePrueba.txt",ios::out);
    Libro libro;
    Estante estante;
    archLibros>>libro;
    archEstantes>>estante;
    estante+=libro;
    archReportePrubea<<estante;
    return 0;
}
