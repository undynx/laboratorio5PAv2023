#include <iostream>
#include <string> 
#include "Factory.h"
#include "InterfaceSesion.h"
#include "InterfaceUsuario.h"
#include "InterfaceConvMens.h"
#include "InterfaceGrupo.h"

using namespace std;

DtFechaHora *fechaSistema = new DtFechaHora(28, 12, 2023, 21, 30);

int main()
{
  Factory *fact = Factory::getInstancia();
  InterfaceSesion *iSesion = fact->getInterfaceSesion();
  InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
  InterfaceConvMens *iConvMens = fact->getInterfaceConvMens();
  InterfaceGrupo *iGrupo = fact->getInterfaceGrupo();

  bool salir = false;
  int opt,optreloj,optenvmsj,optvermsj,optgrupo,optelimsj;
  int numTel,idConver, idConverArch;
  string nombre, imagen, descripcion;
  int dia, mes, anio, hora, min;
  Usuario *user;

  do {

    cout << "\n----------------------------\n";
    cout << "Elige la opcion que desees:\n \n";
    cout << "  0) Precargar datos" << endl;
    cout << "  1) Abrir app" << endl;
    cout << "  2) Alta usuario" << endl;
    cout << "  3) Agregar Contacto" << endl;
    cout << "  4) Modificar mi usuario" << endl;
    cout << "  5) Enviar Mensaje" << endl;
    cout << "  6) Ver Mensaje" << endl;
    cout << "  7) Eliminar Mensaje" << endl;
    cout << "  8) Archivar Conversación" << endl;
    cout << "  9) Gestion de grupos" << endl;
    cout << "  10) Mi perfil" << endl;
    cout << "  11) Reloj del Sistema" << endl;
    cout << "  12) Cerrar sesion" << endl;
    cout << "  13) Salir" << endl;
    cout << "\n----------------------------\n";

    cin >> opt;

    switch(opt) {
      case 1: // Abrir app
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
            cin.ignore();
            cout << "Ingresar la URL de perfil" << endl;
            getline(cin, imagen);
            cout << "Ingresar la descripcion" << endl;
            getline(cin, descripcion);
            user = iUsuario->encontrarUsuarioxnumTel(numTel);
            if(user == NULL) {
              iUsuario->altaUsuario(numTel, nombre, imagen, descripcion, fechaSistema);
              cout << endl;
              cout << "Se dió de alta al usuario" << numTel << endl;
            }else {
              cout << "  ERROR: Ya existe un usuario con el numero " << numTel << endl;
            }
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
            iConvMens->listarConversacionesActivas();
            cout << endl;
            cout << "----------------------------";
            cout << endl;
            cout << "Archivadas: " << iSesion->getUserLoggeado()->getCantArchivadas(); 
            cout << endl;
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
              iConvMens->ingresarIdConversacionEnviarMsj(idConver, fechaSistema);
            break;
            case 2:
              // Ver las conversaciones archivadas
              bool hayArchivadas;
              hayArchivadas = iConvMens->verArchivadas();
              if(hayArchivadas) {
                cout << "---------------------------\n";
                cout << "Ingresar el id de la conversación archivada" << endl;
                cin >> idConverArch;
                iConvMens->ingresarIdConversacionEnviarMsjArch(idConverArch, fechaSistema);
              }
            break;
            case 3:
              //Iniciar conversación con un contacto nuevo;
              cout << "----------------------------" << endl;
              cout << "CONTACTOS: " << endl;
              iUsuario->listarContactos();
              cout << "----------------------------" << endl;
              cout << "Ingresar número de celular del contacto con el cual quiere iniciar la conversación" << endl;
              cin >> numTel;
              iConvMens->iniciarConversacion(numTel, fechaSistema);
            break;
            default:
              cout << opt << " no es una opcion correcta \n" << endl;
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
        iConvMens->listarConversacionesActivas();
        cout << endl;
        cout << "----------------------------";
        cout << endl;
        cout << "Archivadas: " << iSesion->getUserLoggeado()->getCantArchivadas(); 
        cout << endl;
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
          iConvMens->ingresarIdConversacionMostrar(idConver, fechaSistema, false);
				break;
        case 2:
          //Ver las conversaciones archivadas
          bool hayArchivadas;
          hayArchivadas = iConvMens->verArchivadas();
          if(hayArchivadas){
            cout << "---------------------------\n";
            cout << "Ingresar el id de la conversación archivada" << endl;
            cin >> idConverArch;
            iConvMens->ingresarIdConversacionMostrarArch(idConverArch, fechaSistema, false);
          }
        break;
        default:
          cout << opt << " no es una opcion correcta \n" << endl;
        }

        }
      break;
      case 7: 
        //Eliminar Mensaje
        if(iSesion->loggedIn() == false) {
          cout << "ERROR: Debes iniciar sesion antes de poder eliminar mensajes" << endl;
        }else 
        { 
        cout << "----------------------------" << endl;
        cout << "CONVERSACIONES: ";
        iConvMens->listarConversacionesActivas();
        cout << endl;
        cout << "----------------------------";
        cout << endl;
        cout << "Archivadas: " << iSesion->getUserLoggeado()->getCantArchivadas(); 
        cout << endl;
        cout << "----------------------------";

        cout << "\n----------------------------\n";
			  cout << "Elige la opcion que desees:\n";
			  cout << "  1) Seleccionar conversación activa" << endl;
			  cout << "  2) Ver las conversaciones archivadas" << endl;
			  cout << "\n----------------------------\n";

			  cin >> optelimsj;

			  switch (optelimsj)
			  {
			  case 1:
				  //Seleccionar conversación activa
          cout << "Ingresar el id de la conversación" << endl;
          cin >> idConver;
          iConvMens->ingresarIdConversacionMostrar(idConver, fechaSistema, true);
				break;
        case 2:
          //Ver las conversaciones archivadas
          bool hayArchivadas;
          hayArchivadas = iConvMens->verArchivadas();
          if(hayArchivadas) {
            cout << "---------------------------\n";
            cout << "Ingresar el id de la conversación archivada" << endl;
            cin >> idConverArch;
            iConvMens->ingresarIdConversacionMostrarArch(idConverArch, fechaSistema, true);
          }
        break;
        default:
          cout << opt << " no es una opcion correcta \n" << endl;
        }

        }
      break;
      case 8:
        //Archivar Conversacion
        if(iSesion->loggedIn() == false) {
        cout << "ERROR: Debes iniciar sesion antes de poder archivar conversaciones" << endl;
        }else 
        { 
        iConvMens->listarConversacionesActivas();
        iConvMens->archivarConversacion();
        }
        break;
      case 9:
        if (iSesion->loggedIn() == false)
        {
            cout << " ERROR: Debes iniciar sesion antes de poder crear/modificar grupos" << endl;
        }
        else
        {
          cout << "Eligi la opcion que desees \n" << endl;
          cout << "  1) Alta grupo" << endl;
          cout << "  2) Agregar participantes" << endl;
          cout << "  3) Agregar administradores" << endl;
          cout << "  4) Eliminar participante" << endl;

          cin >> optgrupo;

          string nomGrupo, urlGrupo;
          int numTel, id;

          switch(optgrupo)
          {
          case 1: //Alta grupo

          if(iSesion->getUserLoggeado()->getListaContactos().empty()){
              cout << "  ERROR: No tienes ningun contacto con el que iniciar un grupo" << endl;
            } else
            {
              cin.ignore();
              string nomGrupo, urlGrupo;
              cout << "Ingrese los datos del grupo a crear" << endl;
              cout << "Nombre del grupo" << endl;
              getline(cin, nomGrupo);
              cout << "URL de la imagen" << endl;
              getline(cin, urlGrupo);
              iGrupo->crearGrupo(nomGrupo, urlGrupo, fechaSistema);
              cout << "Grupo creado" << endl;
            }
          break;
          case 2: //Agregar participante
          cout << "Ingresa el numero de telefono del participante" << endl;
          cin >> numTel;
          cout << "Ingresa el id del grupo" << endl;
          cin >> id;
          iGrupo->agregarParticipante(numTel, id, fechaSistema);
          break;
          case 3: //Agregar administrador
          cout << "Ingresa el numero de telefono del administrador" << endl;
          cin >> numTel;
          cout << "Ingresa el id del grupo" << endl;
          cin >> id;
          iGrupo->agregarAdministrador(numTel, id);
          break;
          case 4: //Eliminar participante
          cout << "Ingresa el numero de telefono del participante" << endl;
          cin >> numTel;
          cout << "Ingresa el id del grupo" << endl;
          cin >> id;
          iGrupo->eliminarParticipante(numTel, id);
          break;
          }
      }
      break;
      case 10: //Mi perfil
        if (iSesion->loggedIn() == false)
        {
          cout << "ERROR: Debes iniciar sesion para ver tu perfil" << endl;
        }else {
          cout << "Nombre: " << iSesion->getUserLoggeado()->getNombre() << endl;
          cout << "Imagen: " << iSesion->getUserLoggeado()->getImagen() << endl;
          cout << "Descripcion: " << iSesion->getUserLoggeado()->getDescripcion() << endl;
          iSesion->getUserLoggeado()->getFecReg()->mostrarFechayHoraRegistro();
        }
      break;
      case 11:
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
        cout << "ERROR: no es una opcion correcta" << endl;
      break;
      case 12: // Cerrar app
        if (iSesion->loggedIn() == false)
          cout << "  ERROR: No existe ninguna sesión iniciada" << endl;
        else
          iSesion->cerrarApp(fechaSistema);
      break;
      case 13:
        //Salir
        salir = true;
      break;
      case 0:
          //Crea los usuarios
          Usuario * juan = iUsuario->altaUsuario(80123654, "Juan Perez", "home/img/perfil/juan.png", "Amo usar esta app", fechaSistema);
          Usuario * maria = iUsuario->altaUsuario(80765432, "Maria Fernandez", "home/img/perfil/maria.png", "Me encanta Prog. Avanzada", fechaSistema);
          Usuario * pablo = iUsuario->altaUsuario(80246810, "Pablo Iglesias", "home/img/perfil/pablo.png", "Hola! Estoy aquí", fechaSistema);
          Usuario * sara = iUsuario->altaUsuario(80666777, "Sara Ruiz", "home/img/perfil/sara.png", "Estoy feliz!", fechaSistema);
          
          //Agrega los contactos
          juan->setContacto(maria);
          juan->setContacto(pablo);
          juan->setContacto(sara);
          maria->setContacto(juan);
          maria->setContacto(pablo);
          pablo->setContacto(juan);
          pablo->setContacto(maria);
          pablo->setContacto(sara);
          sara->setContacto(juan);
          sara->setContacto(pablo);
          
          //Crea el grupo
          int idGrupo = 1;
          DtFechaHora *fechaGrupo = new DtFechaHora(22, 5, 2023, 15, 35);
          ConversacionGrupal *cg = new ConversacionGrupal(idGrupo, true, "Amigos", "home/img/amigos.png", fechaGrupo);
          Conversacion *conver = cg;
          cg = dynamic_cast<ConversacionGrupal *>(conver);
          cg->setAdministrador(juan);
          cg->setParticipante(juan);
          juan->setConver(cg);
          ControllerConvMens *ccm = ControllerConvMens::getInstancia();
          ccm->setConversacionColSis(cg, idGrupo);

          //Agrega los participantes al grupo
          cg->setParticipante(maria);
          maria->setConver(cg);
          cg->setParticipante(pablo);
          pablo->setConver(cg);
          cg->setParticipante(sara);
          sara->setConver(cg);

          //Crea conversacion entre Juan y Maria
          int idConvJyM = 2;
          ConversacionPrivada *converPrivJyM = new ConversacionPrivada(idConvJyM, true, juan, maria);
          Conversacion *converJyM = converPrivJyM;
          converPrivJyM = dynamic_cast<ConversacionPrivada *>(converJyM);
          ccm->setConversacionColSis(converJyM, idConvJyM);
          juan->setConver(converPrivJyM);
          maria->setConver(converPrivJyM);

          // Crea conversacion entre Pablo y Sara
          int idConvPyS = 3;
          ConversacionPrivada *converPrivPyS = new ConversacionPrivada(idConvPyS, true, pablo, sara);
          Conversacion *converPyS = converPrivPyS;
          converPrivPyS = dynamic_cast<ConversacionPrivada *>(converPyS);
          ccm->setConversacionColSis(converPyS, idConvPyS);
          pablo->setConver(converPrivPyS);
          sara->setConver(converPrivPyS);

          //ENVIO MENSAJES
          //--------------
          //Maria envia en la conversacion con Juan el M5, visto
          DtFechaHora *fecha1 = new DtFechaHora(23, 5, 2023, 12, 23);
          Mensaje *msjMaria = iConvMens->enviarMsjSimple("Hola, me pasas el contacto de Sara que no lo tengo", fecha1, maria->getNumTel());
          msjMaria->setVistoPor(new VistoMensaje(juan->getNumTel(), fecha1, true));
          converJyM->setMensaje(msjMaria);

          //Juan envia contacto Sara a Maria, visto
          DtFechaHora *fecha2 = new DtFechaHora(23, 5, 2023, 12, 25);
          Mensaje *msjJuan = iConvMens->enviarMsjCompartirContacto(sara->getNumTel(), fecha2, juan->getNumTel());
          msjJuan->setVistoPor(new VistoMensaje(maria->getNumTel(), fecha2, true));
          converJyM->setMensaje(msjJuan);

          // Maria envia en la conversacion con Juan el M7, visto
          DtFechaHora *fecha3 = new DtFechaHora(23, 5, 2023, 12, 26);
          Mensaje *msjMaria2 = iConvMens->enviarMsjSimple("Gracias", fecha3, maria->getNumTel());
          msjMaria2->setVistoPor(new VistoMensaje(juan->getNumTel(), fecha3, true));
          converJyM->setMensaje(msjMaria2);

          // Sara le envia a Pablo el M8, visto
          DtFechaHora *fecha4 = new DtFechaHora(23, 5, 2023, 18, 30);
          Mensaje *msjSara = iConvMens->enviarMsjSimple("Hola Pablo, como estas?", fecha4, sara->getNumTel());
          msjSara->setVistoPor(new VistoMensaje(pablo->getNumTel(), fecha4, true));
          converPyS->setMensaje(msjSara);

          // Sara manda M1 en el grupo, visto por Juan y Pablo
          DtFechaHora *fecha5 = new DtFechaHora(23, 5, 2023, 18, 4);
          Mensaje *msjSaraG = iConvMens->enviarMsjSimple("Miren que bueno este video!", fecha5, sara->getNumTel());
          msjSaraG->setVistoPor(new VistoMensaje(juan->getNumTel(), fecha5, true));
          msjSaraG->setVistoPor(new VistoMensaje(pablo->getNumTel(), fecha5, true));
          cg->setMensaje(msjSaraG);

          //Sara manda un video
          Mensaje *msjSaraG2 = iConvMens->enviarMsjVideo("/url/video", 0.5, fecha5, sara->getNumTel());
          msjSaraG2->setVistoPor(new VistoMensaje(juan->getNumTel(), fecha5, true));
          msjSaraG2->setVistoPor(new VistoMensaje(pablo->getNumTel(), fecha5, true));
          cg->setMensaje(msjSaraG2);

          //Juan manda el M3, visto por Pablo y Sara
          DtFechaHora *fecha6 = new DtFechaHora(23, 5, 2023, 18, 12);
          Mensaje *msjJuanG = iConvMens->enviarMsjSimple("Muy gracioso!", fecha6, juan->getNumTel());
          msjJuanG->setVistoPor(new VistoMensaje(pablo->getNumTel(), fecha6, true));
          msjJuanG->setVistoPor(new VistoMensaje(sara->getNumTel(), fecha6, true));
          cg->setMensaje(msjJuanG);

          //Pablo manda M4, visto por Juan y Sara
          DtFechaHora *fecha7 = new DtFechaHora(23, 5, 2023, 18, 13);
          Mensaje *msjPabloG = iConvMens->enviarMsjSimple("Excelente!", fecha7, pablo->getNumTel());
          msjPabloG->setVistoPor(new VistoMensaje(sara->getNumTel(), fecha7, true));
          msjPabloG->setVistoPor(new VistoMensaje(juan->getNumTel(), fecha7, true));
          cg->setMensaje(msjPabloG);

          break;
      }
  } while (!salir);

  return 0;
}

