#ifndef CONTROLLERUSUARIO_H
#define CONTROLLERUSUARIO_H

#include "InterfaceUsuario.h"
#include "Usuario.h"
#include <map>


#include <stdlib.h>

class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instance;
    public: map<int,Usuario*> usuario; //coleccion de usuarios del sistema
    //Memoria del Controller
public:
     static ControllerUsuario* getInstance();
     ControllerUsuario();
     //void altaUsuario(Usuario* user); 
     void altaUsuario(std::string nombre, std::string imagen, std::string descripcion);
     bool ingresarNumero(int numCel);
     set<DtUsuario> listarContactos(int numCel);
     DtUsuario agregarContacto( int numCel);
     void cancelar();
     void salir();
    ~ControllerUsuario();
    //Operaciones
};

#endif
