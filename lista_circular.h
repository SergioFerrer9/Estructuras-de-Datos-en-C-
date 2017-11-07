#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H


///Nodo que corresponde a la Lista Simple...
struct NodoSimple{
    char *Cancion;
    NodoSimple *sig;
    NodoSimple *ant;
};

///Nodo que Corresponde a la lista Doble Enlazada..
struct NodoDoble{
    char *Album;
    NodoDoble *sig;
    NodoDoble *ant;
    NodoSimple *primeroS; //apuntadores al Pimero y al Ultimo de
    NodoSimple *ultimoS;  //la LISTA SIMPLE desde la LISTA DOBLE...
};

///Nodo que corresponde a la lisa Circular...
struct NodoCircular{
    char *Artista;
    NodoCircular *sig;
    NodoCircular *ant;
    NodoDoble *primeroD; //Apuntadores al Primero y al ULtimo de
    NodoDoble *ultimoD;  //la LISTA DOBLE desde la LISTA CIRCULAR...
};

///Metodos y funciones de la Biblioteca
struct Lista_Circuar{
    void Agregar_Circular(char *Artista, char *Album, char *cancion);
    void Eliminar_Cancion(char *Artista, char *Album, char *cancion);
    void Mostrar_Circular();
    void Graficar_Circular();
    int contador=0;
};

#endif // LISTA_CIRCULAR_H
