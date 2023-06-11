#include "ControllerUsuario.h"

ControllerUsuario* ControllerUsuario::instance=NULL;

ControllerUsuario::ControllerUsuario(){}

ControllerUsuario* ControllerUsuario::getInstance(){
    if(instance==NULL) 
    {
        instance = new ControllerUsuario();
    }

    return instance;
}
