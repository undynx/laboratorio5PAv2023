#include "ControllerConvMens.h"

using namespace std;

ControllerConvMens* ControllerConvMens::instancia=NULL;

ControllerConvMens::ControllerConvMens(){}

ControllerConvMens *ControllerConvMens::getInstancia(){
  if (instancia == NULL)
    instancia = new ControllerConvMens();
  return instancia;
}

int ControllerConvMens::iniciarConversacion(int numTelContacto, Usuario* user, DtFechaHora* fechaSistema)
{
  //Factory *fact = Factory::getInstancia();
  //InterfaceUsuario *iUsuario = fact->getInterfaceUsuario();
  //string flag;

  ControllerUsuario* cu = ControllerUsuario::getinstancia();
  Usuario* destinatario = user->getContacto(numTelContacto);

  if(destinatario==NULL)
  {
    throw std::invalid_argument("\nERROR - El número ingresado no está en su lista de contactos");
  }

  int optmsj, numTel;
  string texto, url, tamanio, formato, duracion;
  Mensaje* msj = new Mensaje();

  ConversacionPrivada* converPriv = new ConversacionPrivada(true,rand() % 1000 + 1, user, destinatario);
  Conversacion *conver = dynamic_cast<ConversacionPrivada*>(converPriv);
  //Agrego la conversación a la lista de convers del sistema
  this->colConvers.insert({conver->getId(), conver});
  //Agrego la conversacion a la lista de conversaciones de los usuarios.
  user->setConver(conver);
  destinatario->setConver(conver);
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
          cout << endl;
          msj = enviarMsjSimple(texto, fechaSistema);
          //Agrego al mensaje a la lista de mensajes de la conversación.
          conver->setMensaje(msj);
          cout << "El mensaje ha sido enviado correctamente";
          fechaSistema->mostrarFechayHora();
          cout << endl;
          cout << "Id Conversación: " << conver->getId() << endl;
          cout << "Codigo Mensaje: " << msj->getCodigo() << endl;
				break;
        case 2:
          //Enviar Imagen
          cout << "Ingresar URL de la imagen que desee enviar" << endl;
          cin >> url;
          cout << "Ingresar formato de la imagen que desee enviar" << endl;
          cin >> formato;
          cout << "Ingresar tamaño de la imagen que desee enviar" << endl;
          cin >> tamanio;
          cout << "Ingresar descrpción de la imagen (puede ser vacía)" << endl;
          cin >> texto;
          cout << endl;
        break;
        case 3:
          //Enviar Video    
          cout << "Ingresar URL del video que desee enviar" << endl;
          cin >> url;
          cout << "Ingresar duracion del video que desee enviar" << endl;
          cin >> duracion;
        break;
        case 4:
          //Enviar Contacto 
          cu->listarContactos(user);
          cout << "Ingresar número de celular del contacto que desee enviar" << endl;
          cin >> numTel;

        break;
        //default:
          //cout << opt << " no es una opcion correcta \n" << endl;
        }

}

Mensaje* ControllerConvMens::enviarMsjSimple(string texto, DtFechaHora* fecEnvio)
{
  MSimple* MsjSimple = new MSimple(randomStr(11), fecEnvio, texto);
  Mensaje *Msj = dynamic_cast<MSimple*>(MsjSimple);
  return Msj;
}

Mensaje* ControllerConvMens::enviarMsjImagen(string url, string tamanio, string formato, DtFechaHora* fecEnvio, string texto)
{
  MImagen* MsjImg = new MImagen(randomStr(11), fecEnvio, url, formato, tamanio, texto);
  Mensaje *Msj = dynamic_cast<MImagen*>(MsjImg);
  return Msj;
}

//Mensaje* ControllerConvMens::enviarMsjVideo(string url, float duracion, DtFechaHora* fecEnvio)
//{
 // MVideo* MsjVideo = new MVideo(randomStr(11), fecEnvio, url, duracion);
//Mensaje *Msj = dynamic_cast<MVideo*>(MsjVideo);
 // return Msj;
//}

Mensaje* ControllerConvMens::enviarMsjCompartirContacto(int celularCompContacto, DtFechaHora* fecEnvio)
{
  ControllerUsuario* cu = ControllerUsuario::getinstancia();
  Usuario* cto = cu->encontrarUsuarioxnumTel(celularCompContacto);

  DtUsuario dtContacto = DtUsuario(cto->getNumTel(),cto->getNombre(), cto->getFecReg(), cto->getImagen(), cto->getDescripcion(), cto->getUltCon());

  MContacto* MsjContacto = new MContacto(randomStr(11), fecEnvio, dtContacto);
  Mensaje *Msj = dynamic_cast<MContacto*>(MsjContacto);
  return Msj;
}

string ControllerConvMens::randomStr(int ch)
{
    const int ch_MAX = 26;
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
    string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}

void ControllerConvMens::ingresarIdConversacion(int idConve, Usuario* user)
{

  Conversacion* conver = user->getConver(idConve);

    if(conver == NULL)
    {
      throw std::invalid_argument("\nERROR - El número ingresado no está en su lista de conversaciones");
    }

    this->colMensajesPorConver = conver->getListaMensajes();

    for (auto it = this->colMensajesPorConver.begin(); it != this->colMensajesPorConver.end(); it++){
       cout << it->second->getCodigo() << " - " << it->second->getFechayHora() << endl;
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
