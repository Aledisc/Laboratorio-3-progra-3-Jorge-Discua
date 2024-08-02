#ifndef PRODUCTOCONDESCUENTO_H
#define PRODUCTOCONDESCUENTO_H

#include "producto.h"

class ProductoConDescuento : public Producto
{
private:
    double descuento;

public:
    ProductoConDescuento(double descuento, const QString &nombre, double precio, const QString &descripcion);

    ProductoConDescuento(const QString &nombre, double precio, const QString &descripcion, double descuento)
        : Producto(nombre, precio, descripcion), descuento(descuento) {};

    double calcularValorTotal() const override {
        return precio - (precio * (descuento / 100.00));
    }

    QString mostrarInfo() const override {
        QString info;
        info.append("Nombre del Producto: " +nombreDelProducto.toStdString() + "\n");
        info.append("Precio: " + QString::number(precio) + "\n");
        info.append("Descripción: " + descripcion + "\n");
        info.append("Descuento: " + QString::number(descuento) + "%\n");
        info.append("Precio con Descuento: " + QString::number(calcularValorTotal()) + "\n");
        return info;
    }
};

#endif // PRODUCTOCONDESCUENTO_H
