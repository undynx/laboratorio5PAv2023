#ifndef CONTROLLER_USUARIO
#define CONTROLLER_USUARIO
#include "InterfaceUsuario.h"
#include "Usuario.h"



class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instance;
    std::map<int,Usuario*> usuarios; //coleccion de usuarios
    //Memoria del Controller
public:
    ControllerUsuario();
     void altaUsuario(Usuario* user); 
     //void altaUsuario(std::string nombre, std::string imagen, std::string descripcion);
     bool ingresarNumero(int celular);
     set<DtUsuario> listarContactos(int numCel);
     DtUsuario agregarContacto( int numCel);
     void cancelar();
     void salir();


    //Operaciones
};

#endif
