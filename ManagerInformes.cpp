#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ManagerInformes.h"
#include "Actividad.h"
#include "ArchivoActividad.h"
#include "Socio.h"
#include "ArchivoSocio.h"
#include "Inscripcion.h"
#include "ArchivoInscripcion.h"
#include "Plan.h"
#include "ArchivoPlan.h"
#include "Cobro.h"
#include "ArchivoCobro.h"

using namespace std;

void ManagerInformes::InformarActividades(){

    Actividad act;
    ArchivoActividad actArchivo;
    Socio soc;
    ArchivoSocio socArchivo;
    Plan plan;
    ArchivoPlan planArchivo;
    Inscripcion insc;
    ArchivoInscripcion inscArchivo;
    Fecha hoy;
    hoy.hoy();


    int CantRegAct=actArchivo.getCantidadRegistros();
    int CantRegPlan=planArchivo.getCantidadRegistros();
    int CantRegInsc=inscArchivo.getCantidadRegistros();

    cout << "------------------ DETALLE DE ACTIVIDADES Y SOCIOS INSCRIPTOS ------------------" << endl;

    for(int i=0; i<CantRegAct; i++){

        act=actArchivo.leer(i);

        if(act.getEstado()){

            bool band=false;
            act.MostrarActividad();

            cout << "Socios Inscriptos: "<< endl;

            for(int j=0; j<CantRegPlan; j++){

                plan=planArchivo.Leer(j);

                for(int k=0; k<5; k++){

                    if(act.getIdActividad()==plan.getIdActividadesIncluidas(k)){

                        for(int l=0; l<CantRegInsc; l++){

                            insc=inscArchivo.Leer(l);

                            if(insc.getIdPlanInscripto()==plan.getIdPlan()&& insc.getFechaFin() >= hoy){

                                band=true;

                                soc=socArchivo.Leer(insc.getIdSocioInscripto()-1);

                                cout << " -ID " << insc.getIdSocioInscripto() << " " << soc.getNombres() << " " << soc.getApellidos() << endl;
                            }

                        }


                    }
                }
            }
            if(!band){
            cout<< "No hay socios Inscriptos" << endl;
            }

        }

    }
    cout << "------------------------------------------------------------------------------" << endl;
    system("pause");


}
void ManagerInformes::DetallesCuposEnActividades(){
    ArchivoActividad archAct;
    ArchivoInscripcion archIns;
    ArchivoPlan archPlan;

    /// obtenemos la fecha de hoy
    Fecha hoy;
    hoy.hoy();

    int cantAct = archAct.getCantidadRegistros(); // obtenemos la cantidad de actividades
    if(cantAct <= 0){
        cout << "No hay actividades cargadas." << endl;
        system("pause");
        return;
    }

    cout << "------------------ DETALLE DE CUPOS EN ACTIVIDADES ----------" << endl;

    // recorremos cada actividad
    for(int i = 0; i < cantAct; i++){
        Actividad act = archAct.leer(i);

        // únicamente las que están activas
        if(act.getEstado()){
            int cuposTotales = act.getCuposDisponibles();
            int cuposOcupados = 0;

            int cantIns = archIns.getCantidadRegistros(); // obtenemos todas las inscripciones
            // recorremos las inscripciones
            for(int j = 0; j < cantIns; j++){
                Inscripcion insc = archIns.Leer(j); // leemos la inscripción
                // solo nos interesan las que están activas y vigentes
                if(insc.getActivo() && insc.getFechaFin() >= hoy){
                    // busco el plan de esa inscripción
                    Plan p = archPlan.buscarPlan(insc.getIdPlanInscripto());
                    // comprobamos si este plan incluye la actividad
                    if(p.getIdPlan() != 0){
                        // recorremos las 5 actividades del plan
                        for(int k = 0; k < 5; k++){
                            if(p.getIdActividadesIncluidas(k) == act.getIdActividad()){
                                cuposOcupados++;
                                // una vez encontrado no hace falta seguir buscando
                                break;
                            }
                        }
                    }
                }
            }

            // Mostrar el detalle para la actividad actual
            cout << "Actividad:      " << act.getNombre()               << endl;
            cout << "Cupos Totales:  " << cuposTotales                   << endl;
            cout << "Cupos Ocupados: " << cuposOcupados                  << endl;
            cout << "Cupos Libres:   " << (cuposTotales - cuposOcupados) << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    system("pause");
}
void ManagerInformes::ListarDeudores(){
    ArchivoSocio archSocio;
    ArchivoCobro archCobro;
    ArchivoInscripcion archIns;//instanciamos los archivos.
    Fecha ultimoPago;
    int totalSocios = archSocio.getCantidadRegistros();//agarramos la cantidad de socios.
    int totalInscripciones = archIns.getCantidadRegistros();
    if(totalSocios==0){
        cout << "No hay socios cargados." << endl;
        system("pause");
        return;
    }
    if(totalInscripciones == 0){
        cout<<"No hay inscripciones cargadas. No se puede generar el reporte de deudores."<<endl;
        system("pause");
        return;
    }
    Fecha hoy;//instanciamos la fecha para sacar el dia de hoy.
    hoy.hoy();//utilizamos la funcion para eso de arriba.

    cout << "-------------------------------------------" << endl;
    cout <<" LISTADO DE DEUDORES AL ";
    hoy.mostrar();
    cout << "-------------------------------------------" << endl;

    bool hayDeudores = false;

    for (int i=0;i<totalSocios;i++){
        Socio soc = archSocio.Leer(i);
         //validacion de que el socio se haya leido bien
         if(strcmp(soc.getDni(), "-1") == 0) continue;
        if(soc.getEstado()){//Solo los socios activos
            //Buscamos si tienen inscripciones vigentes
            bool tieneVigencia = false;


            for(int j = 0; j<totalInscripciones; j++){//recorremos las inscripciones
                Inscripcion insc = archIns.Leer(j);//leemos
                if(insc.getIdSocioInscripto()==soc.getIDSocio()&& insc.getActivo() && insc.getFechaFin() >= hoy){//comprobamos que coinicida el id
                    //que este activo y que la fecha de fin se mayor o igual a la de hoy
                    tieneVigencia = true;
                    break;// si es asi, tiene vigencia y no adeuda
                }
                else{
                    Cobro cobro;
                    cobro=archCobro.Leer(j);
                    ultimoPago=cobro.getFechaCobro();
                }

            }
            if(!tieneVigencia){//caso contrario adeuda y se muestra, ademas se pone la flag en true.
                hayDeudores = true;
                //soc.mostrar();
                cout<< "Socio ID " << soc.getIDSocio() << " " << soc.getNombres() << " " << soc.getApellidos()<< endl;
                cout<< "Ultimo Pago ";
                ultimoPago.mostrar();
                cout<<"-------------------------------------------"<<endl;
            }
        }
    }
    if(!hayDeudores) cout<<"No hay deudores actualmente."<<endl;
    system("pause");
}
void ManagerInformes::ListarCobros(){
    ArchivoCobro archivo;
    ArchivoInscripcion inscArchivo;
    ArchivoSocio socArchivo;
    int cantidad = archivo.getCantidadRegistros();
    int mes, anio;
    bool band = false;

    cout << "Ingresar Mes y Anio a Listar: " << endl;
    while(true){

        cout << "Mes: ";
        cin >> mes;
        if(mes>=1&&mes<=12){
            break;
        }
        else{
            cout << "Mes Incorrecto" << endl;
            continue;
        }
    }
    while(true){

        cout << "Anio: ";
        cin >> anio;
        if(anio>=1925){
            break;
        }
        else{
            cout << "Anio Incorrecto" << endl;
            continue;
        }
    }

    cout<<"----------- LISTADO DE COBROS AL "<< mes << "/" << anio <<" -----------"<<endl;
    if (cantidad == 0) {
        cout << "No hay cobros registrados." << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        Cobro cobro = archivo.Leer(i);
        Inscripcion insc = inscArchivo.Leer(i);
        Socio soc = socArchivo.Leer(insc.getIdSocioInscripto()-1);
        if(cobro.getFechaCobro().getAnio()==anio&&cobro.getFechaCobro().getMes()==mes){
        cout << "-------------------------" << endl;
        cout<< "Socio ID " << soc.getIDSocio() << " " << soc.getNombres() << " " << soc.getApellidos()<< endl;
        cout << "ID Cobro: " << cobro.getIdCobro() << endl;
        cout << "ID Inscripcion: " << cobro.getIdInscripcion()<< endl;
        cout << "Fecha de Cobro: ";
        cobro.getFechaCobro().mostrar();
        cout << "Monto: $" << cobro.getMonto() << endl;
        band=true;
        }

    }
    if(!band){

        cout << "No hay cobros en ese periodo" << endl;
    }

    system ("Pause");

}
