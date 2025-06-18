#include <iostream>
#include <cstring>
#include "ArchivoCobro.h"
#include "Cobro.h"
using namespace std;






ArchivoCobro::ArchivoCobro(const char* nombre){
    strcpy(_nombre, nombre);
}

int ArchivoCobro::agregarRegistro(Cobro cobro){
    FILE *pCobro;
    pCobro = fopen(_nombre, "ab");
    if(pCobro==nullptr){
        cout<<"Error de archivo"<<endl;
        return -1;
    }
    int escribio = fwrite(&cobro, sizeof(Cobro), 1, pCobro);
    fclose(pCobro);
    return escribio;
}

Cobro ArchivoCobro::Leer(int pos){
        FILE *pCobro;
        Cobro cobro;
        pCobro = fopen(_nombre, "rb");
        if(pCobro==nullptr){
            cout<<"Error de archivo"<<endl;
            cobro.setIdCobro(-1);
            return cobro;
        }

        fseek(pCobro, sizeof(Cobro)* pos, 0);
        fread(&cobro, sizeof(Cobro),1,pCobro);

        fclose(pCobro);
        return cobro;
}

int ArchivoCobro::getCantidadRegistros(){
    int cantidad, total;
    FILE *pCobro;

    pCobro = fopen(_nombre, "rb");
    if(pCobro==nullptr){
        cout<<"Error de archivo"<<endl;
        return -1;
    }
    fseek(pCobro,0,SEEK_END);
    cantidad = total / sizeof(Cobro);
    fclose(pCobro);
    return cantidad;
}


