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
        cout << "L�mite de productos alcanzado."<<endl;
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
	string nombreBuscar;
    cout << "\n=== ACTUALIZAR PRODUCTO ===" << endl;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreBuscar);
    
    bool buscado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << "Producto encontrado. Datos actuales:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: " << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;
            
            cout << "\nIngrese los nuevos datos:" << endl;
            cout << "Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            cout << "Nuevo stock: ";
            cin >> productos[i].stock;
            cout << "Producto actualizado exitosamente!" << endl;
       		buscado = true;
       		break;
	    }
	}
	if (buscado == false) {
    cout << "Producto no encontrado." << endl;
	}
}

void eliminarProducto() {
	
	string Nombre;
    cout<< "Ingrese el nombre del producto a eliminar: ";
    cin.ignore();
    getline(cin, Nombre);

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == Nombre) {
            for (int j = i; j < totalProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            totalProductos--;
            cout << "Producto eliminado."<<endl;
            return;
        }
    }
    cout<< "Producto no encontrado."<<endl;
	
	
}

void realizarUnaVenta() {
}

void mostrarVentasRealizadas() {
}

void calcularTotalDeVentas() {
}

