#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <stdlib.h>
#include <iostream>
#include <string.h>

///****************NODO LISTA SIMPLE***********************
struct NodoLista
{
    char *Nombre;
    int telefono;
    struct NodoLista *sig;
};

///*************METODOS Y FUNCIONES LISTA SIMPLE***********
struct Lista
{

    void Agregar(char *nombre, int telefono);
    void Mostrar();
    void Graficar_Lista();


};

#endif // LISTAENLAZADA_H
