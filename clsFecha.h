#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

bool esFechaValida(int dia, int mes, int anio);

class Fecha
{
private:
    int dia, mes, anio;
public:

    Fecha()
    {
        time_t now = time(0);
        tm *f = localtime(&now);
        dia = f->tm_mday;
        mes = f->tm_mon + 1;
        anio = f->tm_year + 1900;
    }

    void Cargar();
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    ///sets()
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

    ///gets()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};
void Fecha::Cargar() {
    bool entra;
    /// Pide el d�a
    entra=true;
    while (entra){
        rlutil::locate(50,19);
        cout<<"INGRESE EL DIA: ";
        rlutil::locate(69,19);
        cin>>dia;
        if (dia<=31 && dia>=1)
        {
            entra=false;
        }
        else
        {
            rlutil::locate(69,19);
            cout<<"  ";
            rlutil::locate(50,20);
            rlutil::setColor(rlutil::RED);
            cout<<"EL DIA INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
            rlutil::setColor(rlutil::BLACK);
        }
    }
    /// Pide el mes
    entra=true;
    while (entra==true){
        rlutil::locate(50,21);
        cout<<"INGRESE EL MES: ";
        rlutil::locate(69,21);
        cin>>mes;
        if (mes>=1 && mes<=12){
            entra=false;
        }else{
            rlutil::locate(69,21);
            cout<<"                ";
            rlutil::locate(50,22);
            rlutil::setColor(rlutil::RED);
            cout<<"EL MES INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
            rlutil::setColor(rlutil::BLACK);
        }
    }
    /// Pide el a�o
    entra=true;
    while (entra){
        rlutil::locate(50,23);
        cout<<"INGRESE EL ANIO: ";
        rlutil::locate(68,23);
        cin>>anio;
        if (anio>=1000){
            entra=false;
        }else{
            rlutil::locate(68,23);
            cout<<"    ";
            rlutil::locate(50,24);
            rlutil::setColor(rlutil::RED);
            cout<<"EL ANIO INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
            rlutil::setColor(rlutil::BLACK);
        }
    }
    /// Verifica si la fecha es v�lida
    if (!esFechaValida(dia, mes, anio)) {
        rlutil::locate(69,19);
        cout<<"  ";
        rlutil::locate(69,21);
        cout<<"  ";
        rlutil::locate(68,23);
        cout<<"    ";
        rlutil::locate(50,24);
        rlutil::setColor(rlutil::RED);
        cout << "LA FECHA INGRESADA NO ES VALIDA. INTENTE NUEVAMENTE." << endl;
        cout << endl;
        rlutil::setColor(rlutil::BLACK);
        Cargar(); /// Se llama a la funci�n de nuevo para que el usuario ingrese una fecha v�lida
    }
}
bool esFechaValida(int dia, int mes, int anio) {
    /// Obtiene la fecha actual
    time_t now = time(0);
    tm *f = localtime(&now);
    /// Verifica si la fecha es anterior o igual a la fecha actual
    if (anio > f->tm_year + 1900 || (anio == f->tm_year + 1900 && mes > f->tm_mon + 1) || (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
        rlutil::locate(50,25);
        rlutil::setColor(rlutil::RED);
        cout<<"------------------------------"<<endl;
        rlutil::locate(50,26);
        cout << "LA FECHA DEBE SER ANTERIOR O IGUAL A LA FECHA ACTUAL." << endl;
        rlutil::locate(50,27);
        cout << "FECHA ACTUAL:" << f->tm_mday << "/" << f->tm_mon + 1 << "/" << f->tm_year + 1900 << endl;
        return false;
    }
    /// Verifica si el a�o es bisiesto (tiene 29 d�as en febrero)
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

    /// Verifica si el d�a es v�lido para el mes y a�o dados
    if (mes == 2) { /// Febrero
        if (esBisiesto) {
            return dia >= 1 && dia <= 29;
        } else {
            return dia >= 1 && dia <= 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) { /// Abril, Junio, Septiembre, Noviembre
        return dia >= 1 && dia <= 30;
    }
    return true;
}



#endif // FECHA_H_INCLUDED
