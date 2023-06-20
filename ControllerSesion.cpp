#include "ControllerSesion.h"
#include "Factory.h"
#include "Usuario.h"

using namespace std;

ControllerSesion *ControllerSesion::instancia = NULL;

ControllerSesion::ControllerSesion()
{
	this->userLoggeado = NULL;
}

ControllerSesion *ControllerSesion::getInstancia()
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

void ControllerSesion::setUserLoggeado(Usuario* user)
{
	this->userLoggeado = user;
}

// Devuelve true si hay algun usuario loggeado, false si no
bool ControllerSesion::loggedIn()
{
	if (this->userLoggeado == NULL){
		return false;
	}else{
		return true;
	}
}

int ControllerSesion::abrirApp(int numTel){

  DtFechaHora ultCon = DtFechaHora(24, 9, 1999, 19, 30);

	Factory *fact = Factory::getInstancia();
	InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
	this->getInstancia();

	int opt;
	bool existeNum = false;
	bool salir = false;
	string flag = "";

	Usuario* user = getUserLoggeado();

	if (user != NULL) {
		cout << "Nombre usuario logueado: " << user->getNombre() << "\n";
		cout << "Número usuario logueado: " << user->getNumTel() << "\n";
	}

	if (user != NULL && user->getNumTel() != numTel)
	{

		cout << "\n----------------------------\n";
		cout << "Usted ya posee una sesón iniciada con otro número\n";
		cout << "Desea cerrar sesión para poder ingresar con este número?\n";
		cout << "  1) SI" << endl;
		cout << "  2) NO" << endl;

		cin >> opt;
		do
		{

			switch (opt)
			{
			case 1: // Cerrar app
				salir = true;
				cerrarApp();
				break;
			case 2: // No hago nada
				break;
			default:
				cout << opt << " no es una opcion correcta"<< endl;
			}
		} while (opt != 2 && !salir);

	} else if (user != NULL && user->getNumTel() == numTel)
	{
		existeNum = false;
		cout << "Actualmente ya posee una sesión con ese número.\n";
		cout << endl;
	}

	while (!existeNum && !salir)
	{
		existeNum = iUsuario->ingresarNumero(numTel); // Busco en la colección de usuarios del sistema, si existe el numero.

		if (!existeNum)
		{
			string nombre = "";
			string img = "";
			string desc = "";

			cout << "\n----------------------------\n";
			cout << "El número ingresado no existe en el sistema\n";
			cout << "Elige la opcion que desees:\n";
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
				cout << "Ingresar el nombre" << endl;
        cin >> nombre;
        cin.ignore();
        cout << "Ingresar la URL de perfil" << endl;
				std::getline(cin, img);
				cout << "Ingresar la descripcion" << endl;
				std::getline(cin, desc);
				user = iUsuario->altaUsuario(numTel, nombre, img, desc);
				setUserLoggeado(user);
				salir = true;
				break;
			case 3:
				// cerrarApp();
				salir = true;
				break;
			default:
				cout << opt << " no es una opcion correcta \n" << endl;
			}
		} 
		else //if (user->getNumTel() == numTel)
		{
			user = iUsuario->encontrarUsuarioxnumTel(numTel);
			setUserLoggeado(user);
			cout << endl;
			cout << "Sesión iniciada correcatmente.\n";
			cout << "Nombre usuario logueado: " << user->getNombre() << "\n";
			cout << "Número usuario logueado: " << user->getNumTel() << "\n";
			cout << "Hora de conexión:" << ultCon.getHora() <<":"<< ultCon.getMin();
		}
	}

	return numTel;
}

void ControllerSesion::modificarUsuario(){
	int opt;
	string modificacion;
	Usuario *user;
	ControllerUsuario *cUsuario = ControllerUsuario::getinstancia();

	cout << "¿Qué deseas modificar?" << endl;
	cout << "  1) Nombre de usuario" << endl;
	cout << "  2) Imagen de perfil" << endl;
	cout << "  3) Descripción" << endl;

	cin >> opt;
	cin.ignore();

	switch(opt)
	{
		case 1: //Username
			cout << "Ingresa tu nuevo username: " << endl;
			std::getline(cin, modificacion);
			//Cambia el nombre en el usuario actual
			this->userLoggeado->setNombre(modificacion);
			//Cambia el nombre en la lista de usuarios
			user = cUsuario->encontrarUsuarioxnumTel(this->userLoggeado->getNumTel());
			user->setNombre(modificacion);
			break;
		case 2: //Foto de perfil
			cout << "Ingresa el URL de tu nueva foto de perfil: " << endl;
			std::getline(cin, modificacion);
			// Cambia la foto en el usuario actual
			this->userLoggeado->setImagen(modificacion);
			// Cambia la foto en la lista de usuarios
			user = cUsuario->encontrarUsuarioxnumTel(this->userLoggeado->getNumTel());
			user->setImagen(modificacion);
			break;
		case 3: // Descripcion
			cout << "Ingresa tu nueva descripcion: " << endl;
			std::getline(cin, modificacion);
			// Cambia la descripcion en el usuario actual
			this->userLoggeado->setDescripcion(modificacion);
			// Cambia la descripcion en la lista de usuarios
			user = cUsuario->encontrarUsuarioxnumTel(this->userLoggeado->getNumTel());
			user->setDescripcion(modificacion);
			break;
		default:
		cout << "  ERROR: " << opt << " no es una opcion correcta" << endl;
		break;
	}
}

void ControllerSesion::cerrarApp(){
	bool isLoggedIn = loggedIn();

	if (isLoggedIn){
		this->userLoggeado = NULL;
		this->instancia = NULL;
	}
	cout << "Sesión cerrada exitosamente" << endl;
}

ControllerSesion::~ControllerSesion(){}
