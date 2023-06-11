#ifndef CONTROLLER_USUARIO
#define CONTROLLER_USUARIO
#include "InterfaceUsuario.h"


class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instance;
    //PseudoAtributos
    //Memoria del Controller
public:
    ControllerUsuario();
    void altaUsuario(std::string nombre, std::string imagen, std::string descripcion);
     bool ingresarNumero(int celular);
     set<DtUsuario> listarContactos(int numCel);
     DtUsuario agregarContacto( int numCel);
     void cancelar();
     void salir();


    //Operaciones
};

#endif
