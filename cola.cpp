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

///************MOSTRAR COLA****************************************
void Cola::Mostrar_Cola(){
    NodoC *aux=primeroc;
    cout<<"*******************COLA***********************"<<endl;
    while (aux!=NULL){
        cout<<aux->Nombre<<"--"<<aux->Edad<<endl;
        aux=aux->sig;
    }
}

///***********GRAFICAR COLA****************************************
void Cola::Graficar_Cola(){
    FILE *gra;
    gra=fopen("Cola.dot","wt");
    fputs("digraph g {  \n graph [\n",gra);
    fputs("rankdir= \"LR\"\n];\n",gra);
    fputs("node [\n" ,gra);
    fputs("fontsize = \"16\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"darkslateblue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("];\n",gra);

    int a=0;
    NodoC *aux=primeroc;
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
    aux=primeroc;
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
         system("dot -Tpng Cola.dot -o Cola.png");

}



























