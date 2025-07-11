#include <iostream>
#include "funciones.h"
using namespace std;

#include <iostream>
#include "funciones.h"
using namespace std;


Producto productos[100] = {
    {"Polera Oversize", 89.90, 10},
    {"Jogger Urbano", 79.50, 15},
    {"Gorra Negra", 39.90, 20},
    {"Casaca Denim", 129.99, 8},
    {"Zapatillas Retro", 199.00, 5}
};
int totalProductos = 5; 

void agregarProducto() {
    if (totalProductos < 100) {
        cin.ignore(); 
        cout << "Nombre del producto: ";
        getline(cin, productos[totalProductos].nombre);
        cout << "Precio: ";
        cin >> productos[totalProductos].precio;
        cout << "Stock: ";
        cin >> productos[totalProductos].stock;
        totalProductos++;
        cout << "EL producto fue agregado exitosamente."<<endl;
    } else {
        cout << "Límite de productos alcanzado."<<endl;
    }
}

void mostrarProductos() {
}

void buscarProductos() {
	string nombreBuscar;
    cout << "\n=== BUSCAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin.ignore();
	getline(cin, nombreBuscar);	
    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "\nProducto encontrado:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false) {
        cout << "Producto no encontrado." << endl;
    }
}

void actualizarProducto() {
}

void eliminarProducto() {
}

void realizarUnaVenta() {
}

void mostrarVentasRealizadas() {
}

void calcularTotalDeVentas() {
}

