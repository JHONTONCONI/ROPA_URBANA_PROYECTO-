#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib> 
#include <stdlib.h>   
#include <windows.h>
#include<iostream>
using namespace std;

struct Producto {
	int codigo; //mod
    string nombre;
    float precio;
    int stock;
};

struct Venta {
	int codigo;
	string producto; 
	int cantidad; 
	float total;
};

void realizarUnaCompra();
void mostrarMenuVendedor();
void mostrarMenuCliente();
void agregarProducto();
void mostrarProductos();
void buscarProductos();
void actualizarProducto();
void eliminarProducto();
void realizarUnaVenta();
void mostrarVentasRealizadas();
void calcularTotalDeVentas();
void login();

#endif
