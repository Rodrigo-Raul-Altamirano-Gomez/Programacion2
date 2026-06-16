//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_RESTAURANTE_H
#define PREG01_LAB08_RESTAURANTE_H
#include "Cola.h"


class Restaurante {
    Cola Ccomanda;
public:
    void carga();
    void elimina(int);
    void atiende();
};


#endif //PREG01_LAB08_RESTAURANTE_H
