#ifndef CONTROLLER_USUARIO
#define CONTROLLER_USUARIO
#include <stdlib.h>
#include "InterfaceUsuario.h"


class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instance;
    ControllerUsuario();
    //PseudoAtributos
    //Memoria del Controller
public:
    static ControllerUsuario* getInstance();
    void altaUsuario(std::string nombre, std::string imagen, std::string descripcion);
    bool ingresaNumero(int celular);

    //Operaciones
};

#endif
