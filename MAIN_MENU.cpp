#include <iostream>
#include<string>
#include <windows.h> 
#include "funciones.h"
#include "validaciones.h"
using namespace std;


int main() {
    SetConsoleOutputCP(1252);
    
    while(true) {  // Bucle infinito para que siempre regrese al men� principal
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
        cout << "S. Salir\n";  
        cout << "Seleccione una opci�n: ";
        
        char tipoUsuario;
        cin >> tipoUsuario;
        cin.ignore();
        tipoUsuario = toupper(tipoUsuario);

        switch(tipoUsuario) {
            case 'V': 
                mostrarMenuVendedor();
                break;
            case 'C':
                mostrarMenuCliente();
                break;
            case 'S':
                cout << "Saliendo del programa...\n";
                return 0;  
            default:
                cout << "\nOpci�n inv�lida. Intente nuevamente.\n";
                Sleep(1500);
        }
    }

    return 0;
}
