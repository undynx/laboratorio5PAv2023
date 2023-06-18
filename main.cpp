#include <iostream>
#include <string> 
#include "Factory.h"
#include "InterfaceSesion.h"
#include "InterfaceUsuario.h"
#include "InterfaceConvMens.h"
#include "InterfaceGrupo.h"

using namespace std;

Factory *fact = Factory::getInstancia();
InterfaceSesion *iSesion = fact->getInterfaceSesion();
InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
InterfaceConvMens *iConvMens = fact->getInterfaceConvMens();
InterfaceGrupo *iGrupo = fact->getInterfaceGrupo();

int main()
{
  bool salir = false;
  int opt;
  int numTel;
  string nombre, imagen, descripcion;

  do {

    cout << "\n----------------------------\n";
    cout << "Elige la opcion que desees:\n \n";
    cout << "  1) Abrir app" << endl;
    cout << "  2) Alta usuario" << endl;
    cout << "  3) Agregar Contacto" << endl;
    cout << "  4) Modificar mi usuario" << endl;
    cout << "  8) Mi perfil" << endl;
    cout << "  9) Cerrar sesion" << endl;
    cout << "  10) Salir" << endl;
    cout << "  11) Modificar fecha y hora" << endl;
    cout << "\n----------------------------\n";

    cin >> opt;

    switch(opt) {
      case 1: //Abrir app
        cout << "Ingresar número de celular" << endl;
        cin >> numTel;
        iSesion->abrirApp(numTel);
        break;
      case 2: //Alta usuario
        cout << "Ingresar número de celular" << endl;
        cin >> numTel;
        cout << "Ingresar el nombre" << endl;
        cin >> nombre;
        cin.ignore();
        cout << "Ingresar la URL de perfil" << endl;
        getline(cin, imagen);
        cout << "Ingresar la descripcion" << endl;
        getline(cin, descripcion);
        iUsuario->altaUsuario(numTel, nombre, imagen, descripcion);
        break;
      case 3: // Agregar contacto
        if(iSesion->loggedIn() == false) {
          cout << "ERROR: Debes iniciar sesion antes de poder agregar contactos" << endl;
        }else {
          int opcion;
          bool salirAgregarContacto = false;
          do
          {
            cout << "----------------------------" << endl;
            cout << "CONTACTOS: " << endl;
            iUsuario->listarContactos(iSesion->getUserLoggeado());
            cout << "----------------------------" << endl;
            cout << "\nIngresa el numero del usuario que queres agregar a tus contactos" << endl;
            cin >> numTel;
            iUsuario->agregarContacto(numTel, iSesion->getUserLoggeado());

            cout << "\nDeseas seguir agregando contactos?" << endl;
            cout << "  1) SI \n  2) NO" << endl;
            cin >> opcion;
            if(opcion == 2)
              salirAgregarContacto = true;
          } while (salirAgregarContacto != true);
        }
        break;
      case 4: //Modificar usuario
        if(iSesion->loggedIn() == false) {
          cout << "  ERROR: Debes iniciar sesion para poder modificar tu usuario" << endl;
        }else {
          iSesion->modificarUsuario();
        }
        break;
      case 8: //Mi perfil
        if (iSesion->loggedIn() == false)
        {
          cout << "  ERROR: Debes iniciar sesion antes de poder agregar contactos" << endl;
        }else {
          cout << "Nombre: " << iSesion->getUserLoggeado()->getNombre() << endl;
          cout << "Imagen: " << iSesion->getUserLoggeado()->getImagen() << endl;
          cout << "Descripcion: " << iSesion->getUserLoggeado()->getDescripcion() << endl;
        }
        break;
      case 9: // Cerrar app
        if (iSesion->loggedIn() == false)
          cout << "  ERROR: No existe ninguna sesión iniciada" << endl;
        else
          iSesion->cerrarApp();
        break;
      case 10:
        salir = true;
        break;
      case 11:
        //Modificar Reloj
        break;
      default:
        cout << "  ERROR: no es una opcion correcta" << endl;
        break;
      }
  } while (!salir);

  return 0;
}
