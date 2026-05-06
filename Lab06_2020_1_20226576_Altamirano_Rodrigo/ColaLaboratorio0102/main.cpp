#include "BibliotecaColaGenerica.h"
#include "FuncionesLaboratorio02.h"
#include <iostream>

int main() {
    void* colaClientes;
    double horaApertura;
    int horas,minutos,segundos;
    char car;
    creaCola(colaClientes,leerCliente,"Banco-Clientes.csv");
    imprimir(colaClientes,imprimirCliente,"PruebaClientes.txt");
    cout<<"Ingrese la hora de apertura: ";
    cin>>horas>>car>>minutos>>car>>segundos;
    horaApertura=horas*3600+minutos*60+segundos;
    atiendeCola(colaClientes,horaApertura);
    return 0;
}
