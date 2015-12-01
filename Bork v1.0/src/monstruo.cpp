#include "monstruo.hpp"
int Monstruo::ataca(){
    int aux = ataque;
    if(rand()%10+1==10){
        aux*=0.1;
    }
    return aux;
}
void Monstruo::daniado(int golpe){
    hp-=golpe;
}