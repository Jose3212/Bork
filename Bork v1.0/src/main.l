%{
    #include "juego.hpp"
%}
uso (usar|uso|equipar)
girar   (giro|girar)
direccion   (izquierda|derecha)
huye    (huir|huyo|corro)

%%

{uso}" mapa"   {Objeto o(2);j.usa(o);}
{uso}" espada"  {Objeto o(1);j.usa(o);}
"adelante"  {j.moverse(Jugador::ADELANTE);}
{girar} {string direc;cout<<"¿Donde?<<endl;cin>>direc;
            if (direc=="izquierda")j.moverse(Jugador::GIRA_IZQUIERDA);
            else j.moverse(Jugador::GIRA_DERECHA);}

%%

int main(){
    yyin = stdin;
    string Nombre;
    cout<<"Introduzca nombre jugador: ";
    cin>>Nombre;
    Jugador j1(Nombre);
    Juego j(j1);
    while (j.juego_en_marcha()){
        j.muestra_inventario();
        cout<<"Introduzca accion: "<< j1.get_nombre()<<endl;
        yylex();
    }
}