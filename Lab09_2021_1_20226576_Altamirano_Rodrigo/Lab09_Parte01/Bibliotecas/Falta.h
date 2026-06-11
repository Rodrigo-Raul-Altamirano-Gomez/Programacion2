//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_FALTA_H
#define INFRACCIONES2021_1LAB09_FALTA_H


class Falta {
    int fecha;
    char* placa;
public:
    Falta();
    void setFecha(int);
    void setPlaca(const char*);
    ~Falta();
};


#endif //INFRACCIONES2021_1LAB09_FALTA_H
