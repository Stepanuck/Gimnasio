#include <iostream>
#include <cstring>
#include "Plan.h"
#include "Actividad.h"
#include "ArchivoActividad.h"


using namespace std;

Plan::Plan(){

    _idPlan=0;
    strcpy(_nombre,"");
    _IdActividadesIncluidas[0]=0;
    _IdActividadesIncluidas[1]=0;
    _IdActividadesIncluidas[2]=0;
    _IdActividadesIncluidas[3]=0;
    _IdActividadesIncluidas[4]=0;
    _arancel=0.00;
    _estado=true;



}
Plan::Plan(int idPlan, const char* nombre, int IdActidadesIncluidas[], float arancel, bool estado){

    setIdPlan(idPlan);
    setNombre(nombre);
    setIdActividadesIncluidas(IdActidadesIncluidas);
    setArancel(arancel);
    setEstado(estado);

}
void Plan::setIdPlan(int idPlan){

    _idPlan=idPlan;

}
int Plan::getIdPlan(){

    return _idPlan;

}
void Plan::setNombre(const char* nombre){

    if (strlen(nombre) > 0) {
        strcpy(_nombre, nombre);
    }
    else {
        strcpy(_nombre, "Sin Nombre");
    }

}
const char* Plan::getNombre(){

    return _nombre;

}
void Plan::setIdActividadesIncluidas(int IdActividadesIncluidas[]){

    for(int i=0; i<5; i++){

        _IdActividadesIncluidas[i]=IdActividadesIncluidas[i];

    }
}
int Plan::getIdActividadesIncluidas(int pos){

    return _IdActividadesIncluidas[pos];

}
void Plan::setArancel(float arancel){

    if(arancel>0){

        _arancel=arancel;

    }

}
float Plan::getArancel(){

    return _arancel;

}
void Plan::setEstado(bool estado){

    _estado=estado;

}
bool Plan::getEstado(){

    return _estado;

}
bool Plan::operator == (Plan plan){

    if(strcmp(_nombre,plan._nombre)==0&&_IdActividadesIncluidas[0]==plan._IdActividadesIncluidas[0]
       &&_IdActividadesIncluidas[1]==plan._IdActividadesIncluidas[1]&&_IdActividadesIncluidas[2]==plan._IdActividadesIncluidas[2]
       &&_IdActividadesIncluidas[3]==plan._IdActividadesIncluidas[3]&&_IdActividadesIncluidas[4]==plan._IdActividadesIncluidas[4]
       &&_arancel==plan._arancel){

       return true;

    }
    else {

        return false;

    }

}
void Plan::MostrarPlan(){
    Actividad act;
    ArchivoActividad actArchivo;


    cout << "------------------------------------------"<< endl;
    cout << "ID: " << getIdPlan() << endl;
    cout << "Plan: " << getNombre() << endl;
    cout << "Actividades Incluidas:" << endl;
    for (int i; i<5; i++){
        if(getIdActividadesIncluidas(i)!=0){
            act=actArchivo.leer(getIdActividadesIncluidas(i)-1);
            cout << "  -ID " << getIdActividadesIncluidas(i) << " " << act.getNombre() << endl;
        }
    }
    cout << "Valor del Plan: $" << getArancel() << endl;
    cout << "------------------------------------------"<< endl;

}
