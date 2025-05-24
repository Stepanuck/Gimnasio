#pragma once
#include "Actividad.h"

class Plan{

    private:
    int _idPlan;
    char _nombre[20];
    Actividad _actividadesIncluidas[5];
    float _arancel;

    public:

    void setIdPlan(int idPlan);
    int getIdPlan();
    void setNombre(const char* nombre);
    const char* getNombre();
    void setActividadesIncluidas(Actividad actividadesIncluidas*);
    Actividad getActividadesIncluidas();
    void setArancel(float arancel);
    float getArancel();
    void mostrar();
    void cargar();

};
