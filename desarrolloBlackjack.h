#ifndef DESARROLLOBLACKJACK_H_INCLUDED
#define DESARROLLOBLACKJACK_H_INCLUDED

Jugador jugarBlackjack(Jugador reg) {
    float nuevoDinero=0;
    while (true) {
            Blackjack juego;
            system("cls");
            juego.setGameOver(false);
            while(!juego.getGameOver()){

                if(!juego.opciones(reg, juego))return reg;
                if (juego.getResultado()==1){
                        nuevoDinero=juego.getApuesta()*2;
                        reg.setSaldo(nuevoDinero);
                }
                else if(juego.getResultado()==3){
                        reg.setSaldo(juego.getApuesta());
                }
            }
        }
    return reg;
}

#endif // DESARROLLOBLACKJACK_H_INCLUDED

