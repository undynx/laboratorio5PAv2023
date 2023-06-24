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

DtFechaHora *fechaSistema = new DtFechaHora(28, 12, 2023, 21, 30);

int main()
{
  bool salir = false;
  int opt,optreloj,optenvmsj,optvermsj;
  int numTel,idConver;
  string nombre, imagen, descripcion;
  int dia, mes, anio, hora, min;

  do {

    cout << "\n----------------------------\n";
    cout << "Elige la opcion que desees:\n \n";
    cout << "  1) Abrir app" << endl;
    cout << "  2) Alta usuario" << endl;
    cout << "  3) Agregar Contacto" << endl;
    cout << "  4) Modificar mi usuario" << endl;
    cout << "  5) Enviar Mensaje" << endl;
    cout << "  6) Ver Mensaje" << endl;
    cout << "  7) Eliminar Mensaje" << endl;
    cout << "  8) Archivar Conversación" << endl;
    cout << "  9) Alta Grupo" << endl;
    cout << "  10) Agregar Participante" << endl;
    cout << "  11) Agregar Administrador" << endl;
    cout << "  12) Eliminar Participante" << endl;
    cout << "  13) Mi perfil" << endl;
    cout << "  14) Reloj del Sistema" << endl;
    cout << "  15) Salir" << endl;
    cout << "  0) Cerrar sesion" << endl;
    cout << "\n----------------------------\n";

    cin >> opt;

    switch(opt) {
      case 1: //Abrir app
          try
          {
            cout << "Ingresar número de celular" << endl;
            cin >> numTel;
            iSesion->abrirApp(numTel, fechaSistema);
          }
          catch (std::exception &e)
          {
            std::cerr << e.what() << '\n';
          }
      break;
      case 2: //Alta usuario
          try
          {
            cout << "Ingresar número de celular" << endl;
            cin >> numTel;
            cout << "Ingresar el nombre" << endl;
            cin >> nombre;
            cout << "Ingresar la URL de perfil" << endl;
            cin >> imagen;
            cout << "Ingresar la descripcion" << endl;
            cin >> descripcion;
            iUsuario->altaUsuario(numTel, nombre, imagen, descripcion, fechaSistema);
          }
          catch (std::exception &e)
          {
            std::cerr << e.what() << '\n';
          }
      break;
      case 3: // Agregar contacto
          try
            {
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
          }
          catch (std::exception &e)
          {
            std::cerr << e.what() << '\n';
          }
      break;
      case 4: //Modificar usuario
        if(iSesion->loggedIn() == false) {
          cout << "  ERROR: Debes iniciar sesion para poder modificar tu usuario" << endl;
        }else {
          iSesion->modificarUsuario();
        }
      break;
      case 5: 
        //Enviar Mensaje
        if(iSesion->loggedIn() == false) 
        {
          cout << "ERROR: Debes iniciar sesion antes de poder enviar mensajes" << endl;
        }
        else 
        { 
          try
          {
            cout << "----------------------------" << endl;
            cout << "CONVERSACIONES: ";
            iConvMens->listarConversacionesActivas(iSesion->getUserLoggeado());
            //cout << "Archivadas: " << iConvMens->getcantArchivadas();
            cout << "----------------------------";

            cout << "\n----------------------------\n";
            cout << "Elige la opcion que desees:\n";
            cout << "  1) Seleccionar conversación activa" << endl;
            cout << "  2) Ver las conversaciones archivadas" << endl;
            cout << "  3) Iniciar conversación con un contacto nuevo" << endl;
            cout << "\n----------------------------\n";

            cin >> optenvmsj;

            switch (optenvmsj)
            {
            case 1:
              //Seleccionar conversación activa
              cout << "Ingresar el id de la conversación" << endl;
              cin >> idConver;
              iConvMens->ingresarIdConversacionEnviarMsj(idConver,iSesion->getUserLoggeado(), fechaSistema);
            break;
            case 2:
              //Ver las conversaciones archivadas

            break;
            case 3:
              //Iniciar conversación con un contacto nuevo;
              cout << "----------------------------" << endl;
              cout << "CONTACTOS: " << endl;
              iUsuario->listarContactos(iSesion->getUserLoggeado());
              cout << "----------------------------" << endl;
              cout << "Ingresar número de celular del contacto con el cual quiere iniciar la conversación" << endl;
              cin >> numTel;
              iConvMens->iniciarConversacion(numTel,iSesion->getUserLoggeado(), fechaSistema);
            break;
            //default:
              //cout << opt << " no es una opcion correcta \n" << endl;
            }             
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
      }
      break;
      case 6: 
        //Ver Mensaje
        if(iSesion->loggedIn() == false) {
          cout << "ERROR: Debes iniciar sesion antes de poder ver mensajes" << endl;
        }else 
        { 
        cout << "----------------------------" << endl;
        cout << "CONVERSACIONES: ";
        iConvMens->listarConversacionesActivas(iSesion->getUserLoggeado());
        //cout << "Archivadas: " << iConvMens->getcantArchivadas();
        cout << "----------------------------";

        cout << "\n----------------------------\n";
			  cout << "Elige la opcion que desees:\n";
			  cout << "  1) Seleccionar conversación activa" << endl;
			  cout << "  2) Ver las conversaciones archivadas" << endl;
			  cout << "\n----------------------------\n";

			  cin >> optvermsj;

			  switch (optvermsj)
			  {
			  case 1:
				  //Seleccionar conversación activa
          cout << "Ingresar el id de la conversación" << endl;
          cin >> idConver;
          iConvMens->ingresarIdConversacionMostrar(idConver,iSesion->getUserLoggeado(), fechaSistema);
				break;
        case 2:
          //Ver las conversaciones archivadas

        break;
        //default:
          //cout << opt << " no es una opcion correcta \n" << endl;
        }

        }
      break;
      case 13: //Mi perfil
        if (iSesion->loggedIn() == false)
        {
          cout << "  ERROR: Debes iniciar sesion para ver tu perfil" << endl;
        }else {
          cout << "Nombre: " << iSesion->getUserLoggeado()->getNombre() << endl;
          cout << "Imagen: " << iSesion->getUserLoggeado()->getImagen() << endl;
          cout << "Descripcion: " << iSesion->getUserLoggeado()->getDescripcion() << endl;
          iSesion->getUserLoggeado()->getFecReg()->mostrarFechayHoraRegistro();
        }
      break;
      case 14:
        //Modificar Reloj
        cout << "\n----------------------------\n";
			  cout << "Elige la opcion que desees:\n";
			  cout << "  1) Ver fecha sistema" << endl;
			  cout << "  2) Modificar fecha sistema" << endl;
			  cout << "  3) Salir" << endl;
			  cout << "\n----------------------------\n";

			  cin >> optreloj;

			  switch (optreloj)
			  {
			  case 1:
				  //Ver fecha sistema
          fechaSistema->mostrarFechayHora();
				break;
        case 2:
          // Modificar fecha sistema
          cout << "Ingresar día:\n";				 
          cin >> dia;
          cout << endl;
          cout << "Ingresar mes:\n";
          cin >> mes;
          cout << endl;
          cout << "Ingresar ano:\n";
          cin >> anio;
          cout << endl;
          cout << "Ingresar hora:\n";
          cin >> hora;
          cout << endl;
          cout << "Ingresar minuto:\n";
          cin >> min;
          cout << endl;
          fechaSistema = new DtFechaHora(dia,mes,anio,hora,min);
          cout << "Reloj del sistema actualizado exitosamente\n";
          cout << endl;
        break;
        }
        break;
        default:
        cout << "  ERROR: no es una opcion correcta" << endl;
      break;
      case 15:
        //Salir
        salir = true;
      break;
      case 0: // Cerrar app
        if (iSesion->loggedIn() == false)
          cout << "  ERROR: No existe ninguna sesión iniciada" << endl;
        else
          iSesion->cerrarApp(fechaSistema);
      break;
      }
  } while (!salir);

  return 0;
}

