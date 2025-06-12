#pragma once
#include "Actividad.h"

class Plan{

    private:
    int _idPlan;
    char _nombre[20];
    int _IdActividadesIncluidas[5];
    float _arancel;
    bool _estado;

    public:

    Plan();
    Plan(int idPlan, const char* nombre, int IdActidadesIncluidas[], float arancel, bool estado);
    void setIdPlan(int idPlan);
    int getIdPlan();
    void setNombre(const char* nombre);
    const char* getNombre();
    void setIdActividadesIncluidas(int IdActividadesIncluidas[]);
    int getIdActividadesIncluidas(int pos);
    void setArancel(float arancel);
    float getArancel();
    void setEstado(bool estado);
    bool getEstado();
    bool operator == (Plan plan);
    void MostrarPlan();
};
