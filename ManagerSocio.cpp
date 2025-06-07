#include <iostream>
#include "Socio.h"
#include "ManagerSocio.h"
#include "ArchivoSocio.h"
using namespace std;




void ManagerSocio::altaSocio(){
    ArchivoSocio archiv;
    Socio soc;

    soc.cargar();

    if(archiv.buscarSocio(soc.getDni())!=-1){
        cout<<"Este socio ya existe"<<endl;
        return;
    }
    int cantidad = archiv.getCantidadRegistros();
    int nuevoID = 1;

    if(cantidad>0){
        Socio ultimo = archiv.Leer(cantidad -1);
        nuevoID = ultimo.getIDSocio() + 1;
    }

    soc.setIdSocio(nuevoID);

    if(archiv.agregarRegistro(soc)==1){
        cout<<"Socio agregado con ID: "<< nuevoID <<endl;
    }else{
        cout<<"Error al agregar socio: "<<endl;
    }


}
