#ifndef CLSRULETA_H_INCLUDED
#define CLSRULETA_H_INCLUDED

///CLASE PARA EL JUEGO RULETA
class Ruletas {
private:
    float apuesta=0;///INICIALIZAMOS LA APUESTA DEL JUGADOR EN 0, PERO EL DINERO QUE APUESTE ESTARA ACA
    int numeros[37],numeroGanador, eleccion, opc1,opc2[18],opc3[12],opc4[6] ;
public:

    void inicializarNumeros();///SIRVE PARA INICIALIZAR EL VECTOR DE LOS 37 NUMEROS, QUE USAREMOS DESPUES.
    void dibujarRuleta();///CON ESTE METODO DIBUJAREMOS LA RULETA DE LA IZQUIERDA
    void menuRuleta(Jugador reg);///ESTE ES EL MENU QUE SE ENCUENTRA EN EL MEDIO DEL JUEGO, TAMBIEN INCLUYE EL BOTON SALIR Y EL RECUADRO DE LA DERECHA
    bool dineroApostado(Jugador &reg, Ruletas rg);///ESTO ES PARA ELEGIR EL DINERO QUE QUERES APOSTAR
    bool elegirJugada(Jugador &reg, Ruletas rg);///EL USUARIO ELIGE LA JUGADA QUE QUIERE HACER
    void unNumero();///SUBMENU PARA ELEGIR UN NUMERO A APOSTAR
    void seisNumeros();///SUBMENU PARA ELEGIR LOS 6 NUMEROS A APOSTAR
    void docena();///SUBMENU PARA ELEGIR UNA DOCENA DE NUMEROS A APOSTAR
    void mitad();///SUBMENU PARA ELEGIR 18 NUMEROS A APOSTAR
    void parImpar();///SUBMENU PARA ELEGIR PAR O IMPAR A APOSTAR
    void rojoNegro();///SUBMENU PARA ELEGIR ROJO/NEGRO A APOSTAR
    bool confirmarDinero(Jugador reg, Ruletas rg, float valor);///METODO PARA COMPARAR QUE TENEMOS EL DINERO QUE ESTAMOS APOSTANDO
    Jugador sacarDinero(Jugador &reg, Ruletas rg);///ESTE METODO TE SACA EL DINERO UNA VEZ QUE ELEGIS LA JUGADA QUE QUERES HACER
    void mostrarNumeroAleatorio();///EN EL CUADRO DE LA DERECHA VA MOSTRANDO EL NUMERO ALEATORIO QUE SE CAMBIA 10 VECES HASTA DAR EL RESULTADO

    ///LOS DIFERENTES OPC SON PARA GUARDAR LOS NUMEROS APOSTADOS POR EL JUGADOR
    void setOpc1(int o){
        opc1 = o;
    }

    void setOpc2(int pos, int valor) {
        if (pos >= 0 && pos < 18) {
            opc2[pos] = valor;
        } else {
            cout << "FUERA DE RANGO" << endl;
            exit(1);
        }
    }

    void setOpc3(int pos, int valor) {
        if (pos >= 0 && pos < 12) {
            opc3[pos] = valor;
        } else {
            cout << "FUERA DE RANGO" << endl;
            exit(1);
        }
    }

    void setOpc4(int pos, int valor) {
        if (pos >= 0 && pos < 6) {
            opc4[pos] = valor;
        } else {
            cout << "FUERA DE RANGO" << endl;
            exit(1);
        }
    }

    void setApuesta(float a){
        apuesta = a;
    }
    void setNumeroGanador(float n){
        numeroGanador = n;
    }
    void setEleccion(int num){
        eleccion = num;
    }

    int getOpc1(){return opc1;}

    int getOpc2(int pos) const {
        if (pos >= 0 && pos < 18) {
            return opc2[pos];
        } else {
            cout << "FUERA DE RANGO" << endl;
            return -1;
        }
    }


    int getOpc3(int pos) const {
        if (pos >= 0 && pos < 12) {
            return opc3[pos];
        } else {

            cout << "FUERA DE RANGO" << endl;
            return -1;
        }
    }

