#ifndef SESION
#define SESION
#include <string>
#include "Usuario.h"

class Sesion
{
	private:
		Usuario* user;
		static Sesion* instancia;
		Sesion();
	public:
		static Sesion* getInstancia();
		Usuario* getUsuario();
		void setUsuario(Usuario* user);
		~Sesion();
};

#endif