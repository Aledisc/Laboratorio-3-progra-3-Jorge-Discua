#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "productocondescuento.h"
#include "productoconstock.h"
#include "inventario.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusAgregar->setVisible(false);
    ui->statusEliminar->setVisible(false);
}

Inventario manager;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    exit(0);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget_2->setCurrentIndex(index);
}




void MainWindow::on_pushButton_5_clicked()
{
    QString nombre = ui->nombreProd->text();
    double precio = ui->precioProd->value();
    QString desc = ui->descripcionProd->toPlainText();
    if(ui->stackedWidget_2->currentIndex() == 0){
        double cantidad = ui->cantidadProd->value();
        Producto* p1 = new ProductoConStock(nombre,precio,desc,cantidad);
        manager.agregarProducto(p1);
    }else{
        double descuento = ui->descuentoProd->value();
        Producto* p1 = new ProductoConDescuento(nombre,precio,desc,descuento);
        manager.agregarProducto(p1);
    }
    ui->statusAgregar->setVisible(true);
    QTimer::singleShot(3000, [&](){
        qDebug() << "Han pasado 3 segundos.";
        ui->statusAgregar->setVisible(false);
    });
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QString informacion = manager.mostrarInventario();
    ui->mostrarInformacion->setText(informacion);
    double total = manager.calcularValorInventario();
    QString str = QString::number(total,'f',2);
    ui->valorTotal->setText(str);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->nombreProd->setText("");
    ui->descripcionProd->setText("");
    ui->cantidadProd->setValue(0);
    ui->precioProd->setValue(0);
    ui->descuentoProd->setValue(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->eliminarProd->setText("");
}


void MainWindow::on_pushButton_6_clicked()
{
    QString eliminar = ui->eliminarProd->text();
    manager.eliminarProducto(eliminar);
    ui->statusEliminar->setVisible(true);
    QTimer::singleShot(3000, [&](){
        qDebug() << "Han pasado 3 segundos.";
        ui->statusEliminar->setVisible(false);
    });
}

