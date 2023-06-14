#include "Factory.h"
#include "InterfaceSesion.h"
#include "InterfaceUsuario.h"
#include "InterfaceConvMens.h"
#include "InterfaceGrupo.h"

#include <iostream>

using namespace std;

InterfaceUsuario* iUsuario;

int main (){
  Factory* fact = Factory::getInstancia();
  InterfaceSesion *iSesion = fact->getInterfaceSesion();
  InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
  InterfaceConvMens *iConvMens = fact->getInterfaceConvMens();
  InterfaceGrupo *iGrupo = fact->getInterfaceGrupo();
  bool salir = true;
  int opt;

  do {

    cout << "\n----------------------------\n";
    cout << "Elige la opcion que desees:\n \n";
    cout << "  1) Abrir app" << endl;
    cout << "  2) Alta usuario" << endl;
    cout << "  8) Cerrar app" << endl;
    cout << "  9) Salir" << endl;
    cout << "\n----------------------------\n";

    cin >> opt;

    switch(opt) {
      case 1:
        //Abrir app
        int numCel;
        cout << "Ingresar número de celular" << endl;
        cin >> numCel;
        iSesion->abrirApp(numCel);
        break;
      case 2:
        //Alta Usuario
        cout << "Alta usuario - NO IMPLEMENTADA" << endl;
        break;
      case 8: 
        //Cerrar app
        cout << "Cerrar app - NO IMPLEMENTADA" << endl;
        break;
      case 9:
        salir = true;
        break;
      default:
        cout << opt << " no es una opcion correcta" << endl;
      }
  } while (!salir);

  return 0;
}