    int getOpc4(int pos) const {
        if (pos >= 0 && pos < 6) {
            return opc4[pos];
        } else {
            cout << "FUERA DE RANGO" << endl;
            return -1;
    }
    }

    float getApuesta(){return apuesta;}

    int getNumeroGanador(){return numeroGanador;}

    int getEleccion(){return eleccion;}
    };



void Ruletas::inicializarNumeros() {
        for (int i = 0; i < 37; i++) {
            numeros[i] = i;
        }
    }

void Ruletas::dibujarRuleta() {
    int c = 0, b = 0;

    /// RECTÁNGULO DE APUESTAS
    for (int i = 0; i < 36; i++) {
        /// CUADRADO PARA EL 0
        rlutil::locate(10, 2);
        cout << char(179); /// PALITO │
        rlutil::locate(19, 2);
        cout << char(179); /// PALITO │
        rlutil::locate(10, 1);
        cout << char(218); /// ESQ ┌
        rlutil::locate(19, 1);
        cout << char(191); /// ESQ ┐
        rlutil::locate(11 + c, 1);
        cout << char(196); /// LINEA ─
        rlutil::locate(12 + c, 1);
        cout << char(196); /// LINEA ─
        rlutil::locate(13, 1);
        cout << char(196); /// LINEA ─
        rlutil::locate(16, 1);
        cout << char(196); /// LINEA ─
        rlutil::locate(13, 3);
        cout << char(194); /// LINEA ┬
        rlutil::locate(16, 3);
        cout << char(194); /// LINEA ┬
        rlutil::locate(14, 2);
        rlutil::setColor(rlutil::WHITE);
        cout << "00"; /// NUMERO 00
        rlutil::setColor(rlutil::BLACK);

        /// PARTE DE ARRIBA
        rlutil::locate(11 + c, 3 + b);
        cout << char(196); /// LINEA ─
        rlutil::locate(12 + c, 3 + b);
        cout << char(196); /// LINEA ─
        /// LINEAS HORIZONTALES
        rlutil::locate(10 + c, 4 + b);
        cout << char(179); /// PALITO │
        rlutil::locate(13 + c, 4 + b);
        cout << char(179); /// PALITO │
        /// PARTE DE ABAJO
        rlutil::locate(11 + c, 5 + b);
        cout << char(196); /// LINEA ─
        rlutil::locate(12 + c, 5 + b);
        cout << char(196); /// LINEA ─

        /// PARTE INFERIOR
        rlutil::locate(19, 27);
        cout << char(217); /// ESQ ┘
        rlutil::locate(10, 27);
        cout << char(192); /// ESQ └
        rlutil::locate(13, 27);
        cout << char(193); /// ESQ ┴
        rlutil::locate(16, 27);
        cout << char(193); /// ESQ ┴

        /// UNIONES DEL MEDIO
        if (c != 6) {
            rlutil::locate(13 + c, 5 + b);
            cout << char(197); /// ESQ ┼
        }

        /// UNIONES DE LOS COSTADOS
        if (c == 0) {
            rlutil::locate(10 + c, 3 + b);
            cout << char(195); /// ESQ ├
        }
        if (c == 3) {
            rlutil::locate(16 + c, 3 + b);
            cout << char(180); /// ESQ ┤
        }

        /// NUMEROS
        rlutil::setColor(rlutil::WHITE);
        int num = 1 + i;
        /// NUMEROS ROJOS
        if (num == 1 || num == 3 || num == 5 || num == 7 || num == 9 || num == 12 || num == 14 || num == 16 || num == 18 || num == 19 || num == 21 || num == 23 || num == 25 || num == 27 || num == 30 || num == 32 || num == 34 || num == 36) {
            rlutil::setBackgroundColor(rlutil::RED);
            if (num < 10) {
                if (num % 2 == 0) {
                    rlutil::locate(11 + c, 4 + b);
                    cout << "0";
                    rlutil::locate(11 + c + 1, 4 + b);
                    cout << num;
                } else {
                    rlutil::locate(11 + c, 4 + b);
                    cout << "0";
                    rlutil::locate(11 + c + 1, 4 + b);
                    cout << num;
                }
            } else {
                rlutil::locate(11 + c, 4 + b);
                cout << num;
            }
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        } else {
            /// NUMEROS NEGROS
            rlutil::setBackgroundColor(rlutil::BLACK);
            if (num < 10) {
                if (num % 2 == 0) {
                    rlutil::locate(11 + c, 4 + b);
                    cout << "0";
                    rlutil::locate(11 + c + 1, 4 + b);
                    cout << num;
                } else {
                    rlutil::locate(11 + c, 4 + b);
                    cout << "0";
                    rlutil::locate(11 + c + 1, 4 + b);
                    cout << num;
                }
            } else {
                rlutil::locate(11 + c, 4 + b);
                cout << num;
            }
            rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        }

        rlutil::setColor(rlutil::BLACK);
        /// CONTADORES
        c += 3;
        if (c == 9) {
            b += 2;
            c = 0;
        }
    }
}

