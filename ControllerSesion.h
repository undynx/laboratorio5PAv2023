#ifndef SESION_H
#define SESION_H

#include <string>
#include "Usuario.h"
#include "InterfaceSesion.h"

class ControllerSesion : public InterfaceSesion
{
private:
	static ControllerSesion *instancia;
	Usuario *userLoggeado;
public:
	ControllerSesion();
	static ControllerSesion *getInstancia();
	bool loggedIn();
	Usuario* getUserLoggeado();
	void modificarUsuario();
	void setUserLoggeado(Usuario* user);
	int abrirApp(int numTel, DtFechaHora* fechaSesion);
	void cerrarApp(DtFechaHora* fechaUltCon);
	~ControllerSesion();
};

#endif
