#include "Usuario.h"
#include "Libro.h"

int main() {
    ifstream archUsuarios("Usuarios.csv",ios::in);
    ifstream archLibros("Libros.csv",ios::in);
    ifstream archPrestamos("RegistroDePrestamos.csv",ios::in);
    ofstream archReportePrueba("ReportePrueba.txt",ios::out);
    Usuario usuario;
    Libro libro;
    LibroPrestado libroPrestado;
    archLibros>>libro;
    archUsuarios>>usuario;
    archPrestamos>>libroPrestado;
    usuario+=libroPrestado;
    libro+=libroPrestado;
    usuario*20220000;
    archReportePrueba<<usuario;
    archReportePrueba<<libro;
    return 0;
}
