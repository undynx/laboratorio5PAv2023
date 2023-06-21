#include "Conversacion.h"
//Constructores
Conversacion::Conversacion(){}

Conversacion::Conversacion(bool activo, int id){
    this-> activo=activo;
    this-> id=id;
}

//Gettes
bool Conversacion::getActivo(){
    return this-> activo=activo;
}
int Conversacion::getId(){
    return this-> id=id;
}

Mensaje* Conversacion::getMensaje(string codigo){

 if (colMensajes.find(codigo) != colMensajes.end())
    {
          return colMensajes.at(codigo);
    }
    return NULL;
}

//Setters
void Conversacion::setActivo(bool activo){
    this->activo=activo;
}
void Conversacion::setId(int id){
    this->id=id;
}

void Conversacion::setMensaje(Mensaje* msj){

    //Agrego al usuario que viene por parametro "u" a la lista de participantes de la conversacion
    this->colMensajes.insert({msj->getCodigo(), msj});

}

//Metodos
 Conversacion Conversacion::seleccionarConversacion(){

 }
 Conversacion Conversacion::getConversacion(){

}
DtConversacion Conversacion::obtenerConv(Conversacion c){

}
DtConversacion Conversacion::pedirDatos(){

}
Conversacion Conversacion::archivar(bool archivada){
    
}

map <string, Mensaje*> Conversacion::getListaMensajes()
{
    return this->colMensajes;
}

//Destructor
Conversacion::~Conversacion(){}