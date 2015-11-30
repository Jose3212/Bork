#include "mensaje.hpp"
Mensaje::Mensaje(){
    
}
void Mensaje::pierde(string j1){
    cout<<"El jugador "<<j1<<" ha perdido."<<endl;
}
void Mensaje::fallo_movimiento(string dir){
    cout<<"El movimiento pedido " << dir << " no se ha podido realizar"<<endl;
}
void Mensaje::comenta_evento(int tipo, int orientacion){
    switch(orientacion){
        case 0:
            cout<<"A tu izquierda: ";
            break;
        case 1:
            cout<<"A tu derecha: ";
            break;
        case 2:
            cout<<"Delante: ";
            break;
        case 3:
            cout<<"Detrás: ";
            break;
    }
    switch(tipo){
        case 0:
            cout<<"Encuentras vacío."<<endl;
            break;
        case 1:
            cout<<"Encuentras agua."<<endl;
            break;
        case 2:
            cout<<"Encuentras un camino."<<endl;
            break;
        case 3:
            cout<<"Encuentras un bosque."<<endl;
            break;
        
    }
}
void Mensaje::agua(){
    cout<<"Te encuentras en el agua, ¿qué haces?"<<endl;
}
void Mensaje::camino(){
    cout<<"Te ves en medio de un camino, ¿que direccion tomaras?"<<endl;
}
void Mensaje::estas_en_un_bosque(){
    cout<<"Estas en un bosque."<<endl;
}
void Mensaje::aparece_monstruo(){
    cout<<"Te encuentras con un monstruo, ¿que quieres hacer?"<<endl;
}
void Mensaje::limite(){
    cout<<"Estas en la nada"<<endl;
}
void Mensaje::inventario_lleno(){
    cout<<"El inventario de objetos está lleno."<<endl;
}
void Mensaje::no_posees_objeto(){
    cout<<"No posees el objeto que quieres usar"<<endl;
}