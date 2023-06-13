#include "Factory.h"
#include <iostream>

using namespace std;

InterfaceUsuario* iUsuario;

int main (){
  Factory* fact = Factory::getInstancia();
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

    switch(opt) {
      case 1:
        //Abrir app
        int celular;
        cout << "Abrir app - NO IMPLEMENTADA" << endl;
        cout << "Ingresar número de celular" << endl;
        cin >> celular;
        iUsuario->ingresarNumero(celular);
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
