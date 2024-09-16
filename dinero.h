#ifndef DINERO_H_INCLUDED
#define DINERO_H_INCLUDED

Jugador dinero(Jugador reg){

    int y=0;

    ///OCULTAMOS EL CURSOR DE LA CONSOLA
    rlutil::hidecursor();

    /// LIMPIA LA CONSOLA
    rlutil::cls();

    while(true){
        system("cls");
        if(reg.getLogin()){
            rlutil::locate(53,15);
            cout<<"DEPOSITAR"<<endl;

            rlutil::locate(53,16);
            cout<<"RETIRAR"<<endl;

            rlutil::locate(53,17);
            cout<<"VOLVER"<<endl;

            rlutil::locate(50,15 + y);
            cout<< (char)175 <<endl;

            int key = rlutil::getkey();
            float saldoAct = reg.getSaldo(), saldoNuevo;

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
                    case 0:{

                        system("cls");

                        rlutil::locate(53,15);
                        cout<<"ACTUAL SALDO: $"<< saldoAct<<endl;
                        rlutil::locate(53,16);
                        cout<<"INGRESE DINERO A DEPOSITAR: $";
                        cin>> saldoNuevo;
                        if(saldoNuevo<=0){
                            rlutil::locate(53,18);
                            cout<<"INGRESE UN VALOR VALIDO"<<endl;
                        }
                        else{
                            reg.setSaldo(saldoNuevo);
                            rlutil::locate(53,18);
                            cout<<"DINERO DEPOSITADO CON EXITO"<<endl;
                        }
                        break;
                        }
                    case 1:{
                        system("cls");

                        rlutil::locate(53,15);
                        cout<<"ACTUAL SALDO: $"<< saldoAct<<endl;
                        rlutil::locate(53,16);
                        cout<<"INGRESE DINERO A RETIRAR: $";
                        cin>> saldoNuevo;

                        if(saldoNuevo<=0){
                            rlutil::locate(53,18);
                            cout<<"INGRESE UN VALOR VALIDO"<<endl;
                            rlutil::anykey();
                        }else if(saldoNuevo > saldoAct){
                            rlutil::locate(53,18);
                            cout<<"INGRESE UN VALOR VALIDO"<<endl;
                            rlutil::anykey();
                        }else{
                            reg.setSaldo(-saldoNuevo);
                            rlutil::locate(53,18);
                            cout<<"DINERO RETIRADO CON EXITO"<<endl;
                            rlutil::anykey();
                        }
                        break;
                        }
                    case 2:
                        memoriaADisco(reg.getUsuario(), reg);
                        return reg;
                        break;
                    default:
                        cout<<"OPCION INCORRECTA, VUELVA A INGRESAR UNA DE LAS OPCIONES"<<endl;
                        system("pause");
                        break;
                }

                break;
            }
        }else{
            forzarInicio();
            return reg;
        }
    }
}

#endif // DINERO_H_INCLUDED
