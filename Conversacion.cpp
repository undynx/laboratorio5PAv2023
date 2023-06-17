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

//Setters
void Conversacion::setActivo(bool activo){
    this->activo=activo;
}
void Conversacion::setId(int id){
    this->id=id;
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

//Destructor
Conversacion::~Conversacion(){}