#ifndef _JUEGO
#define _JUEGO
#include "mapa.hpp"
class Juego{
private:
    Mapa m1;
    Jugador j1;
    Mensaje m2;
public:
    Juego( Jugador j1);
    void interaccion(Jugador::movimiento direccion);
    bool juego_en_marcha(){return m1.juego_en_marcha();}
    void mapa();
};
#endif