#include <iostream>
#include "Fecha.h"
#include "Persona.h"
#include "Tutor.h"
#include "Actividad.h"
#include "MenuPrincipal.h"
#include "ArchivoSocio.h"
#include "Socio.h"
#include "rlutil.h"


using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::YELLOW);
    rlutil::setColor(rlutil::BLACK);
    MenuPrincipal MenuGimnasio;
    MenuGimnasio.EjecutarMenuPrincipal();

    return 0;
}
