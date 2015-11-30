#ifndef _MONSTRUO
#define _MONSTRUO
#include <cstdlib>
class Monstruo{
private:
    int hp;
    int ataque;
public:
    Monstruo(){};
    Monstruo(int hp, int ataque){
        this->hp=hp;
        this->ataque=ataque;
    }
    int ataca();
    void daniado(int golpe);
    int get_hp(){return hp;}

};
#endif