#include "DtConversacionArchivada.h"
//Constructores
DtConversacionArchivada::DtConversacionArchivada(){}

DtConversacionArchivada::DtConversacionArchivada(bool _activo, int _id, int cantArch){
    this-> cantArch=cantArch;
}

//Gettes
int DtConversacionArchivada::getCantArch(){
    return this-> cantArch=cantArch;
};

//Destructor
DtConversacionArchivada::~DtConversacionArchivada(){}