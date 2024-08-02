#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <QString>
#include "producto.h"
#include <QDebug>

class Inventario
{
private:
    std::vector<Producto*> productos;
public:
    Inventario();
    //Inventario(const std::vector<Producto *> &productos);

    ~Inventario(){
        for(auto producto : productos){
            delete producto;
        }
    }

    void agregarProducto(Producto* producto){
        productos.push_back(producto);
    }

    void eliminarProducto(const QString& nombre){
        /*
        auto it = std::remove_if(productos.begin(), productos.end(),
                                 [&nombre](Producto* producto) {
                                     return producto->mostrarInfo().contains("Nombre del Producto: " + nombre + "\n");
                                 });
        if (it != productos.end()) {
            delete *it;
            productos.erase(it, productos.end());
        }
        */

        QString nombreBuscado = "Nombre del Producto: " + nombre + "\n";
        auto it = std::remove_if(productos.begin(), productos.end(),
                                 [&nombreBuscado](Producto* producto) {

                                     return producto->mostrarInfo().contains(nombreBuscado);
                                 });
        for (auto i = it; i != productos.end(); ++i) {
            delete *i;
        }
        productos.erase(it, productos.end());
    }

    QString mostrarInventario() const {
        QString info;
        for (const auto& producto : productos) {
            info.append(producto->mostrarInfo() + "\n");
        }
        return info;
    }

    double calcularValorInventario() const {
        double valorTotal = 0.0;
        for (const auto& producto : productos) {
            valorTotal += producto->calcularValorTotal();
        }
        return valorTotal;
    }
};

#endif // INVENTARIO_H
