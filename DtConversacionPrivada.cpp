#include "DtConversacionPrivada.h"
#include <string.h>

//Constructores
DtConversacionPrivada::DtConversacionPrivada(){}

DtConversacionPrivada::DtConversacionPrivada(int numTel, string nombre){
    this->numTel = numTel;
    this->nombre = nombre;
}

//Getters

int DtConversacionPrivada::getNumTel(){
    return this->numTel;
}
string DtConversacionPrivada::getNombre(){
    return this->nombre;
}

//Destructor
DtConversacionPrivada::~DtConversacionPrivada(){}
