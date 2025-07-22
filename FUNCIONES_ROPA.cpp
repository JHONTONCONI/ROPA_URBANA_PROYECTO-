#include <iostream>
#include "funciones.h"
#include "validaciones.h"
#include <cmath>
using namespace std;


void mostrarMenuVendedor() {
	login();
    char opcion;

    do {
        system("cls");
        cout << "**************************************************\n";
        cout << "*        PANEL DE VENDEDOR - TOXSTYLE            *\n";
        cout << "**************************************************\n\n";

        cout << "***Seleccione una opci�n***\n";
        cout << "A. Agregar producto.\n";
        cout << "B. Mostrar productos.\n";
        cout << "C. Buscar productos.\n";
        cout << "D. Actualizar producto.\n";
        cout << "E. Eliminar producto.\n";
        cout << "F. Realizar una venta.\n";
        cout << "G. Mostrar ventas realizadas.\n";
        cout << "H. Calcular total de ventas.\n";
        cout << "I. Salir del programa.\n";
        cout << "Opci�n: ";
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
            case 'I': cout << "Saliendo...\n"; break;
            default: cout << "Opci�n no v�lida.\n"; Sleep(1000);
        }

    } while (opcion != 'I');
}


void mostrarMenuCliente() {
    char opcion;

    do {
        system("cls");
        cout << "**************************************************\n";
        cout << "*         PANEL DE CLIENTE - TOXSTYLE            *\n";
        cout << "**************************************************\n\n";

        cout << "***Seleccione una opci�n***\n";
        cout << "A. Ver productos disponibles.\n";
        cout << "B. Realizar compra.\n";
        cout << "C. Salir.\n";
        cout << "Opci�n: ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': mostrarProductos(); break;
            case 'B': realizarUnaCompra(); break;
            case 'C': cout << "Saliendo...\n"; break;
            default: cout << "Opci�n no v�lida.\n"; Sleep(1000);
        }

    } while (opcion != 'C');
}





Producto productos[100] = {
    {100, "Polo Street", 59.90, 12},
    {101, "Jogger Urbano", 79.50, 15},
    {102, "Chompa Hoodie", 149.90, 7},
    {103, "Casaca Denim", 129.99, 8},
    {104, "Short Deportivo", 49.90, 18},
    {105, "Mochila Urbana", 109.90, 6},
    {106, "Zapatillas Chunky", 219.00, 4},
    {107, "Chaleco Street", 119.90, 6},
    {108, "Cargo Pants", 139.90, 9},
    {109, "Zapatillas Skate", 199.90, 5},
    {110, "Gorra Trucker", 39.90, 15}
};

int totalProductos = 11; 

//Variables globales
Venta ventas[100] = {};
int totalVentas = 0;
	

