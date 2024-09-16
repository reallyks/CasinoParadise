#ifndef CLSBLACKJACK_H_INCLUDED
#define CLSBLACKJACK_H_INCLUDED

class Blackjack{

private:
    float apuesta;
    int opc;
    int suma=0;
    int suma2=0;
    int sumaTotal=0;
    int sumaTotalCro=0;
    int xAct=50; int yAct=21;
    bool nojuega=false;
    bool turnoCro=false;
    int resultado=0;
    bool gameOver=false;

public:

    Blackjack(){
        apuesta=0;
    }

    bool getGameOver(){return gameOver;}
    int getResultado(){return resultado;}
    float getApuesta(){return apuesta;}
    void setApuesta(int a){
        apuesta = a;
    }
    bool setGameOver(bool go){
        gameOver=go;
    }

    void mesaInicio(Jugador reg);
    void mesaJuego(Jugador &reg);
    bool opciones(Jugador &reg, Blackjack rg);

    bool descontarApuesta(Jugador &reg, float valor);
    void repartirCarta(int x, int y);
    void pedirCarta();
    void doblarApuesta(Jugador &reg, Blackjack &rg, float valor);
    bool quedarse();
    void noJuega();
    void turnoCroupier();
    void finDelJuego();


};

void Blackjack::mesaInicio(Jugador reg){
    system("cls");
    /// LINEAS VERTICALES
    Blackjack rg;
    for (int i = 0; i < 26; i++) {
        rlutil::locate(5, 3 + i);
        cout << char(179); /// PALITO │
        rlutil::locate(90, 3 + i);
        cout << char(179); /// PALITO │
    }
    /// LINEAS HORIZONTALES
    for (int x = 0; x < 84; x++) {
        rlutil::locate(6 + x, 2);
        cout << char(196); /// LINEA ─
        rlutil::locate(6 + x, 22);
        cout << char(196); /// LINEA ─
        rlutil::locate(6 + x, 5);
        cout << char(196); /// LINEA ─
        rlutil::locate(6 + x, 29);
        cout << char(196); /// LINEA ─
    }
    /// ESQUINAS
    rlutil::locate(5, 2);
    cout << char(218); /// ESQ ┌
    rlutil::locate(90, 2);
    cout << char(191); /// ESQ ┐
    rlutil::locate(90, 29);
    cout << char(217); /// ESQ ┘
    rlutil::locate(5, 29);
    cout << char(192); /// ESQ └




    rlutil::locate(35, 4);
    cout << "BIENVENIDO " << reg.getUsuario();

    rlutil::locate(23, 12);
    cout << "BIENVENIDO A LA MESA DE BLACKJACK DE CASINO PARADISE!";

    rlutil::locate(23, 14);
    cout << "RECORDA SELECCIONAR TU APUESTA PARA PODER ENTRAR!";

    rlutil::locate(74, 4);
    cout << "SALDO: $" << reg.getSaldo();

    rlutil::locate(32, 24);
    cout << "INGRESE DINERO A APOSTAR: ";

    rlutil::locate(33, 26);
    cout << "100";

    rlutil::locate(39, 26);
    cout << "200";

    rlutil::locate(45, 26);
    cout << "500";

    rlutil::locate(51, 26);
    cout << "1000";

    rlutil::locate(37, 28);
    cout << "5000";

    rlutil::locate(45, 28);
    cout << "10000";

     rlutil::locate(73, 28);
    cout << "VOLVER.";
}