void Ruletas::menuRuleta(Jugador reg) {

    /// LINEAS VERTICALES
    for (int i = 0; i < 19; i++) {
        rlutil::locate(35, 3 + i);
        cout << char(179); /// PALITO │
        rlutil::locate(80, 3 + i);
        cout << char(179); /// PALITO │
    }
    /// LINEAS HORIZONTALES
    for (int x = 0; x < 44; x++) {
        rlutil::locate(36 + x, 2);
        cout << char(196); /// LINEA ─
        rlutil::locate(36 + x, 22);
        cout << char(196); /// LINEA ─
        rlutil::locate(36 + x, 5);
        cout << char(196); /// LINEA ─
        rlutil::locate(36 + x, 9);
        cout << char(196); /// LINEA ─
        rlutil::locate(36 + x, 19);
        cout << char(196); /// LINEA ─
    }
    /// ESQUINAS
    rlutil::locate(35, 2);
    cout << char(218); /// ESQ ┌
    rlutil::locate(80, 2);
    cout << char(191); /// ESQ ┐
    rlutil::locate(80, 22);
    cout << char(217); /// ESQ ┘
    rlutil::locate(35, 22);
    cout << char(192); /// ESQ └

    rlutil::locate(47, 4);
    cout << "BIENVENIDO " << reg.getUsuario();

    rlutil::locate(45, 6);
    cout << "INGRESE DINERO A APOSTAR: ";

    rlutil::locate(46, 7);
    cout << "100";

    rlutil::locate(52, 7);
    cout << "200";

    rlutil::locate(58, 7);
    cout << "500";

    rlutil::locate(64, 7);
    cout << "1000";

    rlutil::locate(50, 8);
    cout << "5000";

    rlutil::locate(58, 8);
    cout << "10000";

    rlutil::locate(53, 10);
    cout << "JUGADA";

    rlutil::locate(42, 12);
    cout << "1 NUMERO";

    rlutil::locate(53, 12);
    cout << "6 NUMEROS";

    rlutil::locate(64, 12);
    cout << "DOCENA";

    rlutil::locate(44, 14);
    cout << "PAR/IMPAR";

    rlutil::locate(60, 14);
    cout << "ROJO/NEGRO";

    rlutil::locate(50, 16);
    cout << "1/18 O 19/36";

    rlutil::locate(53, 20);
    cout << "SALDO: $" << reg.getSaldo();

    rlutil::locate(92, 20);
    cout<<"SALIR";

    for (int i = 0; i < 5; i++) {
        rlutil::locate(90, 11 + i);
        cout << char(219); /// PALITO █
        rlutil::locate(99, 11 + i);
        cout << char(219); /// PALITO █
    }
    for (int x = 0; x < 8; x++) {
        rlutil::locate(91 + x, 11);
        cout << char(223); /// LINEA ▀
        rlutil::locate(91 + x, 15);
        cout << char(220); /// LINEA ▄
    }
}



