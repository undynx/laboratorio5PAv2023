#include "Factory.h"
#include <iostream>

using namespace std;

int main (){
  Factory* fact = Factory::getInstancia();
  bool salir = true;
  int opt;

  do {

    cout << "\n----------------------------\n";
    cout << "Elige la opcion que desees:\n \n";
    cout << "  1) Abrir app" << endl;
    cout << "  8) Cerrar app" << endl;
    cout << "  9) Salir" << endl;
    cout << "\n----------------------------\n";

    switch(opt) {
      case 1:
        //Abrir app
        cout << "Abrir app - NO IMPLEMENTADA" << endl;
      case 8: 
        //Cerrar app
        cout << "Cerrar app - NO IMPLEMENTADA" << endl;
      case 9:
        salir = true;
      default:
        cout << opt << " no es una opcion correcta" << endl;
      }
  } while (!salir);

  return 0;
}
