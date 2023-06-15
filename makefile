todo: main.o Conversacion.o DtConversacion.o DtMensaje.o DtFechaHora.o DtUsuario.o Estado.o DtEstado.o Mensaje.o ConversacionGrupal.o DtConversacionGrupal.o Usuario.o ConversacionPrivada.o DtConversacionPrivada.o ConversacionArchivada.o DtConversacionArchivada.o ControllerConvMens.o ControllerUsuario.o InterfaceUsuario.o InterfaceSesion.o InterfaceConvMens.o ControllerSesion.o MSimple.o DtMSimple.o MImagen.o DtMImagen.o MVideo.o DtMVideo.o MContacto.o DtMContacto.o
	g++ -g -Wall -o main main.o Conversacion.o DtConversacion.o DtMensaje.o DtFechaHora.o DtUsuario.o Estado.o DtEstado.o Mensaje.o ConversacionGrupal.o DtConversacionGrupal.o Usuario.o ConversacionPrivada.o DtConversacionPrivada.o ConversacionArchivada.o DtConversacionArchivada.o ControllerConvMens.o ControllerUsuario.o InterfaceUsuario.o InterfaceSesion.o InterfaceConvMens.o ControllerSesion.o MSimple.o DtMSimple.o MImagen.o DtMImagen.o MVideo.o DtMVideo.o MContacto.o DtMContacto.o
main.o: main.cpp
	g++ -g -Wall -c main.cpp
Conversacion.o: Conversacion.cpp Conversacion.h
	g++ -g -Wall -c Conversacion.cpp
DtConversacion.o: DtConversacion.cpp DtConversacion.h
	g++ -g -Wall -c DtConversacion.cpp
DtFechaHora.o: DtFechaHora.cpp DtFechaHora.h
	g++ -g -Wall -c DtFechaHora.cpp
Estado.o: Estado.cpp Estado.h
	g++ -g -Wall -c Estado.cpp
DtEstado.o: DtEstado.cpp DtEstado.h
	g++ -g -Wall -c DtEstado.cpp
Mensaje.o: Mensaje.cpp Mensaje.h
	g++ -g -Wall -c Mensaje.cpp
DtMensaje.o: DtMensaje.cpp DtMensaje.h
	g++ -g -Wall -c DtMensaje.cpp
Usuario.o: Usuario.cpp Usuario.h
	g++ -g -Wall -c Usuario.cpp Usuario.h
DtUsuario.o: DtUsuario.cpp DtUsuario.h
	g++ -g -Wall -c DtUsuario.cpp
ConversacionGrupal.o: ConversacionGrupal.cpp ConversacionGrupal.h
	g++ -g -Wall -c ConversacionGrupal.cpp
DtConversacionGrupal.o: DtConversacionGrupal.cpp DtConversacionGrupal.h
	g++ -g -Wall -c DtConversacionGrupal.cpp
ConversacionPrivada.o: ConversacionPrivada.cpp ConversacionPrivada.h
	g++ -g -Wall -c ConversacionPrivada.cpp
DtConversacionPrivada.o: DtConversacionPrivada.cpp DtConversacionPrivada.h
	g++ -g -Wall -c DtConversacionPrivada.cpp
ConversacionArchivada.o: ConversacionArchivada.cpp ConversacionArchivada.h
	g++ -g -Wall -c ConversacionArchivada.cpp
DtConversacionArchivada.o: DtConversacionArchivada.cpp DtConversacionArchivada.h
	g++ -g -Wall -c DtConversacionArchivada.cpp
ControllerConvMens.o: ControllerConvMens.cpp ControllerConvMens.h
	g++ -g -Wall -c ControllerConvMens.cpp
ControllerUsuario.o: ControllerUsuario.cpp ControllerUsuario.h
	g++ -g -Wall -c ControllerUsuario.cpp
InterfaceUsuario.o: InterfaceUsuario.h
	g++ -g -Wall -c InterfaceUsuario.h
InterfaceSesion.o: InterfaceSesion.h
	g++ -g -Wall -c InterfaceSesion.h
InterfaceConvMens.o: InterfaceConvMens.h
	g++ -g -Wall -c InterfaceConvMens.h
Factory.o: Factory.cpp Factory.h
	g++ -g -Wall -c Factory.cpp 
ControllerSesion.o: ControllerSesion.cpp ControllerSesion.h
	g++ -g -Wall -c ControllerSesion.cpp
MSimple.o: MSimple.cpp MSimple.h
	g++ -g -Wall -c MSimple.cpp
DtMSimple.o: DtMSimple.cpp DtMSimple.h
	g++ -g -Wall -c DtMSimple.cpp
MImagen.o: MImagen.cpp MImagen.h
	g++ -g -Wall -c MImagen.cpp
DtMImagen.o: DtMImagen.cpp DtMImagen.h
	g++ -g -Wall -c DtMImagen.cpp
MVideo.o: MVideo.cpp MVideo.h
	g++ -g -Wall -c MVideo.cpp
DtMVideo.o: DtMVideo.cpp DtMVideo.h
	g++ -g -Wall -c DtMVideo.cpp
MContacto.o: MContacto.cpp MContacto.h
	g++ -g -Wall -c MContacto.cpp
DtMContacto.o: DtMContacto.cpp DtMContacto.h
	g++ -g -Wall -c DtMContacto.cpp
clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f main
