#include "Factory.h"
#include "ControllerSesion.h"
#include "InterfaceUsuario.h"

ControllerSesion* ControllerSesion::sesion=NULL;

ControllerSesion::ControllerSesion(){}

ControllerSesion* ControllerSesion::getSesion()
{
	if(sesion==NULL)
	{
		sesion = new ControllerSesion();
	}
	return sesion;
}

int ControllerSesion::abrirApp(int numCel){

	Factory* fact = Factory::getInstancia();
	InterfaceUsuario* iUsuario = fact->getInterfaceUsuario();
	ControllerSesion* csesion = ControllerSesion::getSesion();
	int opt;
	bool existeNum = false;
	bool salir = false;

	if(csesion->user->getNumTel()!=numCel){
		
		cout << "\n----------------------------\n";
		cout << "Usted ya posee una sesón iniciada con otro número\n \n";
		cout << "Desea cerrar sesión para poder ingresar con el nuevo número?\n";
		cout << "  1) SI" << endl;
		cout << "  2) NO" << endl;

		cin >> opt;
		do {

		switch(opt) {
				case 1:
					//Cerrar app
					cerrarApp();
					salir = true;
					break;
				case 2:
					//No hago nada
					break;
				default:
					cout << opt << " no es una opcion correcta \n" << endl;
				}
	 }while(opt!=2 && !salir);
	 
	}

	while (!existeNum && !salir)
	{
		existeNum = iUsuario->ingresarNumero(numCel);//Busco en la colección de usuarios del sistema, si existe el numero.
	
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

				switch(opt) {
				case 1:
					//Abrir app
					cout << "Ingresar otro número de celular:\n" << endl;
					cin >> numCel;
					break;
				case 2:
					//Alta Usuario
					cout << "Ingresar nombre:\n" << endl;
					cin >> nombre;
					cout << "Ingresar URL de imagen de perfil:\n" << endl;
					cin >> img;
					cout << "Ingresar descripción breve:\n" << endl;
					cin >> desc;
					iUsuario->altaUsuario(nombre,img,desc);
					cout << "Se dio de alta su usuario correcatmente.\n" << endl;
					break;
				case 3:
					cerrarApp();
					salir = true;
					break;
				default:
					cout << opt << " no es una opcion correcta \n" << endl;
				}
		//return 0;
		}
	}
	
	return numCel;
}

void ControllerSesion::cerrarApp(){

	ControllerSesion* csesion = ControllerSesion::getSesion();
	csesion->getSesion();
	csesion->sesion=NULL;
	csesion->user=NULL;

	cout << "Sesión cerrada exitosamente" << endl;	
}

ControllerSesion::~ControllerSesion(){}
