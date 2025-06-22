#include <iostream>
#include <ctime>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}
void Fecha::setDia(int dia)
{
    if(dia>0 && dia<=31)
    {
        _dia=dia;
    }
    else
    {
        cout<<"Dia invalido"<<endl;
    }
}
int Fecha::getDia()
{
    return _dia;
}

void Fecha::setMes(int mes)
{
    if(mes >= 1 && mes <=12)
    {
        _mes=mes;
    }
    else
    {
        cout<<"Mes invalido"<<endl;
    }
}

int Fecha::getMes()
{
    return _mes;
}

void Fecha::setAnio(int anio)
{
    if(anio>1925)
    {
        _anio=anio;
    }
    else
    {
        cout<<"Anio invalido"<<endl;
    }
}

int Fecha::getAnio()
{
    return _anio;
}


void Fecha::cargar()
{
    do
    {
        cout<<"Ingrese dia: ";
        cin>> _dia;
        if(_dia <1 || _dia>31)
        {
            cout<<"Dia invalido, ingrese un dia valido."<<endl;
        }
    }
    while(_dia <1 || _dia >31);

    do
    {
        cout<<"Ingrese mes: ";
        cin>>_mes;
        if(_mes<0 || _mes>12)
        {
            cout<<"Ingrese un mes valido entre 1 y 12"<<endl;
        }
    }
    while (_mes < 1 || _mes > 12);
    do
    {
        cout<<"Ingrese anio: ";
        cin>>_anio;
        if(_anio<1925)
        {
            cout<<"Ingrese un anio valido"<<endl;
        }
    }
    while(_anio<1925);
}
void Fecha::mostrar()
{

    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;

}
void Fecha::sumarMeses(int cantidad)
{
    _mes+=cantidad;
    while(_mes>12)
    {
        _mes-=12;
        _anio++;
    }
    int diasPorMes[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    //Calculo para el año bisiesto
    if (_mes == 2 && (_anio % 4 == 0 && (_anio % 100 != 0 || _anio % 400 == 0)))
    {
        if (_dia > 29) _dia = 29;
    }
    else if (_dia > diasPorMes[_mes - 1])
    {
        _dia = diasPorMes[_mes - 1];
    }
}


void Fecha::hoy() //time_t es un tipo de dato entero grande.
{
    //el parametro puede ser null porque no hay interes en guardar el valor.
    time_t t = time(NULL); //retorna el tiempo actual.
    struct tm* ahora = localtime(&t);//toma la direccion de t y retorna un puntero a struc tm.
    //struct tm seria esto, la estructura que divide la fecha en partes.
    _dia = ahora->tm_mday;// da el dia del mes.
    _mes = ahora ->tm_mon + 1; // son los meses y sumas 1 porque va de 0 a 11(enero-diciembre).
    _anio = ahora ->tm_year + 1900;//la cantidad de años desde 1900, por eso la suma.
}
//compara dos fechas, si la fecha es igual o despues a la pasada devuelve true;
bool Fecha::operator>=(const Fecha& otra) const
{
    if(_anio > otra._anio) return true; // si el año es mayor, devuelve true.
    if(_anio < otra._anio) return false;
    if(_mes > otra._mes) return true;// si el mes es mayor, devuelve true.
    if(_mes < otra._mes) return false;
    if(_dia >= otra._dia) return true;// si el año y el mes son iguales, compara el dia.
    //si es mayor, devuelve true, caso contrario devuelve false y ninguna anterior se cumplio.
    return false;
}
///recibe el objeto a comparar
bool Fecha::operator == (Fecha fecha)
{

    if(_dia!=fecha._dia)return false;// si el dia es diferente, retorna false.
    if(_mes!=fecha._mes)return false;// si el mes es diferente, retorna false.
    if(_anio!=fecha._anio)return false;// si el año es diferente, retorna false.

    return true;// si no falla ninguno, quiere decir que todos coinciden y devuelve true.
}
int Fecha::operator-(Fecha fecha)
{
    int mes1, mes2;

    mes1=_anio*12+_mes;
    mes2=fecha.getAnio()*12+fecha.getMes();

    return mes1-mes2;


}
