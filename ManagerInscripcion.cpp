#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerInscripcion.h"
#include "ArchivoInscripcion.h"
#include "ArchivoPlan.h"
#include "ArchivoCobro.h"
#include "Cobro.h"
#include "Menu.h"
#include "ArchivoSocio.h"

using namespace std;



void ManagerInscripcion::CargarInscripcion(){

    ArchivoInscripcion archivoIns;
    ArchivoCobro archivoCobro;
    ArchivoPlan archivoPlan;
    ArchivoSocio socioArchivo;

    int idSocio, idPlan, cantidadMeses;
    Fecha fechaPago, fechaFin, fechaCobro;
    bool pago = true;
    float monto;


    //calcular el id autonumerico

    int cantReg = archivoIns.getCantidadRegistros();
    int idInscripcion = 1;
    if(cantReg>0){
        Inscripcion ultima = archivoIns.Leer(cantReg - 1);
        idInscripcion = ultima.getIdInscripcion() + 1;
    }
        //datos

    while(true){

        cout << "Ingresar ID del Socio a Inscribir: ";
        cin >> idSocio;

        if(socioArchivo.buscarSocio(idSocio)!=-1){

            break;
        }
        else{

            cout << "El Socio Ingresado no Existe" << endl;
            continue;
        }

    }
    while(true){

        cout << "Ingresar ID del Plan seleccionado: ";
        cin >> idPlan;

        if(archivoPlan.buscarPosicionPlan(idPlan)!=-1){

            break;
        }
        else{

            cout << "El Plan Ingresado no Existe" << endl;
            continue;
        }

    }


    cout << "Ingrese fecha de pago/inicio (primer mes que paga): " << endl;
    fechaPago.cargar();

    cout << "¿Cuantos meses desea pagar? ";
    cin >> cantidadMeses;

    // Calcular la fecha de vencimiento

    fechaFin = fechaPago;
    fechaFin.sumarMeses(cantidadMeses);

    ///Verificar si la inscripcion ya existe para el mismo socio, plan y periodo

    bool existe = false;
    for(int i=0;i<cantReg;i++){

            Inscripcion guardada= archivoIns.Leer(i);
            if(guardada.getIdSocioInscripto()==idSocio &&
               guardada.getIdPlanInscripto()== idPlan &&
               guardada.getFechaInicio()==fechaPago){
                existe = true;
                break;
               }
    }

    if(!existe){
        //creamos la inscripcion y la guardamos
         Inscripcion insc(idInscripcion, idSocio, idPlan, fechaPago, fechaFin, true);
        if(archivoIns.agregarRegistro(insc) != -1) {
            cout << "Inscripción guardada correctamente. Generando cobro..." << endl;

            // Obtenemos el valor del plan
            Plan p = archivoPlan.buscarPlan(idPlan);
            if(p.getIdPlan()==0){
                cout<<"El plan ingresado no existe. Inscripcion cancelada."<<endl;
                return;
            }
            monto = p.getArancel() * cantidadMeses;

            fechaCobro.hoy();//para calcular la fecha de la inscripcion del dia del sistema
            cout<<"Fecha de cobro registrada automaticamente: ";
            fechaCobro.mostrar();
            cout<<endl;

             //Genero el id de cobro autonumérico
           int cantCobros = archivoCobro.getCantidadRegistros();//recuperamos la cantidad de cobros
           int idCobro = 1;//al primero se le asigna uno
           if(cantCobros>0){//si es el primero que se va a generar no entra aca
            Cobro ultima = archivoCobro.Leer(cantCobros - 1);//si ya es el segundo se lee
            idCobro = ultima.getIdCobro()+1;// y se toma el id y se suma 1
           }
            Cobro cobro(idCobro, idInscripcion, fechaCobro, monto);//constructor que crea el cobro con los datos que calculamos previamente
            if (archivoCobro.agregarRegistro(cobro) == 1) {
                cout << "Cobro registrado correctamente." << endl;
            } else {
                cout << "Error al registrar el cobro." << endl;
            }
        } else {
            cout << "No se pudo guardar la inscripción" << endl;
        }
    } else {
        cout << "Inscripción existente para ese socio, plan y fecha de inicio." << endl;
    }
    system("pause");

}


