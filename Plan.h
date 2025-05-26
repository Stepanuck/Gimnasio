#pragma once
#include "Actividad.h"

class Plan{

    private:
    int _idPlan;
    char _nombre[20];
    Actividad _actividadesIncluidas[5];
    float _arancel;
    bool _estado;

    public:

    Plan();
    Plan(int idPlan, const char* nombre, Actividad actidadesIncluidas[], float arancel, bool estado);
    void setIdPlan(int idPlan);
    int getIdPlan();
    void setNombre(const char* nombre);
    const char* getNombre();
    void setActividadesIncluidas(Actividad actividadesIncluidas[]);
    Actividad getActividadesIncluidas();
    void setArancel(float arancel);
    float getArancel();
    void setEstado(bool estado);
    bool getEstado();
};
