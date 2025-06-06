#include <iostream>
#include "Fecha.h"
#include "Persona.h"
#include "Tutor.h"
#include "Actividad.h"
#include "MenuPrincipal.h"

using namespace std;

int main()
{
    Horario obj;
    Actividad act;
    obj=Horario(12,10);
    Tutor t;
    int id = t.getIDTutor();

    act=Actividad(1,"Natacion", "Jueves", 20, obj, id, true);

    cout<<act.getIdActividad()<<endl;
    cout << act.getNombre()<< endl;
    cout << act.getDiaDeLaSemana()<< endl;
    cout << act.getCuposDisponibles()<< endl;
    act.getHorarioActividad().mostrar();
    cout << act.getIdTutorACargo()<<endl;
    cout << act.getEstado()<<endl;

    //MenuPrincipal MenuGimnasio;
    //MenuGimnasio.EjecutarMenuPrincipal();




    return 0;
}
