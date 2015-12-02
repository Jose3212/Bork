%{
    #include "juego.hpp"
    #include <unistd.h>
    string direc;
    char c;
    Juego j;
    int obj;
    Objeto mapa(2), espada(1);
%}
uso (usar|uso|equipar|usa|equipa)
girar   (giro|girar|gira)
izquierda   (izquierda|iz)
derecha (derecha|der)
avanzar (delante|adelante|avanza)
detras (detras|atras|retrocede)
tira (deshecha|tira|quita|quitar)
aux {girar}" "("a la"|"hacia la"|"para la")
salir (salir|Salir|exit|quit)
%%
"dev_mapa"  {j.mapa();return 0;}
({girar}" "{izquierda}|{aux}" "{izquierda})   {j.moverse(Jugador::GIRA_IZQUIERDA);return 0;}
({girar}" "{derecha}|{aux}" "{derecha}) {j.moverse(Jugador::GIRA_DERECHA);return 0;}
{tira} {cout<<"¿Que objeto deshechas?"<<endl;
        cin >> c;
        switch(c){
        case '1':
            j.quita(0);
            break;
        case '2':
            j.quita(1);
            break;
        case '3':
            j.quita(2);
            break;
        case '4':
            j.quita(3);
            break;
        case '5':
            j.quita(4);
            break;
        }
        return 0;
    }
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