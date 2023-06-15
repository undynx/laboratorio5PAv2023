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

void altaUsuario(int numTel, string nombre, string imagen, string descripcion)
{
    DtFechaHora fecReg = DtFechaHora(24, 9, 1999, 19, 30);
    DtFechaHora ultCon = DtFechaHora(24, 9, 1999, 19, 30);

    ControllerUsuario* cu = ControllerUsuario::getInstance();

    Usuario* user = new Usuario(numTel, nombre, fecReg, imagen, descripcion, ultCon);

    cu->usuario.insert({numTel, user});

    cout << "Se dio de alta su usuario correcatmente.\n"<< endl;
    cout << "Hora de conexión:" << ultCon.getHora() <<":"<< ultCon.getMin();
}

bool ingresarNumero(int numTel)
{
   ControllerUsuario* cu = ControllerUsuario::getInstance();
   
    if(cu->usuario.find(numTel)!=cu->usuario.end())
    {
        return true; //Si encunetro el numTel antes del final del map devuelvo true
    }
    else
    {
        return false; //Si encunetro el numTel antes del final del map devuelvo true
    }
}

set<DtUsuario> listarContactos(int numTel){}
DtUsuario agregarContacto( int numTel){}
void salir(){}
void cancelar(){}

ControllerUsuario::~ControllerUsuario(){}
