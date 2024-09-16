#ifndef CARGARDINERO_H_INCLUDED
#define CARGARDINERO_H_INCLUDED

Jugador cargarDinero(Jugador &reg){
system("cls");

if (!seInicioSesion(reg)) {
    cout << "DEBES INICIAR SESIÓN / REGISTRARTE" << endl;
    return reg;
}

float saldoAct = reg.getSaldo(), saldoNuevo;

cout<<"ACTUAL SALDO: "<< saldoAct;
cout<<endl;
cout<<"INGRESE DINERO A DEPOSITAR: ";
cin>> saldoNuevo;
reg.setSaldo(saldoNuevo);

system("pause");
return reg;
}


#endif // CARGARDINERO_H_INCLUDED
