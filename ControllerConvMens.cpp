#include "ControllerConvMens.h"

using namespace std;

ControllerConvMens* ControllerConvMens::instancia=NULL;

ControllerConvMens::ControllerConvMens(){
  
}

ControllerConvMens *ControllerConvMens::getInstancia(){
  if (instancia == NULL)
    instancia = new ControllerConvMens();
  return instancia;
}

Conversacion* ControllerConvMens::getConverSis(int idConver){
  auto itr = colConversSis.find(idConver);

  if (itr != colConversSis.end())
  {
    return itr->second;
  }
  return NULL;
}


//int ControllerConvMens::getcantArchivadas(){
//  this->cantArchivadas;
//}

void ControllerConvMens::listarConversacionesActivas(Usuario* user)
{

  if(user->isEmptyColConvers())
  {
      cout << "No tiene ninguna conversacion activa" << endl;;
  }
  else
  {
      map <int,Conversacion*> colConversUsuario = user->getListaConvers();

      for (auto it = colConversUsuario.begin(); it != colConversUsuario.end(); it++){
          
        //Caso Conversacion Privada
        ConversacionPrivada* conversPriv = new ConversacionPrivada();
        Conversacion *convers = it->second;
        conversPriv = dynamic_cast<ConversacionPrivada*>(convers);

        cout << "\n----------------------------\n";
        cout << conversPriv->getOtroParticipante(user)->getNombre() << ": " << conversPriv->getOtroParticipante(user)->getNumTel() << endl;
        cout << "Id Conversación: " << conversPriv->getId() << endl;
    
        }
   }
}

