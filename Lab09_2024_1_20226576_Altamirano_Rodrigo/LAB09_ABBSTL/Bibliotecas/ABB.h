//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_ABB_H
#define LAB09_ABBSTL_ABB_H
#include "NodoArbol.h"
#include <fstream>
#include <iomanip>

template<typename T>
class ABB {
    NodoArbol<T>* root;
    void erase(NodoArbol<T>*);
    void insert(NodoArbol<T>*,NodoArbol<T>*,NodoArbol<T>*);
    void print(std::ofstream&,NodoArbol<T>*);
    void find(std::ofstream&,NodoArbol<T>*,const T&) const;
public:
    ABB();
    bool empty() const;
    void insertABB(const T&);
    void printABB(std::ofstream&);
    void findABB(std::ofstream&,const T&) const;
    ~ABB();
};

template<typename T>
ABB<T>::ABB() {
    this->root=nullptr;
}

template<typename T>
bool ABB<T>::empty() const {
    return not this->root;
}

template<typename T>
void ABB<T>::insertABB(const T& dato) {
    NodoArbol<T>* newNode=new NodoArbol<T>;
    newNode->dato=dato;
    this->insert(newNode,nullptr,this->root);
}

template<typename T>
void ABB<T>::insert(NodoArbol<T>* newNode, NodoArbol<T>* preNode, NodoArbol<T>* node) {
    if (not node) {
        if (preNode and newNode->dato<=preNode->dato) preNode->izq=newNode;
        else if (preNode and not (newNode->dato<=preNode->dato)) preNode->der=newNode;
        else this->root=newNode;
        return;
    }
    if (newNode->dato<=node->dato) this->insert(newNode,node,node->izq);
    else this->insert(newNode,node,node->der);
}

template<typename T>
void ABB<T>::printABB(std::ofstream &archReporte) {
    this->print(archReporte,this->root);
}

template<typename T>
void ABB<T>::print(std::ofstream &archReporte, NodoArbol<T> *node) {
    if (not node) return;
    this->print(archReporte,node->izq);
    archReporte<<node->dato<<std::endl;
    this->print(archReporte,node->der);
}

template<typename T>
void ABB<T>::findABB(std::ofstream &archPrueba, const T& key) const {
    this->find(archPrueba,this->root,key);
}

template<typename T>
void ABB<T>::find(std::ofstream &archPrueba, NodoArbol<T> *node, const T& key) const {
    if (not node) {
        archPrueba<<std::setw(10)<<" "<<"No es posible colocar el libro."<<std::endl;
        return;
    }
    if (key<=node->dato) {
        archPrueba<<std::setw(10)<<" "<<"Si hay espacio"<<std::endl;
        archPrueba<<node->dato<<std::endl;
    } else this->find(archPrueba,node->der,key);
}

template<typename T>
void ABB<T>::erase(NodoArbol<T> *node) {
    if (not node) return;
    this->erase(node->izq);
    this->erase(node->der);
    delete node;
}

template<typename T>
ABB<T>::~ABB() {
    if (not this->empty()) this->erase(this->root);
}


#endif //LAB09_ABBSTL_ABB_H
