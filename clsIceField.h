#ifndef CLSICEFIELD_H_INCLUDED
#define CLSICEFIELD_H_INCLUDED

class IceField{

private:
    float Apuesta;
    int HieloRoto, Hielos[2][3];
    bool GameOver;
public:

    IceField(){
        GameOver=true;
        Apuesta = 0;
    }

    /// gets

    bool getGameOver(){return GameOver;}

    float getApuesta(){return Apuesta;}

    /// sets
    void setApuesta(int a){
        Apuesta = a;
    }

    void setGameOver(bool gm){
        GameOver = gm;
    }

    /// metodos

    void dibujarHielo(int x, int y);
    void dibujarTablero();
    void dibujarNumeros();
    int elegirHielo(int col);
    bool desplegarMenu(Jugador reg);
    void asignarHieloRoto();
    void seguimientoColumna(int col);
    bool avanzaColumna(int hielo);
    void actualizarApuesta(int col);
};

/// le damos parametro de cada columna y vamos
/// multiplicando la apuesta con su respectivo multiplicador.

void IceField::actualizarApuesta(int col){

    if(col==0){
        Apuesta*=1.98;
    }else if(col==1){
        Apuesta*=3.96;
    }else if(col==2){
        Apuesta*=7.92;
    }

    rlutil::locate(21, 25);
    cout<<"TOTAL GANADO: "<< Apuesta ;

}

/// verificamos en cada columna si el hielo esta roto o no
/// (2 es roto - 1 avanza columna).
///  retorna falso - retorna verdadero.

