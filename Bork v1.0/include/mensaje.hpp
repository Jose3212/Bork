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
};
#endif