//
// Created by hrodic on 24/04/2026.
//
#include <cstring>
#include <iomanip>
#include "PunterosGenericos.h"

void cargarstreamers(void*& streamers) {
    ifstream archStreamers("streamers.csv",ios::in);
    void *bufferStreamers[300],*streamer;
    int cantStreamers=0;
    while (LeerLineaStreamers(streamer,archStreamers)) {
        bufferStreamers[cantStreamers]=streamer;
        cantStreamers++;
    }
    streamers=new void*[cantStreamers+1]{};
    void** regStreamers=(void**)streamers;
    for (int i=0;i<cantStreamers;i++) regStreamers[i]=bufferStreamers[i];
}

bool LeerLineaStreamers(void*& streamer,ifstream& archStreamers) {
    char *cuentaStreamer,*categoriaStreamer;
    int* cantSeguidoresStreamer;
    cuentaStreamer=LeerCadenaExacta(archStreamers,',');
    if (cuentaStreamer) {
        cantSeguidoresStreamer=new int;
        archStreamers.ignore(20,',');
        archStreamers.ignore(20,',');
        archStreamers>>*cantSeguidoresStreamer;
        archStreamers.ignore();
        categoriaStreamer=LeerCadenaExacta(archStreamers,'\n');
        streamer=new void*[4]{cuentaStreamer,cantSeguidoresStreamer,categoriaStreamer,nullptr};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archStreamers,char delim) {
    char *cadenaExacta,buffer[200];
    archStreamers.getline(buffer,200,delim);
    if (not archStreamers) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void PruebaStreamers(void* streamers) {
    ofstream archPruebaStreamers("PruebaStreamers.txt",ios::out);
    void** regStreamers=(void**)streamers;
    archPruebaStreamers<<"STREAMERS"<<endl;
    archPruebaStreamers<<left<<setw(21)<<"CUENTA"<<setw(15)<<"SEGUDORES"<<"CATEGORIA"<<endl;
    for (int i=0;regStreamers[i];i++) {
        void** regStreamer=(void**)(regStreamers[i]);
        archPruebaStreamers<<left<<setw(20)<<(char*)(regStreamer[0])<<right<<setw(10)<<*(int*)(regStreamer[1]);
        archPruebaStreamers<<setw(9)<<" "<<(char*)(regStreamer[2])<<endl;
    }
}

void cargarcomentarios(void*& comentarios) {
    ifstream archComentarios("comentarios.csv",ios::in);
    void *bufferComentarios[300],*comentario;
    int cantComentarios=0;
    while (LeerLineaComentarios(comentario,archComentarios)) {
        bufferComentarios[cantComentarios]=comentario;
        cantComentarios++;
    }
    comentarios=new void*[cantComentarios+1]{};
    void** regComentarios=(void**)comentarios;
    for (int i=0;i<cantComentarios;i++) regComentarios[i]=bufferComentarios[i];
}

bool LeerLineaComentarios(void*& comentario,ifstream& archComentarios) {
    char *codigoComentario,*textoComentario,*emisorComentario,*receptorComentario;
    codigoComentario=LeerCadenaExacta(archComentarios,',');
    if (codigoComentario) {
        textoComentario=LeerCadenaExacta(archComentarios,'[');
        emisorComentario=LeerCadenaExacta(archComentarios,' ');
        receptorComentario=LeerCadenaExacta(archComentarios,']');
        archComentarios.ignore();
        comentario=new void*[4]{codigoComentario,emisorComentario,receptorComentario,textoComentario};
        return true;
    }
    return false;
}

void PruebaComentarios(void* comentarios) {
    ofstream archPruebaComentarios("PruebaComentarios.txt",ios::out);
    void** regComentarios=(void**)comentarios;
    archPruebaComentarios<<"COMENTARIOS"<<endl;
    archPruebaComentarios<<left<<setw(12)<<"CODIGO"<<setw(20)<<"EMISOR"<<setw(20)<<"RECEPTOR"<<"TEXTO"<<endl;
    for (int i=0;regComentarios[i];i++) {
        void** regComentario=(void**)(regComentarios[i]);
        archPruebaComentarios<<left<<setw(12)<<(char*)(regComentario[0])<<setw(20)<<(char*)(regComentario[1]);
        archPruebaComentarios<<setw(20)<<(char*)(regComentario[2])<<(char*)(regComentario[3])<<endl;
    }
}

void actualizarcomentarios(void* streamers,void* comentarios) {
    void **regStreamers=(void**)streamers,**regComentarios=(void**)comentarios;
    for (int i=0;regStreamers[i];i++) {
        void** regStreamer=(void**)(regStreamers[i]);
        for (int j=0;regComentarios[j];j++) {
            void** regComentario=(void**)(regComentarios[j]);
            if (strcmp((char*)(regStreamer[0]),(char*)(regComentario[1]))==0) {
                char* receptorComentario=CopiarCadenaExacta((char*)(regComentario[2]));
                char* textoComentario=CopiarCadenaExacta((char*)(regComentario[3]));
                void* nuevoComentarioStreamer=new void*[2]{receptorComentario,textoComentario};
                AñadirComentarioStreamer(nuevoComentarioStreamer,regStreamer[3]);
            }
        }
    }
}

void AñadirComentarioStreamer(void* nuevoComentarioStreamer,void*& comentariosStreamer) {
    if (not comentariosStreamer) comentariosStreamer=new void*[2]{nuevoComentarioStreamer,nullptr};
    else {
        int cantComentariosStreamer=0;
        void** regComentariosStreamer=(void**)comentariosStreamer;
        for (int i=0;regComentariosStreamer[i];i++) cantComentariosStreamer++;
        void** aux=new void*[cantComentariosStreamer+2]{};
        for (int i=0;i<cantComentariosStreamer;i++) aux[i]=regComentariosStreamer[i];
        aux[cantComentariosStreamer]=nuevoComentarioStreamer;
        delete[] regComentariosStreamer;
        comentariosStreamer=aux;
    }
}

char* CopiarCadenaExacta(const char* cadena) {
    char* cadenaNueva=new char[strlen(cadena)+1];
    strcpy(cadenaNueva,cadena);
    return cadenaNueva;
}

void imprimestreamers(void* streamers) {
    ofstream archReporte("Reporte.txt",ios::out);
    void** regStreamers=(void**)streamers;
    for (int i=0;regStreamers[i];i++) {
        void** regStreamer=(void**)(regStreamers[i]);
        archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
        archReporte<<left<<setw(15)<<"Cuenta"<<"Seguidores"<<endl;
        archReporte<<setw(15)<<(char*)(regStreamer[0])<<*(int*)(regStreamer[1])<<endl;
        archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
        archReporte<<"Comentarios emitidos:"<<endl;
        archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
        if (regStreamer[3]) EmitirComentariosStreamer(regStreamer[3],archReporte);
        else archReporte<<"Sin comentarios"<<endl;
    }
}

void EmitirComentariosStreamer(void* comentariosStreamer,ofstream& archReporte) {
    void** regComentariosStreamer=(void**)comentariosStreamer;
    archReporte<<setw(20)<<"Receptor"<<"Texto"<<endl;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl;
    for (int i=0;regComentariosStreamer[i];i++) {
        void** regComentarioStreamer=(void**)(regComentariosStreamer[i]);
        archReporte<<setw(20)<<(char*)(regComentarioStreamer[0])<<(char*)(regComentarioStreamer[1])<<endl;
    }
}
