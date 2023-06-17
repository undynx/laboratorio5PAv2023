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
    map<int, Usuario*> colUsuarios; //coleccion de usuarios registrados en el sistema
    map<int, Usuario*> colContactos; //coleccion de contactos

public:
    ControllerUsuario();
    static ControllerUsuario *getinstancia();
    ~ControllerUsuario();
    Usuario *altaUsuario(int numTel, std::string nombre, std::string imagen, std::string descripcion);
    bool ingresarNumero(int numTel);
    Usuario* encontrarUsuarioxnumTel(int numTel);
    void agregarContacto(int numTel);
    Usuario *encontrarContactoxNumTel(int numTel);
    void listarContactos();
    // set<DtUsuario> listarContactos(int numTel);
    // void cancelar();
    // void salir();
    // Operaciones
};

#endif
