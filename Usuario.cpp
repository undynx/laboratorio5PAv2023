#include "Usuario.h"
#include <iterator>


//Constructores

Usuario::Usuario() {}

Usuario::Usuario(int numTel, string nombre, DtFechaHora fecReg, string imagen, string descripcion, DtFechaHora ultCon){
    this->numTel = numTel;
    this->nombre = nombre;
    this->fecReg = fecReg;
    this->imagen = imagen;
    this->descripcion = descripcion;
    this->ultCon = ultCon;
}

//Getters

int Usuario::getNumTel(){
    return this->numTel;
}

string Usuario::getNombre(){
    return this->nombre;
}

DtFechaHora Usuario::getFecReg(){
    return this->fecReg;
}

string Usuario::getImagen(){
    return this->imagen;
}

string Usuario::getDescripcion(){
    return this->descripcion;
}

DtFechaHora Usuario::getUltCon(){
    return this->ultCon;
}

Usuario* Usuario::getContacto(int numtel){

 if (colContactos.find(numTel) != colContactos.end())
    {
          return colContactos.at(numTel);
    }
    return NULL;
}

/*
DtUsuario Usuario::pedirDatos(){
    Usuario *u;
    string nombre;
    cout<<"Ingrese su nombre"<<endl;
    cin>> nombre;
    string imagen;
    cout<<"Ingrese su URL de imagen"<<endl;
    cin>> imagen;
    string descripcion;
    cout<<"Ingrese su Descripcion"<<endl;
    cin>> descripcion;
    return u;
}
*/

//Setters

void Usuario::setNumTel(int numtel){
    this->numTel = numtel;
}

void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}

void Usuario::setDescripcion(string desc){
    this->descripcion = desc;
}

void Usuario::setImagen(string img){
    this->imagen = img;
}

void Usuario::setContacto(Usuario* u){

    //Agrego al usuario que viene por parametro "u" a la lista de contactos del usuario "this"
    this->colContactos.insert({u->numTel, u});

    //Agrego al usuario "this" a la lista de contactos del usuario "u"
    u->colContactos.insert({this->numTel, this});

}

map <int, Usuario*> Usuario::getListaContactos()
{
    return this->colContactos;
}

//DtUsuario Usuario::setUsuario(DtUsuario u){
    //No se que hace
//}


//Destructor
Usuario::~Usuario(){};




