#include "producto.h"

Producto::Producto(const QString& nombre, double precio, const QString& descripcion)
    : nombreDelProducto(nombre), precio(precio), descripcion(descripcion) {
}

Producto::~Producto() {
}

