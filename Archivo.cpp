#include <iostream>
#include "Archivo.h"



  Archivo::Archivo(const char* nombre, int tamanio){
    setNombre(nombre);
    _tamanio = tamanio;
  }
 int Archivo::contarRegistros(){
    FILE *pArchivo;
    pArchivo= fopen(_nombre, "rb");
    if(pArchivo==nullptr){
        cout<<"Error de archivo"<<endl;
        return -1;
    }
    fseek(pArchivo,0,SEEK_END);
    int tam = ftell(pArchivo);
    fclose(pArchivo);
    int cantReg;
    cantReg = tam/_tamanio;
    return cantReg;
 }
 void Archivo::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
 }
 const char* Archivo::getNombre(){
    return _nombre;
 }
