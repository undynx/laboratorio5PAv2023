#include "ControllerUsuario.h"

ControllerUsuario* ControllerUsuario::instance=nullptr;

ControllerUsuario::ControllerUsuario(){}

ControllerUsuario* ControllerUsuario::getInstance()
{
    if(instance==nullptr)
    {
        instance = new ControllerUsuario();
    }
return instance;
}