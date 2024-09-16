#include <iostream>
#include <cstring>
#include <ctime>
#include<cstdlib>
#include "rlutil.h"
#include <algorithm>

using namespace std;

#include "funciones_globales.h"
#include "clsFecha.h"
#include "jugador.h"
#include "desarrolloJugador.h"
#include "iniciarSesion.h"
#include "dinero.h"
#include "menuPrincipal.h"
#include "clsIceField.h"
#include "desarrolloIceField.h"
#include "clsRuleta.h"
#include "desarrolloRuleta.h"
#include "clsBlackjack.h"
#include "desarrolloBlackjack.h"
#include <conio.h>

int main() {
    srand(time(NULL));
    Jugador reg;
    int y= 0;

    while (true) {
        system("cls");
        menuPrincipal(reg, y);

        if(reg.getLogin())memoriaADisco(reg.getUsuario(), reg);/// si el login es verdadero, guardamos el registro en el archivo.

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
                if(y > 5){
                    y = 5;
                }
                break;
            case 1: ///enter (1 en ascii)
                switch(y){
                    case 0:
                        reg = dinero(reg);
                        break;
                    case 1:
                        if(reg.getLogin()){
                            reg = jugarBlackjack(reg);
                        } else{
                            forzarInicio();
                        }
                        break;
                    case 2:
                        if(reg.getLogin()){
                            reg = Ruleta(reg);
                        } else{
                            forzarInicio();
                        }
                        break;
                    case 3:
                        if(reg.getLogin()){
                            reg = iceField(reg);
                        } else{
                            forzarInicio();
                        }
                        break;
                    case 4:
                        if(reg.getLogin()){
                            reg = cerrarSesion(reg);
                        } else{
                            reg = iniciar();
                        }
                        break;
                    case 5:
                        return 0;
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
