#include "jugador.hpp"
void Jugador::pierde(){
    jugador_mensaje.pierde(this->nombre);
}
string Jugador::get_nombre(){
    return nombre;
}