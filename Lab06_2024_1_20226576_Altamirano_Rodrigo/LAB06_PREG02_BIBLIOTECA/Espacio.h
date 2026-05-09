//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB06_PREG01_CLASES_ESPACIO_H
#define LAB06_PREG01_CLASES_ESPACIO_H

#include <fstream>
using namespace std;

class Espacio {
    char contenido;
    int posx;
    int posy;
public:
    void setPosiciones(int,int);
    void setOcupado(char);
    char getContenido() const;
};

ofstream& operator<<(ofstream&,const Espacio&);

#endif //LAB06_PREG01_CLASES_ESPACIO_H
