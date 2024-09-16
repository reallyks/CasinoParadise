#ifndef DESARROLLOJUGADOR_H_INCLUDED
#define DESARROLLOJUGADOR_H_INCLUDED

void memoriaADisco(const char* u, Jugador r);

Jugador nuevoJugador(Jugador reg){
    ArchivoJugador archivo("jugadores.dat");

    if(reg.registrar()==true){
       if(archivo.AgregarRegistro(reg)==true){
            cout<<"JUGADOR REGISTRADO CON EXITO."<<endl<<endl;
        }else{
            cout<<"NO SE PUDO REGISTRAR EL JUGADOR."<<endl<<endl;
        }
    }

    cout<<endl;
    system("pause");
    system("cls");
    return reg;
}

Jugador iniciarSesion(Jugador reg){

    system("cls");

    ArchivoJugador archivo("jugadores.dat");

    char usuarioMail[30], contrasena[30];

    rlutil::locate(50,11);
    cout<<"INGRESE USUARIO O CORREO: ";
    cargarCadena(usuarioMail, 30);
    cout<<endl;

    rlutil::locate(50,12);
    cout<<"INGRESE CONTRASENA: ";
    cargarCadena(contrasena, 30);
    cout<<endl;

    if(archivo.verificarLogin(usuarioMail, contrasena)){
        rlutil::locate(50,13);
        cout<<"INICIASTE SESION CON EXITO"<<endl<<endl;
        int pos = archivo.PosicionRegistro(usuarioMail);
        reg = archivo.leerRegistro(pos);
        reg.setLogin(true);
    }else{
        rlutil::locate(50,13);
        cout<<"USUARIO O CONTRASENA INCORRECTA"<<endl<<endl;
    }

    system("pause");
    system("cls");

    return reg;
}

Jugador cerrarSesion(Jugador reg){

    memoriaADisco(reg.getUsuario(), reg);
    reg.setLogin(false);

    system("cls");

    cout<<"SESION CERRADA"<<endl<<endl;

    system("pause");
    return reg;

}

void memoriaADisco(const char* u, Jugador r){

    ArchivoJugador archivo("jugadores.dat");

    int pos = archivo.PosicionRegistro(u); /// buscamos en el archivo el jugador por el usuario y devolvemos su posicion
    if(!archivo.modificarRegistro(pos, r)){
        cout<<"ERROR";
    }
}

#endif // DESARROLLOJUGADOR_H_INCLUDED
