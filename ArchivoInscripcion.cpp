#include <iostream>
#include <cstring>
#include "Inscripcion.h"
#include "ArchivoInscripcion.h"

using namespace std;


ArchivoInscripcion::ArchivoInscripcion(const char* nombreArchivo) {
    strcpy(_nombre, nombreArchivo);
}


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
       // insc.setIdInscripcion(-1);
        pInscripcion = fopen(_nombre, "rb");

        if(pInscripcion == nullptr){
           // cout<<"Error de archivo"<<endl;
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
           // cout<<"Error de archivo"<<endl;
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


    int ArchivoInscripcion::buscarInscripcion(int idInscripcion){
        Inscripcion insc;
        FILE* pInscripcion;
        pInscripcion= fopen(_nombre, "rb");
        if(pInscripcion == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&insc, sizeof(Inscripcion),1,pInscripcion)==1){
            if(insc.getIdInscripcion()==idInscripcion){
                fclose(pInscripcion);
                return pos;
            }
            pos++;
        }
        fclose(pInscripcion);
        return -1;
    }
















