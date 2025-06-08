/*#include <iostream>
#include <cstring>
#include "Tutor.h"
#include "ArchivoTutor.h"

using namespace std;




    int ArchivoTutor::agregarRegistro(Tutor tut){
        FILE *pTutor;
        pTutor = fopen(_nombre, "ab");
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&tut, sizeof(Tutor),1,pTutor);
        fclose(pTutor);
        return escribio;
    }

    Tutor ArchivoTutor::Leer(int pos){
        FILE *pTutor;
        Tutor tut;
        pTutor = fopen(_nombre, "rb");
        if(pTutor==nullptr){
            cout<<"Error de archivo"<<endl;
            tut.setDni("-1");///
            return tut;
        }
        fseek(pTutor, sizeof(Tutor)* pos, SEEK_SET);
        fread(&tut, sizeof(Tutor),1, pTutor);
        fclose(pTutor);
        return tut;
    }

    int ArchivoTutor::getCantidadRegistros(){
        int total, cantidad;
        FILE* pTutor;

        pTutor = fopen(_nombre, "rb");

        if(pTutor ==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pTutor, 0, SEEK_END);

        total = ftell(pTutor);
        cantidad = total / sizeof(Tutor);
        fclose(pTutor);
        return cantidad;
    }

    int ArchivoTutor::modificarTutor(Tutor tut, int pos){
        FILE* pTutor;
        pTutor = fopen(_nombre, "rb+");
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }

        fseek(pTutor, pos*sizeof(Tutor), SEEK_SET);
        int escribio = fwrite(&tut, sizeof(Tutor), 1, pTutor);
        fclose(pTutor);
        return escribio;
    }

    int ArchivoTutor::buscarTutor(const char* dniTutor){
        Tutor tut;
        FILE* pTutor;
        pTutor = fopen(_nombre, "rb");
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&tut, sizeof(Tutor),1,pTutor)==1){
            if(strcmp(tut.getDni(),dniTutor)==0){
                fclose(pTutor);
                return pos;
            }
            pos++;
        }
        fclose(pTutor);
        return -1;
    }

    bool ArchivoTutor::altaLogica(const char* dni){
        Tutor tut;
        ArchivoTutor archiv;
        int pos = archiv.buscarTutor(dni);
        if(pos==-1)return false;
        tut=archiv.Leer(pos);
        tut.setEstado(true);
        return archiv.modificarTutor(tut, pos);
    }

    bool ArchivoTutor::bajaLogica(const char* dni){
        Tutor tut;
        ArchivoTutor archiv;
        int pos = archiv.buscarTutor(dni);
        if(pos==-1) return false;
        tut=archiv.Leer(pos);
        tut.setEstado(false);
        return archiv.modificarTutor(tut, pos);
    }

*/






