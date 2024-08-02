#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

class Producto
{
protected:
    QString nombreDelProducto;
    double precio;
    QString descripcion;

public:
    Producto(const QString& nombre, double precio, const QString& descripcion);

    virtual double calcularValorTotal() const = 0;
    virtual QString mostrarInfo() const {
        QString info;
        info.append("Nombre del Producto: " + nombreDelProducto + "\n");
        info.append("Precio: " + QString::number(precio) + "\n");
        info.append("Descripción: " + descripcion + "\n");
        return info;
    }

    virtual ~Producto();
};

#endif // PRODUCTO_H
