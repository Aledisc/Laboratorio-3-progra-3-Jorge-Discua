#ifndef PRODUCTOCONSTOCK_H
#define PRODUCTOCONSTOCK_H

#include "producto.h"

class ProductoConStock : public Producto
{
private:
    int cantidad;
public:
    ProductoConStock(const QString &nombre, double precio, const QString &descripcion, int cantidad);
    ProductoConStock(int cantidad, const QString &nombre, double precio, const QString &descripcion);


    double calcularValorTotal() const override;


    QString mostrarInfo() const override;
};

inline ProductoConStock::ProductoConStock(const QString &nombre, double precio, const QString &descripcion, int cantidad)
    : Producto(nombre, precio, descripcion), cantidad(cantidad) {}

inline double ProductoConStock::calcularValorTotal() const {
    return precio * cantidad;
}

inline QString ProductoConStock::mostrarInfo() const {
    QString info;
    info.append("Nombre del Producto: " + nombreDelProducto + "\n");
    info.append("Precio: " + QString::number(precio) + "\n");
    info.append("Descripción: " + descripcion + "\n");
    info.append("Cantidad en Stock: " + QString::number(cantidad) + "\n");
    info.append("Valor Total: " + QString::number(calcularValorTotal()) + "\n");
    return info;
}

#endif // PRODUCTOCONSTOCK_H
