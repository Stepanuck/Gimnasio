#include <iostream>
#include <cstring>
#include "Plan.h"

using namespace std;

Plan::Plan(){

    _idPlan=0;
    strcpy(_nombre,"");
    _actividadesIncluidas[0]=0;
    _actividadesIncluidas[1]=0;
    _actividadesIncluidas[2]=0;
    _actividadesIncluidas[3]=0;
    _actividadesIncluidas[4]=0;
    _arancel=0.00;
    _estado=true;



}
Plan::Plan(int idPlan, const char* nombre, Actividad actidadesIncluidas[], float arancel, bool estado){

    setIdPlan(int idPlan);
    setNombre(const char* nombre);
    setActividadesIncluidas(Actividad actidadesIncluidas[]);
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

    if (strlen(nombres) > 0) {
        strcpy(_nombres, nombres);
    }
    else {
        strcpy(_nombres, "Sin Nombre");
    }

}
const char* Plan::getNombre(){

    return _nombre;

}
void Plan::setActividadesIncluidas(Actividad actividadesIncluidas[]){

    for(int i=0; i<5; i++){

        _actividadesIncluidas[i]=actividadesIncluidas[i];

    }
}
Actividad Plan::getActividadesIncluidas(){

    for(int i=0; i<5; i++){

        return _actividadesIncluidas[i];

    }


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
