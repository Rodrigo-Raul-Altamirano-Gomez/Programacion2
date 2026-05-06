//
// Created by hrodic on 3/05/2026.
//
#include <cstring>
#include <iomanip>
#include "listas_genericas.h"

void crear_lista_heroes(void* arreglo_heroes,void*& lista_heroes,void* (*leer_heroe)(void*)) {
    void** regHeroes=(void**)arreglo_heroes;
    void** regNodoFinal;
    lista_heroes=nullptr;
    for (int i=0;regHeroes[i];i++) {
        void* heroe=leer_heroe(regHeroes[i]);
        void** nuevoNodo=new void*[2]{heroe,nullptr};
        if (not lista_heroes) lista_heroes=nuevoNodo;
        else regNodoFinal[1]=nuevoNodo;
        regNodoFinal=nuevoNodo;
    }
}

void* leer_heroe(void* auxHeroe) {
    void** regAuxHeroe=(void**)auxHeroe;
    int* codigoHeroe=new int(*(int*)regAuxHeroe[0]);
    char* nombreHeroe=CopiarCadenaExacta((char*)regAuxHeroe[1]);
    char* rolHeroe=CopiarCadenaExacta((char*)regAuxHeroe[2]);
    char* categoriaHeroe=CopiarCadenaExacta((char*)regAuxHeroe[3]);
    double* puntajeHeroe=new double(*(double*)regAuxHeroe[4]);
    void* heroe=new void*[5]{codigoHeroe,nombreHeroe,rolHeroe,categoriaHeroe,puntajeHeroe};
    eliminar_registro(auxHeroe);
    return  heroe;
}

char* CopiarCadenaExacta(const char* cadena) {
    char* cadenaExacta=new char[strlen(cadena)+1];
    strcpy(cadenaExacta,cadena);
    return cadenaExacta;
}

void eliminar_registro(void* heroe) {
    void** regHeroe=(void**)heroe;
    delete (int*)regHeroe[0];
    delete[] (char*)regHeroe[1];
    delete[] (char*)regHeroe[2];
    delete[] (char*)regHeroe[3];
    delete (double*)regHeroe[4];
    delete[] regHeroe;
}

void imprimir_lista_heroes(void* lista_heroes,void (*imprimir_registro_heroe)(void*,ofstream&)) {
    ofstream archReporte("Reporte-Heroes.txt",ios::out);
    int cantHeroes=0;
    archReporte<<left<<setw(15)<<"Nombre"<<setw(10)<<"Rol"<<setw(15)<<"Categoria"<<setw(10)<<"Puntaje";
    archReporte<<"Codigo"<<endl<<fixed<<setprecision(2);
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    for (void** regNodoActual=(void**)lista_heroes;regNodoActual;regNodoActual=(void**)regNodoActual[1]) {
        imprimir_registro_heroe(regNodoActual[0],archReporte);
        cantHeroes++;
    }
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<"La lista tiene "<<cantHeroes<<" elementos."<<endl;
}

void imprimir_registro_heroe(void* heroe,ofstream& archReporte) {
    void** regHeroe=(void**)heroe;
    archReporte<<left<<setw(15)<<(char*)regHeroe[1]<<setw(10)<<(char*)regHeroe[2];
    archReporte<<setw(15)<<(char*)regHeroe[3]<<right<<setw(7)<<*(double*)regHeroe[4];
    archReporte<<setw(9)<<*(int*)regHeroe[0]<<endl;
}

void eliminar_lista_heroes_repetidos(void*& lista_heroes,void (*eliminar_registro)(void*)) {
    void** regNodoAnterior=nullptr;
    for (void** regNodoActual=(void**)lista_heroes;regNodoActual;regNodoActual=(void**)regNodoActual[1]) {
        void** regNodoSiguiente=(void**)regNodoActual[1];
        if (regNodoSiguiente) {
            void** regHeroeActual=(void**)regNodoActual[0];
            void** regHeroeSiguiente=(void**)regNodoSiguiente[0];
            if (strcmp((char*)regHeroeActual[1],(char*)regHeroeSiguiente[1])==0) {
                EliminarNodo(regNodoSiguiente,regNodoActual,eliminar_registro);
                regNodoActual=regNodoAnterior;
            }
        }
        regNodoAnterior=regNodoActual;
    }
}

void EliminarNodo(void* nodoAEliminar,void* nodoAuxiliar,void (*eliminar_registro)(void*)) {
    void** regNodoAEliminar=(void**)nodoAEliminar;
    void** regNodoAuxiliar=(void**)nodoAuxiliar;
    regNodoAuxiliar[1]=regNodoAEliminar[1];
    eliminar_registro(regNodoAEliminar[0]);
    delete[] regNodoAEliminar;
}