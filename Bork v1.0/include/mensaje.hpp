#ifndef _MENSAJES
#define _MENSAJES
//#include "mapa.hpp"
//#include "jugador.hpp"
#include <iostream>
using namespace std;
class Mensaje {
public:
    Mensaje();
    void pierde(string j1);
    void fallo_movimiento(string dir);
    void comenta_evento(int tipo, int orientacion);
    void limite();
    void agua();
    void camino();
    void estas_en_un_bosque();
    void aparece_monstruo();
    void inventario_lleno();
    void no_posees_objeto();
    void ataca_monstruo(int danio);
    void atacas_monstruo(int danio);
    void combate_ganado();
    void combate_perdido();
    void vidas(int jugador, int monstruo);
    void ganas_tesoro();
    void encuentras_mapa();
    void encuentras_llave();
    void tienes_mapa();
    void has_ganado();
    void puntuacion(int tesoros);
    void encuentras_espada();
};
#endif