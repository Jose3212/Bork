#include "juego.hpp"
Juego::Juego(Jugador j1){
    this->j1 = j1;
    m1.inicia_juego(j1);
}
void Juego::moverse(Jugador::movimiento direccion){
    m1.moverse(direccion);
    m1.observar();
}
void Juego::mapa(){
    m1.muestra_mapa();
}