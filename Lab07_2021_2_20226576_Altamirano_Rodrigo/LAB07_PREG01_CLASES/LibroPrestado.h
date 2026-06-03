//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB07_PREG01_CLASES_LIBROPRESTADO_H
#define LAB07_PREG01_CLASES_LIBROPRESTADO_H

#include <fstream>
using namespace std;

class LibroPrestado {
    int carne;
    char tipo;
    char* codigoLib;
    int fechaDeRetiro;
    int deuda;
public:
    LibroPrestado();
    void setCarne(int);
    void setTipo(char);
    void setCodigoLib(const char*);
    void setFechaRetiro(int);
    LibroPrestado& operator=(const LibroPrestado&);
    char getTipo() const;
    int getFechaRetiro() const;
    void setDeuda(int);
    const char* getCodigo() const;
    int getFecha() const;
    int getDeuda() const;
    ~LibroPrestado();
};

ifstream& operator>>(ifstream&,LibroPrestado&);
ofstream& operator<<(ofstream&,const LibroPrestado&);

#endif //LAB07_PREG01_CLASES_LIBROPRESTADO_H