bool Ruletas::dineroApostado(Jugador& reg, Ruletas rg){
    int x=0, y=0, c=0;
    bool booleano=true;
    while(true){
    rlutil::locate(35,25);
    cout<<"                       ";
    rlutil::locate(35,26);
    cout<<"                                            ";
    rlutil::locate(45 + x, 7 + y);
    cout<< (char)175 <<endl;
    int key = rlutil::getkey();

    switch (key){
         case 16 : /// flecha para la izquierda
                rlutil::locate(45 + x, 7 + y);
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
                if (x == 3 && y == 1){
                    x=18;
                    y=0;
                    c=3;
                }
                ///DE 10000 A 5000
                if (x == 11 && y == 1){
                    x=4;
                    c=4;
                }
                ///DE SALIR A 10000
                if (x == 45 && y == 13){
                    x=12;
                    y=1;
                    c=5;
                }

                break;
            case 17: /// flecha para la derecha
                rlutil::locate(45 + x, 7 + y);
                cout<< " " <<endl;
                x++;
                ///DE SALIR PARA ADELANTE
                if(x == 47 && y == 13){
                    x=46;
                    c=6;
                }
                ///DE 10000 PARA SALIR
                if(x == 13 && y == 1){
                    x=46;
                    y=13;
                    c=6;
                }
                /// DE 5000 A 10000
                if(x == 5 && y == 1){
                    x=12;
                    c=5;
                }
                /// DE 1000 A 5000
                if(x == 19 && y == 0){
                    x=4;
                    y=1;
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
                    if(!confirmarDinero(reg,rg,100))break;///SI DEVUELVE FALSO ES QUE NO TIENE EL DINERO
                    booleano= elegirJugada(reg,rg);///PROCEDE A ELEGIR LA JUGADA
                    return booleano;
                    break;
                case 1:
                    if(!confirmarDinero(reg,rg,200))break;
                    booleano= elegirJugada(reg,rg);
                    return booleano;
                    break;
                case 2:
                    if(!confirmarDinero(reg,rg,500))break;
                    booleano= elegirJugada(reg,rg);
                    return booleano;
                    break;
                case 3:
                    if(!confirmarDinero(reg,rg,1000))break;
                    booleano= elegirJugada(reg,rg);
                    return booleano;
                    break;
                case 4:
                    if(!confirmarDinero(reg,rg,5000))break;
                    booleano= elegirJugada(reg,rg);
                    return booleano;
                    break;
                case 5:
                    if(!confirmarDinero(reg,rg,10000))break;
                    booleano= elegirJugada(reg,rg);
                    return booleano;
                    break;
                case 6:
                    return false;
                    break;
                default:
                    cout<<"OPCION INCORRECTA, VUELVA A INGRESAR UNA DE LAS OPCIONES"<<endl;
                    system("pause");
                    return false;
                    break;
            }

            break;
    }
    }
}

bool Ruletas::confirmarDinero(Jugador reg, Ruletas rg,float valor){
    if(reg.getSaldo()<valor){
        rlutil::locate(35,25);
        cout<<"INGRESE UN VALOR VALIDO";
        rlutil::locate(35,26);
        system("pause");
    return false;
    }else{
    this->setApuesta(valor);
    return true;
    }
}

Jugador Ruletas::sacarDinero(Jugador& reg, Ruletas rg){
    float valor= this->getApuesta();
    reg.setSaldo(-valor);
    rlutil::locate(61,20);
    cout<<"          ";
    rlutil::locate(61,20);
    cout<<reg.getSaldo();
    rlutil::locate(53,21);
    memoriaADisco(reg.getUsuario(), reg);
    return reg;
}


