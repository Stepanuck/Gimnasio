#include <iostream>
#include <cstring>
#include "Actividad.h"
#include "ArchivoActividad.h"

using namespace std;

    ArchivoActividad::ArchivoActividad(){

        strcpy(_nombre, "Actividad.dat");
    }

    ArchivoActividad::ArchivoActividad(const char* nombreArchivo= "Actividad.dat"){

        strcpy(_nombre,nombreArchivo);

    }

    int ArchivoActividad::agregarRegistro(Actividad act){
        FILE *pActividad;
        pActividad = fopen(_nombre, "ab");
        if(pActividad == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&act, sizeof(Actividad),1,pActividad);
        fclose(pActividad);
        return escribio;
    }

    Actividad ArchivoActividad::leer(int pos){
        FILE *pActividad;
        Actividad act;
        pActividad = fopen(_nombre, "rb");
        ///act.setIdActividad(-1);///
        if(pActividad==nullptr){
            cout<<"Error de archivo"<<endl;
            return act;
        }
        fseek(pActividad, sizeof(Actividad)* pos, SEEK_SET);
        fread(&act, sizeof(Actividad),1, pActividad);
        fclose(pActividad);
        return act;
    }

    int ArchivoActividad::getCantidadRegistros(){
        int total, cantidad;
        FILE* pActividad ;

        pActividad = fopen(_nombre, "rb");
        if(pActividad==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pActividad , 0, SEEK_END);
        total = ftell(pActividad );
        cantidad = total / sizeof(Actividad);
        fclose(pActividad);
        return cantidad;
    }

    int ArchivoActividad::modificarActividad(Actividad act, int pos){
        FILE* pActividad;
        pActividad = fopen(_nombre, "rb+");
        if(pActividad == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }

        fseek(pActividad , pos*sizeof(Actividad), SEEK_SET);
        int escribio = fwrite(&act, sizeof(Actividad), 1, pActividad);
        fclose(pActividad);
        return escribio;
    }

    int ArchivoActividad::buscarActividad(int idActividad){
        Actividad act;
        FILE* pActividad;
        pActividad = fopen(_nombre, "rb");
        if(pActividad == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&act, sizeof(Actividad),1,pActividad)==1){
            if(act.getIdActividad() == idActividad){
                fclose(pActividad);
                return pos;
            }
            pos++;
        }
        fclose(pActividad);
        return -1;
    }




