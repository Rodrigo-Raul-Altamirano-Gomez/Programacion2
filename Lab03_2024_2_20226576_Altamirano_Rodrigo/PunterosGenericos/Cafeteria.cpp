//
// Created by hrodic on 22/04/2026.
//
#include <cstring>
#include <iomanip>
#include "Cafeteria.h"

void cargarInventario(const char* nombreArchivo,void*& inventario) {
    ifstream archInventario(nombreArchivo,ios::in);
    void *bufferInventario[buffer],*insumoInventario;
    int cantInventario=0;
    while (LeerLineaInventario(insumoInventario,archInventario)) {
        bufferInventario[cantInventario]=insumoInventario;
        cantInventario++;
    }
    inventario=new void*[cantInventario+1]{};
    void** regInventario=(void**)inventario;
    for (int i=0;i<cantInventario;i++) regInventario[i]=bufferInventario[i];
}

bool LeerLineaInventario(void*& insumoInventario,ifstream& archInsumos) {
    char *codInsumo,car;
    codInsumo=LeerCadenaExacta(archInsumos,',');
    if (codInsumo) {
        double* cantDisponible=new double,*cantRequerida=new double(0);
        char* nombreInsumo=LeerCadenaExacta(archInsumos,',');
        archInsumos>>*cantDisponible>>car;
        char* unidadMedida=LeerCadenaExacta(archInsumos,'\n');
        insumoInventario=new void*[invNumCampos]{codInsumo,nombreInsumo,cantDisponible,cantRequerida,unidadMedida};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archLectura,char delim) {
    char *cadenaExacta,bufferCadena[buffer];
    archLectura.getline(bufferCadena,buffer,delim);
    if (archLectura.eof()) return nullptr;
    cadenaExacta=new char[strlen(bufferCadena)+1];
    strcpy(cadenaExacta,bufferCadena);
    return cadenaExacta;
}

void cargarMenu(const char* nombreArchivo,void*& menu) {
    ifstream archMenu(nombreArchivo,ios::in);
    void *bufferMenu[buffer],*bebidaMenu;
    int cantMenus=0;
    while (LeerLineaMenu(bebidaMenu,archMenu)) {
        bufferMenu[cantMenus]=bebidaMenu;
        cantMenus++;
    }
    menu=new void*[cantMenus+1]{};
    void** regMenu=(void**)menu ;
    for (int i=0;i<cantMenus;i++) regMenu[i]=bufferMenu[i];
}

bool LeerLineaMenu(void*& bebidaMenu,ifstream& archMenu) {
    char* codBebida=LeerCadenaExacta(archMenu,',');
    if (codBebida) {
        char car,*tipoBebida=new char;
        double* precioBebida=new double;
        int* cantVentasEstBebida=new int;
        bool* disponibiladBebida=new bool(true);
        char* nombreBebida=LeerCadenaExacta(archMenu,',');
        char* descripcionBebida=LeerCadenaExacta(archMenu,',');
        archMenu>>*tipoBebida>>car>>*precioBebida>>car>>*cantVentasEstBebida;
        archMenu.ignore();
        bebidaMenu=new void*[bebNumCampos]{codBebida,nombreBebida,descripcionBebida,tipoBebida,disponibiladBebida
            ,precioBebida,cantVentasEstBebida,nullptr};
        return true;
    }
    return false;
}

void actualizarMenu(const char* nombreArchivo,void* inventario,void* menu) {
    ifstream archInsumosBebidas(nombreArchivo,ios::in);
    char codBebida[5],codInsumo[5],unidadMedida;
    double cantidad;
    while (LeerLineaInsumosBebidas(codBebida,codInsumo,cantidad,unidadMedida,archInsumosBebidas)) {
        void** regBebida=(void**)BuscarBebidaOInsumo(codBebida,menu);
        void** regInsumo=(void**)BuscarBebidaOInsumo(codInsumo,inventario);
        if (regBebida and regInsumo) {
            AñadirInsumoALaBebida(cantidad,unidadMedida,regInsumo,regBebida[bebInsumoInv]);
            double* cantRequeridaInsumo=(double*)(regInsumo[invCantRequerida]);
            *cantRequeridaInsumo+=(cantidad/1000)*(*(int*)(regBebida[bebCantVent]));
            if (*cantRequeridaInsumo>*(double*)(regInsumo[invCantDisponible])) *(bool*)(regBebida[bebDisponible])=false;
        }
    }
}

bool LeerLineaInsumosBebidas(char* codBebida,char* codInsumo,double& cantidad,char& unidadMedida
    ,ifstream& archInsumosBebidas) {
    archInsumosBebidas.getline(codBebida,buffer,',');
    if (archInsumosBebidas) {
        char car;
        archInsumosBebidas.getline(codInsumo,buffer,',');
        archInsumosBebidas>>cantidad>>car>>unidadMedida;
        archInsumosBebidas.ignore();
        return true;
    }
    return false;
}

void* BuscarBebidaOInsumo(const char* codBebidaOInsumo,void* menuOInventario) {
    void** regBebidasOInventario=(void**)menuOInventario;
    for (int i=0;regBebidasOInventario[i];i++) {
        void** regBebidaOInsumo=(void**)(regBebidasOInventario[i]);
        if (strcmp(codBebidaOInsumo,(char*)(regBebidaOInsumo[bebCodigo+invCodigo]))==0) return regBebidasOInventario[i];
    }
    return nullptr;
}

void AñadirInsumoALaBebida(double cantidad,char unidadMedida,void* insumoInventario,void*& insumosBebida) {
    double* cantidadInsumo=new double(cantidad);
    char* unidadMedidaInsumo=new char(unidadMedida);
    void* insumoBebida=new void*[insNumCapos]{insumoInventario,cantidadInsumo,unidadMedidaInsumo};
    int cantInsumosBebida=0;
    if (not insumosBebida) insumosBebida=new void*[2]{insumoBebida,nullptr};
    else {
        void** regInsumosBebida=(void**)insumosBebida;
        for (int i=0;regInsumosBebida[i];i++) cantInsumosBebida++;
        void** aux=new void*[cantInsumosBebida+2]{};
        for (int i=0;i<cantInsumosBebida;i++)  aux[i]=regInsumosBebida[i];
        aux[cantInsumosBebida]=insumoBebida;
        delete[] regInsumosBebida;
        insumosBebida=aux;
    }
}

void  reporteMenu(const char* nombreArchivo,void* menu) {
    ofstream archReporte(nombreArchivo,ios::out);
    void** regMenu=(void**)menu;
    archReporte<<fixed<<setprecision(2)<<setfill('=')<<setw(40)<<" "<<setfill(' ')<<" Menu del dia ";
    archReporte<<setfill('=')<<setw(40)<<" "<<setfill(' ')<<endl;
    for (int i=0;regMenu[i];i++) {
        void** regBebida=(void**)(regMenu[i]);
        archReporte<<ObtenerTipoBebida(*(char*)(regBebida[bebTipo]))<<": "<<(char*)(regBebida[bebNombre])<<endl;
        archReporte<<(char*)(regBebida[bebDescripcion])<<endl;
        archReporte<<"Precio: S/ "<<*(double*)(regBebida[bebPrecio])<<endl;
        archReporte<<"Disponible: ";
        *(bool*)(regBebida[bebDisponible]) ? archReporte<<"Si"<<endl:archReporte<<"No"<<endl;
        archReporte<<setfill('-')<<setw(90)<<" "<<setfill(' ')<<endl;
    }
}

const char* ObtenerTipoBebida(char tipoBebida) {
    switch (tipoBebida) {
        case 'C': return "Cafe";
        case 'T': return "Te";
        case 'I': return "Infusion";
        case 'H': return "Chocolate";
    }
}