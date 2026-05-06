//
// Created by hrodic on 26/04/2026.
//
#include <cstring>
#include <iomanip>
#include "FuncionesLaboratorio02.h"

#include "BibliotecaColaGenerica.h"

bool leerCliente(void*& cliente,ifstream& archClientes) {
    int dni,horaLlegada,minLlegada,segLlegada;
    char car;
    if (archClientes>>dni) {
        int* dniCliente=new int(dni);
        double *horaLLegada=new double,*tiempoTransaccion=new double,tiempoTransaccionMinutos;
        archClientes.ignore();
        char* nombreCliente=LeerCadenaExacta(archClientes);
        archClientes>>horaLlegada>>car>>minLlegada>>car>>segLlegada>>car>>tiempoTransaccionMinutos;
        *horaLLegada=horaLlegada*3600+minLlegada*60+segLlegada;
        *tiempoTransaccion=tiempoTransaccionMinutos*60;
        cliente=new void*[4]{dniCliente,nombreCliente,horaLLegada,tiempoTransaccion};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archClientes) {
    char *cadenaExacta,buffer[200];
    archClientes.getline(buffer,200,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void imprimirCliente(void* cliente,ofstream& archPruebaClientes) {
    void** regCliente=(void**)cliente;
    archPruebaClientes<<left<<setw(12)<<*(int*)(regCliente[0])<<setw(40)<<(char*)(regCliente[1]);
    archPruebaClientes<<right<<setw(9)<<*(double*)(regCliente[2])<<setw(9)<<*(double*)(regCliente[3])<<endl;
}

void atiendeCola(void* colaClientes,double horaApertura) {
    ofstream archReporte("Reporte.txt",ios::out);
    double promedioEspera;
    archReporte<<fixed<<setprecision(2);
    archReporte<<"Hora de apertura: ";
    ImprimirHora(horaApertura,archReporte);
    archReporte<<endl;
    archReporte<<setw(52)<<" "<<left<<setw(15)<<"HORA"<<setw(15)<<"TIEMPO"<<"HORA"<<endl;
    archReporte<<setw(12)<<"DNI"<<setw(40)<<"NOMBRE"<<setw(15)<<"DE LLEGADA"<<setw(15)<<"DE ESPERA";
    archReporte<<"DE SALIDA"<<endl;
    archReporte<<setfill('=')<<setw(120)<<"="<<setfill(' ')<<endl;
    AtenderClientes(colaClientes,horaApertura,archReporte,promedioEspera);
    archReporte<<setfill('=')<<setw(120)<<"="<<setfill(' ')<<endl;
    archReporte<<"Promedio de espera: "<<promedioEspera<<" seg.";
}

void ImprimirHora(int horaApertura,ofstream& archReporte) {
    int horas,minutos,segundos,residuo;
    char car=':';
    horas=horaApertura/3600;
    residuo=horaApertura%3600;
    minutos=residuo/60;
    segundos=residuo%60;
    archReporte<<right<<setfill('0')<<setw(2)<<horas<<car<<setw(2)<<minutos<<car<<setw(2)<<segundos;
    archReporte<<setfill(' ');
}

void AtenderClientes(void* colaClientes,double horaApertura,ofstream& archReporte,double& promedioEspera) {
    double sumTiempoEspera=0,horaSalidaAnt=horaApertura;
    int cantAtenciones=0;
    while (not colaVacia(colaClientes)) {
        void** regCliente=(void**)desencola(colaClientes);
        double horaLLegada=*(double*)(regCliente[2]),tiempoTransaccion=*(double*)(regCliente[3]),tiempoEspera,horaSalida;
        if (horaSalidaAnt<horaLLegada) tiempoEspera=tiempoTransaccion;
        else tiempoEspera=(horaSalidaAnt-horaLLegada)+tiempoTransaccion;
        horaSalida=horaLLegada+tiempoEspera;
        sumTiempoEspera+=tiempoEspera;
        cantAtenciones++;
        horaSalidaAnt=horaSalida;
        ImprimirCliente(regCliente,horaLLegada,tiempoEspera,horaSalida,archReporte);
    }
    promedioEspera=sumTiempoEspera/cantAtenciones;
}

void ImprimirCliente(void* cliente,double horaLLegada,double tiempoEspera,double horaSalida,ofstream& archReporte) {
    void** regCliente=(void**)cliente;
    archReporte<<left<<setw(12)<<*(int*)(regCliente[0])<<setw(40)<<(char*)(regCliente[1]);
    ImprimirHora(horaLLegada,archReporte);
    archReporte<<right<<setw(13)<<tiempoEspera<<" seg."<<setw(5)<<" ";
    ImprimirHora(horaSalida,archReporte);
    archReporte<<endl;
    delete[] (int*)(regCliente[0]);
    delete[] (char*)(regCliente[1]);
    delete[] (double*)(regCliente[2]);
    delete[] (double*)(regCliente[3]);
    delete[] regCliente;
}
