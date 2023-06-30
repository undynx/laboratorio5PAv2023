#include "ControllerConvMens.h"
#include <iostream>
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

void ControllerConvMens::listarConversacionesActivas()
{
  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();

  if(user->isEmptyColConvers())
  {
      cout << "No tiene ninguna conversacion" << endl;;
  }
  else
  {
      bool listePriv, listeGrup = false;
      map <int,Conversacion*> colConversUsuario = user->getListaConvers();

      for (auto it = colConversUsuario.begin(); it != colConversUsuario.end(); it++){
          
        ConversacionPrivada* conversPriv = new ConversacionPrivada();
        ConversacionGrupal* conversGrup = new ConversacionGrupal();
        Conversacion *convers = it->second;
        conversPriv = dynamic_cast<ConversacionPrivada*>(convers);
        conversGrup = dynamic_cast<ConversacionGrupal*>(convers);

        cout << "\n----------------------------\n";
        if(conversPriv!=NULL && conversPriv->getActivo()==true)
        {//Caso Conversacion Privada
          listePriv = true;
          cout << conversPriv->getOtroParticipante(user)->getNombre() << ": " << conversPriv->getOtroParticipante(user)->getNumTel() << endl;
          cout << "Id Conversación: " << conversPriv->getId() << endl;
        }
        else if (conversGrup!=NULL && conversGrup->getActivo()==true)
        {//Caso Conversacion Grupal
          listeGrup =  true;
          cout << "Grupo : " << conversGrup->getNombre() << endl;
          cout << "Id Conversación: " << conversGrup->getId() << endl;
        }
      }
      if(!listeGrup && !listePriv)
      {
          cout << "No tiene ninguna conversación activa" << endl;;
      }
   }
}

