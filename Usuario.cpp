#include "Usuario.h"


//Constructores

Usuario::Usuario() {}

Usuario::Usuario(int numTel, string nombre, DtFechaHora fecReg, string imagen, string descripcion, DtFechaHora ultCon)
{
    this->numTel = numTel;
    this->nombre = nombre;
    this->fecReg = fecReg;
    this->imagen = imagen;
    this->descripcion = descripcion;
    this->ultCon = ultCon;

}

//Getters

int Usuario::getNumTel()
{
    return this->numTel;
}

string Usuario::getNombre()
{
    return this->nombre;
}

DtFechaHora Usuario::getFecReg()
{
    return this->fecReg;
}

string Usuario::getImagen()
{
    return this->imagen;
}

string Usuario::getDescripcion()
{
    return this->descripcion;
}

DtFechaHora Usuario::getUltCon()
{
    return this->ultCon;
}

DtUsuario Usuario::getContacto(int numtel)
{
    //return this->contacto.find(numtel);
}

DtUsuario Usuario::pedirDatos()
{

    
}


//Setters

void Usuario::setNumTel(int numtel)
{
    this->numTel = numtel;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setDescripcion(string desc)
{
    this->descripcion = desc;
}

void Usuario::setImagen(string img)
{
    this->imagen = img;
}

void Usuario::setContacto(Usuario* u)
{
    this->contacto.insert({u->numTel, u});
}

DtUsuario Usuario::setUsuario(DtUsuario u)
{
    //No se que hace
}


//Destructor
Usuario::~Usuario(){};




