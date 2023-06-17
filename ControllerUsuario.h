#ifndef CONTROLLERUSUARIO_H
#define CONTROLLERUSUARIO_H

#include "InterfaceUsuario.h"
#include "ControllerSesion.h"
#include "Usuario.h"
#include <map>

#include <iostream>
#include <stdlib.h>

class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instancia;
    public: map<int,Usuario*> colUsuarios; //coleccion de usuarios del sistema
    //Memoria del Controller
public:
    ControllerUsuario();
    static ControllerUsuario *getinstancia();
    ~ControllerUsuario();
    // void altaUsuario(Usuario* user);
    ControllerSesion* altaUsuario(int numTel, std::string nombre, std::string imagen, std::string descripcion);
    bool ingresarNumero(int numTel);
    Usuario* encontrarUsuarioxnumTel(int numTel);
    //set<DtUsuario> listarContactos(int numTel);
    //DtUsuario agregarContacto(int numTel);
    //void cancelar();
    //void salir();
    //Operaciones
};

#endif
