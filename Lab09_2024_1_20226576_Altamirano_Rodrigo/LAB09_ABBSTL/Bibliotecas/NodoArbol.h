//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_NODOARBOL_H
#define LAB09_ABBSTL_NODOARBOL_H

template<typename T>
class ABB;

template<typename T>
class NodoArbol {
    T dato;
    NodoArbol* izq;
    NodoArbol* der;
    friend class ABB<T>;
public:
    NodoArbol();
};

template<typename T>
NodoArbol<T>::NodoArbol() {
    this->izq=nullptr;
    this->der=nullptr;
}


#endif //LAB09_ABBSTL_NODOARBOL_H