//Funcion de realizar una compra para el panel del usuario
void realizarUnaCompra() {
    if (totalProductos == 0) {
        cout << "No hay productos disponibles." << endl;
        system("pause");
        return;
    }

    cin.ignore();  
    int codigoBuscado;
    int cantidad;

    system("cls");
    cout << "\n========== PRODUCTOS DISPONIBLES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "C�digo  : " << productos[i].codigo << endl;
        cout << "Nombre  : " << productos[i].nombre << endl;
        cout << "Precio  : S/ " << productos[i].precio << endl;
        cout << "Stock   : " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }

    cout << "\n=== COMPRA DE PRODUCTO ===" << endl;
    
    // Validar c�digo ingresado
    float codigoTemp;
	bool codigoValido = false;
	do {
    	cout << "Ingrese el c�digo del producto a comprar (100-199): ";
    	if (!(cin >> codigoTemp)) {
        	cout << "Entrada inv�lida. Ingrese un n�mero entero entre 100 y 199.\n";
        	cin.clear();
       	 	cin.ignore(1000, '\n');
       	 	continue;
   		}

   		 if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
   		     cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
       		 continue;
    	}

    	codigoBuscado = codigoTemp;
   		codigoValido = true;

	} while (!codigoValido);


    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigoBuscado) {
            encontrado = true;
            cout << "Producto encontrado: " << productos[i].nombre << endl;
            cout << "Stock disponible: " << productos[i].stock << endl;

            float cantidadTemp;
            do {
                cout << "Ingrese cantidad a comprar: ";
                if (!(cin >> cantidadTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero entero positivo.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if (cantidadTemp <= 0 || fmod(cantidadTemp, 1) != 0) {
                    cout << "La cantidad debe ser un n�mero entero positivo.\n";
                    continue;
                }

                cantidad = cantidadTemp;
                if (cantidad > productos[i].stock) {
                    cout << "Cantidad mayor al stock disponible. Ingrese un valor v�lido.\n";
                    continue;
                }

                break;
            } while (true);

            cin.ignore(); 

            productos[i].stock -= cantidad;
            float total = cantidad * productos[i].precio;

            cout << "\nCompra realizada con �xito." << endl;
            cout << "Total a pagar: S/ " << total << endl;

            // BOLETA VISUAL
            cout << "\n------------------------------------------\n";
            cout << "              *** BOLETA ***              \n";
            cout << "------------------------------------------\n";
            cout << "Tienda     : TOXSTYLE" << endl;
            cout << "Direcci�n  : Av. Comercial #123, Tacna - Per�" << endl;
            cout << "------------------------------------------\n";
            cout << "Producto        : " << productos[i].nombre << endl;
            cout << "Cantidad        : " << cantidad << endl;
            cout << "Precio unitario : S/ " << productos[i].precio << endl;
            cout << "------------------------------------------\n";
            cout << "TOTAL PAGADO    : S/ " << total << endl;
            cout << "------------------------------------------\n";
            cout << "�Gracias por tu compra!" << endl;
            cout << "Disfruta tu estilo con TOXSTYLE." << endl;
            cout << "------------------------------------------\n\n";

            // Fin del proceso
            string Retorno;
            cout << "\nRegresar al men� principal.......[1]\n";
            do {
                cout << "> ";
                getline(cin, Retorno);
                if (Retorno != "1") {
                    cout << "Opci�n inv�lida. Para regresar al men� digite [1]\n";
                }
            } while (Retorno != "1");

            cout << "\nRegresando al men�..." << endl;
            Sleep(1000);
            system("cls");
            return;
        }
    }

    if (!encontrado) {
        system("cls");
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! C�digo de producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;
		cin.ignore();
		
		//Retornar al menu
        string Retorno;
        cout << "\nRegresar al men� principal.......[1]\n";
        do {
            cout << ">";
            getline(cin, Retorno);
            if (Retorno != "1") {
                cout << "Opci�n inv�lida. Para regresar al men� digite [1]\n";
            }
        } while (Retorno != "1");

        cout << "\nRegresando al men�..." << endl;
        Sleep(1000);
        system("cls");
    }
}





