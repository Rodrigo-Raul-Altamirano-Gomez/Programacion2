//
// Created by hrodic on 1/06/2026.
//

#ifndef STREAMERS_HERENCIA_STREAMER_H
#define STREAMERS_HERENCIA_STREAMER_H

#include <fstream>
using namespace std;

class Streamer {
    int id;
    char* cuenta;
    int n_seguidores;
    char* categoria;
public:
    Streamer();
    Streamer(const Streamer&);
    Streamer(int,const char*,int,const char*);
    Streamer& operator=(const Streamer&);
    void setID(int);
    void setCuenta(const char*);
    void setNumSeguidores(int);
    void setCategoria(const char*);
    int getID() const;
    char* getCuenta() const;
    int getNumSeguidores() const;
    char* getCategoria() const;
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Streamer();
};


#endif //STREAMERS_HERENCIA_STREAMER_H
