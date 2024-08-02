#include "productoconstock.h"

ProductoConStock::ProductoConStock(int cantidad, const QString &nombre, double precio, const QString &descripcion) : Producto(nombre, precio, descripcion),
    cantidad(cantidad)
{}
