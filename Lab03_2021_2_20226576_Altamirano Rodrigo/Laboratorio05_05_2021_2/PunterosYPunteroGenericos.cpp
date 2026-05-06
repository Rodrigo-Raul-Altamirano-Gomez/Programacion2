//
// Created by hrodic on 19/04/2026.
//
#include <cstring>
#include <iomanip>
#include "PunterosYPunteroGenericos.h"

void cargaDeLibros(void*& libros) {
    ifstream archLibros("Libros.csv",ios::in);
    void *bufferLibros[40],*libro;
    int cantLibros=0;
    while (LeerLineaLibros(libro,archLibros)) {
        bufferLibros[cantLibros]=libro;
        cantLibros++;
    }
    libros=new void*[cantLibros+1]{};
    void** regLibros=(void**)libros;
    for (int i=0;i<cantLibros;i++) regLibros[i]=bufferLibros[i];
}

bool LeerLineaLibros(void*& libro,ifstream& archLibros) {
    char *codLibro,*titulo,car;
    codLibro=LeerCadenaExacta(archLibros,',');
    if (codLibro) {
        int* stock=new int;
        double* precio=new double;
        titulo=LeerCadenaExacta(archLibros,',');
        archLibros.ignore(100,',');
        archLibros.ignore(20,',');
        archLibros>>*stock>>car>>*precio;
        archLibros.ignore();
        libro=new void*[4]{codLibro,titulo,stock,precio};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archLectura,char delim) {
    char buffer[200],*cadenaExacta;
    archLectura.getline(buffer,200,delim);
    if (archLectura.eof()) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void reporteDeLibros(const void* libros) {
    ofstream archReporteLibros("ReporteLibros.txt",ios::out);
    void** regLibros=(void**)libros;
    archReporteLibros<<fixed<<setprecision(2)<<setw(50)<<"LIBROS"<<endl;
    archReporteLibros<<left<<setw(10)<<"CODIGO"<<setw(40)<<"NOMBRE"<<setw(10)<<"STOCK"<<"PRECIO"<<endl;
    for (int i=0;regLibros[i];i++) {
        void** regLibro=(void**)regLibros[i];
        archReporteLibros<<left<<setw(10)<<(char*)(regLibro[0])<<setw(40)<<(char*)(regLibro[1]);
        archReporteLibros<<right<<setw(5)<<*(int*)(regLibro[2])<<setw(11)<<*(double*)(regLibro[3])<<endl;
    }
}

void cargaDeUsuarios(int*& carne,char*& tipo,char**& nombre) {
    ifstream archUsuarios("Usuarios.csv",ios::in);
    int cantUsuarios=0,capacidad=0;
    char *nombreUsuario,tipoUsuario;
    int carneUsuario;
    while (LeerLineaUsuarios(carneUsuario,tipoUsuario,nombreUsuario,archUsuarios)) {
        if (cantUsuarios==capacidad) {
            capacidad+=5;
            IncrementarMemoriaCarnes(carne,cantUsuarios,capacidad);
            IncrementarMemoriaTipos(tipo,cantUsuarios,capacidad);
            IncremenentarMemoriaNombres(nombre,cantUsuarios,capacidad);
        }
        carne[cantUsuarios]=carneUsuario;
        tipo[cantUsuarios]=tipoUsuario;
        nombre[cantUsuarios]=nombreUsuario;
        cantUsuarios++;
    }
}

bool LeerLineaUsuarios(int& carneUsuario,char& tipoUsuario,char*& nombreUsuario,ifstream& archUsuarios) {
    char car;
    if (archUsuarios>>carneUsuario) {
        archUsuarios>>tipoUsuario>>car;
        nombreUsuario=LeerCadenaExacta(archUsuarios,'\n');
        return true;
    }
    return false;
}

void IncrementarMemoriaCarnes(int*& carne,int cantUsuarios,int capacidad) {
    if (cantUsuarios==0) carne=new int[capacidad+1]{};
    else {
        int* aux=new int[capacidad+1]{};
        for (int i=0;i<cantUsuarios;i++) aux[i]=carne[i];
        delete[] carne;
        carne=aux;
    }
}

void IncrementarMemoriaTipos(char*& tipos,int cantUsuarios,int capacidad) {
    if (cantUsuarios==0) tipos=new char[capacidad+1]{};
    else {
        char* aux=new char[capacidad+1]{};
        for (int i=0;i<cantUsuarios;i++) aux[i]=tipos[i];
        delete[] tipos;
        tipos=aux;
    }
}

void IncremenentarMemoriaNombres(char**& nombre,int cantUsuarios,int capacidad) {
    if (cantUsuarios==0) nombre=new char*[capacidad+1]{};
    else {
        char** aux=new char*[capacidad+1]{};
        for (int i=0;i<cantUsuarios;i++) aux[i]=nombre[i];
        delete[] nombre;
        nombre=aux;
    }
}

void reporteDeUsuarios(const int* carne,const char* tipo,char** nombre) {
    ofstream archReporteUsuarios("ReporteUsuarios.txt",ios::out);
    archReporteUsuarios<<setw(50)<<"USUARIOS"<<endl;
    archReporteUsuarios<<left<<setw(12)<<"CARNE"<<setw(7)<<"TIPO"<<"NOMBRE"<<endl;
    for (int i=0;carne[i]!=0;i++) {
        archReporteUsuarios<<setw(12)<<carne[i]<<setw(7)<<tipo[i]<<nombre[i]<<endl;
    }
}

void reporteUsuariosInhabilitados(void* libros,int* carne,char* tipo,char** nombre) {
    int diaActual,mesActual,anioActual,fechaActual,cantDeudas=0;
    char car;
    void *deudas,*bufferDeudas[150],*deuda;
    ifstream archPrestamos("RegistroDePrestamos.csv",ios::in);
    cout<<"Ingrese la fecha actual: "<<endl;
    cin>>diaActual>>car>>mesActual>>car>>anioActual;
    fechaActual=diaActual+mesActual*30+anioActual*365;
    while (LeerLineaPrestamo(deuda,archPrestamos)) {
        void** regDeuda=(void**)deuda;
        char tipoUsuario=*(char*)(regDeuda[1]);
        int plazoMaximo=15*(tipoUsuario=='D')+7*(tipoUsuario=='E')+3*(tipoUsuario=='A')
        ,diasRetraso=fechaActual-(*(int*)((regDeuda[3])));
        if (diasRetraso-plazoMaximo>0) {
            bufferDeudas[cantDeudas]=deuda;
            cantDeudas++;
        }
        else DeletearDeuda(regDeuda);
    }
    deudas=new void*[cantDeudas+1]{};
    void** regDeudas=(void**)deudas;
    for (int i=0;i<cantDeudas;i++) regDeudas[i]=bufferDeudas[i];
    EmitirReporte(libros,carne,tipo,nombre,regDeudas,fechaActual);
}

bool LeerLineaPrestamo(void*& deuda,ifstream& archPrestamos) {
    int cod;
    if (archPrestamos>>cod) {
        int* codUsuario=new int(cod),*fechaPrestamo=new int,diaPrestamo,mesPrestamo,anioPrestamo;
        char *tipoUsuario=new char,*codLibro,car;
        archPrestamos>>*tipoUsuario>>car;
        codLibro=LeerCadenaExacta(archPrestamos,',');
        archPrestamos>>diaPrestamo>>car>>mesPrestamo>>car>>anioPrestamo;
        *fechaPrestamo=diaPrestamo+mesPrestamo*30+anioPrestamo*365;
        deuda=new void*[4]{codUsuario,tipoUsuario,codLibro,fechaPrestamo};
        return true;
    }
    return false;
}

void DeletearDeuda(void** regDeuda) {
    delete[] (int*)(regDeuda[0]);
    delete[] (char*)(regDeuda[1]);
    delete[] (char*)(regDeuda[2]);
    delete[] (int*)(regDeuda[3]);
    delete[] regDeuda;
}

void EmitirReporte(void* libros,int* carne,char* tipo,char** nombre,void** regDeudas,int fechaActual) {
    ofstream archRerporte("Reporte.txt",ios::out);
    int cantUsuariosDeudores=0;
    void** regLibros=(void**)libros;
    archRerporte<<fixed<<setprecision(2)<<setw(80)<<"USUARIOS DEUDORES"<<endl;
    archRerporte<<left<<setw(5)<<"No."<<setw(12)<<"CARNE"<<setw(40)<<"NOMBRE"<<setw(10)<<"TIPO";
    archRerporte<<setw(20)<<"COD. DE LIBRO"<<setw(30)<<"TITULO"<<setw(20)<<"DIAS DE RETRASO"<<"DEBE"<<endl;
    for (int i=0;carne[i]!=0;i++) {
        int cantLibrosAdeudadosUsuario=0;
        double deudaTotal=0;
        for (int j=0;regDeudas[j];j++) {
            void** regDeuda=(void**)(regDeudas[j]);
            int codUsuario=(*(int*)(regDeuda[0]));
            if (carne[i]==codUsuario) {
                cantLibrosAdeudadosUsuario++;
                if (cantLibrosAdeudadosUsuario==1) {
                    cantUsuariosDeudores++;
                    archRerporte<<right<<setw(2)<<cantUsuariosDeudores<<")  "<<left<<setw(12)<<carne[i];
                    archRerporte<<setw(40)<<nombre[i]<<setw(10)<<tipo[i];
                }
                ImprimirDeudaUsuario(regDeuda,regLibros,fechaActual,cantLibrosAdeudadosUsuario,deudaTotal
                    ,archRerporte);
            }
        }
        if (cantLibrosAdeudadosUsuario!=0) archRerporte<<setw(124)<<" "<<left<<setw(10)<<"Total:"<<deudaTotal<<endl;
    }
}

void ImprimirDeudaUsuario(void** regDeuda,void** regLibros,int fechaActual,int cantLibrosAdeudadosUsuario
    ,double& deudaTotal,ofstream& archRerporte) {
    char* codLibro=(char*)(regDeuda[2]);
    int posLibro=BuscarLibro(codLibro,regLibros);
    if (posLibro>=0) {
        void** regLibro=(void**)(regLibros[posLibro]);
        double precioLibro=(*(double*)(regLibro[3]));
        char tipoUsuario=(*(char*)(regDeuda[1]));
        int diasPosesion=fechaActual-(*(int*)(regDeuda[3]))
        ,plazoMaximo=15*(tipoUsuario=='D')+7*(tipoUsuario=='E')+3*(tipoUsuario=='A')
        ,diasRetraso=diasPosesion-plazoMaximo;
        double porcenPago=0.5*(tipoUsuario=='E')+0.75*(tipoUsuario=='A')+1.0*(tipoUsuario=='D')
        ,deudaLibro=diasRetraso*(porcenPago/100)*precioLibro;
        if (cantLibrosAdeudadosUsuario!=1) archRerporte<<setw(67)<<" ";
        archRerporte<<left<<setw(20)<<codLibro<<setw(30)<<(char*)(regLibro[1])<<right<<setw(7)<<diasRetraso;
        archRerporte<<setw(15)<<deudaLibro<<endl;
        deudaTotal+=deudaLibro;
    }
}

int BuscarLibro(const char* codLibro,void** regLibros) {
    for (int i=0;regLibros[i];i++) {
        void** regLibro=(void**)(regLibros[i]);
        if (strcmp(codLibro,(char*)(regLibro[0]))==0) return i;
    }
    return -1;
}