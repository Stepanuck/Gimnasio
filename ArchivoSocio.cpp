#include <iostream>
#include <cstring>
#include "Socio.h"
#include "ArchivoSocio.h"
    using namespace std;



    ArchivoSocio::ArchivoSocio(const char* nombreArchivo) {
    strcpy(_nombre, nombreArchivo);
}
    int ArchivoSocio::agregarRegistro(Socio soc){
        FILE *pSocio;
        pSocio = fopen(_nombre, "ab");
       if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&soc, sizeof(Socio), 1, pSocio);
        fclose(pSocio);
        return escribio;
    }

    Socio ArchivoSocio::Leer(int pos){
        FILE *pSocio;
       Socio soc;
    pSocio=fopen(_nombre,"rb");
    soc.setDni("-1");
    if(pSocio==nullptr){  ///NULL
      cout<<"ERROR DE ARCHIVO"<<endl;
        return soc;
    }

    fseek(pSocio, sizeof(Socio)* pos,0);
    fread(&soc, sizeof(Socio), 1, pSocio);

    fclose(pSocio);
    return soc;
    }

    bool ArchivoSocio::listarRegistrosActivos(){
        Socio soc;
        FILE *pSocio;
        pSocio = fopen(_nombre, "rb");
        if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return false;
        }
        while(fread(&soc, sizeof(Socio),1,pSocio)==1){
            if(soc.getEstado()){
                soc.mostrar();
            }
        }
        fclose(pSocio);
        return true;
    }
    bool ArchivoSocio::listarTodosLosRegistros(){
        Socio soc;
        FILE *pSocio = fopen(_nombre, "rb");
        if(pSocio==nullptr){
            cout<<"Error de archivo"<<endl;
            return false;
        }
        while(fread(&soc,sizeof(Socio), 1, pSocio)==1){
            soc.mostrar();
            cout<<"Estado: "<<(soc.getEstado()? "Activo" : "Inactivo")<<endl;
            cout<<"-------------------------------"<<endl;
        }
        fclose(pSocio);
        return true;
    }

    bool ArchivoSocio::listarRegistrosInactivos(){
        Socio soc;
        FILE *pSocio = fopen(_nombre, "rb");

        if(pSocio==nullptr){
            cout<<"Error de archivo"<<endl;
            return false;
        }

        bool hayInactivos = true;

        while (fread(&soc, sizeof(Socio),1,pSocio)==1){
            if(!soc.getEstado()){
                soc.mostrar();
                hayInactivos= true;
            }
        }
        fclose(pSocio);

        if(!hayInactivos){
        cout<<"No hay socios inactivos."<<endl;
        }
        return hayInactivos;
    }
    int ArchivoSocio::getCantidadRegistros(){
        int  total, cantidad;
        FILE* pSocio;

        pSocio = fopen(_nombre, "rb");

        if(pSocio==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pSocio, 0, SEEK_END);

        total = ftell(pSocio);
        cantidad = total / sizeof(Socio);
        fclose(pSocio);
        return cantidad;
    }

    int ArchivoSocio::modificarSocio(Socio soc, int pos){
        FILE *pSocio;
        pSocio=fopen(_nombre,"rb+");
        if(pSocio ==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }

    fseek(pSocio, pos*sizeof(Socio), SEEK_SET);
    int escribio = fwrite(&soc, sizeof(Socio), 1, pSocio);
        fclose(pSocio);
        return escribio;
    }

    int ArchivoSocio::buscarSocio(const char* dniSocio){
        Socio soc;
        FILE *pSocio;
        pSocio = fopen(_nombre, "rb");
        if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }

        int pos = 0;
        while(fread(&soc, sizeof(Socio), 1, pSocio)==1){
            if(strcmp(soc.getDni(), dniSocio)==0){
                return pos;
            }
            pos++;
        }
        fclose (pSocio);
        return -1;
    }
    bool ArchivoSocio::altaLogica(const char* dni){
        Socio soc;
        ArchivoSocio archiv;
        int pos = archiv.buscarSocio(dni);
        if(pos==-1) return false;
        soc = archiv.Leer(pos);
        soc.setEstado(true);
        return archiv.modificarSocio(soc, pos);
    }
    bool ArchivoSocio::bajaLogica(const char* dni){
        Socio soc;
        ArchivoSocio archiv;
        int pos = archiv.buscarSocio(dni);
        if(pos==-1) return false;
        soc=archiv.Leer(pos);
        soc.setEstado(false);
        return archiv.modificarSocio(soc, pos);
    }


