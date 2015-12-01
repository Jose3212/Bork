#ifndef _MAPA
#define _MAPA
#include <cstdlib>
#include "jugador.hpp"
#include "evento.hpp"
#include "monstruo.hpp"
class Mapa{
private:
    const int SIZE = 40;
    vector<vector<unsigned int > > mapa;
    int posicion_y, posicion_x;
    bool juego = false; //Al principio no se juega;
    enum orientacion{
        NORTE, ESTE, SUR, OESTE
    };
    Mapa::orientacion pos;
    Jugador j1;
    Evento even1_principal;
    Mensaje mapa_mensaje;
    void calcular_nueva_orientacion(Jugador::movimiento giro);
    void girar_norte(Jugador::movimiento dir);
    void girar_sur(Jugador::movimiento dir);
    void girar_oeste(Jugador::movimiento dir);
    void girar_este(Jugador::movimiento dir);
    
public:
    Mapa();
    void inicia_juego(Jugador j1);    
    int moverse(Jugador::movimiento direccion);
    void observar();
    enum zonas{
        VACIO = 0,
        AGUA = 1,
        CAMINO = 2,
        BOSQUE = 3,
        TESORO = 4,
        ESPECIAL1 = 5,
        ESPECIAL2 = 6
    };
    void genera(int &posx, int &posy, Mapa::zonas z);
    bool juego_en_marcha(){return juego;}
    void muestra_mapa();
    void fin_juego(){juego = false;}
    void modifica(zonas a){mapa[posicion_x][posicion_y]=a;}
};
#endif