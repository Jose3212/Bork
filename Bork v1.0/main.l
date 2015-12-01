%{
    #include "juego.hpp"
    string direc;
    Jugador j1("Jugador");
    Juego j(j1);
%}
uso (usar|uso|equipar)
girar   (giro|girar)
direccion   (izquierda|derecha)
huye    (huir|huyo|corro)

%%

{uso}" mapa"   {Objeto o(2);j.usa(o);}
{uso}" espada"  {Objeto o(1);j.usa(o);}
"adelante"  {j.moverse(Jugador::ADELANTE);}
{girar} {
    cout << "¿Donde?" << endl;
    cin >> direc;
    if (direc=="izquierda"){j.moverse(Jugador::GIRA_IZQUIERDA);}
    else {j.moverse(Jugador::GIRA_DERECHA);}
    }

%%

int main(){
    yyin = stdin;
    while (j.juego_en_marcha()){
        j.mostrar_inventario();
        cout<<"Introduzca accion: "<<endl;
        yylex();
    }
}