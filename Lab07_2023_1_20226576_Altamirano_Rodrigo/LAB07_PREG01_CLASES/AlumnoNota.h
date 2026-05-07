//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB07_PREG01_CLASES_ALUMNONOTA_H
#define LAB07_PREG01_CLASES_ALUMNONOTA_H

#include <fstream>
using namespace std;

class Nota;

class AlumnoNota {
    int codigo;
    char* codCurso;
    int ciclo;
    int nota;
public:
    friend ifstream& operator>>(ifstream&,AlumnoNota&);
    void operator&(Nota&);
};


#endif //LAB07_PREG01_CLASES_ALUMNONOTA_H
