# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= ./bin/Bork

SOURCES=	src/jugador.cpp src/evento.cpp src/juego.cpp src/mapa.cpp src/mensaje.cpp src/monstruo.cpp
TEMP = src/*~ include/*~
OBJ_LEX=	obj/main.o
SOURCE_LEX=	src/lex.yy.c
LEX=  main.l
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
CC = g++ -Wno-write-strings -std=c++11
C=	gcc -Wno-write-strings

# orden que sera ejecutada por defecto
#
default:	$(CARPETAS) $(OBJ_LEX) $(SOURCES) $(TARGETS)  

# regla de ejecucion
#
$(OBJ_LEX):	$(SOURCE_LEX)
	$(CC) $(CXXFLAGS) $^ -o $@
$(CARPETAS):
	mkdir -p $(CARPETAS)
$(TARGETS):	$(OBJECTS)	
	$(CC) -o $@ $^ obj/main.o $(LDFLAGS)
$(OBJECTS):
	$(CC) $(CXXFLAGS) src/$(@F:.o=.cpp) -o $@
$(SOURCE_LEX):	$(LEX)
	lex	$^
	mv lex.yy.c src/

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
	rm -f $(OBJ_LEX)
	rm -f $(SOURCE_LEX)
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
	tar -zcf practica_lex.tgz .

