%{
    #include "juego.hpp"
    #include <unistd.h>
    string direc;
    Juego j;
    int juega();
    Objeto mapa(2), espada(1);
%}
uso (usar|uso|equipar|usa)
girar   (giro|girar|gira)
direccion   (izquierda|derecha)
avanzar (delante|adelante)
detras (detras|atras)
salir (salir|Salir|exit|quit)
%%
{uso}" mapa"   {j.usa(mapa);return 0;}
{uso}" espada"  {j.usa(espada);return 0;}
{avanzar}  {j.moverse(Jugador::ADELANTE);return 0;}
{girar} {
    cout << "¿Donde?" << endl;
    cin >> direc;
    if (direc=="izquierda"){j.moverse(Jugador::GIRA_IZQUIERDA);}
    else {j.moverse(Jugador::GIRA_DERECHA);}
    return 0;
    }
{detras}    {cout<<"No se puede ir hacia atras, gire hasta la posicion deseada"<<endl;return 0;}
{salir} {j.salir();return 0;}
%%

int main(){
    cout <<"Introduce nombre jugador: ";
    cin >> direc;
    Jugador j1(direc);
    j.aniade_jugador(j1);
    yyin = stdin;
    cout<<"Tu aventura empieza a mediodia, deberas encontrar la llave"<<endl<<"Para poder volver a tu casa con las riquezas ganadas"<<endl;
    usleep(5000000);
    while (j.juego_en_marcha()){
        j.opciones();
        yylex();
    }
}