//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA02_PLCOLA_H
#define PREGUNTA02_PLCOLA_H
#include "NodoCola.h"
#include <fstream>
#include <iomanip>

template<typename T>
std::ofstream& operator<<(std::ofstream&, const PlCola<T>&);

template <typename T>
class PlCola {
    NodoCola<T>* cabeza;
    NodoCola<T>* cola;
protected:
    void imprimir(std::ofstream&) const;
    friend std::ofstream& operator<<<T>(std::ofstream&,const PlCola&);
public:
    PlCola();
    bool esColaVacia() const;
    void encola(T);
    T desencola();
    ~PlCola();
};

template<typename T>
PlCola<T>::PlCola() {
    this->cabeza=nullptr;
    this->cola=nullptr;
}

template<typename T>
bool PlCola<T>::esColaVacia() const {
    return  not this->cabeza;
}

template<typename T>
void PlCola<T>::encola(T nuevoDato) {
    NodoCola<T>* nuevoNodo=new NodoCola<T>;
    nuevoNodo->dato=nuevoDato;
    if (this->esColaVacia()) this->cabeza=nuevoNodo;
    else this->cola->siguiente=nuevoNodo;
    this->cola=nuevoNodo;
}

template<typename T>
T PlCola<T>::desencola() {
    NodoCola<T>* nodo=this->cabeza;
    T dato=nodo->dato;
    this->cabeza=nodo->siguiente;
    if (this->esColaVacia()) this->cola=nullptr;
    delete nodo;
    return dato;
}

template<typename T>
void PlCola<T>::imprimir(std::ofstream &archReporte) const {
    for (NodoCola<T>* nodoActual=this->cabeza;nodoActual;nodoActual=nodoActual->siguiente) {
        archReporte<<nodoActual->dato<<std::endl;
        archReporte<<std::setfill('-')<<std::setw(50)<<" "<<std::setfill(' ')<<std::endl;
    }
}

template<typename T>
std::ofstream& operator<<(std::ofstream& archReporte,const PlCola<T>& cola) {
    cola.imprimir(archReporte);
    return archReporte;
}

template<typename T>
PlCola<T>::~PlCola() {
    while (not this->esColaVacia()) this->desencola();
}


#endif //PREGUNTA02_PLCOLA_H