//Funcion para agregar productos
void agregarProducto() {
    system("cls");
    char seguir;
    cout << "=========================================\n";
    cout << " SE AGREGAR�N PRODUCTOS AL INVENTARIO\n";
    cout << " Se requieren los siguientes datos:\n";
    cout << " - C�digo (100 - 199, �nico)\n - Nombre\n - Precio\n - Stock\n";
    cout << "=========================================\n\n";

    do {
        if (totalProductos < 100) {
            cin.ignore();

            // Validar c�digo del producto
            float codigoTemp;
            int codigo;
            bool codigoValido;
            do {
                codigoValido = true;
                cout << "C�digo del producto (100 - 199): ";
                if (!(cin >> codigoTemp)) {
                    cout << "Entrada inv�lida. Ingrese un n�mero.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    codigoValido = false;
                    continue;
                }

                if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
                    cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
                    codigoValido = false;
                    continue;
                }

                codigo = codigoTemp;  

                // Verificar si ya existe
                for (int i = 0; i < totalProductos; i++) {
                    if (productos[i].codigo == codigo) {
                        cout << "C�digo duplicado. Ya existe un producto con ese c�digo.\n";
                        codigoValido = false;
                        break;
                    }
                }

            } while (!codigoValido);

            productos[totalProductos].codigo = codigo;

            cin.ignore();  
            do {
                cout << "Nombre del producto: ";
                getline(cin, productos[totalProductos].nombre);
                if (productos[totalProductos].nombre == "") {
                    cout << "El nombre no puede estar vac�o. Intente de nuevo.\n";
                }
            } while (productos[totalProductos].nombre == "");

            // Precio
            do {
                cout << "Precio: ";
                if (!(cin >> productos[totalProductos].precio)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    productos[totalProductos].precio = -1;
                    continue;
                }
                if (productos[totalProductos].precio <= 0) {
                    cout << "El precio debe ser mayor que 0. Intente de nuevo.\n";
                }
            } while (productos[totalProductos].precio <= 0);

            // Stock
            float stockTemp;
            do {
                cout << "Stock: ";
                if (!(cin >> stockTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero entero.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (stockTemp < 0 || fmod(stockTemp, 1) != 0) {
                    cout << "El stock debe ser un n�mero entero no negativo. Intente de nuevo.\n";
                    continue;
                }

                productos[totalProductos].stock = stockTemp;
                break;

            } while (true);

            totalProductos++;
            cout << "El producto fue agregado exitosamente." << endl;

        } else {
            cout << "L�mite de productos alcanzado." << endl;
            break;
        }

        do {
            cout << "\n�Desea agregar otro producto? (S/N): ";
            cin.ignore(1000, '\n');
            cin >> seguir;
            seguir = toupper(seguir);
            if (seguir != 'S' && seguir != 'N') {
                cout << "Opci�n inv�lida. Por favor ingrese solo 'S' o 'N'." << endl;
            }
        } while (seguir != 'S' && seguir != 'N');

    } while (seguir == 'S');

    cout << "\nRegresando al men�..." << endl;
    Sleep(1000);
    system("cls");
}




//Funcion para comparar el texto ingresado
string aMinuscula(string texto) {
    for (int i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

//Funcion para mostrar los productos 
void mostrarProductos() {
    char RetornoMenu;
    if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }
    
    char respuesta;
    do {
        system("cls");
        cout << "\n�Desea ver los productos ordenados? (S/N): ";
        cin >> respuesta;
        respuesta = toupper(respuesta);
        if (respuesta != 'S' && respuesta != 'N') {
            cout << "\n---------------------------------------------------" << endl;
            cout << "Opci�n inv�lida. Debe digitar S o N." << endl;
            cout << "---------------------------------------------------" << endl;
            system("pause");
        }
    } while (respuesta != 'S' && respuesta != 'N');

    if (respuesta == 'S') {
        char opcionChar;
        int opcion;
        do {
            system("cls");
            cout << "\n�C�mo desea ordenarlos?" << endl;
            cout << "1. Por nombre (A-Z)" << endl;
            cout << "2. Por precio (menor a mayor)" << endl;
            cout << "3. Por stock (menor a mayor)" << endl;
            cout << "Ingrese una opci�n (1-3): ";
            cin >> opcionChar;

            if (opcionChar == '1' || opcionChar == '2' || opcionChar == '3') {
                opcion = opcionChar - '0'; //los caracteres 0, 1, 2 y 3 valen respectivamente 48, 49, 50 y 51, esto es en codigo ASCII por lo cual al restar nos dara un valor entero para la variable "opcion"
                break;
            } else {
                cout << "\n---------------------------------------------------" << endl;
                cout << "Opci�n inv�lida, vuelva a digitar un n�mero (1-3)" << endl;
                cout << "---------------------------------------------------" << endl;
                system("pause");
            }

        } while (true);

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
                    Producto temp = productos[j];
                    productos[j] = productos[j + 1];
                    productos[j + 1] = temp;
                }
            }
        }
    }

    system("cls");
    cout << "\n========== PRODUCTOS DISPONIBLES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "C�digo : " << productos[i].codigo << endl;
        cout << "Nombre : " << productos[i].nombre << endl;
        cout << "Precio : S/ " << productos[i].precio << endl;
        cout << "Stock  : " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }

    string Retorno;
    cout << "\nRegresar al menu principal.......[1]" << endl;
    cin.ignore();
    do {
        getline(cin, Retorno);
        if (Retorno != "1") {
            cout << "Opci�n inv�lida. Para regresar al Menu digite [1]" << endl;
        }
    } while (Retorno != "1");

    cout << "\nRegresando al menu..." << endl;
    Sleep(1000);
    system("cls");
}


//Funcion para buscar los productos 
void buscarProductos() {
    system("cls");
    cout << "\n=== BUSCAR PRODUCTO ===" << endl;

    float codigoTemp;
    int codigoBuscado;
    bool codigoValido;

    // Validar entrada del c�digo
    do {
        cout << "Ingrese el c�digo del producto a buscar (100-199): ";
        if (!(cin >> codigoTemp)) {
            cout << "Entrada inv�lida. Debe ingresar un n�mero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
            cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
            continue;
        }

        codigoBuscado = codigoTemp;
        break;

    } while (true);

    bool encontrado = false;
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigoBuscado) {
            cout << "\nProducto encontrado:" << endl;
            cout << "C�digo : " << productos[i].codigo << endl;
            cout << "Nombre : " << productos[i].nombre << endl;
            cout << "Precio : S/ " << productos[i].precio << endl;
            cout << "Stock  : " << productos[i].stock << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! Producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;
    }

    string Retorno;
    cout << "\nRegresar al men� principal.......[1]" << endl;
    cin.ignore();
    do {
        cout << "> ";
        getline(cin, Retorno);
        if (Retorno != "1") {
            cout << "Opci�n inv�lida. Para regresar al men� digite [1]" << endl;
        }
    } while (Retorno != "1");

    cout << "\nRegresando al men�..." << endl;
    Sleep(1000);
    system("cls");
}



