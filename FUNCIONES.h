#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib> 
#include <stdlib.h>   
#include <windows.h>
#include<iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    int stock;
};

struct Venta {
	string producto; 
	int cantidad; 
	float total;
};


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
