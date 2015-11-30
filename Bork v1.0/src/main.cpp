#include "juego.hpp"
int main(){
    string nombre;
    cout<<"Introduzca nombre jugador"<<endl;
    cin>>nombre;
    Jugador j1(nombre);
    Juego j(j1);
    while(j.juego_en_marcha()){
        cout<<"Introduzca accion: "<< j1.get_nombre()<<endl;
        cin>>nombre;
        //cout<<nombre<<endl;
        if(nombre == "adelante")j.moverse(Jugador::ADELANTE);
        else if(nombre == "mapa")j.mapa();
        //else if(nombre = "huye")j.interaccion(HUYE);
        //else if(nombre = "nada")j.interaccion(NADA);
       // else if(nombre = "abre")j.interaccion(ABRE);
        else if(nombre == "gira"){
            cout<<"¿Donde?"<<endl;
            cin>>nombre;
            if (nombre == "izquierda")j.moverse(Jugador::GIRA_IZQUIERDA);
            if (nombre == "derecha")j.moverse(Jugador::GIRA_DERECHA);
        }
        else if(nombre == "salir"){return 0;}
        else{
            cout<<"Introduzca Accion valida"<<endl;
        }
    }
}