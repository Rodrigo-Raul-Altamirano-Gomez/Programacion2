//
// Created by hrodic on 3/05/2026.
//
#include <cstring>
#include "arreglos_genericos.h"

void llenar_arreglo_heroes(void*& arreglo_heroes,int& cantidad_total_heroes,const char* nombreArchivoHeroes) {
    ifstream archHeroes(nombreArchivoHeroes,ios::in);
    void *heroe,*bufferHeroes[275];
    cantidad_total_heroes=0;
    while (leerLineaHeroes(heroe,archHeroes)) {
        bufferHeroes[cantidad_total_heroes]=heroe;
        cantidad_total_heroes++;
    }
    arreglo_heroes=new void*[cantidad_total_heroes+1]{};
    void** regHeroes=(void**)arreglo_heroes;
    for (int i=0;i<cantidad_total_heroes;i++) regHeroes[i]=bufferHeroes[i];
}

bool leerLineaHeroes(void*& heroe,ifstream& archHeroes) {
    int codigo;
    if (archHeroes>>codigo) {
        int* codigoHeroe=new int(codigo);
        double* puntajeHeroe=new double;
        archHeroes.ignore();
        char* nombreHeroe=LeerCadenaExacta(archHeroes);
        char* rolHeroe=LeerCadenaExacta(archHeroes);
        char* categoriaHeroe=LeerCadenaExacta(archHeroes);
        archHeroes>>*puntajeHeroe;
        heroe=new void*[5]{codigoHeroe,nombreHeroe,rolHeroe,categoriaHeroe,puntajeHeroe};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archHeroes) {
    char *cadenaExacta,buffer[200];
    archHeroes.getline(buffer,200,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

int cmp_multicriterio_void(const void* a,const void* b) {
    const void* heroeA=*(const void**)a;
    const void* heroeB=*(const void**)b;
    const void** regHeroeA=(const void**)heroeA;
    const void** regHeroeB=(const void**)heroeB;
    const char* nombreHeroeA=(const char*)regHeroeA[1];
    const char* nombreHeroeB=(const char*)regHeroeB[1];
    const double puntajeHeroeA=*(const double*)regHeroeA[4];
    const double puntajeHeroeB=*(const double*)regHeroeB[4];
    int comparacionNombres=strcmp(nombreHeroeA,nombreHeroeB);
    if (comparacionNombres==0) return puntajeHeroeB-puntajeHeroeA;
    else return comparacionNombres;
}