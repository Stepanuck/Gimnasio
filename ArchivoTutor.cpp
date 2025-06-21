#include <iostream>
#include <cstring>
#include "Tutor.h"
#include "ArchivoTutor.h"

using namespace std;


        ArchivoTutor::ArchivoTutor(const char* nombreArchivo){
            strcpy(_nombre, nombreArchivo);
        }

    int ArchivoTutor::agregarRegistro(Tutor tut){
        FILE *pTutor;
        pTutor = fopen(_nombre, "ab");//Abrimos el archivo, si no existe lo crea
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&tut, sizeof(Tutor),1,pTutor);// si pudo abrir el archivo, lo escribe
        fclose(pTutor);// cerramos el archivo
        return escribio; //devolucion si escribio
    }

    Tutor ArchivoTutor::Leer(int pos){
        FILE *pTutor;
        Tutor tut;
        pTutor = fopen(_nombre, "rb");//abrimos el archivo
        if(pTutor==nullptr){
            cout<<"Error de archivo"<<endl;
            tut.setDni("-1");///si falla la lectura devuelve error y setea un tutor con dni-1
            return tut;// lo devuelve
        }
        // si pudo abrirlo, se mueve a la posicion
        fseek(pTutor, sizeof(Tutor)* pos, SEEK_SET);
        fread(&tut, sizeof(Tutor),1, pTutor); // lee el registro
        fclose(pTutor);//cerramos el archivo
        return tut;// lo devuelve
    }
        bool ArchivoTutor::listarRegistrosActivos(){
            Tutor tut;
            FILE *pTutor;
            pTutor = fopen (_nombre, "rb"); //abrimos el archivo
            if(pTutor ==nullptr){
                cout<<"Error de archivo"<<endl;
                return false; //si no existe tira error y retorna false
            }
            while(fread(&tut, sizeof(Tutor),1,pTutor)==1){
                if(tut.getEstado()){
                    tut.mostrar();
                }
            }
            fclose(pTutor);
            return true;
        }
         bool ArchivoTutor::listarTodosLosRegistros(){
            Tutor tut;
            FILE *pTutor;
            pTutor = fopen (_nombre, "rb"); //abrimos el archivo
            if(pTutor ==nullptr){
                cout<<"Error de archivo"<<endl;
                return false; //si no existe tira error y retorna false
            }
            while(fread(&tut,sizeof(Tutor), 1, pTutor)==1){

                tut.mostrar();  //Condicion el estado, si devuelve true es activo, si devuelve false es inactivo.
            cout<<"Estado: "<<(tut.getEstado()? "Activo" : "Inactivo")<<endl;
            cout<<"-------------------------------"<<endl;//lineas facheras
        }
            fclose(pTutor);//cerramos el archivo
            return true;
        }

        bool ArchivoTutor::listarRegistrosInactivos(){
            Tutor tut;
            FILE *pTutor = fopen(_nombre, "rb");//abrimos el archivo
            if(pTutor == nullptr){
                cout<<"Error de archivo"<<endl;
                return false;
            }
            bool hayInactivos = false;//seteamos en falso por si no hay inactivos.

        while (fread(&tut, sizeof(Tutor),1,pTutor)==1){//recorremos el archivo
            if(!tut.getEstado()){//vemos si el estado es distinto de true
                tut.mostrar();//si lo es lo muestro porque esta inactivo
                hayInactivos= true;//mi bandera la vuelvo true porque encontre inactivos
            }
        }
        fclose(pTutor);//cierro el archivo

        if(!hayInactivos){//si es distinto es false y no hay inactivos
        cout<<"No hay Tutores inactivos."<<endl;
        }
        return hayInactivos;//retorna el valor de bandera
        }
    int ArchivoTutor::getCantidadRegistros(){
        int total, cantidad;
        FILE* pTutor;

        pTutor = fopen(_nombre, "rb");

        if(pTutor ==nullptr){
            cout<<"Error de archivo"<<endl;//abre el archivo
            return -1;
        }
        fseek(pTutor, 0, SEEK_END);//nos movemos al final del archiov

        total = ftell(pTutor);//con el ftell, me devuelve el tamaño total del archivo
        cantidad = total / sizeof(Tutor);// con el tamaño del objeto lo divimos por el total
        //y me da la cantidad total de registros
        fclose(pTutor);
        return cantidad;
    }

    int ArchivoTutor::modificarTutor(Tutor tut, int pos){
        FILE* pTutor;
        pTutor = fopen(_nombre, "rb+");//abrimos el archivo en lectura y escritura
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;//si el archivo no existe retorna -1
        }

        fseek(pTutor, pos*sizeof(Tutor), SEEK_SET); //movemos la posicion que queremos
        int escribio = fwrite(&tut, sizeof(Tutor), 1, pTutor);//escribimos encima del registro
        fclose(pTutor);//cerramos el archivo
        return escribio;//devuelve si escribio
    }

    int ArchivoTutor::buscarTutor(const char* dniTutor){
        Tutor tut;
        FILE* pTutor;
        pTutor = fopen(_nombre, "rb");//abrimos el archivo
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;//si el archivo no se abre devuelve -2
        }
        int pos = 0;//inicializamos el contador de la posicion en 0
        while(fread(&tut, sizeof(Tutor),1,pTutor)==1){//leemos socio por socio
            if(strcmp(tut.getDni(),dniTutor)==0){//comparamos el dni buscado con el dni del socio
                fclose(pTutor);
                return pos;// si coincide cierra el archivo y retorna la posicion
            }
            pos++;//si no lo encontramos incrementa el contador
        }
        fclose(pTutor);
        return -1;//si no lo encuentra devuelve -1
    }

    int ArchivoTutor::buscarTutor(int idTutor){
        Tutor tut;
        FILE* pTutor;
        pTutor = fopen(_nombre, "rb");
        if(pTutor == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;
        }
        int pos = 0;
        while(fread(&tut, sizeof(Tutor),1,pTutor)==1){
            if(tut.getIDTutor() == idTutor){
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








