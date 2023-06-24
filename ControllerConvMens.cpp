#include "ControllerConvMens.h"

using namespace std;

ControllerConvMens* ControllerConvMens::instancia=NULL;

ControllerConvMens::ControllerConvMens(){
  this->cantArchivadas = 0;
}

ControllerConvMens *ControllerConvMens::getInstancia(){
  if (instancia == NULL)
    instancia = new ControllerConvMens();
  return instancia;
}

//int ControllerConvMens::getcantArchivadas(){
//  this->cantArchivadas;
//}

void ControllerConvMens::listarConversacionesActivas(Usuario* user)
{
    map <int,Conversacion*> colConversUsuario = user->getListaConvers();

    for (auto it = colConversUsuario.begin(); it != colConversUsuario.end(); it++){
          
        //Caso Conversacion Privada
        ConversacionPrivada* conversPriv = new ConversacionPrivada();
        Conversacion *convers = it->second;
        conversPriv = dynamic_cast<ConversacionPrivada*>(convers);

        cout << conversPriv->getOtroParticipante(user)->getNombre() << ": " << conversPriv->getOtroParticipante(user)->getNumTel() << endl;
        cout << "Id Conversación: " << conversPriv->getId();
       
    }
}

int ControllerConvMens::iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema)
{
  int optmsj, numTelCto, numTelRte, idConve;
  float duracion;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ControllerUsuario* cu = ControllerUsuario::getinstancia();
  Usuario* destinatario = user->getContacto(numTelContacto);
  DtUsuario dtUser = user->pedirDatos();
  numTelRte = dtUser.getNumTel();

    //cout << "Numero: " << dtUser.getNumTel();
    //cout << "Nombre: " << dtUser.getNombre();
    //cout << "Imagen: " << dtUser.getImagen();
    //dtUser.getFecReg()->mostrarFechayHoraRegistro();

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
  //Agrego al destinatario del mensaje a la lista de integrantes de la conversacion
  //Conver->setParticipante(destinatario);
  //Agrego al usuario a la lista de integrantes de la conversacion
  //Conver->setParticipante(user);
  
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
          msj = enviarMsjSimple(texto, fechaSistema, numTelRte);
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHora();
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
          cout << "Ingresar tamaño de la imagen que desee enviar" << endl;
          cin >> tamanio;
          cout << endl;
          cout << "Ingresar descrpción de la imagen (puede ser vacía)" << endl;
          cin >> texto;
          cout << endl;
          msj = enviarMsjImagen(url, tamanio, formato, fechaSistema, texto, numTelRte);
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHora();
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
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHora();
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
          //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
          conver->setMensaje(msj);
          this->colMensajesSis.insert({msj->getCodigo(), msj});
          cout << "El mensaje ha sido enviado correctamente";
          msj->getFechayHora()->mostrarFechayHora();
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
  MImagen* MsjImg = new MImagen(randomStr(5), numTelRemitente ,fecEnvio, url, formato, tamanio, texto);
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
  ControllerUsuario* cu = ControllerUsuario::getinstancia();
  Usuario* cto = cu->encontrarUsuarioxnumTel(celularCompContacto);

  DtUsuario dtContacto = DtUsuario(cto->getNumTel(),cto->getNombre(), cto->getFecReg(), cto->getImagen(), cto->getDescripcion(), cto->getUltCon());

  MContacto* MsjContacto = new MContacto(randomStr(5), numTelRemitente, fecEnvio, dtContacto);
  Mensaje *Msj = MsjContacto;
  MsjContacto = dynamic_cast<MContacto*>(Msj);
  return MsjContacto;
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

void ControllerConvMens::ingresarIdConversacion(int idConver, Usuario* user)
{
  ControllerUsuario* cu = ControllerUsuario::getinstancia();

  Conversacion* conver = user->getConver(idConver);

    if(conver == NULL)
    {
      throw std::invalid_argument("\nERROR - El número ingresado no está en su lista de conversaciones");
    }

    if (conver->isColMensajesEmpty()){
        cout << "Esta conversación no tiene mensajes" << endl;
    }
    else
    {
        map<string,Mensaje*> colMensajesPorConver = conver->getListaMensajes();
        
        for (auto it = colMensajesPorConver.begin(); it != colMensajesPorConver.end(); it++){
 
        MSimple* msjSimple = new MSimple();
        Mensaje *msj = it->second;
        msjSimple = dynamic_cast<MSimple*>(msj);

        Usuario* remitente = cu->encontrarUsuarioxnumTel(msjSimple->getNumRemitente());

        cout << remitente->getNombre() << ": " << msjSimple->getTexto() << endl;
        cout << "Codigo: " << msjSimple->getCodigo();
        msjSimple->getFechayHora()->mostrarFechayHora();

        }
    }


}

ControllerConvMens::~ControllerConvMens(){}

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
