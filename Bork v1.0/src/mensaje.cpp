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
        case 4:
            cout<<"Encuentras un tesoro."<<endl;
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
void Mensaje::ataca_monstruo(int danio){
    cout<<"El monstruo te inglige: "<< danio<<endl;
}
void Mensaje::atacas_monstruo(int danio){
    cout<<"Infliges: "<<danio<<" puntos al monstruo"<<endl;
}
void Mensaje::combate_ganado(){
    cout<<"Has ganado el combate"<<endl;
}
void Mensaje::combate_perdido(){
    cout<<"Has muerto"<<endl;
}
void Mensaje::vidas(int jugador, int monstruo){
    cout<<"Tienes: "<<jugador<<" puntos de vida."<<endl;
    cout<<"El monstruo tiene: "<<monstruo<<" puntos de vida."<<endl;
}
void Mensaje::ganas_tesoro(){
    cout<<"Encuentras un Tesoro, bien hecho."<<endl;
}
void Mensaje::encuentras_mapa(){
    cout<<"Has encontrado un mapa, ya puedes orientarte."<<endl;
}
void Mensaje::encuentras_llave(){
    cout<<"Enhorabuena, has encontrado la llave."<<endl;
}
void Mensaje::tienes_mapa(){
    cout<<"Encuentras un mapa, pero ya tienes uno."<<endl;
}
void Mensaje::has_ganado(){
    cout<<"Has cumplido con tu cometido, puedes regresar a casa"<<endl;
}
void Mensaje::puntuacion(int tesoros){
    cout<<"Finalizas la aventura con: "<<tesoros<<" tesoros."<<endl;
}
void Mensaje::encuentras_espada(){
    cout<<"Encuentras una espada, eres más eficiente combatiendo."<<endl;
}
string Mensaje::wait(){
    string uno;
    cout<< "¿Que haces?" << endl;
    cin >> uno;
    return uno;
}
void Mensaje::escapas(){
    cout<< "Consigues escapar del combate"<<endl;
}
void Mensaje::mostrar_inventario(vector <Objeto> ob){
    cout<< "El inventario es: ";
    for(int i=0; i < ob.size();i++){cout<<ob[i].to_char()<<" , ";}
    cout<<endl;
}