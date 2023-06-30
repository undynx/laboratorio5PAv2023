#include "Mensaje.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Constructores

Mensaje::Mensaje(){}

Mensaje::Mensaje(string codigo, int numTelRemitente,DtFechaHora* fechayHora){
    this-> codigo = codigo;
    this-> numTelRemitente = numTelRemitente;
    this-> fechayHora = fechayHora;
}

//Gettes

string Mensaje::getCodigo(){
    return this->codigo;
}

DtFechaHora* Mensaje::getFechayHora(){
    return this->fechayHora;
}

int Mensaje::getNumRemitente(){
    return this->numTelRemitente;
}

VistoMensaje* Mensaje::getVistoPor(int numVistoPor){

    if (vistoPor.find(numVistoPor) != vistoPor.end())
    {
          return vistoPor.at(numVistoPor);
    }
    return NULL;
}

map<int,VistoMensaje*> Mensaje::getListaVistoPor(){
    return this->vistoPor;
}

/* DtMensaje Mensaje::seleccionar(){
    return NULL;
} */

//Setters

void Mensaje::eraseVistoPor(int numTel){
    this->vistoPor.erase(numTel);
}

void Mensaje::setCodigo (string codigo){
    this->codigo = codigo;
}

 void Mensaje::setVistoPor(VistoMensaje* vistoPor){
    this->vistoPor.insert({vistoPor->getDestinatario(), vistoPor});
 }

//Destructor

Mensaje::~Mensaje(){}