bool Ruletas::elegirJugada(Jugador& reg, Ruletas rg) {
    int x = 0, y = 0, c = 0;
    while (true) {
        rlutil::locate(41 + x, 12 + y);
        cout << (char)175 << endl;

        int key = rlutil::getkey();

        switch (key) {
            case 16: // Flecha para la izquierda
                rlutil::locate(41 + x, 12 + y);
                cout << " " << endl;
                x--;

                ///DE 1 NUMERO PARA ATRAS
                if(x<0 && y==0){
                    x=0;
                    c=0;
                }
                ///DE 6
                if(x == 10 && y == 0){
                    x=0;
                    c=0;
                }

                if(x == 21 && y == 0){
                    x=11;
                    c=1;
                }

                if(x == 1 && y == 2){
                    x=22;
                    y=0;
                    c=2;
                }

                if (x == 17 && y == 2){
                    x=2;
                    c=3;
                }

                if (x == 7 && y == 4){
                    x=18;
                    y=2;
                    c=4;
                }

                if (x == 49 && y == 8){
                    x=8;
                    y=4;
                    c=5;
                }

                break;

            case 17: // Flecha para la derecha
                rlutil::locate(41 + x, 12 + y);
                cout << " " << endl;
                x++;

                if(x == 51 && y == 8){
                    x=50;
                    c=6;
                }

                if(x == 9 && y == 4){
                    x=50;
                    y=8;
                    c=6;
                }

                if(x == 19 && y == 2){
                    x=8;
                    y=4;
                    c=5;
                }

                if(x == 3 && y == 2){
                    x=18;
                    c=4;
                }

                if(x == 23 && y == 0){
                    x=2;
                    y=2;
                    c=3;
                }

                if(x == 12 && y == 0){
                    x=22;
                    c=2;
                }

                if(x == 1 && y == 0){
                    x=11;
                    c=1;
                }

                break;

            case 1: // Enter (1 en ASCII)
                switch (c) {
                    case 0:
                        setEleccion(1);///LA ELECCION SE LA VAMOS A DEVOLVER AL DESARROLLO PARA QUE SEPA CUANTOS NUMEROS HAY QUE COMPARAR
                        unNumero();
                        sacarDinero(reg,rg);
                        return true;
                        break;
                    case 1:
                        setEleccion(4);
                        seisNumeros();
                        sacarDinero(reg,rg);
                        return true;
                        break;

                    case 2:
                        setEleccion(3);
                        docena();
                        sacarDinero(reg,rg);
                        return true;
                        break;

                    case 3:
                        setEleccion(2);
                        parImpar();
                        sacarDinero(reg,rg);
                        return true;
                        break;

                    case 4:
                        setEleccion(2);
                        rojoNegro();
                        sacarDinero(reg,rg);
                        return true;
                        break;
                    case 5:
                        setEleccion(2);
                        mitad();
                        sacarDinero(reg,rg);
                        return true;
                        break;
                    default:
                        cout<<"VALOR INCORRECTO, INGRESE NUEVAMENTE: ";
                        return false;
                        break;
                }
                break;
        }
    }
}


