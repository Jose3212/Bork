#include "juego.hpp"
Juego::Juego(Jugador j1){
    this->j1 = j1;
    m1.inicia_juego(j1);
}
void Juego::aniade_jugador(Jugador j1){
    this->j1 = j1;
    m1.inicia_juego(j1);
}
void Juego::mostrar_inventario(){
    m2.mostrar_inventario(j1.get_inventario());
}
void Juego::moverse(Jugador::movimiento direccion){
    int opcion;
    Objeto mapa(2),llave(4),espada(1);
    bool combate_r;
    opcion=m1.moverse(direccion);
    //if (opcion == 0)m1.observar();
    if(opcion == 1){
        Monstruo mons(rand()%20+1,rand()%5+1);
        string accion;
        accion = m2.wait();
        if (accion == "huye"){
            if(rand()%4+1==4){
                m2.escapas();
            }
            else goto combate;
        }
        else{
            combate:
            combate_r = combate(mons);
            if (combate_r){
                m2.ganas_tesoro();
                j1.aniade_tesoro();
            }
            else {
                j1.pierde();
                m1.fin_juego();
            }
        }
    }
    else if(opcion == 2){
        j1.aniade_tesoro();
    }
    else if(opcion == 3){
        if(!mapa_1){
            mapa_1 = true;
            j1.aniade_a_inventario(mapa);
        }
        m2.tienes_mapa();
    }
    else if(opcion == 4){
        Monstruo mons(50,6);
        combate_r = combate(mons);
        if(combate_r){
            llave = true;
            m2.has_ganado();
            m2.puntuacion(j1.get_tesoros());
            m1.fin_juego();
        }
        else{
            j1.pierde();
            m1.fin_juego();
        }
    }

    else if(opcion == 5){
        m2.encuentras_espada();
        j1.aniade_a_inventario(espada);
    }
    m1.observar();
}
void Juego::mapa(){
    m1.muestra_mapa();
}
void Juego::usa(Objeto o1){
//   cout<<"1"<<endl;
    Objeto::tipo map, weap, t;
    map = Objeto::MAPA;
    weap = Objeto::ARMA;
    vector<Objeto> aux;
//    cout<<"1"<<endl;
    aux = j1.get_inventario();
//    cout<<"1"<<endl;
    int it = -1;
//   cout<<"1"<<endl;
    for (int i = 0; i < aux.size(); i++){
        if (aux[i]==o1){
            it = i;
        }
        else it = -1;
    }
//    cout<<"1"<<endl;
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
void Juego::salir(){
    m1.fin_juego();
}
void Juego::opciones(){
    mostrar_inventario();
    cout << "Introduzca accion: "<< j1.get_nombre() <<endl;
}