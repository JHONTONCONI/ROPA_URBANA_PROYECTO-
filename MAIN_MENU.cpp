#include <iostream>
#include<string>
#include <windows.h> 
#include "funciones.h"
using namespace std;


int main() {
	SetConsoleOutputCP(1252);
	login();
    char opcion;

    do {
        cout << endl;
        cout << "**************************************************\n";
    	cout << "*                                                *\n";
    	cout << "*        BIENVENIDO A LA TIENDA URBANA           *\n";
    	cout << "*                                                *\n";
    	cout << "*           << STAY FRESH, STAY COOL >>          *\n";
    	cout << "*                                                *\n";
    	cout << "**************************************************\n\n";
        cout << endl;
        cout << "***Seleccione una opcion***" << endl;
        cout << "A. Agregar producto." << endl;
        cout << "B. Mostrar productos." << endl;
        cout << "C. Buscar productos." << endl;
        cout << "D. Actualizar producto." << endl;
        cout << "E. Eliminar producto" << endl;
		cout << "F. Realizar una venta" << endl;
		cout << "G. Mostrar ventas realizadas" << endl;
		cout << "H. Calcular total de ventas" << endl;
		cout << "I. Salir del programa." << endl;
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': agregarProducto(); break;
            case 'B': mostrarProductos(); break; 
            case 'C': buscarProductos(); break;
            case 'D': actualizarProducto(); break;
			case 'E': eliminarProducto(); break;
			case 'F': realizarUnaVenta(); break;
			case 'G': mostrarVentasRealizadas(); break;
			case 'H': calcularTotalDeVentas(); break;
            case 'I': cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }

    } while (opcion != 'I');

    return 0;
}
