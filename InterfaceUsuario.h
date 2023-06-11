#ifndef INTERGACEUSUARIO.H
#define INTERFACEUSUARIO.H
#include <list>
#include <string.h>
#include "Usuario.h"
#include <set>
using namespace std;

class InterfaceUsuario
{
	public:
		virtual DtUsuario altaUsuario(string nombre, string imagen, string descripcion)=0; 
		virtual bool ingresarNumero(int celular)=0;
        virtual set<DtUsuario> listarContactos(int numCel)=0;
        virtual DtUsuario agregarContacto( int numCel)=0;
        virtual void salir()=0;
      // repetida  virtual <set> DtUsuario listarContactos()=0;
        virtual void cancelar()=0;

};
#endif