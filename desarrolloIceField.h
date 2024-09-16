#ifndef DESARROLLOICEFIELD_H_INCLUDED
#define DESARROLLOICEFIELD_H_INCLUDED

Jugador iceField(Jugador reg){

    IceField juego;

    while(true){
        /// seteamos la apuesta en 0
        juego.setApuesta(0);
        /// asignamos los hielos rotos en la matriz
        juego.asignarHieloRoto();
        if(juego.desplegarMenu(reg)){ /// si el menu retorna en verdadero comienza el juego.
            juego.setGameOver(true); /// seteamos el gameOver en verdadero.
            reg.setSaldo( -juego.getApuesta() ); /// restamos la apuesta realizada al saldo.
            rlutil::locate(21, 24);
            cout<<"              ";
            rlutil::locate(21, 24);
            cout<<"SALDO: $"<<reg.getSaldo(); /// mostramos el saldo del usuario otra vez

            int col=0; /// seteamos columna en 0 para ir actualizandola
            while(juego.getGameOver()){ /// mientras que GameOver este en true se ejecuta
                juego.dibujarNumeros();
                juego.seguimientoColumna(col); /// decoramos columnas
                int hielo = juego.elegirHielo(col); /// elegimos el hielo
                if( juego.avanzaColumna( hielo ) ){ /// verificamos si no esta el hielo roto
                    juego.actualizarApuesta(col); /// actualizamos la apuesta con multiplicadores
                    col++;
                }else{ /// si el hielo esta roto ejecutamos esta parte
                    juego.setGameOver(false); /// seteamos game over en false asi rompemos el bucle while
                    rlutil::locate(20, 9);
                    rlutil::setColor(rlutil::RED);
                    cout<<"HIELO ROTO";
                    rlutil::setColor(rlutil::BLACK);
                    rlutil::anykey();
                }
                if(col==3){ /// si columna llego a tres quiere decir que el juego termino xq ganaste
                    reg.setSaldo( juego.getApuesta() ); /// seteamos el saldo del usuario con lo ganado de la apuesta.
                    juego.setGameOver(false); /// salimos del bucle while
                    rlutil::locate(20, 9);
                    cout<<"                             ";
                    rlutil::locate(20, 9);
                    cout<<"WIN WIN WIN: $ "<<juego.getApuesta(); /// mostramos el total ganado.
                    rlutil::anykey();
                    rlutil::setColor(rlutil::BLACK);
                }
            }
        }
        else{
            return reg; /// retornamos el registro de usuario actualizado.
        }
    }
}



#endif // DESARROLLOICEFIELD_H_INCLUDED