bool IceField::avanzaColumna(int hielo){

    switch(hielo){

    case 1:
        if(Hielos[0][0] == 2){
            return false;
        }else if(Hielos[0][0] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;
    case 2:
        if(Hielos[1][0] == 2){
            return false;
        }else if(Hielos[1][0] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;
    case 3:
        if(Hielos[0][1] == 2){
            return false;
        }else if(Hielos[1][2] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;
    case 4:
        if(Hielos[1][1] == 2){
            return false;
        }else if(Hielos[0][0] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;
    case 5:
        if(Hielos[0][2] == 2){
            return false;
        }else if(Hielos[0][2] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;
    case 6:
        if(Hielos[1][2] == 2){
            return false;
        }else if(Hielos[0][0] == 1){
            rlutil::locate(30, 12);
            cout<<"X";
            return true;
        }
        break;

    }

}

/// decora la columna

void IceField::seguimientoColumna(int col){

    rlutil::locate(20+col*8,9);
    rlutil::setColor(rlutil::YELLOW);
    cout<<" ---- ";

}

/// dibuja los numeros en cada columna.

void IceField::dibujarNumeros(){
    int num=0;

    for(int i=0;i<3;i++){

        rlutil::locate(22+i*8, 12);
        num+=1;
        cout<<num;
        rlutil::locate(22+i*8, 15);
        num+=1;
        cout<<num;
    }
}

/// asigna el valor de hielo roto en cada columna
/// 2 es roto - 1 es sano

void IceField::asignarHieloRoto(){



     for (int col = 0; col < 3; col++) {
        int filaRota = rand() % 2; // Elige 0 o 1 para la fila rota
        for (int fila = 0; fila < 2; fila++) {
            if (fila == filaRota) {
                Hielos[fila][col] = 2; // Asigna el valor 2 al hielo roto
            } else {
                Hielos[fila][col] = 1; // Asigna el valor 1 al otro hielo
            }
        }
    }
}

/// elegimos el hielo de la columna (1 al 6 los hielos)

int IceField::elegirHielo(int col){
    int hielo;
    rlutil::locate(21,19);
    cout<<"INGRESE EL HIELO A ELEGIR EN COLUMNA " << col +1 <<" : ";
    rlutil::locate(61, 19);
    cout<<"     ";
    rlutil::locate(62, 19);
    cin>>hielo;
    return hielo;
}

/// dibuja el hielito

void IceField::dibujarHielo(int x, int y){
    rlutil::locate(x,y);
    cout<<" ---- ";

    rlutil::locate(x,y+1);
    cout<<"|    |";

    rlutil::locate(x,y+2);
    cout<<"|    |";

    rlutil::locate(x,y+3);
    cout<<" ---- ";
}

/// dibuja el tablero de los hielos

void IceField::dibujarTablero(){
    int x = 20;
    int y=10;   /// establecemos las coordenadas para ubicar los hielos

    rlutil::locate(20, 7);
    cout<<"1.98x";
    rlutil::locate(28, 7);  /// multiplicadores
    cout<<"3.96x";
    rlutil::locate(36, 7);
    cout<<"7.92x";


    for(int row=0;row<2;row++){
        for(int col=0;col<3;col++){

        if(row==1){
            y=14; /// cuando la fila sea la segunda posicionamos y en 14
        }
         dibujarHielo(x+col*8, y); /// a X le sumamos el numero de columna y lo multiplicamos por 8 (8 lineas de pantalla)
        }                          /// para separar las columnas.
    }
}

/// menu del juego

bool IceField::desplegarMenu(Jugador reg){

    int y=0, x=0; /// coordenadas
    bool apuestaInvalida=true; /// validamos si la apuesta cumple con minimo o maximo,
                            /// o si le da el saldo al jugador
    while (true) {

        system("cls");

        rlutil::locate(10, 2);

        cout<<"APUESTA MINIMA: $20.00 ";

        cout<<"APUESTA MAXIMO: $100.000";

        rlutil::locate( 80, 2);
        cout<<"BIENVENIDO "<<reg.getUsuario();

        dibujarTablero();

        rlutil::locate(21, 21);
        cout<<"INGRESE APUESTA: $"<<Apuesta;
        rlutil::locate(21, 22);
        cout<<"APOSTAR";
        rlutil::locate(21, 23);
        cout<<"VOLVER AL MENU";
        rlutil::locate(21, 24);
        cout<<"SALDO: $"<<reg.getSaldo();
        rlutil::locate(21, 25);
        cout<<"TOTAL GANADO: ";

        rlutil::locate(18 + x, 21 + y);
        cout<< (char)175 <<endl;

        cout<<endl;

        int key = rlutil::getkey();

        switch (key){
             case 14 : ///arriba (14 en ascii)
                    y--; /// modificamos posicion Y en locate de rlutil
                    if(y<0){
                        y = 0;
                    }
                    break;
                case 15: ///abajo (15 en ascii)
                    y++; /// modificamos posicion Y en locate de rlutil
                    if(y > 2){
                        y = 2;
                    }
                    break;
            case 1: ///enter (1 en ascii)
                switch(y){
                    case 0:
                        if(apuestaInvalida){   /// validamos la apuesta del usuario
                            rlutil::locate(39,21);
                            cout<<" ";
                            rlutil::locate(39,21);
                            cin>>Apuesta;

                            if(Apuesta < reg.getSaldo() && Apuesta >= 20 && Apuesta < 100000 ){
                                apuestaInvalida=false; /// validamos la apuesta del usuario
                            }else{
                                rlutil::locate(38,21);
                                rlutil::setColor(rlutil::RED);
                                cout<<"APUESTA INVALIDA. INGRESE OTRA VEZ ENTER";
                                rlutil::setColor(rlutil::BLACK);
                                rlutil::anykey();
                                rlutil::locate(38,21);
                                Apuesta=0;
                                cout<<"$                                         ";
                            }
                        }
                        break;
                    case 1:  /// si aprieta el boton de apostar y no se realizo apuesta pide que se realice.
                        if(apuestaInvalida){
                            rlutil::locate(20, 9);
                            rlutil::setColor(rlutil::RED);
                            cout<<" REALICE UNA APUESTA ";
                            rlutil::anykey();
                            rlutil::setColor(rlutil::BLACK);
                        }else{
                            return true;
                        }

                        break;
                    case 2:
                        return false;  /// retorna falso para salir del bucle y retornar al menu.
                        break;
                    default:
                        cout<<"OPCION INCORRECTA, VUELVA A INGRESAR UNA DE LAS OPCIONES"<<endl;
                        system("pause");
                        break;
                    }
                break;
        }
    }
}


#endif // CLSICEFIELD_H_INCLUDED