void Ruletas::unNumero(){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout << "ELIJA UN NUMERO (0 A 36):      ";
        rlutil::locate(40,13);
        cout<< "                                ";
        rlutil::locate(40,14);
        cout<< "                                ";
        rlutil::locate(40,15);
        cout<< "                                ";
        rlutil::locate(40,16);
        cout<< "                                ";
        rlutil::locate(66,12);
        cin >> eleccion;

        // Validar que la elección esté en la lista de números disponibles
        while (find(begin(numeros), end(numeros), eleccion) == end(numeros)) { ///busca la eleccion entre el principio y el final del vector, si la encuentra devuelve un iterador que apunta a la posicion del elemento que encontro, y sino devuelve end(numeros) que es el final del vector
            rlutil::locate(40,11);
            cout << "NUMERO INVALIDO";
            rlutil::locate(40,12);
            cout << "ELIJA UN NUMERO (0 A 36): ";
            rlutil::locate(66,12);
            cout << "              ";
            rlutil::locate(66,12);
            cin >> eleccion;
        }
        setOpc1(eleccion);

}
void Ruletas::seisNumeros(){
    bool booleano= true;
    while(booleano){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "OPCION 1: APOSTAR DEL 1 AL 6    ";
        rlutil::locate(40,12);
        cout<< "OPCION 2: APOSTAR DEL 7 AL 12   ";
        rlutil::locate(40,13);
        cout<< "OPCION 3: APOSTAR DEL 13 AL 18  ";
        rlutil::locate(40,14);
        cout<< "OPCION 4: APOSTAR DEL 19 AL 24  ";
        rlutil::locate(40,15);
        cout<< "OPCION 5: APOSTAR DEL 25 AL 30  ";
        rlutil::locate(40,16);
        cout<< "OPCION 6: APOSTAR DEL 31 AL 36  ";
        rlutil::locate(40,17);
        cout<< "INGRESE UNA OPCION:             ";
        rlutil::locate(40,18);
        cout<< "                                ";
        rlutil::locate(60,17);
        cin>>eleccion;
        switch(eleccion){
        case 1:
            for(int i=0;i<6;i++){
                setOpc4(i,i+1);
            }
            booleano=false;
            break;
        case 2:
            for(int i=0;i<6;i++){
                setOpc4(i,i+6);
            }
            booleano=false;
            break;
        case 3:
            for(int i=0;i<6;i++){
                setOpc4(i,i+12);
            }
            booleano=false;
            break;
        case 4:
            for(int i=0;i<6;i++){
                setOpc4(i,i+18);
            }
            booleano=false;
            break;
        case 5:
            for(int i=0;i<6;i++){
                setOpc4(i,i+24);
            }
            booleano=false;
            break;
        case 6:
            for(int i=0;i<6;i++){
                setOpc4(i,i+30);
            }
            booleano=false;
            break;
        default:
        rlutil::locate(40,18);
        cout<<"INGRESE UNA OPCION CORRECTA";
        rlutil::anykey();
        }
    }
}
void Ruletas::docena(){
    bool booleano= true;
    while(booleano){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout<< "OPCION 1: DEL 1 AL 12           ";
        rlutil::locate(40,13);
        cout<< "OPCION 2: DEL 13 AL 24          ";
        rlutil::locate(40,14);
        cout<< "OPCION 3: DEL 25 AL 36          ";
        rlutil::locate(40,15);
        cout<< "                                ";
        rlutil::locate(40,16);
        cout<< "                                ";
        rlutil::locate(40,17);
        cout<< "INGRESE UNA OPCION:             ";
        rlutil::locate(40,18);
        cout<< "                                ";
        rlutil::locate(60,17);
        cin>>eleccion;
        switch(eleccion){
    case 1:
        for(int i=0; i<12;i++){
            setOpc3(i,i+1);
        }
        booleano=false;
        break;
    case 2:
        for(int i=0; i<12;i++){
            setOpc3(i,i+12);
        }
        booleano=false;
        break;
    case 3:
        for(int i=0; i<12;i++){
            setOpc3(i,i+24);
        }
        booleano=false;
        break;
    default:
        rlutil::locate(40,18);
        cout<<"INGRESE UNA OPCION CORRECTA";
        rlutil::anykey();
        }
    }
}
void Ruletas::parImpar(){
    bool booleano= true;
    while(booleano){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout<< "OPCION 1: APOSTAR NUMEROS PARES:";
        rlutil::locate(40,13);
        cout<< "OPCION 2: APOSTAR NUMEROS IMPARES:";
        rlutil::locate(40,14);
        cout<< "                                ";
        rlutil::locate(40,15);
        cout<< "DIGITE LA OPCION:               ";
        rlutil::locate(40,16);
        cout<< "                                ";
        rlutil::locate(57,15);
        cin>>eleccion;
        switch(eleccion){
    case 1:
        for(int i=0; i<18; i++){
            setOpc2(i,i+2);
        }
        booleano=false;
        break;
    case 2:
        for(int i=0; i<18; i++){
            if(i==0){
            setOpc2(i,i+1);
            }else{
            setOpc2(i,i+2);
            }
        }
        booleano=false;
        break;
    default:
        rlutil::locate(40,16);
        cout<<"INGRESE UNA OPCION CORRECTA";
        rlutil::anykey();
        }
    }
}

