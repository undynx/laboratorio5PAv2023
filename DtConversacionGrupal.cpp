#include "DtConversacionGrupal.h"
#include <string.h>
//Constructores
DtConversacionGrupal::DtConversacionGrupal(){}

DtConversacionGrupal::DtConversacionGrupal(bool activo, int id, string nombre){
    this-> nombre=nombre;
}

//Getters
string DtConversacionGrupal::getNombre(){
    return this->nombre=nombre;
}

//Destructor
DtConversacionGrupal::~DtConversacionGrupal(){};