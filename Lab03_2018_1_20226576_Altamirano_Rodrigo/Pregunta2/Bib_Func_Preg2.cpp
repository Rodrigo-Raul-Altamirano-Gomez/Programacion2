//
// Created by hrodic on 19/04/2026.
//
#include <iomanip>
#include "Bib_Func_Preg2.h"
#include "Bib_Func_Preg1.h"

void leerPrestamos(void* usuarios) {
    ifstream archPrestamos("Prestamos.csv",ios::in);
    void* libroPrestadoUsuario;
    int codUsuario,posUsuario;
    while (LeerLineaPrestamos(codUsuario,libroPrestadoUsuario,archPrestamos)) {
        posUsuario=BuscarUsuario(codUsuario,usuarios);
        if (posUsuario>=0) AñadirLibroPrestadoUsuario(libroPrestadoUsuario,((void**)usuarios)[posUsuario]);
        else {
            delete[] (char*)(((void**)libroPrestadoUsuario)[0]);
            delete[] (char*)(((void**)libroPrestadoUsuario)[1]);
            delete[] (void**)libroPrestadoUsuario;
        }
    }
}

bool LeerLineaPrestamos(int& codUsuario,void*& libroPrestadoUsuario,ifstream& archPrestamos) {
    int diaFecha,mesFecha,anioFecha,*fechaPrestamo=new int[1];
    char *codLibro,car;
    if (archPrestamos>>codUsuario) {
        archPrestamos.ignore();
        codLibro=LeeCadenaExacta(archPrestamos,',');
        archPrestamos>>diaFecha>>car>>mesFecha>>car>>anioFecha;
        *fechaPrestamo=diaFecha+mesFecha*100+anioFecha*10000;
        libroPrestadoUsuario=new void*[2]{codLibro,fechaPrestamo};
        return true;
    }
    return false;
}

int BuscarUsuario(int codUsuario,void* usuarios) {
    void* usuario;
    void* ptrCodUsuario;
    for (int i=0;((void**)usuarios)[i];i++) {
        usuario=((void**)usuarios)[i];
        ptrCodUsuario=((void**)usuario)[0];
        if (codUsuario==*((int*)ptrCodUsuario)) return i;
    }
    return -1;
}

void AñadirLibroPrestadoUsuario(void* libroPrestadoUsuario,void* usuario) {
    int capacidad=0;
    void*& librosPrestados=((void**)usuario)[2];
    void*& numLibros=((void**)usuario)[3];
    if (not numLibros) numLibros=new int*[1]{};
    if (librosPrestados) {
        for (int i=0;((void**)librosPrestados)[i];i++) capacidad++;
    }
    if (*((int*)(numLibros))==capacidad) IncrementarMemoriaLibrosUsuario(librosPrestados,numLibros,capacidad);
    ((void**)librosPrestados)[*((int*)(numLibros))]=(void**)libroPrestadoUsuario;
    (*((int*)(numLibros)))++;
}

void IncrementarMemoriaLibrosUsuario(void*& librosPrestados,void* numLibros,int& capacidad) {
    capacidad+=2;
    if (not librosPrestados) librosPrestados=new void*[capacidad+1];
    else {
        void** aux=new void*[capacidad+1];
        for (int i=0;i<*((int*)numLibros);i++) aux[i]=((void**)librosPrestados)[i];
        delete[] ((void**)librosPrestados);
        librosPrestados=aux;
    }
    ((void**)librosPrestados)[capacidad]=nullptr;
}

void imprimirPrestamos(void* usuarios) {
    void** regUsuarios=(void**)usuarios;
    int cont=0;
    ofstream archReporteLibrosPrestados("ReporteLibrosPrestados.txt",ios::out);
    archReporteLibrosPrestados<<"REGISTRO DE PRESTAMOS DE LA BIBLIOTECA"<<endl;
    archReporteLibrosPrestados<<setw(70)<<"LIBROS PRESTADOS"<<endl;
    archReporteLibrosPrestados<<left<<setw(5)<<"No."<<setw(12)<<"CODIGO"<<setw(20)<<"NOMBRE";
    archReporteLibrosPrestados<<setw(7)<<"CANT"<<setw(15)<<"CODIGO LIB"<<"FECHA"<<endl;
    for (int i=0;regUsuarios[i];i++) {
        void** regUsuario=(void**)(regUsuarios[i]);
        if (regUsuario[2]) {
            ImprimirLibrosPrestados(regUsuario,cont,archReporteLibrosPrestados);
            cont++;
        }
    }
}

void ImprimirLibrosPrestados(void** regUsuario,int cont,ofstream& archReporteLibrosPrestados) {
    void** regLibrosPrestados=(void**)(regUsuario[2]);
    archReporteLibrosPrestados<<right<<setw(2)<<cont+1<<")  "<<left<<setw(12)<<*((int*)(regUsuario[0]));
    archReporteLibrosPrestados<<setw(20)<<(char*)(regUsuario[1])<<right<<setw(3)<<*((int*)(regUsuario[3]));
    archReporteLibrosPrestados<<left<<setw(5)<<" ";
    for (int i=0;i<*((int*)(regUsuario[3]));i++) {
        void** regLibroPrestado=(void**)(regLibrosPrestados[i]);
        if (i>0) archReporteLibrosPrestados<<setw(45)<<" ";
        archReporteLibrosPrestados<<setw(14)<<(char*)(regLibroPrestado[0])<<*((int*)(regLibroPrestado[1]))<<endl;
    }
}
