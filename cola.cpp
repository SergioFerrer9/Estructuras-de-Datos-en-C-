#include "cola.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

///**************PUNTEROS PRIMERO Y ULTIMO DE LA COLA***************
typedef struct NodoCola NodoC;
NodoC *primeroc;
NodoC *ultimoc;

///*************AGREGAR A LA COLA DE IZQ a DER***********************
void Cola::Agregar_Cola(char *nombre, int edad){
    NodoC *nuevo;
    nuevo=(NodoC*)malloc(sizeof(struct NodoCola));
    nuevo->Nombre=nombre;
    nuevo->Edad=edad;
    nuevo->sig=NULL;

    if(primeroc==NULL){///Agregar el primer Nodo...
        nuevo->sig=primeroc;
        primeroc=nuevo;
        ultimoc=nuevo;
    }else{///Agregar un nodo al lado izquierdo......
        nuevo->sig=primeroc;
        primeroc=nuevo;
    }
}

///***********ELIMINAR EL PRIMERO EN LA COLA************************
void Cola::Eliminar_Cola(){
    if(primeroc==ultimoc){
        cout<<"Se eliminio el ultimo de la Cola...."<<endl;
    }else{
        NodoC *temp=primeroc;
        while (temp->sig!=ultimoc) {
            temp=temp->sig;
        }
        ultimoc=temp;
        ultimoc->sig=NULL;
    }
}

///************MOSTRAR COLOA****************************************
void Cola::Mostrar_Cola(){
    NodoC *aux=primeroc;
    cout<<"*******************COLA***********************"<<endl;
    while (aux!=NULL){
        cout<<aux->Nombre<<"--"<<aux->Edad<<endl;
        aux=aux->sig;
    }
}







