#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class ArchivoJugador;

class Jugador{

private:
    char Usuario[30], Contrasena[30], Mail[30];
    Fecha FechaNacimiento;
    float Saldo;
    bool Login;
public:

    Jugador(){
        Saldo =0;
        Login = false;
    }

    char setUsuario(const char *u){strcpy(Usuario, u);}
    char setMail(const char *m){strcpy(Mail, m);}
    char setContrasena(const char *c){strcpy(Contrasena, c);}
    Fecha setFecha(Fecha f){FechaNacimiento=f;}
    float setSaldo(float s=0){
        if (s < 0) {
        // Restar el valor absoluto de s al saldo actual (retirar dinero)
        Saldo -= abs(s);
    } else {
        // Sumar s al saldo actual (depositar dinero)
        Saldo += s;
    }
    }
    bool setLogin(bool login=false){Login = login;}

    const char *getUsuario(){return Usuario;}
    const char *getMail(){return Mail;}
    const char *getContrasena(){return Contrasena;}
    Fecha getFecha(){return FechaNacimiento;}
    float getSaldo(){return Saldo;}
    bool getLogin(){return Login;}

    bool existeUsuario(const char* u, const char* c){

        FILE* p = fopen("jugadores.dat", "rb");

        if(p==NULL){
            return false;
        }

        Jugador reg;
        bool encontrado = false;


        while(fread(&reg,sizeof(Jugador), 1, p)==1){

            if(strcmp(reg.getUsuario(), u)==0 || strcmp(reg.getMail(), c)==0){
                encontrado = true;
                break;
            }

        }

        return encontrado;

        fclose(p);

    }

    bool registrar() {
        system("cls");
        Fecha fechaActual;
        char usuario[30], contrasena[30], mail[30];

        rlutil::locate(50,11);
        cout << "Ingrese su correo: ";
        cargarCadena(mail, 30);

        while(existeUsuario("", mail)){
            rlutil::locate(50,12);
            rlutil::setColor(rlutil::RED);
            cout<<"ESTE CORREO ESTA EN USO. INGRESE OTRO"<<endl<<endl;
            rlutil::setColor(rlutil::BLACK);
            rlutil::locate(69,11);
            cout<<"                    ";
            rlutil::locate(69,11);
            cargarCadena(mail, 30);
        }
        rlutil::locate(50,13);
        cout << "Ingrese un nombre de usuario: ";
        cargarCadena(usuario, 30);

        while(existeUsuario(usuario, "")){
            rlutil::locate(50,14);
            rlutil::setColor(rlutil::RED);
            cout<<"ESTE USUARIO ESTA EN USO. INGRESE OTRO"<<endl<<endl;
            rlutil::setColor(rlutil::BLACK);
            rlutil::locate(80,13);
            cout<<"                    ";
            rlutil::locate(80,13);
            cargarCadena(usuario, 30);
        }
        rlutil::locate(50,15);
        cout << "Ingrese una contrasenia: ";
        cargarCadena(contrasena, 30);
        rlutil::locate(50,17);
        cout << "Ingrese su fecha de nacimiento: ";
        FechaNacimiento.Cargar(); // Usa la fecha de la clase en lugar de una variable local

        int edad = fechaActual.getAnio() - FechaNacimiento.getAnio();
        if (fechaActual.getMes() < FechaNacimiento.getMes() || (fechaActual.getMes() == FechaNacimiento.getMes() && fechaActual.getDia() < FechaNacimiento.getDia())) {
            edad--;
        }

        if (edad < 18) {
            cout << "TENES QUE SER MAYOR DE EDAD" << endl;
            return false;
        } else {
            setUsuario(usuario);
            setMail(mail);
            setContrasena(contrasena);
            // No es necesario setear la fecha de nuevo, ya está almacenada en FechaNacimiento
            system("cls");
            setLogin(true);
            return true;
        }
    }

};

class ArchivoJugador{
    private:
    char nombre[30]; /// jugadores.dat
    public:
    ArchivoJugador(const char *nJug){
            strcpy(nombre, nJug);
        }
    const char *getNombre(){return nombre;}

    bool AgregarRegistro(Jugador reg); /// agregamos registro al archivo (disco)
    bool verificarLogin(const char* usuarioMail, const char* contrasena);
    Jugador leerRegistro(int pos);
    int PosicionRegistro(const char* usuario);
    bool modificarRegistro(int pos, Jugador reg);


};

bool ArchivoJugador::modificarRegistro(int pos, Jugador reg){

    FILE *p=fopen(nombre, "rb+");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    fseek(p,sizeof reg * pos, 0);

    bool escribio = fwrite(&reg, sizeof reg, 1,p);

    fclose(p);

    return escribio;

}

int ArchivoJugador::PosicionRegistro(const char* usuario){

    Jugador reg;
    int cont=0;

    FILE* p = fopen(nombre, "rb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return -1;
    }

    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (strcmp(reg.getUsuario(), usuario) == 0) {
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

Jugador ArchivoJugador::leerRegistro(int pos){

    /// copiar lo del disco a la memoria

    Jugador reg;

    FILE *p = fopen(nombre, "rb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return reg;
    }

    fseek(p, sizeof reg * pos,0);

    /// puntero / cantidad de bytes x la posicion / desde donde inicio

    fread(&reg, sizeof reg, 1, p);

    fclose(p);
    return reg;
}

bool ArchivoJugador::AgregarRegistro(Jugador reg){

    FILE *p=fopen(nombre, "ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return false;
    }

    bool escribio = fwrite(&reg, sizeof reg, 1, p)==1;


    fclose(p);
    return escribio;

}

bool ArchivoJugador::verificarLogin(const char* usuarioMail, const char* contrasena){

    Jugador reg;

    FILE* p = fopen(nombre, "rb");
    if (p == NULL) {
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        return false;
    }

    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (strcmp(reg.getUsuario(), usuarioMail) == 0  || strcmp(reg.getMail(), usuarioMail) == 0  ) {
            if(strcmp(reg.getContrasena(), contrasena) == 0 ){
                fclose(p);
                return true;
            }

        }
    }
    fclose(p);
    return false;
}


#endif // JUGADOR_H_INCLUDED
