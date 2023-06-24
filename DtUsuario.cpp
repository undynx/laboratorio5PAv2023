#include "DtUsuario.h"

DtUsuario::DtUsuario(){}

DtUsuario::DtUsuario(int numTel, string nombre, DtFechaHora* fecReg, string imagen, string descripcion, DtFechaHora* ultCon)
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->fecReg = fecReg;
    this->imagen = imagen;
    this->descripcion = descripcion;
    this->ultCon = ultCon;

}

//Getters
int DtUsuario::getNumTel()
{
    return this->numTel;
}

string DtUsuario::getNombre()
{
    return this->nombre;
}

DtFechaHora* DtUsuario::getFecReg()
{
    return this->fecReg;
}

string DtUsuario::getImagen()
{
    return this->imagen;
}

string DtUsuario::getDescripcion()
{
    return this->descripcion;
}

DtFechaHora* DtUsuario::getUltCon()
{
    return this->ultCon;
}

//Destructor
DtUsuario::~DtUsuario(){};