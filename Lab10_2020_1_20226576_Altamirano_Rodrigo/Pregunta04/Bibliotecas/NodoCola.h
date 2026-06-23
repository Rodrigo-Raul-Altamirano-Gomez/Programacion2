//
// Created by hrodic on 21/06/2026.
//

#ifndef PREGUNTA02_NODOCOLA_H
#define PREGUNTA02_NODOCOLA_H

template <typename T>
class PlCola;

template <typename T>
class NodoCola {
    T dato;
    NodoCola* siguiente;
    friend class PlCola<T>;
public:
    NodoCola();
};

template<typename T>
NodoCola<T>::NodoCola() {
    this->siguiente=nullptr;
}


#endif //PREGUNTA02_NODOCOLA_H
