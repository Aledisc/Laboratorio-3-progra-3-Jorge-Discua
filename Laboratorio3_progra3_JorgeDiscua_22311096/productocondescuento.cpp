#include "productocondescuento.h"

//ProductoConDescuento::ProductoConDescuento() {}

ProductoConDescuento::ProductoConDescuento(double descuento, const QString &nombre, double precio, const QString &descripcion) : Producto(nombre, precio, descripcion),
    descuento(descuento)
{}