//Funcion para actualizar los productos 
void actualizarProducto() {
    system("cls");
    cout << "\n=== ACTUALIZAR PRODUCTO ===" << endl;

    float codigoTemp;
    int codigoBuscar;

    // Validaci�n del c�digo
    do {
        cout << "Ingrese el c�digo del producto a actualizar (100-199): ";
        if (!(cin >> codigoTemp)) {
            cout << "Entrada inv�lida. Debe ingresar un n�mero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
            cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
            continue;
        }

        codigoBuscar = codigoTemp;
        break;
    } while (true);

    bool buscado = false;
    cin.ignore();
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigoBuscar) {
            cout << "\n***Producto encontrado***\n";
            cout << "C�digo: " << productos[i].codigo << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Precio: S/ " << productos[i].precio << endl;
            cout << "Stock: " << productos[i].stock << endl;

            cout << "\nIngrese los nuevos datos:" << endl;

            do {
                cout << "Nuevo nombre: ";
                getline(cin, productos[i].nombre);
                if (productos[i].nombre == "") {
                    cout << "El nombre no puede estar vac�o. Intente de nuevo.\n";
                }
            } while (productos[i].nombre == "");

            float precioTemp;
            do {
                cout << "Nuevo precio: ";
                if (!(cin >> precioTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if (precioTemp <= 0) {
                    cout << "El precio debe ser mayor a 0. Intente de nuevo.\n";
                    continue;
                }
                productos[i].precio = precioTemp;
                break;
            } while (true);

            float stockTemp;
            do {
                cout << "Nuevo stock: ";
                if (!(cin >> stockTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero entero.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if (stockTemp < 0 || fmod(stockTemp, 1) != 0) {
                    cout << "El stock debe ser un n�mero entero no negativo.\n";
                    continue;
                }
                productos[i].stock = stockTemp;
                break;
            } while (true);

            cout << "Producto actualizado exitosamente!\n";
            buscado = true;
            break;
        }
    }

    if (!buscado) {
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! Producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;
    }

    string Retorno;
    cout << "\nRegresar al men� principal.......[1]" << endl;
    cin.ignore();
    do {
        getline(cin, Retorno);
        if (Retorno != "1") {
            cout << "Opci�n inv�lida. Para regresar al men� digite [1]" << endl;
        }
    } while (Retorno != "1");

    cout << "\nRegresando al men�..." << endl;
    Sleep(1000);
    system("cls");
}



//Funcion para eliminar un productos
void eliminarProducto() {
    system("cls");
    cout << "\n========== PRODUCTOS ACTUALES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "C�digo : " << productos[i].codigo << endl;
        cout << "Nombre : " << productos[i].nombre << endl;
        cout << "Precio : S/ " << productos[i].precio << endl;
        cout << "Stock  : " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }

    float codigoTemp;
    int codigoEliminar;

    // Validaci�n del c�digo
    do {
        cout << "\nIngrese el c�digo del producto a eliminar (100-199): ";
        if (!(cin >> codigoTemp)) {
            cout << "Entrada inv�lida. Debe ingresar un n�mero.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
            cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
            continue;
        }
        codigoEliminar = codigoTemp;
        break;
    } while (true);

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigoEliminar) {
            // Confirmar eliminaci�n
            char confirmar;
            do {
                cout << "�Est� seguro de eliminar el producto '" << productos[i].nombre << "'? (S/N): ";
                cin >> confirmar;
                confirmar = toupper(confirmar);
                if (confirmar != 'S' && confirmar != 'N') {
                    cout << "Opci�n inv�lida. Debe ingresar S o N.\n";
                }
            } while (confirmar != 'S' && confirmar != 'N');

            if (confirmar != 'S') {
                cout << "Eliminaci�n cancelada.\n";
                cout << "Regresando al men� principal..." << endl;
                Sleep(1800);
                system("cls");
                return;
            }

            // Eliminar producto desplazando el arreglo
            for (int j = i; j < totalProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            totalProductos--;

            cout << "Producto eliminado exitosamente.\n";

            string Retorno;
            cout << "\nRegresar al men� principal.......[1]\n";
            cin.ignore();
            do {
                getline(cin, Retorno);
                if (Retorno != "1") {
                    cout << "Opci�n inv�lida. Para regresar al men� digite [1]\n";
                }
            } while (Retorno != "1");

            cout << "\nRegresando al men�..." << endl;
            Sleep(1000);
            system("cls");
            return;
        }
    }

    // Si no se encontr� el producto
    cout << "\n-----------------------------------" << endl;
    cout << "�Error! Producto no encontrado." << endl;
    cout << "-----------------------------------" << endl;

    string Retorno;
    cout << "\nRegresar al men� principal.......[1]" << endl;
    cin.ignore();
    do {
        cout << "> ";
        getline(cin, Retorno);
        if (Retorno != "1") {
            cout << "Opci�n inv�lida. Para regresar al men� digite [1]" << endl;
        }
    } while (Retorno != "1");

    cout << "\nRegresando al men�..." << endl;
    Sleep(1000);
    system("cls");
}


