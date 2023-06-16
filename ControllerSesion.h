#ifndef SESION_H
#define SESION_H

#include <string>
#include "Usuario.h"
#include "InterfaceSesion.h"

class ControllerSesion: public InterfaceSesion{
	private:
		static ControllerSesion* sesion;
		static Usuario* user;
	public:
		static ControllerSesion* getSesion();
		int abrirApp(int numTel);
		void cerrarApp();
		~ControllerSesion();
};

#endif
