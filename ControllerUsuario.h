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
     void altaUsuario(int numTel, std::string nombre, std::string imagen, std::string descripcion);
     bool ingresarNumero(int numTel);
     set<DtUsuario> listarContactos(int numTel);
     DtUsuario agregarContacto( int numTel);
     void cancelar();
     void salir();
    ~ControllerUsuario();
    //Operaciones
};

#endif
