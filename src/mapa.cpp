#include "mapa.hpp"
Mapa::Mapa(){
    mapa.reserve(10);
        for(int i = 0; i < 10; i++)mapa[i].reserve(10);
        for(int m = 0; m < 10; m++){
            for(int n = 0; n < 10; n++){
                if(m == 0)mapa[m][n]=0;
                else if(n == 0)mapa[m][n]=0;
                else if(m == SIZE-1)mapa[m][n]=0;
                else if(n == SIZE-1)mapa[m][n]=0;
                else mapa[m][n]=rand()%4;
            }
        }
}
void Mapa::inicia_juego(Jugador j1){
    this -> j1= j1;
    juego = true;
    posicion_y = rand()%SIZE;
    posicion_x = rand()%SIZE;
    pos = NORTE;
    
}
void Mapa::moverse(Jugador::movimiento direccion){
    if (direccion == Jugador::ADELANTE){
        switch (pos){
            case NORTE:
                posicion_y++;
                break;
            case SUR:
                posicion_y--;
                break;
            case OESTE:
                posicion_x--;
                break;
            case ESTE:
                posicion_x++;
                break;
        }
    }
    else if (direccion == (Jugador::GIRA_IZQUIERDA||Jugador::GIRA_DERECHA)){
        calcular_nueva_orientacion(direccion);
    }
    else {
        mapa_mensaje.fallo_movimiento(" Al moverse ");
    }
}
void Mapa::calcular_nueva_orientacion(Jugador::movimiento giro){
    switch (pos){
        case NORTE:
            girar_norte(giro);
            break;
        case SUR:
            girar_sur(giro);
            break;
        case OESTE:
            girar_oeste(giro);
            break;
        case ESTE:
            girar_este(giro);
            break;
    }
}
void Mapa::girar_norte(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = OESTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = ESTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Norte ");
    }
}
void Mapa::girar_sur(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = ESTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = OESTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Sur ");
    }
}
void Mapa::girar_este(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = NORTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = SUR;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Este ");
    }
}
void Mapa::girar_oeste(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = SUR;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = NORTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar Oeste ");
    }
}
void Mapa::observar(){
    zonas izquierda, derecha, delante, detras;
    izquierda = (Mapa::zonas) mapa[posicion_x -1][posicion_y];
    derecha = (Mapa::zonas) mapa[posicion_x +1][posicion_y];
    delante = (Mapa::zonas) mapa[posicion_x][posicion_y +1];
    detras = (Mapa::zonas) mapa[posicion_x][posicion_y -1];
    mapa_mensaje.comenta_evento(izquierda);
    mapa_mensaje.comenta_evento(derecha);
    mapa_mensaje.comenta_evento(delante);
    mapa_mensaje.comenta_evento(detras);
}