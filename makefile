todo: main.o Conversacion.o DtConversacion.o DtMensaje.o DtFechaHora.o DtUsuario.o Estado.o DtEstado.o Mensaje.o ConversacionGrupal.o DtConversacionGrupal.o Usuario.o ConversacionPrivada.o DtConversacionPrivada.o ConversacionArchivada.o DtConversacionArchivada.o
	g++ -g -Wall -o main main.o Conversacion.o DtConversacion.o DtMensaje.o DtFechaHora.o DtUsuario.o Estado.o DtEstado.o Mensaje.o ConversacionGrupal.o DtConversacionGrupal.o Usuario.o ConversacionPrivada.o DtConversacionPrivada.o ConversacionArchivada.o DtConversacionArchivada.o
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
clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f main
