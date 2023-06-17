#ifndef SESION_H
#define SESION_H

#include <string>
#include "Usuario.h"
#include "InterfaceSesion.h"

class ControllerSesion: public InterfaceSesion{
	private:
		static ControllerSesion* instancia;
		static Usuario *user;

	public:
		ControllerSesion();
		static ControllerSesion* getInstancia();
		/*int abrirApp(int numTel);
		void cerrarApp();
		~ControllerSesion();*/
};

#endif
