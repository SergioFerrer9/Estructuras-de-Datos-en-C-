#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <listaenlazada.h>
#include <cola.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <QLine>

using std::cout;
using std::endl;

using std::string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   Lista *lista = new Lista();
   lista->Agregar("uno",1);
   lista->Agregar("dos",2);
   lista->Agregar("tres",3);
   lista->Agregar("cuatro",4);
   lista->Agregar("cinco",5);
   lista->Agregar("seis",6);
   lista->Agregar("siete",7);
   lista->Agregar("ocho",8);
   lista->Mostrar();
   lista->Graficar_Lista();
   QPixmap pix("/home/debian9/Escritorio/ProyectoVacas/Lista_Simple.png");
   ui->label->setPixmap(pix);

   Cola *cola = new Cola();
   cola->Agregar_Cola("Sergio", 28);
   cola->Agregar_Cola("Tomas", 29);
   cola->Agregar_Cola("Angel", 30);
   cola->Agregar_Cola("Luna", 31);
   cola->Agregar_Cola("Laura", 32);
   cola->Agregar_Cola("Samuel", 33);
   cola->Agregar_Cola("Judas", 34);
   cola->Agregar_Cola("Estopa", 35);
   cola->Agregar_Cola("Luis", 36);
   cola->Agregar_Cola("Sol", 37);
   cola->Mostrar_Cola();






}


void MainWindow::on_pushButton_2_clicked()
{//Boton 2 Agrear a COLA...

    Cola *cola = new Cola();

    //Obtener el nombre del LineEdit()...
    string nombre =ui->lineEdit->text().toUtf8().constData();
    //Castear de String a Char...
    char *nombrec = strdup(nombre.c_str());
    //Obtener el numero del LineEdit_2()...
    int edad = ui->lineEdit_2->text().toInt();
    //Agregar a Cola y mostrar la Cola...
    cola->Agregar_Cola(nombrec,edad);
    cola->Mostrar_Cola();

}

void MainWindow::on_pushButton_3_clicked()
{//Boton 3 Eliminar de la Cola...
    Cola *cola = new Cola();
    cola->Eliminar_Cola();
    cola->Mostrar_Cola();

}
