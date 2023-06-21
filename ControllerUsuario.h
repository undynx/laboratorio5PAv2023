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
    map<int, Usuario*> colContactos; //coleccion de contactos - se usa para acceder a una lista de contactos de un Usuario

public:
    ControllerUsuario();
    static ControllerUsuario *getinstancia();
    ~ControllerUsuario();
    Usuario *altaUsuario(int numTel, string nombre, string imagen, string descripcion, DtFechaHora* fecReg);
    bool ingresarNumero(int numTel);
    Usuario* encontrarUsuarioxnumTel(int numTel);
    void agregarContacto(int numTel, Usuario* user);
    Usuario *encontrarContactoxNumTel(int numTel);
    void listarContactos(Usuario* user);
    // set<DtUsuario> listarContactos(Usuario* user);
    // void cancelar();
    // void salir();
    // Operaciones
};

#endif
