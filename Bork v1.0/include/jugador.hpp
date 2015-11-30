#ifndef _JUGADOR
#define _JUGADOR
#include <string>
#include <algorithm>
#include <vector>
#include "mensaje.hpp"
#include "objeto.hpp"
class Jugador{
private:
    string nombre;
    Mensaje jugador_mensaje;
    vector <Objeto> inventario;
    Objeto equipado;
    int num_tesoros = 0;
    int max_obj = 5;
public:
    Jugador(){};
    Jugador(string nombre){this->nombre=nombre;}
    enum acciones{
        LUCHA,HUYE,NADA,ABRE,USA
    };
    enum movimiento{
        ADELANTE=0,RETROCEDE=1,GIRA_IZQUIERDA=2,GIRA_DERECHA=3
    };
    void pierde();
    void aniade_a_inventario(Objeto o1);
    void aniade_tesoro(){num_tesoros++;}
    void elimina_de_inventario(int posicion);
    void equipa(Objeto o1);
    void usar(Objeto o1);
    string get_nombre();
    vector<Objeto> get_inventario(){return inventario;}
};
#endif