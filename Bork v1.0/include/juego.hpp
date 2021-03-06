#ifndef _JUEGO
#define _JUEGO
#include "mapa.hpp"
class Juego{
private:
    Mapa m1;
    Jugador j1;
    Mensaje m2;
    bool mapa_1, llave;
public:
    Juego( Jugador j1);
    Juego(){}
    void aniade_jugador(Jugador j1);
    void moverse(Jugador::movimiento direccion);
    void usa(Objeto o1);
    bool juego_en_marcha(){return m1.juego_en_marcha();}
    void mapa();
    bool combate(Monstruo mons);
    void mostrar_inventario();
    void salir();
    string get_nombre(){j1.get_nombre();}
    void opciones();
    void quita(int i);
};
#endif