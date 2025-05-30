#pragma once


class Menu{

protected:

    std::string _nombre;
    std::string _opcionesMenu[10];
    int _numOpcion;

public:

    Menu();
    Menu(std::string nombre);
    void CargarOpciones(std::string opcionMenu);
    void Mostrar();
    int SeleccionarOpcion();
};
