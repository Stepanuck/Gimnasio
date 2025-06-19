#pragma once
#include "Menu.h"

class SubMenuCobros : public Menu {
public:
    SubMenuCobros();
    SubMenuCobros(std::string nombre);
    int EjecutarSubMenuCobros();
};
