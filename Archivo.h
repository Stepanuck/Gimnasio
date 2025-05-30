#pragma once
#include <cstring>




class Archivo{

protected:
    char _nombre[30];
    int _tamanio;

 public:

    Archivo(const char* nombre, int tamanio);
 int contarRegistros();
 void setNombre(const char* nombre);
 const char* getNombre();


};
