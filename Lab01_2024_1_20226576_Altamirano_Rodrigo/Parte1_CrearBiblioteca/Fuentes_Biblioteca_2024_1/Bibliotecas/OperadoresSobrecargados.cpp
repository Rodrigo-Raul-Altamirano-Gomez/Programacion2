//
// Created by hrodic on 9/04/2026.
//
#include <cstring>
#include "OperadoresSobrecargados.h"
#include <iomanip>

ifstream& operator>> (ifstream& archLectura, Libro& libro) {
    if (archLectura.getline(libro.codigo,7,',')) {
        archLectura.getline(libro.titulo,80,',');
        archLectura.getline(libro.autor,60,',');
        archLectura>>libro.stock;
        archLectura.ignore();
        archLectura>>libro.precio;
        archLectura.ignore();
    }
    return archLectura;
}

ifstream& operator>> (ifstream& archLectura, Cliente& cliente) {
    if (archLectura>>cliente.dni) {
        archLectura.getline(cliente.nombre,60);
        cliente.cantDeLibros=0;
        cliente.pagoTotal=0;
    }
    return archLectura;
}

bool operator>> (LibroSolicitado& libroSolicitado, Libro* arregloLibros) {
    int posLibro=BuscarLibro(libroSolicitado.codigoDelLibro,arregloLibros);
    if (posLibro>=0) {
        if (arregloLibros[posLibro].stock>0) {
            arregloLibros[posLibro].stock--;
            libroSolicitado.precio=arregloLibros[posLibro].precio;
            libroSolicitado.atendido=true;
            return true;
        }
        else {
            libroSolicitado.atendido=false;
            return false;
        }
    }
    return false;
}

int BuscarLibro(const char* codigoDelLibro,Libro* arregloLibros) {
    for (int cont=0;strcmp(arregloLibros[cont].codigo,"FIN")!=0;cont++) {
        if (strcmp(arregloLibros[cont].codigo,codigoDelLibro)==0) return cont;
    }
    return -1;
}

bool operator<< (Cliente& cliente, const LibroSolicitado& libroSolicitado) {
    if (cliente.cantDeLibros<30) {
        cliente.librosSolicitados[cliente.cantDeLibros].numeroDePedido=libroSolicitado.numeroDePedido;
        strcpy(cliente.librosSolicitados[cliente.cantDeLibros].codigoDelLibro,libroSolicitado.codigoDelLibro);
        cliente.librosSolicitados[cliente.cantDeLibros].precio=libroSolicitado.precio;
        cliente.librosSolicitados[cliente.cantDeLibros].atendido=libroSolicitado.atendido;
        cliente.cantDeLibros++;
        return true;
    }
    return false;
}

void operator++ (Cliente& cliente, int) {
    for (int cont=0;cont<cliente.cantDeLibros;cont++) cliente.pagoTotal+=cliente.librosSolicitados[cont].precio;
}

ofstream& operator<< (ofstream& archEscritura, const Libro& libro) {
    archEscritura<<fixed<<setprecision(2);
    archEscritura<<left<<setw(12)<<libro.codigo<<setw(85)<<libro.titulo<<setw(60)<<libro.autor;
    archEscritura<<right<<setw(5)<<libro.stock<<setw(9)<<libro.precio<<endl;
    return archEscritura;
}

ofstream& operator<< (ofstream& archEscritura, const Cliente& cliente) {
    archEscritura<<fixed<<setprecision(2);
    archEscritura<<setfill('0')<<setw(8)<<cliente.dni<<setfill(' ')<<left<<setw(60)<<cliente.nombre<<endl;
    ImprimirLibrosCliente(archEscritura,cliente,true);
    ImprimirLibrosCliente(archEscritura,cliente,false);
    return archEscritura;
}

void ImprimirLibrosCliente(ofstream& archEscritura,const Cliente& cliente,bool entregados) {
    int cont2=0;
    LibroSolicitado libroSolicitado;
    entregados ? archEscritura<<"Libros entregados:":archEscritura<<"Libros no entregados por falta de stock:";
    archEscritura<<endl<<setw(7)<<" "<<setw(15)<<"Pedido No."<<setw(10)<<"Codigo"<<right<<endl;
    if (entregados) archEscritura<<"Precio"<<endl;
    for (int cont=0;cont<cliente.cantDeLibros;cont++) {
        if (cliente.librosSolicitados[cont].atendido==entregados) {
            libroSolicitado=cliente.librosSolicitados[cont];
            archEscritura<<setw(9)<<" "<<setfill('0')<<setw(5)<<libroSolicitado.numeroDePedido<<setfill(' ');
            archEscritura<<setw(7)<<" "<<left<<setw(10)<<libroSolicitado.codigoDelLibro<<right<<endl;
            if (entregados) archEscritura<<setw(6)<<libroSolicitado.precio<<endl;
        }
    }
    if (entregados) archEscritura<<"Total a pagar: "<<cliente.pagoTotal<<endl;
}