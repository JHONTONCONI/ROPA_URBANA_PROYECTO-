#ifndef FUNCIONES_H
#define FUNCIONES_H
#include<iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    int stock;
};


void agregarProducto();
void mostrarProductos();
void buscarProductos();
void actualizarProducto();
void eliminarProducto();
void realizarUnaVenta();
void mostrarVentasRealizadas();
void calcularTotalDeVentas();

#endif
