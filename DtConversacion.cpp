#include "DtConversacion.h"
//Constructores
DtConversacion::DtConversacion(){}

DtConversacion::DtConversacion(bool activo, int id){
    this-> activo=activo;
    this-> id=id;
}

//Gettes
bool DtConversacion::getActivo(){
    return this-> activo=activo;
}
int DtConversacion::getId(){
    return this-> id=id;
}

//Destructor
DtConversacion::~DtConversacion(){}