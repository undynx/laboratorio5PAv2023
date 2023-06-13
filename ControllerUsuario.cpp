#include "ControllerUsuario.h"

ControllerUsuario* ControllerUsuario::instance=NULL;

ControllerUsuario::ControllerUsuario(){}

ControllerUsuario* ControllerUsuario::getInstance(){
    if(instance==NULL) {
        instance = new ControllerUsuario();
    }

    return instance;
}

void ControllerUsuario::altaUsuario(Usuario* user)
{
    //usuarios.insert;
}

bool ControllerUsuario::ingresarNumero(int celular)
{
    if (usuarios.find(celular)!=usuarios.end())
    {
        /* code */
    }
    
    
    
}