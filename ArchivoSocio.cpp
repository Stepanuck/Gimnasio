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
        pSocio = fopen(_nombre, "ab");//abrimos el archivo, si no existe lo crea
       if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        int escribio = fwrite(&soc, sizeof(Socio), 1, pSocio);//Si pudo abrir el archivo, lo crea.
        fclose(pSocio);//cerramos el archivo
        return escribio;//devolucion si escribio
    }

    Socio ArchivoSocio::Leer(int pos){
        FILE *pSocio;
       Socio soc;
    pSocio=fopen(_nombre,"rb");//abrimos el archivo
    if(pSocio==nullptr){  ///NULL
      cout<<"ERROR DE ARCHIVO"<<endl;
        soc.setDni("-1");//Si falla la lecturam devuelve error y se setea un socio con dni invalido
        return soc;//lo devuelve
    }
    // si pudo abrirlo, se mueve a la posicion
    fseek(pSocio, sizeof(Socio)* pos,0);
    fread(&soc, sizeof(Socio), 1, pSocio);//lee el registro

    fclose(pSocio);//cerramos el archivo
    return soc;//devuelve el socio
    }

    bool ArchivoSocio::listarRegistrosActivos(){
        Socio soc;
        FILE *pSocio;
        pSocio = fopen(_nombre, "rb");//abrimos el archivo
        if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return false;//Si no existe tira error y retorna false
        }
        while(fread(&soc, sizeof(Socio),1,pSocio)==1){//si existe el archivo lee socio por socio
            if(soc.getEstado()){//revisamos que el estado este true de activo.
                soc.mostrar();//lo mostramos
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
        }//Mas lo mismo que arriba pero aca vemos todos y con el operador ternario, le ponemos el estado
        while(fread(&soc,sizeof(Socio), 1, pSocio)==1){
            soc.mostrar();  //Condicion el estado, si devuelve true es activo, si devuelve false es inactivo.
            cout<<"Estado: "<<(soc.getEstado()? "Activo" : "Inactivo")<<endl;
            cout<<"-------------------------------"<<endl;//lineas facheras
        }
        fclose(pSocio);//cerramos el archivo
        return true;
    }

    bool ArchivoSocio::listarRegistrosInactivos(){
        Socio soc;
        FILE *pSocio = fopen(_nombre, "rb");//abrimos el archivo

        if(pSocio==nullptr){
            cout<<"Error de archivo"<<endl;//error si no existe
            return false;
        }

        bool hayInactivos = false;//seteamos en falso por si no hay inactivos.

        while (fread(&soc, sizeof(Socio),1,pSocio)==1){//recorremos el archivo
            if(!soc.getEstado()){//vemos si el estado es distinto de true
                soc.mostrar();//si lo es lo muestro porque esta inactivo
                hayInactivos= true;//mi bandera la vuelvo true porque encontre inactivos
            }
        }
        fclose(pSocio);//cierro el archivo

        if(!hayInactivos){//si es distinto es false y no hay inactivos
        cout<<"No hay socios inactivos."<<endl;
        }
        return hayInactivos;//retorna el valor de bandera
    }
    int ArchivoSocio::getCantidadRegistros(){
        int  total, cantidad;
        FILE* pSocio;

        pSocio = fopen(_nombre, "rb");//abre el archivo

        if(pSocio==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;
        }
        fseek(pSocio, 0, SEEK_END);//nos movemos al final del archivo

        total = ftell(pSocio);// con el ftell me devuelve el tamaño total del archivo
        cantidad = total / sizeof(Socio); //con el tamaño del objeto lo divimios por el total que me da ftell
        //y me da la cantidad total de registros
        fclose(pSocio);
        return cantidad;
    }

    int ArchivoSocio::modificarSocio(Socio soc, int pos){
        FILE *pSocio;
        pSocio=fopen(_nombre,"rb+");//abrimos el archivo en lectura y escritura
        if(pSocio ==nullptr){
            cout<<"Error de archivo"<<endl;
            return -1;//si el archivo no existe retorna -1
        }

    fseek(pSocio, pos*sizeof(Socio), SEEK_SET);//movemos a la posicion que queremos
    int escribio = fwrite(&soc, sizeof(Socio), 1, pSocio);//escribimos encima del registro
        fclose(pSocio);//cerramos el archivo
        return escribio;//devuelve si escribio
    }

    int ArchivoSocio::buscarSocio(const char* dniSocio){
        Socio soc;
        FILE *pSocio;
        pSocio = fopen(_nombre, "rb");//abrimos el archiov
        if(pSocio == nullptr){
            cout<<"Error de archivo"<<endl;
            return -2;// si el archivo no se abre devuelve -2
        }

        int pos = 0;//inicializamos el contador de la posicion en 0
        while(fread(&soc, sizeof(Socio), 1, pSocio)==1){//leemos socio por socio
            if(strcmp(soc.getDni(), dniSocio)==0){//comparamos el dni buscado con el dni del socio
                fclose(pSocio);
                return pos;//si coincide cierra el archivo y retorna la posicion
            }
            pos++;//si no lo encontramos incrementa el contador
        }
        fclose (pSocio);
        return -1;//si no lo encuentra devuelve -1
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