void Ruletas::rojoNegro(){
    bool booleano= true;
    while(booleano){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout<< "OPCION 1: APOSTAR AL ROJO       ";
        rlutil::locate(40,13);
        cout<< "OPCION 2: APOSTAR AL NEGRO      ";
        rlutil::locate(40,14);
        cout<< "                                ";
        rlutil::locate(40,15);
        cout<< "DIGITE LA OPCION:               ";
        rlutil::locate(40,16);
        cout<< "                                ";
        rlutil::locate(57,15);
        cin>>eleccion;
        switch(eleccion){
    case 1:
        setOpc2(0,1);
        setOpc2(1,3);
        setOpc2(2,5);
        setOpc2(3,9);
        setOpc2(4,7);
        setOpc2(5,12);
        setOpc2(6,14);
        setOpc2(7,16);
        setOpc2(8,18);
        setOpc2(9,19);
        setOpc2(10,21);
        setOpc2(11,23);
        setOpc2(12,25);
        setOpc2(13,27);
        setOpc2(14,30);
        setOpc2(15,32);
        setOpc2(16,34);
        setOpc2(17,36);
        booleano=false;
        break;
    case 2:
        setOpc2(0,2);
        setOpc2(1,4);
        setOpc2(2,6);
        setOpc2(3,8);
        setOpc2(4,10);
        setOpc2(5,11);
        setOpc2(6,13);
        setOpc2(7,15);
        setOpc2(8,17);
        setOpc2(9,20);
        setOpc2(10,22);
        setOpc2(11,24);
        setOpc2(12,26);
        setOpc2(13,28);
        setOpc2(14,29);
        setOpc2(15,31);
        setOpc2(16,33);
        setOpc2(17,35);
        booleano=false;
        break;
    default:
        rlutil::locate(40,16);
        cout<<"INGRESE UNA OPCION CORRECTA";
        rlutil::anykey();
        }
    }
}

void Ruletas::mitad(){
    bool booleano= true;
    while(booleano){
        int eleccion;
        rlutil::locate(40,10);
        cout<< "                                ";
        rlutil::locate(40,11);
        cout<< "                                ";
        rlutil::locate(40,12);
        cout<< "OPCION 1: APOSTAR DEL 1 AL 18   ";
        rlutil::locate(40,13);
        cout<< "OPCION 2: APOSTAR DEL 19 AL 36  ";
        rlutil::locate(40,14);
        cout<< "                                ";
        rlutil::locate(40,15);
        cout<< "DIGITE LA OPCION:               ";
        rlutil::locate(40,16);
        cout<< "                                ";
        rlutil::locate(57,15);
        cin>>eleccion;
        switch(eleccion){
    case 1:
        for(int i=0; i<18; i++){
            setOpc2(i,i+1);
        }
        booleano=false;
        break;
    case 2:
        for(int i=0; i<18; i++){
            setOpc2(i,i+18);
        }
        booleano=false;
        break;
    default:
        rlutil::locate(40,16);
        cout<<"INGRESE UNA OPCION CORRECTA";
        rlutil::anykey();
        }
    }
}

void Ruletas::mostrarNumeroAleatorio() {
    int numeroAleatorio;

        // Bucle para mostrar números aleatorios
        for (int i = 0; i < 10; ++i) {  // Cambia el número de iteraciones según tus necesidades
            // Generar un número aleatorio entre 1 y 32

            numeroAleatorio = rand() % 35 + 1;

            // Imprimir el número aleatorio
            rlutil::locate(94,13);
            cout << numeroAleatorio << endl;

            if(numeroAleatorio<10){
            rlutil::locate(95,13);
            cout << " " << endl;
            }

            // Esperar un breve período antes de la próxima iteración
            Sleep(500);  // Espera 500 milisegundos (0.5 segundos)
        }
        setNumeroGanador(numeroAleatorio);
     }



#endif // CLSRULETA_H_INCLUDED
