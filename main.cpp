#include <iostream>
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
    cout << "  4) Alta Grupo" << endl;
    cout << "  8) Cerrar app" << endl;
    cout << "  9) Salir" << endl;
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
        cout << "Ingresar la URL de perfil" << endl;
        cin >> imagen;
        cout << "Ingresar la descripcion" << endl;
        cin >> descripcion;
        iUsuario->altaUsuario(numTel, nombre, imagen, descripcion);
        break;
      case 3: // Agregar contacto
        if(iSesion->loggedIn() == false) {
          cout << "  ERROR: Debes iniciar sesion antes de poder agregar contactos" << endl;
        }else {
          int opcion;
          bool salirAgregarContacto = false;
          do
          {
            cout << "----------------------------" << endl;
            cout << "CONTACTOS: " << endl;
            iUsuario->listarContactos();
            cout << "----------------------------" << endl;
            cout << "\nIngresa el numero del usuario que queres agregar a tus contactos" << endl;
            cin >> numTel;
            iUsuario->agregarContacto(numTel);

            cout << "\nDeseas seguir agregando contactos?" << endl;
            cout << "  1) SI \n  2) NO" << endl;
            cin >> opcion;
            if(opcion == 2)
              salirAgregarContacto = true;
          } while (salirAgregarContacto != true);
        }
      case 4: 
        //Alta Grupo
        if(iSesion->loggedIn()==false){
          cout << "  ERROR: Debes iniciar sesion antes de poder crear un grupo" << endl;

        }else{
          int opcion,op;
          bool salir = false;
          do
          {
            cout << "Listado de contactos participantes:" << endl;
            //iGrupo->listarContactosPart
            cout << "Listado de contactos restantes:" << endl;
            //iGrupo->listarContactosRest
            cout << "1) Agregar participante\n 2) Quitar Participante \n" << endl;
            switch (op)
            {
            case 1:
            cout << "Ingrese el número para ingresar al participante" << endl;
            //cin >> variable
            //iGrupo->agregarParticipante(variable)
              break;
            case 2:
            cout << "Ingrese el número para quitar al participante" << endl;
            //cin >> variable
            //iGrupo->quitarParticipante(variable)
              break;
            default:
              cout << opt << " no es una opcion correcta" << endl;
            }
            cout << "\nDeseas seguir?" << endl;
            cout << "  1) SI \n  2) NO" << endl;
            cin >> opcion;
            if(opcion == 2)
              salir = true;
          } while (salir !=true);

          cout << "Ingrese los datos del grupo a crear" << endl;
          cout << "Nombre del grupo" << endl;
          //cin >> variable;
          cout << "URL de la imagen" << endl;
          //cin >> variable;
          //iGrupo->ingresoGrupo(var1,var2)
          cout << "Grupo creado" << endl;

        }

        break;
      case 8: 
        //Cerrar app
  
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