/*
void ManagerInscripcion::CargarInscripcion(){

    ArchivoInscripcion Archivo;
    Inscripcion Insc, InscGuardada;
    int idSocio;
    int idPlan;
    Fecha fechaDePago;
    bool pago;
    int cantReg=Archivo.getCantidadRegistros();

    int idInscripcion = 1; //por defecto el primero es 1

    if(cantReg>0){
        InscGuardada = Archivo.Leer(cantReg - 1); //leo el ultimo registro
        idInscripcion = InscGuardada.getIdInscripcion() + 1; // Sumo uno al ultimo registro
    }

    cout << "Ingresar ID del Socio a Inscribir: ";
    cin >> idSocio;

    cout << "Ingresar ID del Plan seleccionado: ";
    cin >> idPlan;

    fechaDePago.cargar();

    pago=true;

    Insc=Inscripcion(idInscripcion,idSocio, idPlan, fechaDePago, pago);

    bool existe=false;

    for(int i = 0; i < cantReg; i++){
        InscGuardada = Archivo.Leer(i);
        if(Insc == InscGuardada){
            existe = true;
            break;
        }
    }

    if(!existe){


        if(Archivo.agregarRegistro(Insc)!=-1){

            cout << "El registro se guardo correctamente" << endl;

        }
        else{

            cout << "No se pudo guardar" << endl;
        }
    }
    else{

        cout << "Inscripcion existente" << endl;

    }
    system("pause");

}*/
void ManagerInscripcion::ListarInscripcionesActivas(){
    Inscripcion inscripcion;
    ArchivoInscripcion Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){

        inscripcion=Archivo.Leer(i);

        if(inscripcion.getActivo()){

            inscripcion.MostrarInscripcion();

        }
    }
    system("pause");

}
void ManagerInscripcion::ListarInscripciones(){
    Inscripcion inscripcion;
    ArchivoInscripcion Archivo;
    int cantidadRegistros=Archivo.getCantidadRegistros();

    for(int i=0; i<cantidadRegistros; i++){

        inscripcion=Archivo.Leer(i);

        inscripcion.MostrarInscripcion();
    }
    system("pause");


}
void ManagerInscripcion::ModificarInscripcion(){
    Menu submenu("MODIFICAR INSCRIPCION");

    submenu.CargarOpciones("ID SOCIO");
    submenu.CargarOpciones("ID PLAN");
    submenu.CargarOpciones("FECHA INICIO");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int id, posicion, idSocio;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;
            ArchivoSocio socioArchivo;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);

                while(true){

                    cout << "Ingresar nuevo ID del socio: ";
                    cin >> idSocio;

                    if(socioArchivo.buscarSocio(idSocio)!=-1){

                        break;
                    }
                    else{

                        cout << "El Socio Ingresado no Existe" << endl;
                        continue;
                    }
                }

               insc.setIdSocioInscripto(idSocio);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);


                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 2:{
            int id, posicion, idPlan;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;
            ArchivoPlan planArchivo;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);
                while(true){

                    cout << "Ingresar nuevo ID del Plan: ";
                    cin >> idPlan;

                    if(planArchivo.buscarPosicionPlan(idPlan)!=-1){


                        break;
                    }
                    else{

                        cout << "El Plan Ingresado no Existe" << endl;
                        continue;
                    }

                }

               insc.setIdPlanInscripto(idPlan);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);

                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 3:{
            int id, posicion;
            Fecha fechaDeInicio;
            ArchivoInscripcion Archivo;
            Inscripcion insc, inscGuardada;

            cout << "Ingresar ID de la Inscripcion a modificar: ";
            cin >> id;
            cin.ignore();

            posicion=Archivo.buscarInscripcion(id);

            if(posicion>=0){

               insc=Archivo.Leer(posicion);

               cout << "Ingresar la nueva fecha ingreso: ";
               fechaDeInicio.cargar();

               insc.setFechaInicio(fechaDeInicio);

                int cantReg=Archivo.getCantidadRegistros();
                bool existe=false;

                for(int i=0; i<cantReg; i++){

                    inscGuardada=Archivo.Leer(i);

                    if(insc==inscGuardada){

                        existe=true;

                    }

                }
                if(!existe){


                    if(Archivo.modificarInscripcion(insc,posicion)!=-1){

                        cout << "El registro se guardo correctamente" << endl;

                    }
                    else{

                        cout << "No se pudo guardar" << endl;
                    }
                }
                else{

                    cout << "Inscripcion existente" << endl;

                }

            }
            else{
                    if (posicion == -1){
                        cout << "No existe el ID de la Inscripcion buscada." << endl;
                    }
                    else if (posicion == -2){
                        cout << "El archivo no fue encontrado." << endl;
                    }
            }
            system("pause");
            break;
        }
        case 0: band=true;
            break;
        }
    }while(!band);


}
void ManagerInscripcion::BuscarInscripcion(){

    Menu submenu("BUSCAR INSCRIPCION");

    submenu.CargarOpciones("POR ID SOCIO");
    submenu.CargarOpciones("POR ID PLAN");
    submenu.CargarOpciones("POR FECHA INGRESO");
    submenu.CargarOpciones("REGRESAR");
    bool band=false;
    do{
        system("cls");
        submenu.Mostrar();

        switch(submenu.SeleccionarOpcion()){
        case 1:{
            int idSocio;
            ArchivoInscripcion Archivo;
            Inscripcion insc;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;

            cout << "Ingresar ID Socio a buscar: ";
            cin >> idSocio;
            cin.ignore();

            for(int i=0; i<cantReg; i++){

                insc=Archivo.Leer(i);

                if(insc.getIdSocioInscripto()==idSocio){

                    insc.MostrarInscripcion();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Inscripciones para ese Socio." << endl;
            }

            system("pause");

            break;
        }
        case 2:{
            int idPlan;
            ArchivoInscripcion Archivo;
            Inscripcion insc;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;

            cout << "Ingresar ID Plan a buscar: ";
            cin >> idPlan;
            cin.ignore();

            for(int i=0; i<cantReg; i++){

                insc=Archivo.Leer(i);

                if(insc.getIdPlanInscripto()==idPlan){

                    insc.MostrarInscripcion();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Inscripciones para ese Plan." << endl;
            }

            system("pause");

            break;
        }
        case 3:{
            Fecha fechaConsulta;
            ArchivoInscripcion Archivo;
            Inscripcion insc;
            int cantReg=Archivo.getCantidadRegistros();
            bool band=false;

            cout << "Ingresar la Fecha a Buscar: ";
            fechaConsulta.cargar();
            cin.ignore();

            for(int i=0; i<cantReg; i++){

                insc=Archivo.Leer(i);

                if(insc.getFechaInicio()==fechaConsulta){

                    insc.MostrarInscripcion();
                    band=true;
                }

            }
            if(!band){
                cout << "No se encontraron Inscripciones para esa Fecha." << endl;
            }

            system("pause");

            break;

        }
        case 0: band=true;
            break;
        }
    }while(!band);

}
