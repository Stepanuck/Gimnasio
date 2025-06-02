#include <iostream>
#include <cstring>
#include "Socio.h"
#include "Archivo.h"
#include "ArchivoSocio.h"

/*
    ArchivoSocio::ArchivoSocio(const char* nombre = "Socios.dat")
    : Archivo (nombre, sizeof(Socio)){}

    int ArchivoSocio::agregarRegistro(Socio soc){
        FILE *pSocio;
        pSocio = fopen(_nombre, "ab");
       if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&soc, _tamanio, 1, pSocio);
        fclose(pSocio);
        return escribio;
    }
    Socio ArchivoSocio::Leer(int pos){
       Socio soc;
    FILE *pSocio;
    pSocio=fopen(_nombre,"rb");
    soc.setDni("-1");
    if(pSocio==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return soc;
    }

    fseek(pSocio, pos*_tamanio,0);
    fread(&soc, _tamanio, 1, pSocio);

    fclose(pSocio);
    return soc;
    }
    int modificarSocio(Socio soc, int pos){
        FILE *pSocio;
        pSocio=fopen(_nombre,"rb+");
        if(pSocio ==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }

    fseek(pSocio, pos*_tamanio, 0);
    int escribio = fwrite(&soc, _tamanio, 1, pSocio);
        fclose(pSocio);
        return escribio;
    }
    int ArchivoSocio::BuscarSocio(const char* dniSocio){
        Socio soc;
        FILE *pSocio;
        pSocio = fopen(_nombre, "rb");
        if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }

        int pos = 0;
        while(fread(&soc, _tamanio, 1, pSocio)==1){
            if(strcmp(soc.getDni(), dniSocio)==0){
                return pos;
            }
            pos++;
        }
        fclose (pSocio);
        return -1;
    }
    bool ArchivoSocio::bajaLogica(const char* dni);
    bool ArchivoSocio::altaLogica(const char* dni);

*/
