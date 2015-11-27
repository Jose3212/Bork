#ifndef _MAPA
#define _MAPA
#include <vector>
#include <cstdlib>
#include "jugador.hpp"
#include "evento.hpp"
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
    
    void moverse(Jugador::movimiento direccion);
    void observar();
    enum zonas{
        VACIO = 0,
        AGUA = 1,
        CAMINO = 2,
        BOSQUE = 3
    };
    bool juego_en_marcha(){return juego;}
};
#endif