#include "jugador.hpp"
void Jugador::pierde(){
    jugador_mensaje.pierde(this->nombre);
}
string Jugador::get_nombre(){
    return nombre;
}
void Jugador::aniade_inventario(Objeto o1){
    if(inventario.size()<max_obj){
        inventario.push_back(o1);
    }
    else{
        jugador_mensaje.inventario_lleno();
    }
}
void Jugador::elimina_de_inventario(int posicion){
    vector <Objeto> aux;
    inventario.erase(inventario.begin()+(posicion-1));
    for(int i = 0; i < max_obj; i++){
        if(i==(posicion-1)){
            aux.push_back(inventario[i]);
        }
    }
    inventario.clear();
    inventario.swap(aux);
}
void Jugador::usar(Objeto o1){
    vector<Objeto>::iterator it;
    it= find(inventario.begin(),inventario.end(),o1);
    if (it != inventario.end()){
        (*it).uso();
    }
    else{
        jugador_mensaje.no_posees_objeto();
    }
}