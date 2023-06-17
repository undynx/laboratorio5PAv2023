#include "ControllerSesion.h"

ControllerSesion *ControllerSesion::instancia = NULL;

ControllerSesion::ControllerSesion(){}

ControllerSesion *ControllerSesion::getInstancia()
{
	if (instancia == NULL)
	{
		instancia = new ControllerSesion();
	}
	return instancia;
}

/*int ControllerSesion::abrirApp(int numTel)
{
	if (instancia == NULL)
	{
		instancia = new ControllerSesion();
	}
	return instancia;
}

Usuario *ControllerSesion::getUserLoggeado()
{
		return this->userLoggeado;
}

//Devuelve true si hay algun usuario loggeado, false si no
bool ControllerSesion::loggedIn(){
	if(this->userLoggeado != NULL)
		return true;
	else
		return false;
}

/*int ControllerSesion::abrirApp(int numTel){

	Factory *fact = Factory::getInstancia();
	InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
	ControllerSesion *csesion = ControllerSesion::getInstancia();
	int opt;
	bool existeNum = false;
	bool salir = false;

	if (csesion->user->getNumTel() != numTel)
	{

		cout << "\n----------------------------\n";
		cout << "Usted ya posee una sesón iniciada con el número\n \n";
		cout << "Desea cerrar sesión para poder ingresar con el nuevo número?\n";
		cout << "  1) SI" << endl;
		cout << "  2) NO" << endl;

		cin >> opt;
		do
		{

			switch (opt)
			{
			case 1:
				// Cerrar app
				salir = true;
				// cerrarApp();
				break;
			case 2:
				// No hago nada
				break;
			default:
				cout << opt << " no es una opcion correcta \n"
						 << endl;
			}
		} while (opt != 2 && !salir);
	}

	while (!existeNum && !salir)
	{
		// existeNum = iUsuario->ingresarNumero(numTel); // Busco en la colección de usuarios del sistema, si existe el numero.

		if (!existeNum)
		{
			string nombre = "";
			string img = "";
			string desc = "";

			cout << "\n----------------------------\n";
			cout << "El número ingresado no existe en el sistema\n \n";
			cout << "Elige la opcion que desees:\n \n";
			cout << "  1) Ingresar otro número" << endl;
			cout << "  2) Registrarme con este número" << endl;
			cout << "  3) Salir" << endl;
			cout << "\n----------------------------\n";

			cin >> opt;

			switch (opt)
			{
			case 1:
				// Abrir app
				cout << "Ingresar otro número de celular:\n"
						 << endl;
				cin >> numTel;
				break;
			case 2:
				// Alta Usuario
				cout << "Ingresar nombre:\n"
						 << endl;
				cin >> nombre;
				cout << "Ingresar URL de imagen de perfil:\n"
						 << endl;
				cin >> img;
				cout << "Ingresar descripción breve:\n"
						 << endl;
				cin >> desc;
				// iUsuario->altaUsuario(numTel, nombre, img, desc);
				salir = true;
				break;
			case 3:
				// cerrarApp();
				salir = true;
				break;
			default:
				cout << opt << " no es una opcion correcta \n"
						 << endl;
			}
		}
	}

	return numTel;
}*/

/*

void ControllerSesion::cerrarApp()
{

	ControllerSesion *csesion = ControllerSesion::getInstancia();
	csesion->getInstancia();
	csesion->instancia = NULL;
	csesion->user = NULL;

	cout << "Sesión cerrada exitosamente" << endl;
}*/

//ControllerSesion::~ControllerSesion(){}