void ControllerConvMens::iniciarConversacion(int numTelContacto, DtFechaHora* fechaSistema)
{
  int optmsj, numTelCto, numTelRte, numTelDest,idConve;
  float duracion;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();
  ControllerUsuario* cu = ControllerUsuario::getInstancia();
  Usuario* destinatario = user->getContacto(numTelContacto);
  DtUsuario dtUser = user->pedirDatos();
  
  if(destinatario==NULL)
  {
    cout << "ERROR: El número ingresado no está en su lista de contactos" << endl;
  }
  else
  { 
    numTelDest = destinatario->getNumTel();
    numTelRte = dtUser.getNumTel();
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
            cu->listarContactos();
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

Mensaje* ControllerConvMens::enviarMsjVideo(string url ,float duracion, DtFechaHora* fecEnvio, int numTelRemitente)
{
  MVideo* MsjVideo = new MVideo(randomStr(5), numTelRemitente, fecEnvio, url, duracion);
  Mensaje *Msj = MsjVideo;
  MsjVideo = dynamic_cast<MVideo*>(Msj);
  return MsjVideo;
}

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


void ControllerConvMens::ingresarIdConversacionEnviarMsj(int idConver, DtFechaHora* fecEnvio)
{
  int optmsj, numTelCto, numTelRte, numTelDest;
  float duracion;
  map<int, Usuario*> colParticipantes;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();

  ConversacionPrivada* converPriv;
  ConversacionGrupal* converGrup;
  Conversacion *conver = user->getConver(idConver);

  if(conver==NULL)
  {
    cout << "ERROR - El id ingresado no está en su lista de conversaciones";
  }
  else if(!conver->getActivo())
  {
    cout << "ERROR - El id ingresado no es de una conversación activa";
  }
  else
  {
    converPriv = dynamic_cast<ConversacionPrivada*>(conver);
    converGrup = dynamic_cast<ConversacionGrupal*>(conver);

    if(converPriv!=NULL)
    {
      numTelDest = converPriv->getOtroParticipante(user)->getNumTel();
    }
    else if (converGrup!=NULL)
    {
      colParticipantes = converGrup->getListaParticipantes();
    }

    ControllerUsuario* cu = ControllerUsuario::getInstancia();
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
      if(converPriv!=NULL)
      {//Caso Conversacion Privada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
      }
      else if (converGrup!=NULL)
      {//Caso Conversacion Grupal
        for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
        {
            msj->setVistoPor(new VistoMensaje(it->second->getNumTel(),NULL,false));
        }
      }
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
      if(converPriv!=NULL)
      {//Caso Conversacion Privada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
      }
      else if (converGrup!=NULL)
      {//Caso Conversacion Grupal
        for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
        {
            msj->setVistoPor(new VistoMensaje(it->second->getNumTel(),NULL,false));
        }
      }
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
        msj = enviarMsjVideo(url , duracion, fecEnvio, numTelRte);
        //Agrego la instancia de vistoPor a la instancia de mensaje creada
        if(converPriv!=NULL)
        {//Caso Conversacion Privada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
        }
        else if (converGrup!=NULL)
        {//Caso Conversacion Grupal
          for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
          {
            msj->setVistoPor(new VistoMensaje(it->second->getNumTel(),NULL,false));
          }
        }
        //Agrego al mensaje a la lista de mensajes de la conversación y del sistema.
        conver->setMensaje(msj);
        this->colMensajesSis.insert({msj->getCodigo(), msj});
        cout << "El mensaje ha sido enviado correctamente";
        msj->getFechayHora()->mostrarFechayHoraEnviado();
      break;
      case 4:
        //Enviar Contacto 
        cu->listarContactos();
        cout << "Ingresar número de celular del contacto que desee enviar" << endl;
        cin >> numTelCto;
        cout << endl;
        msj = enviarMsjCompartirContacto(numTelCto, fecEnvio, numTelRte);
        //Agrego la instancia de vistoPor a la instancia de mensaje creada
        if(converPriv!=NULL)
        {//Caso Conversacion Privada
          msj->setVistoPor(new VistoMensaje(numTelDest,NULL,false));
        }
        else if (converGrup!=NULL)
        {//Caso Conversacion Grupal
          for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
          {
            msj->setVistoPor(new VistoMensaje(it->second->getNumTel(),NULL,false));
          }
        }
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
}

void ControllerConvMens::ingresarIdConversacionEnviarMsjArch(int idConver, DtFechaHora* fecEnvio)
{

  int optmsj, numTelCto, numTelRte, numTelDest;
  float duracion;
  map<int, Usuario*> colParticipantes;
  string texto, url, tamanio, formato;
  Mensaje* msj;

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();

  ConversacionPrivada* converPriv;
  ConversacionArchivada* converArch;
  Conversacion *conver = user->getConver(idConver);
  if(conver==NULL)
  {
    cout << "ERROR - El id ingresado no está en su lista de conversaciones";
  }
  else
  {
    converArch = dynamic_cast<ConversacionArchivada*>(conver);

    ControllerUsuario* cu = ControllerUsuario::getInstancia();
    DtUsuario dtUser = user->pedirDatos();
    numTelRte = dtUser.getNumTel();

    if(converArch!=NULL)
    {
        Usuario* destinatario = converArch->getOtroParticipante(user);
        numTelDest = destinatario->getNumTel();
        converPriv = new ConversacionPrivada(idConver, true, user, destinatario);
        conver = converPriv;
        converPriv = dynamic_cast<ConversacionPrivada*>(conver);

        converPriv->setListaMensajes(converArch->getListaMensajes());//Traspaso la lista de mensajes de converArch a converPriv

        user->eraseConver(idConver);//Elimino la conversación archivada de la colección del usuario
        destinatario->eraseConver(idConver);//Elimino la conversación archivada de la colección del destinatario
        converArch->~ConversacionArchivada();//Llamo al destuctor de la instancia de conversacionArchivada
           
        user->setConver(converPriv);
        destinatario->setConver(converPriv);
        user->setCantArchivadas(user->getCantArchivadas() - 1);
        destinatario->setCantArchivadas(destinatario->getCantArchivadas() - 1);
    }

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
        msj = enviarMsjVideo(url , duracion, fecEnvio, numTelRte);
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
        cu->listarContactos();
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
  }


void ControllerConvMens::ingresarIdConversacionMostrar(int idConver, DtFechaHora* fecVisto, bool eliminar)
{
  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();
  ControllerUsuario* cu = ControllerUsuario::getInstancia();

  VistoMensaje* vistoPor;
  ConversacionGrupal* converGrup;
  ConversacionPrivada* converPriv;
  Conversacion *conver = user->getConver(idConver);
  if(conver==NULL)
  {
    cout << "ERROR - El id ingresado no está en su lista de conversaciones";
  }
  else if(!conver->getActivo())
  {
    cout << "ERROR - El id ingresado no es de una conversación activa";
  }
  else
  {
    converPriv = dynamic_cast<ConversacionPrivada*>(conver);
    converGrup = dynamic_cast<ConversacionGrupal*>(conver);

    if (conver->isColMensajesEmpty()){
        cout << "Esta conversación no tiene mensajes" << endl;
    }
    else
    {
        map<int, Usuario*> colParticipantes;
        map<string,Mensaje*> colMensajesPorConver = conver->getListaMensajes();
        bool mostreMsj = false;
          
        for (auto it = colMensajesPorConver.begin(); it != colMensajesPorConver.end(); it++)
        {
          MSimple* msjSimple = new MSimple();
          MImagen* msjImg = new MImagen();
          MVideo* msjVideo = new MVideo();
          MContacto* msjCon = new MContacto();
          Mensaje *msj = it->second;
          msjSimple = dynamic_cast<MSimple*>(msj);
          msjImg = dynamic_cast<MImagen*>(msj);
          msjVideo = dynamic_cast<MVideo*>(msj);
          msjCon = dynamic_cast<MContacto*>(msj);

          Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
          DtFechaHora* fechaIngreso = NULL;
          bool msjBorrado = false;

          if(converPriv!=NULL)
          {
            if(remitente!=user)
            {
                if(msj->getVistoPor(user->getNumTel())==NULL)
                {
                    //Significa que hubo borrado logico
                    msjBorrado = true;
                }
            }
          }
          else if(converGrup!=NULL)
          {
            fechaIngreso = converGrup->getFechaIngresoParticipante(user->getNumTel());
            colParticipantes = converGrup->getListaParticipantes();
            if(remitente!=user)
            {
                if(msj->getVistoPor(user->getNumTel())==NULL)
                {
                    //Significa que hubo borrado logico
                    msjBorrado = true;
                }
            }
          }

          if(msj->getFechayHora()->esMayorIgualQue(fechaIngreso) && !msjBorrado){

            mostreMsj = true;

            cout << "\n----------------------------\n";
            if(msjSimple!=NULL)
            {//Caso Msj Simple
              cout << remitente->getNombre() << ": " << msjSimple->getTexto() << endl;
              cout << "Codigo: " << msjSimple->getCodigo();
            }
            else if(msjImg!=NULL)
            {//Caso Msj Imagen
              cout << remitente->getNombre() << ": " << msjImg->getUrl() << endl;
              cout << "Codigo: " << msjImg->getCodigo();
              cout << "URL: " << msjImg->getUrl();
              cout << "Formato: " << msjImg->getFormato();
              cout << "Tamaño: " << msjImg->getTamano();
              cout << "Texto: " << msjImg->getTexto();
            }
            else if(msjVideo!=NULL)
            {//Caso Msj Video
              cout << remitente->getNombre() << ": " << msjVideo->getUrl() << endl;
              cout << "Codigo: " << msjVideo->getCodigo();
              cout << "URL: " << msjVideo->getUrl();
              cout << "Duración: " << msjVideo->getDuracion();
            }
            else if(msjCon!=NULL)
            {//Caso Msj Contacto
              cout << remitente->getNombre() << ": Nombre contacto -:" << msjCon->getContacto().getNombre() << " - Número contacto -:" << msjCon->getContacto().getNumTel() << endl;
              cout << "Codigo: " << msjCon->getCodigo();
            }

            if(remitente==user)
            {
                bool visto;
                if(converPriv!=NULL)
                { 
                    if(msj->getVistoPor(converPriv->getOtroParticipante(user)->getNumTel()) != NULL)
                    {
                      vistoPor = msj->getVistoPor(converPriv->getOtroParticipante(user)->getNumTel());
                      visto = vistoPor->getVisto();
                    }
                    else
                    {
                      cout << endl << "VISTO y ELIMINADO por el destinatario";
                    }
                }
                else if(converGrup!=NULL)
                {
                    for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
                    {
                      if(it->second!=user)
                      {
                        vistoPor = msj->getVistoPor(it->second->getNumTel()); 
                        if(vistoPor!=NULL)
                        {
                          visto = vistoPor->getVisto();
                          if(!visto){break;} 
                        }
                      }       
                    }
                }
                if(visto) 
                {
                  if(converPriv!=NULL){vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();}           
                  else if(converGrup!=NULL){cout << endl << "VISTO por TODOS";}
                }
                else
                {
                  msj->getFechayHora()->mostrarFechayHoraEnviado();
                }    
            }
            else
            {
                vistoPor = msj->getVistoPor(user->getNumTel());
                if(!vistoPor->getVisto()) 
                {
                  vistoPor->setVisto();
                  vistoPor->setFecHoraVisto(fecVisto);
                }
                msj->getFechayHora()->mostrarFechayHoraEnviado();
            }
          }
        }
        //Aca Termina el Listado de los mensajes
        //Faltan seleccionar el mensaje para ver detalle o eliminar
        if(mostreMsj)
        {
          cout << "\n----------------------------\n";
          string codigo;
          if(eliminar==true)
          {
              //Eliminar Mensaje
              cout << endl;
              cout << "Ingresar el codigo del mensaje que desee eliminar" << endl;
              cin >> codigo;
              cout << endl;
              if(converPriv!=NULL)
              {
                Mensaje* msj = converPriv->getMensaje(codigo);
                if (msj==NULL)
                {
                    cout << "El mensaje no pertenece a la conversación o no existe"<<endl; 
                }
                else
                {
                  Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
                  //Eliminar mensaje privado
                  if(user==remitente){
                    msj->eraseVistoPor(user->getNumTel());
                    msj->eraseVistoPor(remitente->getNumTel());
                    converPriv->eraseMensaje(codigo);
                    colMensajesSis.erase(codigo);
                    msj->~Mensaje();
                    //Si es remitente lo elimina de todos los mensajes
                    cout << "\nMensaje eliminado de la conversación correctamente\n";
                  }else
                  {
                    msj->eraseVistoPor(user->getNumTel());
                    cout << "\nMensaje eliminado (para tí) correctamente\n";
                  }  
                }               
              }
              else if(converGrup!=NULL)
              {
                Mensaje* msj = converGrup->getMensaje(codigo);
                if (msj==NULL)
                {
                    cout << "El mensaje no pertenece a la conversación o no existe"<<endl; 
                }
                else
                {
                  Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
                  colParticipantes = converGrup->getListaParticipantes();
                  //Borrado fisico si es el remitente
                  if(user==remitente){
                    for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
                        {
                          if(it->second!=user)
                          {
                            if(msj->getVistoPor(it->second->getNumTel())!=NULL)
                            {
                                msj->eraseVistoPor(it->second->getNumTel());
                            }
                          }       
                        }
                    converGrup->eraseMensaje(codigo);
                    colMensajesSis.erase(codigo);
                    msj->~Mensaje();
                    cout << "\nMensaje eliminado de la conversación correctamente\n";
                    //Borrado logico si no es el remitente
                  }else
                  {
                    msj->eraseVistoPor(user->getNumTel());    
                    cout << "\nMensaje eliminado (para tí) correctamente\n";      
                  } 
                } 
              }
              else
              {
                cout << "El mensaje no pertenece a una conversación activa"<<endl; 
              } 
          }
          else
          {
              //Ver Mensaje
              int opt;
              bool salir = false;
              cout << "Deseas ver info de los receptores de algún mensaje enviado?" << endl;
              cout << "  1) SI" << endl;
              cout << "  2) NO" << endl;
              cin >> opt;
              if (opt == 2)
              {
              salir = true;
              }
              while (!salir)
              {           
                cout << endl;
                cout << "Ingresar el codigo del mensaje para ver la info de los receptores" << endl;
                cin >> codigo;
                cout << endl;
                Mensaje* msj;
                if(converPriv!=NULL){msj = converPriv->getMensaje(codigo);}
                if(converGrup!=NULL){msj = converGrup->getMensaje(codigo);}
                if (msj==NULL)
                {
                    cout << "El mensaje no pertenece a la conversación o no existe"<<endl; 
                }
                else
                {
                  Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
                  if(remitente==user){
                      VistoMensaje* vistoPor;
                      cout << "\n----------------------------\n";
                      if(converPriv!=NULL)
                      {
                        Usuario* destinatario = converPriv->getOtroParticipante(remitente);
                        vistoPor = msj->getVistoPor(destinatario->getNumTel());
                        if(vistoPor!=NULL)
                        {
                          if(vistoPor->getVisto())
                          {
                              cout << destinatario->getNombre() << " - " << destinatario->getNumTel();
                              vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();
                          }
                          else
                          {
                          cout << "El mensaje aún no ha sido VISTO por su destinatario";
                          }
                        }
                        else
                        {
                            cout << "El mensaje ha sido ELIMINADO por su destinatario";
                        }
                    }
                    else if(converGrup!=NULL)
                    {
                      Mensaje* msj = converGrup->getMensaje(codigo);
                      colParticipantes = converGrup->getListaParticipantes(); 
                      int cantVistos = 0;
                        for (auto it = colParticipantes.begin(); it != colParticipantes.end(); it++)
                        {;
                          if(it->second!=user)
                          {
                            vistoPor = msj->getVistoPor(it->second->getNumTel()); 
                            if(vistoPor!=NULL)
                            {
                              if(vistoPor->getVisto())
                              {
                                cout << "\n----------------------------\n";
                                cout << it->second->getNombre() << " - " << it->second->getNumTel();
                                vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();
                                cantVistos++;             
                              }
                            }
                            else
                            {
                                cout << "\n----------------------------\n";
                                cout << it->second->getNombre() << " - " << it->second->getNumTel();
                                cout << "ELIMINADO por el participante";
                            }
                          }       
                        }
                        if(cantVistos==0)
                        {
                          cout << "Ningún participante ha visto el mensaje aún"<<endl; 
                        }
                    }
                    else
                    {
                      cout << "El mensaje no pertenece a una conversación activa"<<endl; 
                    } 
                  }
                  else
                  {
                    cout << "Debe ser el remitente del mensaje para ver la info de los receptores"<<endl; 
                  }
                }
                cout << endl;
                cout << "\nDeseas ver info de los receptores de otro mensaje enviado?" << endl;
                cout << "  1) SI" << endl;
                cout << "  2) NO" << endl;
                cin >> opt;
                if (opt == 2)
                {
                salir = true;
                }
              }
          }
        }
        else
        {
            cout << "Esta conversación no tiene mensajes" << endl;
        }       
    }
  }
}

string ControllerConvMens::randomStr(int ch)
{
  string result = "";
  bool salir = false;
  const int ch_MAX = 26;
  char alpha[ch_MAX] = {  'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 
                          'u','v', 'w', 'x', 'y', 'z' };
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


void ControllerConvMens::setConversacionColSis(Conversacion* conv, int id){
   this->colConversSis.insert({id, conv});
}

void ControllerConvMens::ingresarIdConversacionMostrarArch(int idConver, DtFechaHora* fecVisto, bool eliminar)
{

  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();
  ControllerUsuario* cu = ControllerUsuario::getInstancia();

  VistoMensaje* vistoPor;
  ConversacionArchivada* converArch;
  Conversacion *conver = user->getConver(idConver);
  if(conver==NULL)
  {
    cout << "ERROR - El id ingresado no está en su lista de conversaciones";
  }
  else if(conver->getActivo())
  {
    cout << "ERROR - El id ingresado no es de una conversación archivada";
  }
  else
  {
    converArch = dynamic_cast<ConversacionArchivada*>(conver);

    if (conver->isColMensajesEmpty()){
        cout << "Esta conversación no tiene mensajes" << endl;
    }
    else
    {
        bool msjBorrado, mostreMsj = false;
        map<string,Mensaje*> colMensajesPorConver = conver->getListaMensajes();
          
        for (auto it = colMensajesPorConver.begin(); it != colMensajesPorConver.end(); it++)
        {
          MSimple* msjSimple = new MSimple();
          MImagen* msjImg = new MImagen();
          MVideo* msjVideo = new MVideo();
          MContacto* msjCon = new MContacto();
          Mensaje *msj = it->second;
          msjSimple = dynamic_cast<MSimple*>(msj);
          msjImg = dynamic_cast<MImagen*>(msj);
          msjVideo = dynamic_cast<MVideo*>(msj);
          msjCon = dynamic_cast<MContacto*>(msj);

          Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());

          if(converArch!=NULL)
          {
            if(remitente!=user)
            {
                if(msj->getVistoPor(user->getNumTel())==NULL)
                {
                    //Significa que hubo borrado logico
                    msjBorrado = true;
                }
            }
          }

          if(!msjBorrado)
          {
          mostreMsj = true;

          cout << "\n----------------------------\n";
          if(msjSimple!=NULL)
          {//Caso Msj Simple
            cout << remitente->getNombre() << ": " << msjSimple->getTexto() << endl;
            cout << "Codigo: " << msjSimple->getCodigo();
          }
          else if(msjImg!=NULL)
          {//Caso Msj Imagen
            cout << remitente->getNombre() << ": " << msjImg->getUrl() << endl;
            cout << "Codigo: " << msjImg->getCodigo();
            cout << "URL: " << msjImg->getUrl();
            cout << "Formato: " << msjImg->getFormato();
            cout << "Tamaño: " << msjImg->getTamano();
            cout << "Texto: " << msjImg->getTexto();
          }
          else if(msjVideo!=NULL)
          {//Caso Msj Video
            cout << remitente->getNombre() << ": " << msjVideo->getUrl() << endl;
            cout << "Codigo: " << msjVideo->getCodigo();
            cout << "URL: " << msjVideo->getUrl();
            cout << "Duración: " << msjVideo->getDuracion();
          }
          else if(msjCon!=NULL)
          {//Caso Msj Contacto
            cout << remitente->getNombre() << ": Nombre contacto -:" << msjCon->getContacto().getNombre() << " - Número contacto -:" << msjCon->getContacto().getNumTel() << endl;
            cout << "Codigo: " << msjCon->getCodigo();
          }
            if(remitente==user)
            {
                bool visto;
                if(converArch!=NULL)
                {
                    if(msj->getVistoPor(converArch->getOtroParticipante(user)->getNumTel()) != NULL)
                    {
                      vistoPor = msj->getVistoPor(converArch->getOtroParticipante(user)->getNumTel());
                      visto = vistoPor->getVisto();
                    }
                    else
                    {
                      cout << endl << "VISTO y ELIMINADO por el destinatario";
                    }
                }
                if(visto) 
                {
                  vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();        
                }
                else
                {
                  msj->getFechayHora()->mostrarFechayHoraEnviado();
                }    
            }
            else
            {
                vistoPor = msj->getVistoPor(user->getNumTel());
                if(!vistoPor->getVisto()) 
                {
                  vistoPor->setVisto();
                  vistoPor->setFecHoraVisto(fecVisto);
                }
                msj->getFechayHora()->mostrarFechayHoraEnviado();
            }
          }   
        }
        //Aca Termina el Listado de los mensajes
        //Faltan seleccionar el mensaje para ver detalle
        if(mostreMsj)
        {
          cout << "\n----------------------------\n";
          string codigo;
          if(eliminar==true)
          {
              //Eliminar Mensaje
              cout << endl;
              cout << "Ingresar el codigo del mensaje que desee eliminar" << endl;
              cin >> codigo;
              cout << endl;
              if(converArch!=NULL)
              {
                Mensaje* msj = converArch->getMensaje(codigo);
                if (msj==NULL)
                {
                    cout << "El mensaje no pertenece a la conversación o no existe"<<endl; 
                }
                else
                {
                  Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
                  //Eliminar mensaje privado
                  if(user==remitente){
                    msj->eraseVistoPor(user->getNumTel());
                    msj->eraseVistoPor(remitente->getNumTel());
                    converArch->eraseMensaje(codigo);
                    colMensajesSis.erase(codigo);
                    msj->~Mensaje();
                    //Si es remitente lo elimina de todos los mensajes
                    cout << "\nMensaje eliminado de la conversación correctamente\n";
                  }else
                  {
                    msj->eraseVistoPor(user->getNumTel());
                    cout << "\nMensaje eliminado (para tí) correctamente\n";
                  }  
                }               
              }
              else
              {
                cout << "El mensaje no pertenece a una conversación archivada"<<endl; 
              } 
          }
          else
          {
              //Ver Mensaje
              int opt;
              bool salir = false;
              cout << "Deseas ver info de los receptores de algún mensaje enviado?" << endl;
              cout << "  1) SI" << endl;
              cout << "  2) NO" << endl;
              cin >> opt;
              if (opt == 2)
              {
              salir = true;
              }
              while (!salir)
              {           
                cout << endl;
                cout << "Ingresar el codigo del mensaje para ver la info de los receptores" << endl;
                cin >> codigo;
                cout << endl;
                Mensaje* msj;
                if(converArch!=NULL){msj = converArch->getMensaje(codigo);}
                if (msj==NULL)
                {
                    cout << "El mensaje no pertenece a la conversación o no existe"<<endl; 
                }
                else
                {
                  Usuario* remitente = cu->encontrarUsuarioxnumTel(msj->getNumRemitente());
                  if(remitente==user){
                      VistoMensaje* vistoPor;
                      cout << "\n----------------------------\n";
                      if(converArch!=NULL)
                      {
                        Usuario* destinatario = converArch->getOtroParticipante(remitente);
                        vistoPor = msj->getVistoPor(destinatario->getNumTel());
                        if(vistoPor!=NULL)
                        {
                          if(vistoPor->getVisto())
                          {
                              cout << destinatario->getNombre() << " - " << destinatario->getNumTel();
                              vistoPor->getfecHoraVisto()->mostrarFechayHoraVisto();
                          }
                          else
                          {
                          cout << "El mensaje aún no ha sido VISTO por su destinatario";
                          }
                        }
                        else
                        {
                            cout << "El mensaje ha sido ELIMINADO por su destinatario";
                        }
                      }
                      else
                      {
                      cout << "El mensaje no pertenece a una conversación archivada"<<endl; 
                      } 
                  }
                  else
                  {
                    cout << "Debe ser el remitente del mensaje para ver la info de los receptores"<<endl; 
                  }
                }
                cout << endl;
                cout << "\nDeseas ver info de los receptores de otro mensaje enviado?" << endl;
                cout << "  1) SI" << endl;
                cout << "  2) NO" << endl;
                cin >> opt;
                if (opt == 2)
                {
                salir = true;
                }
              }
          }
        }
        else
        {
            cout << "Esta conversación no tiene mensajes" << endl;
        } 

      }
    }
}


void ControllerConvMens::archivarConversacion(){
  
  ControllerSesion *cSesion = ControllerSesion::getInstancia();
  Usuario *user = cSesion->getUserLoggeado();

  int idConver;

  map <int,Conversacion*> colConvers = user->getListaConvers();

  cout<<endl<<"------------------------------"<<endl;
  cout<<"Ingrese la id de la conversacion que desee archivar: "<<endl;
  cin>>idConver;
  cout<<"------------------------------"<<endl;

      ConversacionArchivada* converArch = new ConversacionArchivada();
      ConversacionGrupal *converGrup = new ConversacionGrupal();
      ConversacionPrivada *converPriv = new ConversacionPrivada(); 
      Conversacion *conver = user->getConver(idConver); 
      if(conver==NULL)
      {
          cout << "ERROR - El id ingresado no está en su lista de conversaciones";
      }
      else
      {
        converArch = dynamic_cast<ConversacionArchivada*>(conver);
        converPriv = dynamic_cast<ConversacionPrivada*>(conver);
        converGrup = dynamic_cast<ConversacionGrupal*>(conver);

        if(converPriv!=NULL)
        {
          Usuario* destinatario = converPriv->getOtroParticipante(user);
          converArch = new ConversacionArchivada(idConver, false, user, destinatario);
          conver = converArch;
          converArch = dynamic_cast<ConversacionArchivada*>(conver);

          converArch->setListaMensajes(converPriv->getListaMensajes());//Traspaso la lista de mensajes de converPriv a converArch

          user->eraseConver(idConver);//Elimino la conversación activa de la colección del usuario
          destinatario->eraseConver(idConver);
          converPriv->~ConversacionPrivada();//Llamo al destuctor de la instancia de conversacionPrivada

          if(converArch!=NULL)
          {           
          user->setConver(converArch);//Agrego la conversación archivada a la colección del usuario
          destinatario->setConver(converArch);
          user->setCantArchivadas(user->getCantArchivadas() + 1);
          destinatario->setCantArchivadas(destinatario->getCantArchivadas() + 1);
          cout<<"Se archivó la conversacion con Id: " << idConver <<endl;
          }

        }
        else if (converGrup!=NULL)
        {
          cout << "Las conversaciones grupales no pueden archivarse";
        }
        else if (converArch!=NULL)
        {
          cout << "Esta conversación ya se encuentra archivada";
        }
      }
}


void ControllerConvMens::verArchivadas(){
    
    ControllerSesion *cSesion = ControllerSesion::getInstancia();
    Usuario *user = cSesion->getUserLoggeado();
    map <int,Conversacion*> colConvers = user->getListaConvers();
    bool listeArch = false;

    for (auto it = colConvers.begin(); it != colConvers.end(); it++)
    {
      if( user->getConver(it->first)->getActivo()==false){
            ConversacionArchivada *converArch = new ConversacionArchivada;
            Conversacion *conver = it->second;
            converArch = dynamic_cast<ConversacionArchivada*>(conver);

            if (converArch != NULL){
                // La conversión a ConversacionArchivada se realizó con éxito
              listeArch = true;
              cout << "\n----------------------------\n";
              cout << converArch->getOtroParticipante(user)->getNombre() << ": " << converArch->getOtroParticipante(user)->getNumTel() << endl;
              cout << "Id Conversación: " << converArch->getId() << endl;
              //  cout << archivada->getId() << endl;
            } 

          }
      }
    if(!listeArch)
    {
      cout << "No tiene ninguna conversación archivada" << endl;
    }
    }      


ControllerConvMens::~ControllerConvMens(){}
