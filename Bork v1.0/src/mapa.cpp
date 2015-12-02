#include "mapa.hpp"
Mapa::Mapa(){
    int random;
    mapa.reserve(SIZE);
        for(int i = 0; i < SIZE; i++)mapa[i].reserve(SIZE);
        for(int m = 0; m < SIZE; m++){
            for(int n = 0; n < SIZE; n++){
                if(m == 0)mapa[m][n]=0;
                else if(n == 0)mapa[m][n]=0;
                else if(m == (SIZE-1))mapa[m][n]=0;
                else if(n == (SIZE-1))mapa[m][n]=0;
                else {
                    random= rand()%4 + 1;
                    if(random==1){
                        mapa[m][n]=AGUA;
                    }
                    else if(random==2){
                        mapa[m][n]=BOSQUE;
                    }
                    else if(random==3){
                        mapa[m][n]=CAMINO;
                    }
                    else if(random==4){
                        mapa[m][n]=TESORO;
                    }
                }
            }
        }
        /*
        for(int m = 1; m < SIZE-1; m++){
            for(int n = 1; n < SIZE-1; n++){
                if((mapa[m][n]!=AGUA)&&(mapa[m][n]!=BOSQUE)&&(mapa[m][n]!=CAMINO)){
                    mapa[m][n]= rand()%3 + 1;
                }
            }
        }/*
        for(int m = 1; m < SIZE-1; m++){
            for(int n = 1; n < SIZE-1; n++){
                if((rand()%10)==10){
                    mapa[m][n]=TESORO;
                }
            }
        }*/
        mapa[rand()%(SIZE-1)+1][rand()%(SIZE-1)+1]=ESPECIAL1;
        mapa[rand()%(SIZE-1)+1][rand()%(SIZE-1)+1]=ESPECIAL2;
}
void Mapa::genera(int &posx, int &posy, Mapa::zonas z){
    int anchura, altura;
    anchura=rand()%8+1;
    altura=rand()%8+1;
    for(int i = posx; i < anchura; i++){
        if(i<SIZE){
            for(int j = posy; j < altura; j++){
                if(j < SIZE){
                    mapa[i][j]=z;
                    posx=i;
                    posy=j;
                }
            }
        }
    }
}
void Mapa::inicia_juego(Jugador j1){
    this -> j1= j1;
    juego = true;
    posicion_y = rand()%(SIZE-1)+1;
    posicion_x = rand()%(SIZE-1)+1;
    pos = NORTE;
    
}
int Mapa::moverse(Jugador::movimiento direccion){
    int evento;
    if (direccion == Jugador::ADELANTE){
        switch (pos){
            case NORTE:
                if(posicion_x>0){
                    posicion_x--;
                }
                else mapa_mensaje.fallo_movimiento(" Fuera de Rango ");
                break;
            case SUR:
                if(posicion_x<SIZE){
                    posicion_x++;
                }
                else mapa_mensaje.fallo_movimiento(" Fuera de Rango ");
                break;
            case OESTE:
                if(posicion_y>0){
                    posicion_y--;
                }
                else mapa_mensaje.fallo_movimiento(" Fuera de Rango ");
                break;
            case ESTE:
                if(posicion_y<SIZE){
                    posicion_y++;
                }
                else mapa_mensaje.fallo_movimiento(" Fuera de Rango ");
                break;
        }
    }
    else if ((direccion == Jugador::GIRA_IZQUIERDA)||(direccion == Jugador::GIRA_DERECHA)){
        calcular_nueva_orientacion(direccion);
    }
    else {
        mapa_mensaje.fallo_movimiento(" Al moverse ");
    }
    evento = even1_principal.siguiente_evento(mapa[posicion_x][posicion_y]);
    return evento;
}
void Mapa::calcular_nueva_orientacion(Jugador::movimiento giro){
    switch (pos){
        case NORTE:
            girar_norte(giro);
            break;
        case SUR:
            girar_sur(giro);
            break;
        case OESTE:
            girar_oeste(giro);
            break;
        case ESTE:
            girar_este(giro);
            break;
    }
}
void Mapa::girar_norte(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = OESTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = ESTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Norte ");
    }
}
void Mapa::girar_sur(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = ESTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = OESTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Sur ");
    }
}
void Mapa::girar_este(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = NORTE;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = SUR;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar al Este ");
    }
}
void Mapa::girar_oeste(Jugador::movimiento giro){
    if(giro == Jugador::GIRA_IZQUIERDA){
        pos = SUR;
    }
    else if(giro = Jugador::GIRA_DERECHA){
        pos = NORTE;
    }
    else{
        mapa_mensaje.fallo_movimiento(" Al girar Oeste ");
    }
}
void Mapa::observar(){
    zonas izquierda, derecha, delante, detras;
    int iz, der, del, det;
    if(posicion_y>0)izquierda = (Mapa::zonas) mapa[posicion_x][posicion_y-1];
    if(posicion_y<SIZE)derecha = (Mapa::zonas) mapa[posicion_x][posicion_y+1];
    if(posicion_x<SIZE)delante = (Mapa::zonas) mapa[posicion_x-1][posicion_y];
    if(posicion_x>0)detras = (Mapa::zonas) mapa[posicion_x+1][posicion_y];
    switch(pos){
        case NORTE:
            iz=0;
            der=1;
            del=2;
            det=3;
            break;
        case OESTE:
            iz=2;
            der=3;
            del=1;
            det=0;
            break;
        case SUR:
            iz=1;
            der=0;
            del=3;
            det=2;
            break;
        case ESTE:
            iz=3;
            der=2;
            del=0;
            det=1;
            break;        
    }
    mapa_mensaje.comenta_evento(izquierda, iz);
    mapa_mensaje.comenta_evento(derecha, der);
    mapa_mensaje.comenta_evento(delante, del);
    mapa_mensaje.comenta_evento(detras, det);
    
}
void Mapa::muestra_mapa(){
    for(int i = 0; i < SIZE; i++){
        cout << " ";
        for(int j = 0; j < SIZE; j++){
            if((i==posicion_x) && (j==posicion_y)){
                cout << "X" << "-";
            }
            else cout << mapa[i][j] << "-";
        }
        cout<< endl;
    }
}