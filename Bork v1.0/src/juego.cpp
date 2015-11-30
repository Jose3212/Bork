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
void Juego::usa(Objeto o1){
    Objeto::tipo map, weap, t;
    map = Objeto::MAPA;
    weap = Objeto::ARMA;
    vector<Objeto> aux;
    aux = j1.get_inventario();
    int it;
    for (int i = 0; i < aux.size(); i++){
        if (aux[i]==o1){
            it = i;
        }
        else it = -1;
    }
    if(it != -1){
        t=aux[it].get_tipo();
        if(t == map){
            mapa();
        }
        else if(t == weap){
            j1.equipa(aux[it]);
        }
    }
    else{
        m2.no_posees_objeto();
    }
}