void ControllerConvMens::iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema)
{
  int optmsj, numTelCto, numTelRte, numTelDest,idConve;
  float duracion;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ControllerUsuario* cu = ControllerUsuario::getInstancia();
  Usuario* destinatario = user->getContacto(numTelContacto);
  numTelDest = destinatario->getNumTel();
  DtUsuario dtUser = user->pedirDatos();
  numTelRte = dtUser.getNumTel();

  if(destinatario==NULL)
  {
    throw std::invalid_argument("\nERROR - El número ingresado no está en su lista de contactos");
  }

  idConve = rand() % 100 + 1;

  ConversacionPrivada* converPriv = new ConversacionPrivada(idConve, true, user, destinatario);
  Conversacion *conver = converPriv;
  converPriv = dynamic_cast<ConversacionPrivada*>(conver);
  
  //Agrego la conversación a la lista de convers del sistema
  this->colConversSis.insert({converPriv->getId(), converPriv});
  //Agrego la conversacion a la lista de conversaciones de los usuarios.
  user->setConver(converPriv);
  destinatario->setConver(converPriv);

        cout << "\n----------------------------\n";
			  cout << "Elige la opcion que desees:\n\n";
			  cout << "  1) Enviar Mensaje Simple" << endl;
			  cout << "  2) Enviar Imagen" << endl;
			  cout << "  3) Enviar Video" << endl;
        cout << "  4) Enviar Contacto" << endl;
			  cout << "\n----------------------------\n";

			  cin >> optmsj;

			  switch (optmsj)
			  {
			  case 1:
				  //Enviar Mensaje Simple
          cout << "Ingresar el texto desee enviar" << endl;
          cin >> texto;
          //cout << endl;
          msj = enviarMsjSimple(texto, fechaSistema, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
          cout << endl;
          cout << "Id Conversación: " << conver->getId() << endl;      
				break;
        case 2:
          //Enviar Imagen
          cout << "Ingresar URL de la imagen que desee enviar" << endl;
          cin >> url;
          cout << endl;
          cout << "Ingresar formato de la imagen que desee enviar" << endl;
          cin >> formato;
          cout << endl;
          cout << "Ingresar tamano de la imagen que desee enviar" << endl;
          cin >> tamanio;
          cout << endl;
          cout << "Ingresar descrpción de la imagen (puede ser vacía)" << endl;
          cin >> texto;
          cout << endl;
          msj = enviarMsjImagen(url, tamanio, formato, fechaSistema, texto, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          //vistoPor = new VistoMensaje(numTelRte,NULL,false);
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
          cout << endl;
          cout << "Id Conversación: " << conver->getId() << endl;
        break;
        case 3:
          //Enviar Video    
          cout << "Ingresar URL del video que desee enviar" << endl;
          cin >> url;
          cout << endl;
          cout << "Ingresar duracion del video que desee enviar" << endl;
          cin >> duracion;
          cout << endl;
          //msj = enviarMsjVideo(url , duracion, fechaSistema, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
          cout << endl;
          cout << "Id Conversación: " << conver->getId() << endl;
        break;
        case 4:
          //Enviar Contacto 
          cu->listarContactos(user);
          cout << "Ingresar número de celular del contacto que desee enviar" << endl;
          cin >> numTelCto;
          cout << endl;
          msj = enviarMsjCompartirContacto(numTelCto, fechaSistema, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
          cout << endl;
          cout << "Id Conversación: " << conver->getId() << endl;
        break;
        default:
            cout << optmsj << " no es una opcion correcta \n" << endl;
        }

}

Mensaje* ControllerConvMens::enviarMsjSimple(string texto, DtFechaHora* fecEnvio, int numTelRemitente)
{
  MSimple* MsjSimple = new MSimple(randomStr(5), numTelRemitente, fecEnvio, texto);
  Mensaje *Msj = MsjSimple;
  MsjSimple = dynamic_cast<MSimple*>(Msj);
  return MsjSimple;
}

Mensaje* ControllerConvMens::enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto, int numTelRemitente)
{
  MImagen* MsjImg = new MImagen(randomStr(5), numTelRemitente, fecEnvio, url, formato, tamanio, texto);
  Mensaje *Msj = MsjImg;
  MsjImg = dynamic_cast<MImagen*>(Msj);
  return MsjImg;
}

/*Mensaje* ControllerConvMens::enviarMsjVideo(string url ,float duracion, DtFechaHora* fecEnvio, int numTelRemitente)
{
  MVideo* MsjVideo = new MVideo(randomStr(5), numTelRemitente, fecEnvio, url, duracion);
  Mensaje *Msj = MsjVideo;
  MsjVideo = dynamic_cast<MVideo*>(Msj);
  return MsjVideo;
}*/

Mensaje* ControllerConvMens::enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio, int numTelRemitente)
{
  ControllerUsuario* cu = ControllerUsuario::getInstancia();
  Usuario* cto = cu->encontrarUsuarioxnumTel(celularCompContacto);

  DtUsuario dtContacto = DtUsuario(cto->getNumTel(),cto->getNombre(), cto->getFecReg(), cto->getImagen(), cto->getDescripcion(), cto->getUltCon());

  MContacto* MsjContacto = new MContacto(randomStr(5), numTelRemitente, fecEnvio, dtContacto);
  Mensaje *Msj = MsjContacto;
  MsjContacto = dynamic_cast<MContacto*>(Msj);
  return MsjContacto;
}


void ControllerConvMens::ingresarIdConversacionEnviarMsj(int idConver, Usuario* user, DtFechaHora* fecEnvio)
{
  int optmsj, numTelCto, numTelRte, numTelDest;
  float duracion;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ConversacionPrivada* converPriv;
  Conversacion *conver = user->getConver(idConver);
  if(conver==NULL)
  {
    throw std::invalid_argument("\nERROR - El id ingresado no está en su lista de conversaciones");
  }
  converPriv = dynamic_cast<ConversacionPrivada*>(conver);

  ControllerUsuario* cu = ControllerUsuario::getInstancia();
  numTelDest = converPriv->getOtroParticipante(user)->getNumTel();
  DtUsuario dtUser = user->pedirDatos();
  numTelRte = dtUser.getNumTel();

        cout << "\n----------------------------\n";
			  cout << "Elige la opcion que desees:\n";
			  cout << "  1) Enviar Mensaje Simple" << endl;
			  cout << "  2) Enviar Imagen" << endl;
			  cout << "  3) Enviar Video" << endl;
        cout << "  4) Enviar Contacto" << endl;
			  cout << "\n----------------------------\n";

			  cin >> optmsj;

			  switch (optmsj)
			  {
			  case 1:
				  //Enviar Mensaje Simple
          cout << "Ingresar el texto desee enviar" << endl;
          cin >> texto;
          //cout << endl;
          msj = enviarMsjSimple(texto, fecEnvio, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();  
				break;
        case 2:
          //Enviar Imagen
          cout << "Ingresar URL de la imagen que desee enviar" << endl;
          cin >> url;
          cout << endl;
          cout << "Ingresar formato de la imagen que desee enviar" << endl;
          cin >> formato;
          cout << endl;
          cout << "Ingresar tamano de la imagen que desee enviar" << endl;
          cin >> tamanio;
          cout << endl;
          cout << "Ingresar descrpción de la imagen (puede ser vacía)" << endl;
          cin >> texto;
          cout << endl;
          msj = enviarMsjImagen(url, tamanio, formato, fecEnvio, texto, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
        break;
        case 3:
          //Enviar Video    
          cout << "Ingresar URL del video que desee enviar" << endl;
          cin >> url;
          cout << endl;
          cout << "Ingresar duracion del video que desee enviar" << endl;
          cin >> duracion;
          cout << endl;
          //msj = enviarMsjVideo(url , duracion, fecEnvio, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
        break;
        case 4:
          //Enviar Contacto 
          cu->listarContactos(user);
          cout << "Ingresar número de celular del contacto que desee enviar" << endl;
          cin >> numTelCto;
          cout << endl;
          msj = enviarMsjCompartirContacto(numTelCto, fecEnvio, numTelRte);
          //Agrego la instancia de vistoPor a la instancia de mensaje creada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHoraEnviado();
        break;
        default:
            cout << optmsj << " no es una opcion correcta \n" << endl;
        }

}

void ControllerConvMens::ingresarIdConversacionMostrar(int idConver, Usuario* user, DtFechaHora* fecVisto)
{
  ControllerUsuario* cu = ControllerUsuario::getInstancia();

  VistoMensaje* vistoPor;
  ConversacionPrivada* converPriv;
  Conversacion *conver = user->getConver(idConver);
  if(conver==NULL)
  {
      throw std::invalid_argument("\nERROR - El id ingresado no está en su lista de conversaciones");
  }
  converPriv = dynamic_cast<ConversacionPrivada*>(conver);

  if (conver->isColMensajesEmpty()){
      cout << "Esta conversación no tiene mensajes" << endl;
  }
  else
  {
      map<string,Mensaje*> colMensajesPorConver = converPriv->getListaMensajes();
        
      for (auto it = colMensajesPorConver.begin(); it != colMensajesPorConver.end(); it++){
 
      MSimple* msjSimple = new MSimple();
      Mensaje *msj = it->second;
      msjSimple = dynamic_cast<MSimple*>(msj);

      Usuario* remitente = cu->encontrarUsuarioxnumTel(msjSimple->getNumRemitente());

      cout << "\n----------------------------\n";
      cout << remitente->getNombre() << ": " << msjSimple->getTexto() << endl;
      cout << "Codigo: " << msjSimple->getCodigo();

      if(remitente==user)
      {
          vistoPor = msjSimple->getVistoPor(converPriv->getOtroParticipante(user)->getNumTel());
          if(vistoPor->getVisto()) 
          {
            vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();
          }
          else
          {
            msjSimple->getFechayHora()->mostrarFechayHoraEnviado();
          }    
      }
      else
      {
          vistoPor = msjSimple->getVistoPor(user->getNumTel());
          if(!vistoPor->getVisto()) 
          {
            vistoPor->setVisto();
            vistoPor->setFecHoraVisto(fecVisto);
          }
          msjSimple->getFechayHora()->mostrarFechayHoraEnviado();
      }
    
      }
  }

}

string ControllerConvMens::randomStr(int ch)
{
  string result = "";
  bool salir = false;
  const int ch_MAX = 26;
  char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
  do
  {
  
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX]; //Se guarda el codigo autogenerado en 'result'

    if(this->encontrarMensaje(result)==NULL) //Si no existe ningun mensaje con el codigo autogenerado
    {
      salir=true; //Salgo del bucle
    }

  }
  while (!salir);

  return result;

}

Mensaje* ControllerConvMens::encontrarMensaje(string codigo)
{
   if (colMensajesSis.find(codigo) != colMensajesSis.end())
    {
          return this->colMensajesSis.at(codigo);
    }
   return NULL;

}

ControllerConvMens::~ControllerConvMens(){}

void ControllerConvMens::setConversacionColSis(Conversacion* conv, int id){
   this->colConversSis.insert({id, conv});
}

/*int mostrarCantidad(){}
set<DtConversacion> seleccionarConversacion(string id){}
set<DtMensaje> datosMensajes(string id){}
DtMensaje borrarMensaje(DtConversacion borrar){}
set<DtConversacion> seleccionarConversacionesTodas(){}
DtMensaje enviarMsjVideo(string url, string formato, float duracion){}
DtMensaje enviarMsjCompartirContacto(int celularCompContacto){}
DtMensaje enviarMsjImagen(string url, string tamanio, string formato){}
set<DtConversacion> buscarConv(int id){}
set<DtConversacion> buscarConvArch(int id){}
DtMensaje seleccionarMsj(int id){}*/
