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
	if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    cout << "\n========== PRODUCTOS DISPONIBLES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }
}

void buscarProductos() {
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