void Blackjack::mesaJuego(Jugador &reg){
    system("cls");
    /// LINEAS VERTICALES
    for (int i = 0; i < 26; i++) {
    rlutil::locate(5, 3 + i);
    cout << char(179); /// PALITO │
    rlutil::locate(90, 3 + i);
    cout << char(179); /// PALITO │
    }
    /// LINEAS HORIZONTALES
    for (int x = 0; x < 84; x++) {
    rlutil::locate(6 + x, 2);
    cout << char(196); /// LINEA ─
    rlutil::locate(6 + x, 22);
    cout << char(196); /// LINEA ─
    rlutil::locate(6 + x, 5);
    cout << char(196); /// LINEA ─
    rlutil::locate(6 + x, 29);
    cout << char(196); /// LINEA ─
    }
    /// ESQUINAS
    rlutil::locate(5, 2);
    cout << char(218); /// ESQ ┌
    rlutil::locate(90, 2);
    cout << char(191); /// ESQ ┐
    rlutil::locate(90, 29);
    cout << char(217); /// ESQ ┘
    rlutil::locate(5, 29);
    cout << char(192); /// ESQ └



    rlutil::locate(7, 4);
    cout << "TU APUESTA: $"<<apuesta;

    rlutil::locate(37, 7);
    cout << "MANO DEL CROUPIER:";

    rlutil::locate(41, 17);
    cout << "TU MANO:";

    rlutil::locate(74, 4);
    cout << "SALDO: $" << reg.getSaldo();

    repartirCarta(47, 9);
    repartirCarta(46, 19);
    repartirCarta(43, 9);
    repartirCarta(42 , 19);


    rlutil::locate(35, 24);
    cout << "MAKE YOUR CHOICE!";

    rlutil::locate(26, 26);
    cout << "PEDIR (+)";

    rlutil::locate(40, 26);
    cout << "DOBLAR";

    rlutil::locate(54, 26);
    cout << "QUEDARSE (-)";


    int x=0, y=0, c=0;

    while(!gameOver){
        if(sumaTotal>=21||nojuega==true){
            nojuega=true;
            noJuega();
        }
        else{
            rlutil::locate(25 + x, 26 + y);
            cout<< (char)175 <<endl;
            int key = rlutil::getkey();


        switch (key){
            case 16 : /// flecha para la izquierda
                rlutil::locate(25 + x, 26 + y);
                cout<< " " <<endl;
                x--; /// modificamos posicion X en locate de rlutil
                    ///DE PEDIR PARA ATRAS
                if(x<0){
                    x=0;
                    c=0;
                }
                ///DE DOBLAR A PEDIR
                if(x == 13 ){
                    x=0;
                    c=0;
                }
                ///DE QUEDARSE A DOBLAR
                if(x == 27 ){
                    x=14;
                    c=1;
                }


                break;
            case 17: /// flecha para la derecha
                rlutil::locate(25 + x, 26 + y);
                cout<< " " <<endl;
                x++;
                /// DE QUEDARSE A TOPE
                if(x > 28){
                    x=28;
                    c=2;
                }
                /// DE DOBLAR A QUEDARSE
                if(x == 15 ){
                    x=28;
                    c=2;
                }
                /// DE PEDIR A DOBLAR
                if(x == 1 ){
                    x=14;
                    c=1;
                }
                break;
            case 1: ///enter (1 en ascii)

                switch(c){
                    case 0:
                        if(sumaTotal>=21||nojuega==true) {
                        nojuega=true;
                        noJuega();
                        }else{
                        pedirCarta();
                        turnoCroupier();
                        }

                        break;
                    case 1:{
                        if(sumaTotal>=21||nojuega==true){
                        nojuega=true;
                        noJuega();
                        }else{
                        float apuestaa=apuesta;
                        apuestaa*2;
                        apuesta=apuestaa;
                        descontarApuesta(reg, apuesta);
                        rlutil::locate(7, 4);
                        cout<<"                 ";
                        rlutil::locate(7, 4);
                        cout << "TU APUESTA: $"<<apuestaa*2;
                        pedirCarta();
                        turnoCroupier();
                        }
                        break;
                    }
                    case 2:
                        nojuega=true;
                        noJuega();
                        turnoCroupier();
                        break;
                }
            }


        }
    }
    system("cls");
}




