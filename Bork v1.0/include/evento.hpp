#ifndef _EVENTOS
#define _EVENTOS
#include "monstruo.hpp"
#include "mensaje.hpp"
#include "objeto.hpp"
#include <cstdlib>
class Evento{
private:
    Mensaje mensaje_evento;
    int tipo;
    int revela_evento();
public:
    Evento();
    int siguiente_evento(int posicion_nueva);
};
#endif