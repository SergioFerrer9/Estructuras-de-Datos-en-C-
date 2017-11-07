#include "listaenlazada.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <QLabel>
#include <mainwindow.h>

using namespace std;
using std::cout;
using std::endl;

///**************PUNTEROS PRIMERO Y ULTIMO*****************
typedef struct NodoLista NodoL;
    NodoL *primero;
    NodoL *ultimo;

///*********AGREGAR EN LA LISTA SIMPLE*******************************
void Lista::Agregar(char *nombre, int telefono){
    NodoL *nuevo;
    nuevo=(NodoL*)malloc(sizeof(struct NodoLista));
    nuevo->Nombre=nombre;
    nuevo->telefono=telefono;
    nuevo->sig=NULL;

    if(primero==NULL){
        nuevo->sig=primero;
        primero=nuevo;
        ultimo=nuevo;
    }else{
        nuevo->sig=primero;
        primero=nuevo;
    }

}

///***********************MOSTRAR LISTA SIMPLE**************************
void Lista::Mostrar(){
    NodoL *aux=primero;
    cout<<"*****************LISTA SIMPLE*************************\n";
    while(aux!=NULL){
        cout<<aux->Nombre<< " " <<aux->telefono<<endl;
        aux=aux->sig;
    }
    cout<<"\n"<<endl;
}



void Lista::Graficar_Lista(){
    FILE *gra;
    gra=fopen("Lista_Simple.dot","wt");
    fputs("digraph g {  \n graph [\n",gra);
    fputs("rankdir= \"LR\"\n];\n",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"16\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    int a=0;
    NodoL *aux=primero;
    while(aux!=NULL){
        fputs("\"",gra);
        fputs("node",gra);
        fprintf(gra,"%d",a);
        fputs("\"",gra);
        fputs("\n[ ",gra);
        fprintf(gra, "label=\" " );
        fprintf(gra, "%s",aux->Nombre);
        fputs("\"];\n",gra);
        a++;


            aux=aux->sig;
    }

    int b =0;
    int c =b+1;
    aux=primero;
    while(aux->sig!=NULL){
        // nodo1---->nodo2 siguintes
        fputs("\"node",gra);
        fprintf(gra,"%d",b);
        fputs("\"-> \"node",gra);
        fprintf(gra,"%d",c);
        fputs( "\";\n",gra);


            aux=aux->sig;
            b++;
            c++;
    }

         fputs("}",gra);
         fclose(gra);
         system("dot -Tpng Lista_Simple.dot -o Lista_Simple.png");


}























