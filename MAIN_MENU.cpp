#include <iostream>
#include<string>
#include <windows.h> 
#include "funciones.h"
#include "validaciones.h"
using namespace std;


int main() {
	SetConsoleOutputCP(1252);
	
    char opcion;
    char tipoUsuario;

    do {
    	system("cls");
        cout << endl;
        
        cout << "**************************************************\n";
    	cout << "*                                                *\n";
    	cout << "*        BIENVENIDO A LA TIENDA URBANA           *\n";
    	cout << "*                                                *\n";
    	cout << "*               << TOXSTYLE >>                   *\n";
    	cout << "*                                                *\n";
    	cout << "**************************************************\n\n";
        cout << endl;
        cout << "***�Qu� tipo de usuario eres?***\n" << endl;
        cout << "V. Vendedor\n";
        cout << "C. Cliente\n";
        cout << "Seleccione una opci�n: ";
        
        cin >> tipoUsuario;
        cin.ignore();
        tipoUsuario = toupper(tipoUsuario);

        if (tipoUsuario != 'V' && tipoUsuario != 'C') {
            cout << "\nOpci�n inv�lida. Intente nuevamente.\n";
            Sleep(1500);
        }
    } while (tipoUsuario != 'V' && tipoUsuario != 'C');

    // Mostrar men� seg�n el tipo de usuario
    if (tipoUsuario == 'V') {
        mostrarMenuVendedor();
    } else {
        mostrarMenuCliente();
    }

    return 0;
}