//Funcion para realizar una venta
void realizarUnaVenta() {
    cin.ignore();
    int codigoBuscado;
    int cantidad;
    bool encontrado = false;

    if (totalProductos == 0) {
        cout << "No hay productos registrados." << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "\n========== PRODUCTOS ACTUALES ==========\n";
    for (int i = 0; i < totalProductos; i++) {
        cout << "C�digo  : " << productos[i].codigo << endl;
        cout << "Nombre  : " << productos[i].nombre << endl;
        cout << "Precio  : S/ " << productos[i].precio << endl;
        cout << "Stock   : " << productos[i].stock << endl;
        cout << "------------------------------------------\n";
    }

    // Validar c�digo de producto
    float codigoTemp;
    do {
        cout << "Ingrese el c�digo del producto a vender (100-199): ";
        if (!(cin >> codigoTemp)) {
            cout << "Entrada inv�lida. Ingrese un n�mero entero entre 100 y 199.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (codigoTemp < 100 || codigoTemp > 199 || fmod(codigoTemp, 1) != 0) {
            cout << "C�digo inv�lido. Debe ser un n�mero entero entre 100 y 199.\n";
            continue;
        }

        codigoBuscado = codigoTemp;
        break;
    } while (true);

    cin.ignore();

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigoBuscado) {
            encontrado = true;
            cout << "Stock disponible: " << productos[i].stock << endl;

            float cantidadTemp;
            do {
                cout << "Ingrese cantidad a vender: ";
                if (!(cin >> cantidadTemp)) {
                    cout << "Entrada inv�lida. Debe ingresar un n�mero entero positivo.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                if (cantidadTemp <= 0 || fmod(cantidadTemp, 1) != 0) {
                    cout << "La cantidad debe ser un n�mero entero positivo.\n";
                    continue;
                }

                cantidad = cantidadTemp;

                if (cantidad > productos[i].stock) {
                    cout << "Stock insuficiente. Ingrese una cantidad dentro del l�mite (" << productos[i].stock << ").\n";
                    continue;
                }

                break;
            } while (true);

            productos[i].stock -= cantidad;
            float total = cantidad * productos[i].precio;
            ventas[totalVentas].producto = productos[i].nombre;
            ventas[totalVentas].cantidad = cantidad;
            ventas[totalVentas].total = total;
            totalVentas++;

            cout << "\nVenta realizada con �xito." << endl;
            cout << "Total a pagar: S/ " << total << endl;

            // BOLETA VISUAL
            cout << "\n------------------------------------------\n";
            cout << "              *** BOLETA ***              \n";
            cout << "------------------------------------------\n";
            cout << "Tienda     : TOXSTYLE" << endl;
            cout << "Direcci�n  : Av. Comercial #123, Tacna - Per�" << endl;
            cout << "RUC        : 12345678901" << endl;
            cout << "------------------------------------------\n";
            cout << "Producto        : " << productos[i].nombre << endl;
            cout << "Cantidad        : " << cantidad << endl;
            cout << "Precio unitario : S/ " << productos[i].precio << endl;
            cout << "------------------------------------------\n";
            cout << "TOTAL RECIBIDO  : S/ " << total << endl;
            cout << "------------------------------------------\n";
            cout << "�Gracias por vender en nuestra tienda!" << endl;
            cout << "Valoramos mucho tu preferencia." << endl;
            cout << "------------------------------------------\n\n";

            cin.ignore();
            string Retorno;
            cout << "\nRegresar al men� principal.......[1]\n";
            do {
                cout << "> ";
                getline(cin, Retorno);
                if (Retorno != "1") {
                    cout << "Opci�n inv�lida. Para regresar al men� digite [1]\n";
                }
            } while (Retorno != "1");

            cout << "\nRegresando al men�..." << endl;
            Sleep(1000);
            system("cls");
            return;
        }
    }

    if (!encontrado) {
        system("cls");
        cout << "\n-----------------------------------" << endl;
        cout << "�Error! Producto no encontrado." << endl;
        cout << "-----------------------------------" << endl;

        string Retorno;
        cout << "\nRegresar al men� principal.......[1]\n";
        do {
            cout << ">";
            getline(cin, Retorno);
            if (Retorno != "1") {
                cout << "Opci�n inv�lida. Para regresar al men� digite [1]\n";
            }
        } while (Retorno != "1");

        cout << "\nRegresando al men�..." << endl;
        Sleep(1000);
        system("cls");
    }
}



