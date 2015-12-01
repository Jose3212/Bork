#include "evento.hpp"
Evento::Evento(){
    tipo = 0;
}
int Evento::revela_evento(){
    int monstruo = 0;
    if (tipo == 4){
        if(rand()%20+1==20){
            mensaje_evento.aparece_monstruo();
            monstruo = 1;
        }
        else if(rand()%4+1==4){
            monstruo=5;
        }
        else {
            mensaje_evento.ganas_tesoro();
            monstruo= 2;
        }
    }
    else if (tipo == 5){
        mensaje_evento.encuentras_mapa();
        monstruo = 3;
    }
    else if (tipo == 6){
        mensaje_evento.encuentras_llave();
        monstruo = 4;
    }
    else{
        switch(tipo){
            case 0:
                mensaje_evento.limite();
                break;
            case 1:
                mensaje_evento.agua();
                break;
            case 2:
                mensaje_evento.camino();
                break;
            case 3:
                mensaje_evento.estas_en_un_bosque();
                break;
        }
    }
    return monstruo;
}
int Evento::siguiente_evento(int posicion_nueva){
    tipo = posicion_nueva;
    return revela_evento();
}