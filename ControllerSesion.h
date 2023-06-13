#ifndef SESION
#define SESION
#include <string>
#include "Usuario.h"
#include "InterfaceSesion.h"

class ControllerSesion: public InterfaceSesion{
	private:
		Usuario* user;
	public:
		int abrirApp(int numTel);
		void cerrarApp();
		~ControllerSesion();
};

#endif
