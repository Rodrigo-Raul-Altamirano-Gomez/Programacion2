//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_CONDUCTOR_H
#define INFRACCIONES2021_1LAB09_CONDUCTOR_H

#include <cstring>
#include <fstream>
using namespace std;

class Conductor {
    int licencia;
    char* nombre;
public:
    Conductor();
    void setLicencia(int);
    void setNombre(const char*);
    ~Conductor();
};


#endif //INFRACCIONES2021_1LAB09_CONDUCTOR_H
