//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_NLIBRO_H
#define LAB09_ABBSTL_NLIBRO_H
#include "Libro.h"

class NLibro {
    Libro* plibro;
public:
    NLibro();
    NLibro(const NLibro&);
    NLibro& operator=(const NLibro&);
    Libro*& operator*();
    ~NLibro();
};


#endif //LAB09_ABBSTL_NLIBRO_H
