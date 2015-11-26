#ifndef _EVENTOS
#define _EVENTOS
//#include "monstruo.hpp"
#include "mensaje.hpp"
#include <cstdlib>
class Evento{
private:
    Mensaje mensaje_evento;
    int tipo;
    void revela_evento();
public:
    Evento();
    void siguiente_evento(int posicion_nueva);
};
#endif