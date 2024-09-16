#ifndef DESARROLLORULETA_H_INCLUDED
#define DESARROLLORULETA_H_INCLUDED


Jugador Ruleta(Jugador reg) {
        Ruletas rg;///CREAMOS UN OBJETO RULETA
        rg.inicializarNumeros();///ESTE METODO INICIALIZA EL VECTOR DE NUMEROS[37] PARA EL DIBUJO DE LA IZQUIERDA DEL JUEGO
        int numeroApostado;///CREAMOS LA VARIABLE NUMERO APOSTADO PARA QUE RECIBA EL O LOS NUMEROS QUE APOSTO EL JUGADOR
        bool booleano=true;///CREAMOS UN BOOL PARA SABER SI SALIO O NO DEL JUEGO
        float nuevoDinero=0;///CREAMOS UNA VARIABLES
        while (true) {
            system("cls");
            rg.dibujarRuleta();///ESTE METODO DE LA CLASE RULETAS SIRVE PARA DIBUJAR TODO EL CUADRO DE LA IZQUIERDA
            rg.menuRuleta(reg);///ESTE DIBUJA EL MENU QUE SE ENCUENTRA EN EL MEDIO Y TAMBIEN EL CUADRO DE LA DERECHA DONDE SALE EL NUMERO ALEATORIO
            booleano= rg.dineroApostado(reg,rg);///SI ELEGISTE LA OPCION SALIR TE DEVUELVE FALSO, PERO SI APOSTASTE SIGUE EL PROGRAMA
            if(booleano==false)break;///SI TE DEVUELVE FALSO SE BREAKEA EL WHILE
            rg.mostrarNumeroAleatorio();/// SI APOSTAMOS Y ELEGIMOS LA JUGADA ENTONCES SE PRODUCE LA ANIMACION DE NUMERO ALEATORIO
            int NumGanador=rg.getNumeroGanador();///ACA RECIBIMOS EL NUMERO QUE SALIO EN LA RULETA Y LO GUARDAMOS EN UNA VARIABLE ENTERA PARA COMPARARLO
            int opc=rg.getEleccion();///OPC VA A DEPENDER DE LO QUE SE COMPARE, SI SE COMPARA UN NUMERO CON OTRO ENTONCES DEVUELVE 1, SI SE COMPARA 18 NUMEROS CON 1 DEVUELVE 2, Y ASI.
            float plataApostada= rg.getApuesta();///CREAMOS UNA VARIABLE PLATA APOSTADA PARA RECIBIR LA CANTIDAD DE PLATA QUE SE APOSTO EN EL JUEGO
            switch(opc){
        case 1:///CASO 1 ELEGIMOS SOLO UN NUMERO PARA APOSTAR
            numeroApostado=rg.getOpc1();///ASIGNAMOS EL NUMERO APOSTADO AL QUE ESTA EN EL GETOPC1
            if(numeroApostado==NumGanador){///LO COMPARAMOS Y SI ES IGUAL QUIERE DECIR QUE GANO
                nuevoDinero=(plataApostada*35)+plataApostada;///AL NUEVO DINERO LE ASIGNAMOS EL SALDO GANADO
                reg.setSaldo(nuevoDinero);///LO SETEAMOS
                memoriaADisco(reg.getUsuario(), reg);///Y LUEGO CON ESTA FUNCION LO GUARDAREMOS EN EL DISCO
                rlutil::locate(90, 18);
                cout<<"FELICIDADES GANASTE";
            }
                rlutil::locate(35,25);
                system("pause");
            break;
        case 2:///CASO 2 ELEGIMOS 18 NUMEROS PARA APOSTAR
            for(int i=0; i<18; i++){
                numeroApostado=rg.getOpc2(i);///ASIGNAMOS EL NUMERO APOSTADO AL QUE ESTA EN LA POSICION I
                if(numeroApostado==NumGanador){///LO COMPARAMOS Y SI ES IGUAL QUIERE DECIR QUE GANO
                nuevoDinero=plataApostada*2;///AL NUEVO DINERO LE ASIGNAMOS EL SALDO GANADO
                reg.setSaldo(nuevoDinero);///LO SETEAMOS
                memoriaADisco(reg.getUsuario(), reg);///Y LUEGO CON ESTA FUNCION LO GUARDAREMOS EN EL DISCO
                rlutil::locate(90, 18);
                cout<<"FELICIDADES GANASTE";
                }
            }
                rlutil::locate(35,25);
                system("pause");
            break;
        case 3:///CASO 3 ELEGIMOS 12 NUMEROS PARA APOSTAR
            for(int i=0; i<12; i++){
                numeroApostado=rg.getOpc3(i);///ASIGNAMOS EL NUMERO APOSTADO AL QUE ESTA EN LA POSICION I
                if(numeroApostado==NumGanador){///LO COMPARAMOS Y SI ES IGUAL QUIERE DECIR QUE GANO
                nuevoDinero=(plataApostada*2)+plataApostada;///AL NUEVO DINERO LE ASIGNAMOS EL SALDO GANADO
                reg.setSaldo(nuevoDinero);///LO SETEAMOS
                memoriaADisco(reg.getUsuario(), reg);///Y LUEGO CON ESTA FUNCION LO GUARDAREMOS EN EL DISCO
                rlutil::locate(90, 18);
                cout<<"FELICIDADES GANASTE";
                }
            }
            rlutil::locate(35,25);
            system("pause");
            break;
        case 4:///CASO 4 ELEGIMOS 6 NUMEROS PARA APOSTAR
            for(int i=0; i<6; i++){
                numeroApostado=rg.getOpc4(i);///ASIGNAMOS EL NUMERO APOSTADO AL QUE ESTA EN LA POSICION I
                if(numeroApostado==NumGanador){///LO COMPARAMOS Y SI ES IGUAL QUIERE DECIR QUE GANO
                nuevoDinero=(plataApostada*5)+plataApostada;///AL NUEVO DINERO LE ASIGNAMOS EL SALDO GANADO
                reg.setSaldo(nuevoDinero);///LO SETEAMOS
                memoriaADisco(reg.getUsuario(), reg);///Y LUEGO CON ESTA FUNCION LO GUARDAREMOS EN EL DISCO
                rlutil::locate(90, 18);
                cout<<"FELICIDADES GANASTE";
                }
            }
            rlutil::locate(35,25);
            system("pause");
            break;
            }

        }
            return reg;
}


#endif // DESARROLLORULETA_H_INCLUDED
