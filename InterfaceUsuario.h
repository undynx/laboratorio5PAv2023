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
    virtual void agregarContacto(int numTel)=0;
    virtual void listarContactos()=0;
};

#endif
