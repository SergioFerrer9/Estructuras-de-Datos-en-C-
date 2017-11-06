#ifndef PILA_H
#define PILA_H

struct NodoPila{

    char *Departamento;
    int Municipios;
    struct NodoPila *sig;
};

struct Pila{
    void Agregar_Pila(char *Departamento, int Municipios);
    void Eliminar_Pila();
    void Mostrar_Pila();
    void Graficar_Pila();

};

#endif // PILA_H
