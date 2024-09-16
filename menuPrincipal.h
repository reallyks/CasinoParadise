#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuPrincipal(Jugador reg, int y){

    float saldo = reg.getSaldo();

    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::BLACK);

    if(reg.getLogin()){
        char usuario[30];
        strcpy(usuario, reg.getUsuario());

        ///OCULTAMOS EL CURSOR DE LA CONSOLA
        rlutil::hidecursor();

        /// LIMPIA LA CONSOLA
        rlutil::cls();

        rlutil::locate(50,9);
        cout<<"---------------------"<<endl;

        rlutil::locate(51,10);
        cout<<"BIENVENIDO " << usuario<<endl;

        rlutil::locate(50,11);
        cout<<"---------------------"<<endl;

        rlutil::locate(53,13);
        cout<<"MENU PRINCIPAL"<<endl;

        /// OPCIONES

        rlutil::locate(53,15);
        cout<<"DEPOSITAR/RETIRAR DINERO"<<endl;

        rlutil::locate(53,16);
        cout<<"BLACKJACK"<<endl;

        rlutil::locate(53,17);
        cout<<"RULETA"<<endl;

        rlutil::locate(53,18);
        cout<<"ICE FIELD"<<endl;

        rlutil::locate(53,19);
        cout<<"CERRAR SESION"<<endl;

        rlutil::locate(53,20);
        cout<<"SALIR"<<endl;

        rlutil::locate(50,15 + y);
        cout<< (char)175 <<endl;

        rlutil::locate(53,22);
        cout<<"SALDO: $"<<saldo<<endl;

        rlutil::locate(45,24);
        cout<<"-------------------------------"<<endl;
        }
        else{
        ///OCULTAMOS EL CURSOR DE LA CONSOLA
        rlutil::hidecursor();

        /// LIMPIA LA CONSOLA
        rlutil::cls();

        rlutil::locate(44,9);
        cout<<"----------------------------------"<<endl;

        rlutil::locate(45,10);
        cout<<"BIENVENIDO A UTN CASINO PARADISE"<<endl;

        rlutil::locate(44,11);
        cout<<"----------------------------------"<<endl;

        rlutil::locate(53,13);
        cout<<"MENU PRINCIPAL"<<endl;

        /// OPCIONES

        rlutil::locate(50,15);
        cout<<"DEPOSITAR/RETIRAR DINERO"<<endl;

        rlutil::locate(50,16);
        cout<<"BLACKJACK"<<endl;

        rlutil::locate(50,17);
        cout<<"RULETA"<<endl;

        rlutil::locate(50,18);
        cout<<"ICE FIELD"<<endl;

        rlutil::locate(50,19);
        cout<<"INICIAR SESION / REGISTRARSE"<<endl;

        rlutil::locate(50,20);
        cout<<"SALIR"<<endl;

        rlutil::locate(48,15 + y);
        cout<< (char)175 <<endl;

        rlutil::locate(45,22);
        cout<<"-------------------------------"<<endl;
    }

}

#endif // MENUPRINCIPAL_H_INCLUDED
