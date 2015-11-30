#include "monstruo.hpp"
int Monstruo::ataca(){
    int aux = ataque;
    if(rand()%6+1==6){
        aux*=0.1;
    }
    return aux;
}
void Monstruo::daniado(int golpe){
    hp-=golpe;
}