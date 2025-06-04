#include <iostream>
#include <cstring>
#include "Actividad.h"
#include "ArchivoActividad.h"

using namespace std;




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
        act.setIdActividad(-1);///
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

    bool ArchivoActividad::altaLogica(int idActividad){
        Actividad act;
        ArchivoActividad archiv;
        int pos = archiv.buscarActividad(idActividad);
        if(pos==-1)return false;
        act=archiv.leer(pos);
        act.setEstado(true);
        return archiv.modificarActividad(act, pos);
    }

    bool ArchivoActividad::bajaLogica(int idActividad){
        Actividad act;
        ArchivoActividad archiv;
        int pos = archiv.buscarActividad(idActividad);
        if(pos==-1) return false;
        act=archiv.leer(pos);
        act.setEstado(false);
        return archiv.modificarActividad(act, pos);
    }






