#include <iostream>
#include <string>
#include "Dates.h"
using namespace std;

int main(){
    string date;
    int opc = 1;

    while (opc == 1) {
        system("cls");
        cout << "Digite la fecha: ";
        cin >> date;
        system("cls");
        Date* d = new Date(date);
        d->valInput();

        system("pause");
        system("cls");

        cout << "Desea validar otra fecha:" << endl;
        cout << "1.-Si" << endl;
        cout << "0.-No" << endl;
        cout << "Elige una opcion: ";
        cin >> opc;
        delete d;
    }
    system("cls");
    cout << "Gracias por usar el programa. FIN" << endl;
}