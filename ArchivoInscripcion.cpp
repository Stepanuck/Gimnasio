/*#include <iostream>
#include <cstring>
#include "Inscripcion.h"
#include "ArchivoInscripcion.h"

using namespace std;



    int ArchivoInscripcion::agregarRegistro(Inscripcion insc){
        FILE* pInscripcion;
        pInscripcion = fopen(_nombre, "ab");
        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&insc, sizeof(Inscripcion), 1, pInscripcion);
        fclose(pInscripcion);
        return escribio;
    }

    Inscripcion ArchivoInscripcion::Leer(int pos){
        FILE* pInscripcion;
        Inscripcion insc;
        insc.setIdInscripcion(-1);
        pInscripcion = fopen(_nombre, "rb");

        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return insc;
        }
        fseek(pInscripcion, sizeof(Inscripcion)*pos, SEEK_SET);
        fread(&insc, sizeof(Inscripcion), 1, pInscripcion);
        fclose(pInscripcion);
        return insc;
    }

    int ArchivoInscripcion::getCantidadRegistros(){
        int total, cantidad;
        FILE* pInscripcion;
        pInscripcion = fopen(_nombre, "rb");
        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pInscripcion, 0, SEEK_END);
        total = ftell(pInscripcion);
        cantidad = total / sizeof(Inscripcion);
        fclose(pInscripcion);
        return cantidad;
    }

    int ArchivoInscripcion::modificarInscripcion(Inscripcion insc, int pos){
        FILE* pInscripcion;
        pInscripcion = fopen(_nombre, "rb+");
        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pInscripcion, pos*sizeof(Inscripcion), SEEK_SET);
        int escribio = fwrite(&insc, sizeof(Inscripcion),1,pInscripcion);
        fclose(pInscripcion);
        return escribio;
    }


    int ArchivoInscripcion::buscarInscripcion(int idincripcion){
        Inscripcion insc;
        FILE* pInscripcion;
        pInscripcion= fopen(_nombre, "rb");
        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&insc, sizeof(Inscripcion),1,pInscripcion)==1){
            if(insc.getIdInscripcion()==idincripcion){
                fclose(pInscripcion);
                return pos;
            }
            pos++;
        }
        fclose(pInscripcion);
        return -1;
    }


    bool ArchivoInscripcion::altaLogica(int idInscripcion){
        Inscripcion insc;
        ArchivoInscripcion archiv;
        int pos = archiv.buscarInscripcion(idInscripcion);
        if(pos==-1)return false;
        insc=archiv.Leer(pos);
        insc.setEstado(true);
        return archiv.modificarInscripcion(insc, pos);
    }

    bool ArchivoInscripcion::bajaLogica(int idInscripcion){
        Inscripcion insc;
        ArchivoInscripcion archiv;
        int pos = archiv.buscarInscripcion(idInscripcion);
        if(pos==-1) return false;
        insc=archiv.Leer(pos);
        insc.setEstado(false);
        return archiv.modificarInscripcion(insc, pos);
    }

*/
















