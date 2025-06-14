#include <iostream>
#include "ManagerTutor.h"
#include "ArchivoTutor.h"
using namespace std;




    void ManagerTutor::altaTutor(){
        ArchivoTutor archiv;
    Tutor tut;
    cin.ignore();
    tut.cargar();//Se le piden los datos al tutor

   int pos = archiv.buscarTutor(tut.getDni());
   if (pos>=0){
    cout<<"Este tutor ya existe"<<endl;
    return;
   }//Con esto si la posicion retorna mas de 0, es porque existe

    int cantidad = archiv.getCantidadRegistros();
    int nuevoID = (cantidad >0)//me constato que haya almenos un tutor guardado
        ? archiv.Leer(cantidad-1).getIDTutor()+1 //si es verdadero se lee el ultimo tutor, sacamos el id y le sumamos 1
        : 1;//si es falso el primero siempre tendra 1
    tut.setIDTutor(nuevoID);//Se le asigna el nuevo id al tutor

    //Guardamos el tutor
    if(archiv.agregarRegistro(tut)==1){
        cout<<"Tutor agregado con ID: "<< nuevoID <<endl;
    }else{
        cout<<"Error al agregar tutor: "<<endl;
    }
    }
    void ManagerTutor::listarTutoresActivos(){
        ArchivoTutor archiv;
        archiv.listarRegistrosActivos();
    }
    void ManagerTutor::listarTodosLosTutores(){
        ArchivoTutor archiv;
        archiv.listarTodosLosRegistros();
    }
    void ManagerTutor::listarTutoresInactivos(){
        ArchivoTutor archiv;
        archiv.listarRegistrosInactivos();
    }
    void ManagerTutor::modificarTutor(){
        ArchivoTutor archiv;
        char dni[10];
        cout<<"Ingrese el DNI del tutor a modificar: ";
        cin>>dni;
        int pos = archiv.buscarTutor(dni);//lo buscamos y obtenemos la posicion
        if(pos==-1){
            cout<<"No se ha encontrado un tutor con ese DNI."<<endl;// si no lo encuentra se va
            return;
        }

        Tutor tut = archiv.Leer(pos);//existe lo leo
        cout<<"Datos actuales del tutor:"<<endl;
        tut.mostrar();// muestro los datos actuales

        cout<<"Ingrese los nuevos datos: "<<endl;
        tut.cargar();
        tut.setIDTutor(archiv.Leer(pos).getIDTutor());//Le seteo el idTutor que ya tenia previamente para conservarle el mismo id
        archiv.modificarTutor(tut,pos);
        cout<<"Tutor modificado correctamente."<<endl;
    }
    void ManagerTutor::eliminarLogicoTutor(){
    ArchivoTutor archiv;
    char dni[10];
    cout<<"Ingrese el DNI del tutor a dar de baja: ";
    cin>>dni;

    if(archiv.bajaLogica(dni)){
        cout<<"Tutor dado de baja correctamente."<<endl;
    }else{
        cout<<"No se pudo dar de baja al tutor. Verifique el DNI."<<endl;
    }
    }
    void ManagerTutor::buscarTutor(){
        ArchivoTutor archiv;
        char dni[10];
        cout<<"Ingrese el DNI del Tutor a buscar: ";
        cin>>dni;
        int pos = archiv.buscarTutor(dni);//con buscar obtengo la posicion.
        if(pos == -1){
            cout<<"No se encontro un Tutor con ese DNI."<<endl;//si no lo encuentra se va
            return;
        }
        Tutor tut=archiv.Leer(pos);//si lo encuentra lo lee
        tut.mostrar();//Luego lo muestra.
    }


