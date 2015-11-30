# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= ./bin/Bork

SOURCES=	src/jugador.cpp src/main.cpp src/evento.cpp src/juego.cpp src/mapa.cpp src/mensaje.cpp src/monstruo.cpp
TEMP = src/*~ include/*~
OBJECTS=	$(SOURCES:src/%.cpp=obj/%.o)
DAT	=	data
INCLUDE = include
CARPETAS=	include obj src bin data
# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -c -I/usr/include -I$(INCLUDE) -I.
CXXFLAGS=  -c -I/usr/include -I$(INCLUDE) -I.
DEPURACION=	-g -I/usr/include -I$(INCLUDE) -I.
# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lfl

# definicion del compilador
#
CC = g++ -Wno-write-strings

# orden que sera ejecutada por defecto
#
default:	$(CARPETAS) $(SOURCES) $(TARGETS)

# regla de ejecucion
#
$(CARPETAS):
	mkdir -p $(CARPETAS)
$(TARGETS):	$(OBJECTS)	
	$(CC) -o $@ $^ $(LDFLAGS)
$(OBJECTS):
	$(CC) $(CXXFLAGS) src/$(@F:.o=.cpp) -o $@

.PHONY: depuracion
depuracion :
	$(CC) $(DEPURACION) $(SOURCES) -o $(TARGETS) $(LDFLAGS)
#
clean:
	rm -f $(OBJECTS)
	rm -f $(TARGETS)

#
#
directorio:
	mkdir src bin obj data include
programa:
	$(TARGETS)
redo:
	rm -f $(TARGETS)
	rm -f $(OBJECTS)
	make

#
#
superclean:
	rm -f $(OBJECTS)
	rm -f $(TEMP)
	rm -f $(TARGETS)

#
#
tgz:
	rm -f $(OBJECTS)
	rm -f $(TEMP)
	tar -zcf practica.tgz -C ./src/ . -C ../bin/ . -C ../include/ .

