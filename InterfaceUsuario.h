#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H
#include <map>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ControllerSesion.h"
#include "Usuario.h"

using namespace std;

class InterfaceUsuario {
	public: 
		virtual Usuario* altaUsuario(int numTel,string nombre, string imagen, string descripcion, DtFechaHora* fecReg)=0; 
		virtual bool ingresarNumero(int numTel)=0;
    virtual Usuario* encontrarUsuarioxnumTel(int numTel)=0;
    virtual void agregarContacto(int numTel, Usuario* user) = 0;
    virtual void listarContactos(Usuario* user)= 0;
    // virtual void agregarContacto() = 0;
    //  virtual set<DtUsuario> listarContactos(int numTel)=0;
    //  virtual DtUsuario agregarContacto( int numTel)=0;
    //  virtual void salir()=0;
    //  repetida  virtual <set> DtUsuario listarContactos()=0;
    //  virtual void cancelar()=0;
    //  virtual ~InterfaceUsuario(){};
};

#endif
