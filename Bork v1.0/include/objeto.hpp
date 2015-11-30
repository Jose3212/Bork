#ifndef _OBJETO
#define _OBJETO
class Objeto{
public:
    enum tipo{
        ARMA, MAPA, TESORO, LLAVE
    };
    Objeto(){};
    Objeto(int n){
//        if (n == 0)t=NULL;
        if (n == 1)t=ARMA;
        else if (n == 2)t=MAPA;
        else if (n == 3)t=TESORO;
        else if (n == 4)t=LLAVE;
    }
    tipo get_tipo(){return t;}
    bool operator==(Objeto o1){if (t==o1.get_tipo())return true;else return false;}
private:
    tipo t;
};
#endif