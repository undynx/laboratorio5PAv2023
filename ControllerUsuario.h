#ifndef CONTROLLERUSUARIO_H
#define CONTROLLERUSUARIO_H
#include "InterfaceUsuario.h"

class ControllerUsuario: public InterfaceUsuario
{
private:
    static ControllerUsuario* instancia;
    map<int, Usuario*> colUsuarios; //coleccion de usuarios registrados en el sistema
    //map<int, Usuario*> colContactos; //coleccion de contactos - se usa para acceder a una lista de contactos de un Usuario

public:
    ControllerUsuario();
    static ControllerUsuario *getInstancia();
    ~ControllerUsuario();
    Usuario *altaUsuario(int numTel, string nombre, string imagen, int cant, string descripcion, DtFechaHora* fecReg);
    bool ingresarNumero(int numTel);
    Usuario* encontrarUsuarioxnumTel(int numTel);
    void agregarContacto(int numTel);
    Usuario *encontrarContactoxNumTel(int numTel);
    void listarContactos();
    // set<DtUsuario> listarContactos(Usuario* user);
    // void cancelar();
    // void salir();
    // Operaciones
};

#endif
