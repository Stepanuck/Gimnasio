#include <iostream>
#include "Socio.h"
#include "ManagerSocio.h"
#include "ArchivoSocio.h"
using namespace std;




void ManagerSocio::altaSocio(){
    ArchivoSocio archiv;
    Socio soc;

    soc.cargar();//Se le piden los datos al socio

   int pos = archiv.buscarSocio(soc.getDni());
   if (pos>=0){
    cout<<"Este socio ya existe"<<endl;
    return;
   }//Con esto si la posicion retorna mas de 0, es porque existe

    int cantidad = archiv.getCantidadRegistros();
    int nuevoID = (cantidad >0)//me constato que haya almenos un socio guardado
        ? archiv.Leer(cantidad-1).getIDSocio()+1 //si es verdadero se lee el ultimo socio, sacamos el id y le sumamos 1
        : 1;//si es falso el primero siempre tendra 1
    soc.setIdSocio(nuevoID);//Se le asigna el nuevo id al socio

    //Guardamos el socio
    if(archiv.agregarRegistro(soc)==1){
        cout<<"Socio agregado con ID: "<< nuevoID <<endl;
    }else{
        cout<<"Error al agregar socio: "<<endl;
    }
}


void ManagerSocio::listarSociosActivos(){
    ArchivoSocio archiv;
    archiv.listarRegistrosActivos();
}

void ManagerSocio::listarTodosLosSocios(){
    ArchivoSocio archiv;
    archiv.listarTodosLosRegistros();
}

void ManagerSocio::listarSociosInactivos(){
    ArchivoSocio archiv;
    archiv.listarRegistrosInactivos();
}


void ManagerSocio::modificarSocio(){
    ArchivoSocio archiv;
    char dni[10];
    cout<<"Ingrese el DNI del socio a modificar: ";
    cin>>dni;

    int pos = archiv.buscarSocio(dni);//lo buscamos y obtenemos la posicion
    if(pos == -1){
        cout<<"No se ha encontrado un socio con ese DNI."<<endl;//si no lo encuentra se va
        return;
    }

    Socio soc = archiv.Leer(pos);//existe lo leo
    cout<<"Datos actuales del socio:"<<endl;
    soc.mostrar();//muestro los datos actuales

    cout<<"Ingrese los nuevos datos: "<<endl;
    soc.cargar();//pedimos lo nuevos datos
    soc.setIdSocio(archiv.Leer(pos).getIDSocio());//le seteo el idsocio que ya tenia previamente para conservarle el mismo id
    archiv.modificarSocio(soc,pos);//modifica el socio
    cout<<"Socio modificado correctamente."<<endl;
}


void ManagerSocio::buscarSocio(){
    ArchivoSocio archiv;
    char dni[10];

    cout<<"Ingrese el DNI del socio a buscar: ";
    cin>>dni;

    int pos = archiv.buscarSocio(dni);//con buscar obtengo la posicion
    if(pos == -1){
        cout<<"No se encontre un socio con ese DNI."<<endl;//si no lo encuentra se va
        return;
    }
    Socio soc=archiv.Leer(pos);//si lo encuentra lo lee
    soc.mostrar();//luego lo muestra
}

void ManagerSocio::eliminarLogicoSocio(){
    ArchivoSocio archiv;
    char dni[10];

    cout<<"Ingrese el DNI del socio a dar de baja: ";
    cin>>dni;

    if(archiv.bajaLogica(dni)){
        cout<<"Socio dado de baja correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de baja al socio. Verifique el DNI."<<endl;
    }

}
