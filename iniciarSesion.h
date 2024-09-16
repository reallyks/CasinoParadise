#ifndef INICIARSESION_H_INCLUDED
#define INICIARSESION_H_INCLUDED

Jugador iniciar() {

    Jugador reg;
    int y= 0;

    while (true) {
        system("cls");

        system("cls");
        rlutil::locate(50,11);
        cout << "REGISTRARSE" << endl;
        rlutil::locate(50,12);
        cout << "INICIAR SESION" << endl;
        rlutil::locate(50,13);
        cout << "CERRAR" << endl;
        rlutil::locate(48, 11 + y);
        cout<< (char)175 <<endl;

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
                        reg = nuevoJugador(reg);
                        break;
                    case 1:
                        reg = iniciarSesion(reg);
                        break;
                    case 2:
                        return reg;
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

void forzarInicio(){
    system("cls");
    rlutil::locate(49,12);
    cout<<"DEBES INICIAR SESION O REGISTRARTE";
    rlutil::locate(49,14);
    cout<<"PRESIONA UNA TECLA PARA VOLVER AL MENU";
    rlutil::anykey();
}

#endif // INICIARSESION_H_INCLUDED