bool Blackjack::opciones(Jugador &reg, Blackjack rg){

    int x=0, y=0, c=0;

    mesaInicio(reg);
    while(!gameOver){
        rlutil::locate(32 + x, 26 + y);
        cout<< (char)175 <<endl;
        int key = rlutil::getkey();

        switch (key){
             case 16 : /// flecha para la izquierda
                    rlutil::locate(32 + x, 26 + y);
                    cout<< " " <<endl;
                    x--; /// modificamos posicion X en locate de rlutil
                    ///DE 100 PARA ATRAS
                    if(x<0 && y==0){
                        x=0;
                        c=0;
                    }
                    ///DE 200 A 100
                    if(x == 5 && y == 0){
                        x=0;
                        c=0;
                    }
                    ///DE 500 A 200
                    if(x == 11 && y == 0){
                        x=6;
                        c=1;
                    }
                    ///DE 1000 A 500
                    if(x == 17 && y == 0){
                        x=12;
                        c=2;
                    }
                    ///DE 5000 A 1000
                    if (x == 3 && y == 2){
                        x=18;
                        y=0;
                        c=3;
                    }
                    ///DE 10000 A 5000
                    if (x == 11 && y == 2){
                        x=4;
                        c=4;
                    }
                    ///DE SALIR A 10000
                    if (x == 39 && y == 2){
                        x=12;
                        c=5;
                    }

                    break;
                case 17: /// flecha para la derecha
                    rlutil::locate(32 + x, 26 + y);
                    cout<< " " <<endl;
                    x++;
                    ///DE SALIR PARA ADELANTE
                    if(x == 41 && y == 2){
                        x=40;
                        c=6;
                    }
                    ///DE 10000 PARA SALIR
                    if(x == 13 && y == 2){
                        x=40;
                        c=6;
                    }
                    /// DE 5000 A 10000
                    if(x == 5 && y == 2){
                        x=12;
                        c=5;
                    }
                    /// DE 1000 A 5000
                    if(x == 19 && y == 0){
                        x=4;
                        y=2;
                        c=4;
                    }
                    /// DE 500 A 1000
                    if(x == 13 && y == 0){
                        x=18;
                        c=3;
                    }
                    /// DE 200 A 500
                    if(x == 7 && y == 0){
                        x=12;
                        c=2;
                    }
                    /// DE 100 A 200
                    if(x == 1 && y == 0){
                        x=6;
                        c=1;
                    }
                    break;
            case 1: ///enter (1 en ascii)
                switch(c){
                    case 0:
                        if(descontarApuesta(reg, 100)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 1:
                        if(descontarApuesta(reg, 200)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 2:
                        if(descontarApuesta(reg,500)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 3:
                        if(descontarApuesta(reg, 1000)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 4:
                        if(descontarApuesta(reg, 5000)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 5:
                        if(descontarApuesta(reg, 10000)){
                           mesaJuego(reg);
                        }
                        rlutil::locate(35,16);
                        cout<<"FONDOS INSUFICIENTES";
                        break;
                    case 6:
                        return false;
                        break;
                    default:
                        cout<<"OPCION INCORRECTA, VUELVA A INGRESAR UNA DE LAS OPCIONES"<<endl;
                        system("pause");
                        break;
                }

                break;
        }

        }

    return true;
}

bool Blackjack::descontarApuesta(Jugador &reg,float valor){

        bool apuestaValida = false;

        apuesta=valor;

        if(reg.getSaldo()< apuesta){
            return apuestaValida;
        }
        reg.setSaldo(-valor);
        rlutil::locate(74,4);
        cout<<"       ";
        rlutil::locate(74,4);
        cout<<"SALDO: $"<<reg.getSaldo();
        rlutil::locate(7, 4);
        cout<<"                 ";
        rlutil::locate(7, 4);
        cout << "TU APUESTA: $"<<apuesta;

        apuestaValida =true;
        return apuestaValida;
}




void Blackjack::repartirCarta(int x, int y){
    int numeroAleatorio;

    Sleep(1500);///DELAY PARA MOSTRAR LAS CARTAS
    /// Inicializa la semilla para los números aleatorios

    numeroAleatorio = rand() % 14 + 1;


    if(x==43&y==9&turnoCro==false){
        rlutil::locate(x,y);
        cout<<"*";
    }
    else{
        if(y==9&&numeroAleatorio==1||y==9&&numeroAleatorio==14){
            numeroAleatorio=1;
            rlutil::locate(x,y);
            cout<<"1";
        }
        else if(numeroAleatorio==1||numeroAleatorio==14){
   rlutil::locate(41, 12);
    cout << "A  Valor 1 (A) u 11 (B)? ";
    char opcion;
    cin >> opcion;
    rlutil::locate(41, 12);
    cout<<"                                 ";
     if (opcion == 'A' || opcion == 'a') {
        numeroAleatorio = 1;
        rlutil::locate(x,y);
        cout<<"1";
    } else if (opcion == 'B' || opcion == 'b') {
        numeroAleatorio = 11;
        rlutil::locate(x,y);
        cout<<"11";
    } else {
        // Manejo de errores o valores por defecto
        numeroAleatorio = 1;
    }

     }
    else if(numeroAleatorio==11){
        rlutil::locate(x,y);
        cout<<"J";
        numeroAleatorio=10;
     }

     else if(numeroAleatorio==12){
        rlutil::locate(x,y);
        cout<<"Q";
        numeroAleatorio=10;
        }
     else if(numeroAleatorio==13){
        rlutil::locate(x,y);
        cout<<"K";
        numeroAleatorio=10;
        }
    else{
         rlutil::locate(x,y);
        cout << numeroAleatorio << endl;
    }
}

 if(y==9&&x==47||turnoCro==true){
        sumaTotalCro+=numeroAleatorio;
        suma=sumaTotalCro;
        rlutil::locate(44,11);
        cout<<suma;
    }
    else if(y==19){
        sumaTotal+=numeroAleatorio;
        suma2=sumaTotal;
        rlutil::locate(43,21);
        cout<<suma2;
    }

}




void Blackjack::pedirCarta(){

int numeroAleatorio;
Sleep(1500);///DELAY PARA MOSTRAR LAS CARTAS


srand(time(NULL));
    numeroAleatorio = rand() % 14 + 1;

    if(nojuega==false&&numeroAleatorio==1||nojuega==false&&numeroAleatorio==14){
        numeroAleatorio==1;
    }
    if(numeroAleatorio==1||numeroAleatorio==14){
    rlutil::locate(41, 12);
    cout << "A  Valor 1 (A) u 11 (B)? ";
    char opcion;
    cin >> opcion;
    rlutil::locate(41, 12);
    cout<<"                                  ";
     if (opcion == 'A' || opcion == 'a') {
        numeroAleatorio = 1;
    } else if (opcion == 'B' || opcion == 'b') {
        numeroAleatorio = 11;
    } else {
        // Manejo de errores o valores por defecto
        numeroAleatorio = 1;
    }

     }
    else if(numeroAleatorio==11){
        rlutil::locate(xAct,19);
        cout<<"J";
        xAct+=4;
        numeroAleatorio=10;
     }

     else if(numeroAleatorio==12){
        rlutil::locate(xAct,19);
        cout<<"Q";
        xAct+=4;
        numeroAleatorio=10;
        }
     else if(numeroAleatorio==13){
        rlutil::locate(xAct,19);
        cout<<"K";
        xAct+=4;
        numeroAleatorio=10;
        }
    else{
        rlutil::locate(xAct,19);
        cout << numeroAleatorio << endl;
        xAct+=4;
    }

    sumaTotal+=numeroAleatorio;
        suma2=sumaTotal;
        rlutil::locate(43, 21);
        cout<<suma2;

        if(sumaTotal>=21||nojuega==true) {
                nojuega=true;
                noJuega();
        }
}






void Blackjack::noJuega(){
    if(nojuega==true){
    rlutil::locate(35,24);
    cout<<"TURNO DEL CROUPIER..";

    rlutil::locate(20,26);
    cout<<"                                                  ";
    turnoCro=true;

    }
}




void Blackjack::doblarApuesta(Jugador &reg, Blackjack &rg, float valor){

    rg.setApuesta(valor);
    valor=rg.getApuesta();
    int numeroAleatorio;

    rg.setApuesta(valor);
    valor=rg.getApuesta();
    if(reg.getSaldo()<valor)exit(1);
    reg.setSaldo(-valor);
    rlutil::locate(74,4);
    cout<<"       ";
    rlutil::locate(74,4);
    cout<<"SALDO: $"<<reg.getSaldo();
    rlutil::locate(32,22);




    memoriaADisco(reg.getUsuario(), reg);


if(sumaTotal>=21||nojuega==true){
    rlutil::locate(22,26);
    cout<<"                                                ";

    noJuega();

}
else{
srand(time(NULL));
    numeroAleatorio = rand() % 14 + 1;

    if(numeroAleatorio==1||numeroAleatorio==14){
        rlutil::locate(xAct,19);
        cout<<"A";
        xAct+=4;
     }
    else if(numeroAleatorio==11){
        rlutil::locate(xAct,19);
        cout<<"J";
        xAct+=4;
     }

     else if(numeroAleatorio==12){
        rlutil::locate(xAct,19);
        cout<<"Q";
        xAct+=4;
        }
     else if(numeroAleatorio==13){
        rlutil::locate(xAct,19);
        cout<<"K";
        xAct+=4;
        }
    else{
        rlutil::locate(xAct,19);
        cout << numeroAleatorio << endl;
        xAct+=4;
    }

    sumaTotal+=numeroAleatorio;
        suma2=sumaTotal;
        rlutil::locate(43, 21);
        cout<<suma2;
}

}

void Blackjack::turnoCroupier(){
    int tam=8;
    bool croEnJuego=true;
    if(turnoCro==true){
        rlutil::locate(43,9);
        cout<<"  ";
        repartirCarta(43, 9);
        while(croEnJuego){
            if(sumaTotalCro==21){
                    finDelJuego();
                    croEnJuego=false;
            }
            if(sumaTotal>21){
                finDelJuego();
                croEnJuego=false;
            }
            else if(sumaTotalCro>sumaTotal&&sumaTotalCro<21){
                    finDelJuego();
                    croEnJuego=false;
            }
            else if(sumaTotalCro<sumaTotal){
                repartirCarta(43+tam,9);
            }
            else if(sumaTotalCro==sumaTotal){
                 finDelJuego();
                croEnJuego=false;
            }
            tam=tam+4;
            if(sumaTotalCro>21){
                finDelJuego();
                croEnJuego=false;
            }

        }

    }
}

void Blackjack::finDelJuego(){
    Sleep(1500);
    if(sumaTotal>21){
        rlutil::locate(35,14);
        cout<<"PERDISTE :(";
        resultado=2;
    }

    else if(sumaTotal>sumaTotalCro){
        rlutil::locate(35,14);
        cout<<"FELICIDADES GANASTE !!";
        resultado=1;
    }

    else if(sumaTotalCro<=21&&sumaTotalCro>sumaTotal){
        rlutil::locate(35,14);
        cout<<"PERDISTE :(";
        resultado=2;
    }

    else if(sumaTotalCro>21){
        rlutil::locate(35,14);
        cout<<"FELICIDADES GANASTE !!";
        resultado=1;

    }
    else{
        rlutil::locate(35,14);
        cout<<"EMPATE";
        resultado=3;
    }
    gameOver=true;
    rlutil::anykey();

}


#endif // CLSBLACKJACK_H_INCLUDED
