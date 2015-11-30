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
bool Juego::combate(Monstruo mons){
    int ataque_j, ataque_m;
    int hp_batalla = j1.get_hp();
    Objeto equipo = j1.get_equipo();
    ataque_j = j1.get_ataque();
    if(equipo.get_tipo()==Objeto::ARMA){
        ataque_j *= 5; 
    }
    while(hp_batalla > 0){
        ataque_m = mons.ataca();
        m2.ataca_monstruo(ataque_m);
        hp_batalla-=ataque_m;
        m2.atacas_monstruo(ataque_j);
        mons.daniado(ataque_j);
        m2.vidas(hp_batalla, mons.get_hp());
        if(mons.get_hp()<=0)break;
    }
    if(hp_batalla > 0){
        m2.combate_ganado();
        return true;
    }
    else{
        m2.combate_perdido();
        return false;
    }
}