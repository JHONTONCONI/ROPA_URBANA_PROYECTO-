#include "validaciones.h"
#include <iostream>
#include <cmath>
using namespace std;

string leerNombre(string mensaje) { //VALIDA QUE EL NOMBRE NO ESTE VACIO
    string nombre;
    do {
        cout << mensaje;
        getline(cin, nombre);
        if (nombre.empty()) {
            cout << "El nombre no puede estar vacío. Intente de nuevo.\n";
        }
    } while (nombre.empty());
    return nombre;
}

float leerPrecio(string mensaje) { //VALIDA QUE EL PRECIO NO SEA NEGATIVO NI CARACTER
    float precio;
    while (true) {
        cout << mensaje;
        if (!(cin >> precio)) {
            cout << "Entrada inválida. Debe ingresar un número decimal. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (precio <= 0) {
            cout << "El precio debe ser mayor que 0. Intente de nuevo.\n";
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');
        return precio;
    }
}

int leerStock(string mensaje) {//VALIDA QUE EL STOCK NO SEA CARACTER, NO SEA NEGATIVO O DECIMAL
    float stockTemp;
    while (true) {
        cout << mensaje;
        if (!(cin >> stockTemp)) {
            cout << "Entrada inválida. Debe ingresar un número.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (stockTemp < 0 || fmod(stockTemp, 1) != 0) {
            cout << "El stock debe ser un número entero no negativo.\n";
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');
        return stockTemp; // Conversión implícita de float a int
    }
}

char leerSN(string mensaje) {//VALIDA QUE LA RESPUESTA A CONTINUAR SOLO SEA UN CARACTER Y QUE SEA S O N
    string entrada;
    char opcion;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.length() == 1) {
            opcion = toupper(entrada[0]);
            if (opcion == 'S' || opcion == 'N') {
                return opcion;
            }
        }
        cout << "Opción inválida. Por favor ingrese solo 'S' o 'N'.\n";
    }
}

