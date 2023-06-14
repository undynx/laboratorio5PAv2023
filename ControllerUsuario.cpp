#include "ControllerUsuario.h"

ControllerUsuario* ControllerUsuario::instance=NULL;

ControllerUsuario::ControllerUsuario(){}

ControllerUsuario* ControllerUsuario::getInstance()
{
    if(instance==NULL){
        instance = new ControllerUsuario();
    }
    return instance;
}

void altaUsuario(string nombre, string imagen, string descripcion){}

bool ingresarNumero(int numCel)
{
   ControllerUsuario* cu = ControllerUsuario::getInstance();
   
    if(cu->usuario.find(numCel)!=cu->usuario.end())
    {
        return true; //Si encunetro el numCel antes del final del map devuelvo true
    }
    else
    {
        return false; //Si encunetro el numCel antes del final del map devuelvo true
    }
}

set<DtUsuario> listarContactos(int numCel){}
DtUsuario agregarContacto( int numCel){}
void salir(){}
void cancelar(){}

ControllerUsuario::~ControllerUsuario(){}
