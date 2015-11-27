#include "evento.hpp"
Evento::Evento(){
    tipo = 0;
}
void Evento::revela_evento(){
    int monstruo = rand()%6+1;
    if(monstruo == 6){
        mensaje_evento.aparece_monstruo();
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
}
void Evento::siguiente_evento(int posicion_nueva){
    tipo = posicion_nueva;
    revela_evento();
}