//Funcion para mostrar las ventas 
void mostrarVentasRealizadas() {
	cin.ignore();
	system("cls");
    cout << "\n============================================" << endl;
    cout << "               VENTAS REALIZADAS            " << endl;
    cout << "============================================" << endl;

    if (totalVentas == 0){
        cout << "\nTodav�a no se ha realizado ninguna venta." << endl;
        cout << "============================================" << endl;
        string Retorno;
		cout<<"\nRegresar al menu principal.......[1]"<<endl;	    
	    do{
			cout<<">";
			getline(cin, Retorno);
			if(Retorno != "1"){
			   	cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
			}
		}while(Retorno != "1");
		cout<<"\nRegresando al menu..."<<endl;
		Sleep(1000);
		system("cls");
		return;
    }

    for (int i = 0; i < totalVentas; i++) {
        cout << "\nVenta #" << i + 1 << endl;
        cout << "Producto : " << ventas[i].producto << endl;
        cout << "Cantidad : " << ventas[i].cantidad << endl;
        cout << "Total    : S/ " << ventas[i].total << endl;
        cout << "--------------------------------------------" << endl;
    }
	string Retorn;
	cout<<"\nRegresar al menu principal.......[1]"<<endl;	    
    do{
		cout<<"> ";
		getline(cin, Retorn);
		if(Retorn != "1"){
		   	cout<<"Opcion inv�lida. Para regresar el Menu digite [1]"<<endl;
		}
	}while(Retorn != "1");
	cout<<"\nRegresando al menu..."<<endl;
	Sleep(1000);
	system("cls");
}


//Funcion para calcular el total de ventas 
void calcularTotalDeVentas() {
    cout << "\n============================================" << endl;
    cout << "               TOTAL DE VENTAS              " << endl;
    cout << "============================================" << endl;

    if (totalVentas == 0) {
        cout << "\nNo se ha realizado ninguna venta." << endl;
        cout << "============================================" << endl;
        system("pause");
        cout<<"Regresando al menu...";
		Sleep(1800);
		system("cls");
        return;
    }

    float sumaTotal = 0;
    for (int i = 0; i < totalVentas; i++) {
        sumaTotal += ventas[i].total;
    }

    cout << "\nEl total acumulado de todas las ventas es: S/ " << sumaTotal << endl;
    cout << "============================================" << endl;
    system("pause");
    cout<<"saliendo al menu...";
    Sleep(1800);
	system("cls");
}

//funcion para iniciar sesion
void login() {
    string contrasenaReal = "toxo123";
    string intento;

    while (true) {
        system("cls");

        cout << "==========================================" << endl;
        cout << "               TOXO TIENDA                " << endl;
        cout<<  "                -LOGIN-                   " << endl;
        cout << "==========================================" << endl;
        cout << "| Ingrese la contrase�a para continuar   |" << endl;
        cout << "------------------------------------------" << endl;
        cout << "\n> Contrase�a: ";
        getline(cin, intento);

        if (intento == contrasenaReal) {
            cout << "\n Acceso concedido. Bienvenido al sistema." << endl;
            Sleep(1000); 
            system("cls");
            return;
        } else {
            cout << "\n Contrase�a incorrecta." << endl;
            cout << " Int�ntelo nuevamente..." << endl;
            Sleep(1000);
        }
    }
}









