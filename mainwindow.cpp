#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <listaenlazada.h>
#include <cola.h>
#include <pila.h>
#include <lista_circular.h>
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
   cola->Graficar_Cola();
   QPixmap pixc("/home/debian9/Escritorio/ProyectoVacas/Cola.png");
   ui->label_4->setPixmap(pixc);

   Pila *pila = new Pila();
   pila->Agregar_Pila("Guatemala",17);
   pila->Agregar_Pila("Huehetenango",32);
   pila->Agregar_Pila("San Marcos",30);
   pila->Agregar_Pila("Quetzaltenango",24);
   pila->Agregar_Pila("Quiche",21);
   pila->Agregar_Pila("Suchitepequez",21);
   pila->Agregar_Pila("Solola",19);
   pila->Agregar_Pila("Alta Verapaz",17);
   pila->Agregar_Pila("Santa Rosa",17);
   pila->Mostrar_Pila();
   pila->Graficar_Pila();
   QPixmap pixp("/home/debian9/Escritorio/ProyectoVacas/Pila.png");
   ui->label_5->setPixmap(pixp);

   Lista_Circuar *Circular = new  Lista_Circuar();
   Circular->Agregar_Circular("Mago de Oz","Finisterra","Santiago");
   Circular->Agregar_Circular("Mago de Oz","Finisterra","Kelpie");
   Circular->Agregar_Circular("Mago de Oz","Jesus de Chamberi","Genesis");
   Circular->Agregar_Circular("Mago de Oz","Jesus de Chamberi","Angel Caido");
   Circular->Agregar_Circular("Mago de Oz","Jesus de Chamberi","Judas");
   Circular->Agregar_Circular("Tierra Santa","Legendario","Atlantida");
   Circular->Agregar_Circular("Tierra Santa","Tierra de","La tormenta");
   Circular->Agregar_Circular("Rata Blanca","Magos","El ada y el mago");
   Circular->Agregar_Circular("Saratoga","Morir en el bien ","Como el viento");
   Circular->Mostrar_Circular();
   Circular->Graficar_Circular();







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
