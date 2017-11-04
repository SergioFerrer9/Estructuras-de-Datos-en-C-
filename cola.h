#ifndef COLA_H
#define COLA_H
#include <stdlib.h>
#include <iostream>
#include <string.h>

struct NodoCola
{
    char *Nombre;
    int  Edad;
    struct NodoCola *sig;
};


struct Cola{
    FILE *gra;
    void Agregar_Cola(char *nombre, int edad);
    void Eliminar_Cola();
    void Mostrar_Cola();
    void Graficar_Cola();
};

#endif // COLA_H
