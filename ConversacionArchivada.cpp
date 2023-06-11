#include "ConversacionArchivada.h"
//Constructores
ConversacionArchivada::ConversacionArchivada(){}

ConversacionArchivada::ConversacionArchivada(bool _activo, int _id, int cantArch){
    this-> cantArch=cantArch;
}

//Gettes
int ConversacionArchivada::getCantArch(){
    return this-> cantArch=cantArch;
}


//Setters
void ConversacionArchivada::setCantArch(int cantArch){
    this->cantArch=cantArch;
}

//Destructor
ConversacionArchivada::~ConversacionArchivada(){}