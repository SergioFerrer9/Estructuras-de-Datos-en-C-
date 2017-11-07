#include "pila.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

///*************PUNTEROS PRIMERO Y ULTIMO DE LA PILA***************
typedef struct NodoPila NodoP;
NodoP *primerop;
NodoP *ultimop;

///************AGREGAR A PILA**************************************
void Pila::Agregar_Pila(char *Departamento, int Municipios){
    NodoP *nuevo;
    nuevo=(NodoP*)malloc(sizeof(struct NodoPila));
    nuevo->Departamento=Departamento;
    nuevo->Municipios=Municipios;
    nuevo->sig=NULL;

    if(primerop==NULL){///Agregar el Primer Nodo....
        nuevo->sig=primerop;
        primerop=nuevo;
        ultimop=nuevo;

    }else{///Agregar un nuevo nodo(al Princiopio del lado Derecho)...
        ultimop->sig=nuevo;
        ultimop=nuevo;
    }

}

///*************ELIMINAR DE PILA**********************************
void Pila::Eliminar_Pila(){
        if(primerop!=ultimop){
            primerop=primerop->sig;
        }else{
            cout<<"La Pila esta vacia...."<<endl;
        }
}

///************MOSTRAR PILA***************************************
void Pila::Mostrar_Pila(){
    NodoP *aux=primerop;
    cout<<"*********************PILA****************************\n";
    while(aux!=NULL){
        cout<<aux->Departamento<<"--"<<aux->Municipios<<endl;
        aux=aux->sig;
    }
}

///************GRAFICAR PILA**************************************
void Pila::Graficar_Pila(){
     FILE *gra;
        gra=fopen("Pila.dot","wt");
        fputs("digraph g {  \n graph [\n",gra);
        fputs("rankdir= \"LR\"\n];\n",gra);
        fputs("node [\n" ,gra);
        fputs("fontsize = \"16\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"darkslateblue\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("];\n",gra);

        int a=0;
        NodoP *aux=primerop;
        while(aux!=NULL){
            fputs("\"",gra);
            fputs("node",gra);
            fprintf(gra,"%d",a);
            fputs("\"",gra);
            fputs("\n[ ",gra);
            fprintf(gra, "label=\" " );
            fprintf(gra, "%s",aux->Departamento);
            fputs(" , ",gra);
            fprintf(gra, "%d",aux->Municipios);

            fputs("\"];\n",gra);
            a++;


                aux=aux->sig;
        }

        int b =0;
        int c =b+1;
        aux=primerop;
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
             system("dot -Tpng Pila.dot -o Pila.png");
}



















