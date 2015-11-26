#ifndef _JUGADOR
#define _JUGADOR
#include <string>
#include "mensaje.hpp"
class Jugador{
private:
    string nombre;
    Mensaje jugador_mensaje;
public:
    Jugador(){};
    Jugador(string nombre){this->nombre=nombre;}
    enum acciones{
        LUCHA,HUYE,NADA,ABRE
    };
    enum movimiento{
        ADELANTE=0,RETROCEDE=1,GIRA_IZQUIERDA=2,GIRA_DERECHA=3
    };
    void pierde();
    string get_nombre();
};
#endif