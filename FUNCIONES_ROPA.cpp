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

Venta ventas[100] = {};
int totalVentas = 0;
	

void agregarProducto() {
	char seguir;
	do{
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
	        system("pause");
	    } else {
	        cout << "Limite de productos alcanzado."<<endl;
	        system("pause");
	        break;
	    }
	    cout << "\n¿Desea agregar otro producto? (S/N): ";
        cin >> seguir;
        seguir = toupper(seguir);
	}while (seguir == 'S');
	system("pause");
}

string aMinuscula(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

void mostrarProductos() {
	if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }
    char respuesta;
    cout << "\n¿Desea ver los productos ordenados? (S/N): ";
    cin >> respuesta;
    respuesta = toupper(respuesta);  
    if (respuesta == 'S') {
    	int opcion;
        cout << "\n¿Cómo desea ordenarlos?" << endl;
        cout << "1. Por nombre (A-Z)" << endl;
        cout << "2. Por precio (menor a mayor)" << endl;
        cout << "3. Por stock (menor a mayor)" << endl;
        cout << "Ingrese una opción (1-3): ";
        cin >> opcion;

        for (int i = 0; i < totalProductos - 1; i++) {
            for (int j = 0; j < totalProductos - i - 1; j++) {
            	
                bool debeIntercambiar = false;

                if (opcion == 1 && aMinuscula(productos[j].nombre) > aMinuscula(productos[j + 1].nombre)) {
                    debeIntercambiar = true;
                } else if (opcion == 2 && productos[j].precio > productos[j + 1].precio) {
                    debeIntercambiar = true;
                } else if (opcion == 3 && productos[j].stock > productos[j + 1].stock) {
                    debeIntercambiar = true;
                }

                if (debeIntercambiar) {
                    
                    Producto temp;
                    temp.nombre = productos[j].nombre;
                    temp.precio = productos[j].precio;
                    temp.stock = productos[j].stock;

                    productos[j].nombre = productos[j + 1].nombre;
                    productos[j].precio = productos[j + 1].precio;
                    productos[j].stock = productos[j + 1].stock;

                    productos[j + 1].nombre = temp.nombre;
                    productos[j + 1].precio = temp.precio;
                    productos[j + 1].stock = temp.stock;
                }
            }
        }
    }
    cout << "\n========== PRODUCTOS DISPONIBLES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }
    system("pause");
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
    system("pause");
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
	system("pause");
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
            system("pause");
            return;
        }
    }
    cout<< "Producto no encontrado."<<endl;
    system("pause");
}

void realizarUnaVenta() {
	cin.ignore();  // Limpiar buffer
    string nombreBuscado;
    int cantidad;
    
	if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }

    cout << "\n========== PRODUCTOS ACTUALES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << "Precio: S/ " << productos[i].precio << endl;
        cout << "Stock: " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }

    cout << "Ingrese el nombre del producto a vender: ";
    getline(cin, nombreBuscado);

    bool encontrado = false;

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].nombre == nombreBuscado) {
            encontrado = true;
            cout << "Stock disponible: " << productos[i].stock << endl;
            cout << "Ingrese cantidad a vender: ";
            cin >> cantidad;

            if (cantidad <= productos[i].stock) {
                productos[i].stock -= cantidad;
                float total = cantidad * productos[i].precio;
                ventas[totalVentas].producto = productos[i].nombre;
                ventas[totalVentas].cantidad = cantidad;
                ventas[totalVentas].total = total;
                totalVentas++;
                cout << "Venta realizada con éxito." << endl;
                cout << "Total a pagar: S/ " << total << endl;
            } else {
                cout << "Stock insuficiente." << endl;
                system("pause");
            }

            break;
        }
    }

    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
        system("pause");
    }
}

void mostrarVentasRealizadas() {
	cout<<"\n=== VENTAS REALIZADAS ==="<<endl;
	if (totalVentas == 0){
		cout<<"Todavia no se a realizado ventas"<<endl;
		system("pause");
		return;
	}
	for (int i=0;i<totalVentas; i++){
		cout << "\nVenta #" << i + 1 << ":" << endl;
        cout << "Producto: " << ventas[i].producto << endl;
        cout << "Cantidad: " << ventas[i].cantidad << endl;
        cout << "Total: S/ " << ventas[i].total << endl;
	}
	
}

void calcularTotalDeVentas() {
	cout << "\n=== TOTAL DE VENTAS ===" << endl;
    if (totalVentas == 0) {
        cout << "No se ha realizado ninguna venta." << endl;
        system("pause");
        return;
    }

    float sumaTotal = 0;
    for (int i = 0; i < totalVentas; i++) {
        sumaTotal += ventas[i].total;
    }

    cout << "El total acumulado de todas las ventas es: S/ " << sumaTotal << endl;
    system("pause");
}


void login() {
    string contrasenaReal = "toxo123";
    string intento;

    while (true) {
        system("cls");  // Limpia la pantalla antes de cada intento

        cout << "==========================================" << endl;
        cout << "               TOXO TIENDA                " << endl;
        cout<<  "                -LOGIN-                   " << endl;
        cout << "==========================================" << endl;
        cout << "| Ingrese la contraseña para continuar   |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "\n> Contraseña: ";
        getline(cin, intento);

        if (intento == contrasenaReal) {
            cout << "\n Acceso concedido. Bienvenido al sistema." << endl;
            Sleep(1500); 
            system("cls");
            return;
        } else {
            cout << "\n Contraseña incorrecta." << endl;
            cout << " Inténtelo nuevamente..." << endl;
            Sleep(1500);
        }
    }
}









