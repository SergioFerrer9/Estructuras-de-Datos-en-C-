#include "lista_circular.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

///****APUNTADORES AL PRIMERO Y ULTIMO DE LA LISTA CIRCULAR*******
typedef struct NodoCircular NodoC;
    NodoC *primeroCir;
    NodoC *ultimoCir;

typedef struct NodoDoble NodoD;
typedef struct NodoSimple NodoS;

Lista_Circuar *circular = new Lista_Circuar();

///********AGREGAR A LA BIBLIOTECA********************************
void Lista_Circuar::Agregar_Circular(char *Artista, char *Album, char *cancion){
        ///Inicializamos los nodos de las listas....
        ///Inicializar el nodo de la Lista Circular(Artistas)...
        NodoC *nuevoC;
        nuevoC=(NodoC*)malloc(sizeof(struct NodoCircular));
        nuevoC->Artista=Artista;
        nuevoC->ant=NULL;
        nuevoC->sig=NULL;
        ///Inicializamos el Nodo de la lista Doble Enlazada(Albums)...
        NodoD *nuevoD;
        nuevoD=(NodoD*)malloc(sizeof(struct NodoDoble));
        nuevoD->Album=Album;
        nuevoD->ant=NULL;
        nuevoD->sig=NULL;
        ///Inicializamos el Nodo de la Lista Simple(Canciones)...
        NodoS *nuevoS;
        nuevoS=(NodoS*)malloc(sizeof(struct NodoSimple));
        nuevoS->Cancion=cancion;
        nuevoS->ant=NULL;
        nuevoS->sig=NULL;

        ///Nodos Auxiliares...
        NodoC *aux=primeroCir;
        NodoD *actual=NULL;
        NodoS *actualS=NULL;

        ///Contadores...
        int dato=0;
        int dato2=0;
        int dato3=0;

        if(primeroCir==NULL){///Si la lista Circular esta vacia...
            ///Agregar el Primer nodo de la Lista Circular...
            nuevoC->sig=nuevoC;
            nuevoC->ant=nuevoC;
            primeroCir=nuevoC;
            ultimoCir=nuevoC;
            circular->contador++;
                    ///Agregar el Primer nodo de la Lista Doble...
                    nuevoD->sig=NULL;
                    nuevoD->ant=NULL;
                    ultimoCir->primeroD=nuevoD;
                    ultimoCir->ultimoD=nuevoD;
                            ///Agregar el Primer nodo de la Lista Simple...
                            ultimoCir->ultimoD->primeroS=nuevoS;
                            ultimoCir->ultimoD->ultimoS=nuevoS;

        }else{///Si la Lista Circular Tiene almenos 1 nodo...
            for(int i=1;i<=circular->contador; i++){//Recorrer la lista Circular para verificar si el nuevo nodo existe o no...
                   if(strcmp(aux->Artista,Artista)==0){///Si el Artista esta Repetido...
                      dato=1;
                      actual=aux->primeroD;///Me corro al primero de la lista Doble...
                      while(actual!=NULL){//Recorro la lista Doble para verificar si ya existe...
                              if(strcmp(actual->Album,Album)==0){///Si el Album es repetido...
                                  dato2=1;
                                  actualS=actual->primeroS;///Me corro al primero de la lista Simple...
                                      while(actualS!=NULL){//Recorro la lista Simple para verificar si ya existe...
                                          if(strcmp(actualS->Cancion,cancion)==0){///Si la cancion es Repetida...
                                              dato3=1;
                                              ///NO SE AGREGA NADA POR QUE YA EXISTE....

                                          }
                                          actualS=actualS->sig;
                                      }
                                      if(dato==0){//Agregar una Cancion Nueva...
                                          actual->ultimoS->sig=nuevoS;
                                          actual->ultimoS=nuevoS;
                                      }
                                      dato3=0;
                              }
                              actual=actual->sig;

                      }///FIN DEL WHILE...

                              if(dato2==0){///Si No se encontro un Album Repetido Aanteriormente...
                                  ///Artista Repetido, Album Nuevo..
                                  nuevoD->sig=NULL;
                                  nuevoD->ant=aux->ultimoD;
                                  aux->ultimoD->sig=nuevoD;
                                  aux->ultimoD=nuevoD;
                                        ///Agregar la Cancion Nueva...
                                        aux->ultimoD->primeroS=nuevoS;
                                        aux->ultimoD->ultimoS=nuevoS;

                              }
                              dato2=0;

                }
                aux=aux->sig;
            }///FIN DEL FOR...

            if(dato==0){
                ///Agregar un Artista Nuevo...
                nuevoC->sig=primeroCir;
                nuevoC->ant=ultimoCir;
                ultimoCir->sig=nuevoC;
                ultimoCir=nuevoC;
                circular->contador++;
                        ///Agregar un Album Nuevo...
                        nuevoD->sig=NULL;
                        nuevoD->ant=NULL;
                        ultimoCir->primeroD=nuevoD;
                        ultimoCir->ultimoD=nuevoD;
                                ///Agregar una Cancion Nueva...
                                ultimoCir->ultimoD->primeroS=nuevoS;
                                ultimoCir->ultimoD->ultimoS=nuevoS;

            }

        }///FIN ELSE...

        dato=0;

    }

///***************MOSTRAR LA LISTA CIRCULAR*************************
void Lista_Circuar::Mostrar_Circular(){

        NodoC *temporal=primeroCir;
        NodoD *temp;
        NodoS *actual;
        cout<<"********************BIBLIOTECA***********************"<<endl;
        for(int i=1; i<=circular->contador; i++){///Recorrer la Lista Circular...
            printf("[%s]=>\n",temporal->Artista);
            temp=temporal->primeroD;
            while(temp!=NULL){///Recorrer la Lista Doble...
                printf("{%s}=>",temp->Album);
                actual=temp->primeroS;
                while(actual!=NULL){///Recorrer la Lista Simple...
                    printf("(%s)=>",actual->Cancion);
                    actual=actual->sig;
                }
                printf("\n");
                temp=temp->sig;
            }
            printf("\n");
            temporal=temporal->sig;
        }


    }


void Lista_Circuar::Graficar_Circular(){
    FILE *gra;
        gra=fopen("Biblioteca.dot","wt");
        fputs("digraph g {  \n graph [\n",gra);
        fputs("rankdir= \"LR\"\n];\n",gra);
        fputs("node [\n" ,gra);
        fputs("fontsize = \"16\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"darkslateblue\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("];\n",gra);

        NodoC * temporal;
        NodoC *temporal2;

        NodoD *actual;
        NodoD *actual2;
        NodoD *actual3;
        NodoD *actual4;


        temporal = primeroCir;
        temporal2 = primeroCir;



        int contadorc=0;
        int contadord=0;
        int contadors=0;
        int contadord2=0;
        int contadorl=0;
        ///Recorrer La lista Doble Circular y Crear Nodos...
         for (int i=1; i<=circular->contador; i++){
               ///Crear Nodos..
               fputs("\"",gra);
               fputs("node",gra);
               fprintf(gra,"%d",contadorc);
               fputs("\"",gra);
               fputs("\n[ ",gra);
               fprintf(gra, "label=\" " );
               fprintf(gra, "%s",temporal->Artista);
               fputs("\"];\n",gra);

                    ///Recorrer La lista Doble y Crear Nodos...
                    actual=temporal->primeroD;
                    while(actual!=NULL){
                        fputs("\"",gra);
                        fputs("node",gra);
                        fprintf(gra,"%d",contadorc);
                        fprintf(gra,"%s",actual->Album);
                        fputs("\"",gra);
                        fputs("\n[ ",gra);
                        fprintf(gra, "label=\" " );
                        fprintf(gra, "%s",actual->Album);
                        fputs("\"];\n",gra);
                        contadord++;

                        actual=actual->sig;
                    }
                  contadord=0;
               temporal= temporal->sig;
               contadorc++;
          }
           contadorc=0;
           int contadornull=0;

           ///Crear los Aputadores Lista Doble Circular...........................
           for(int i=0; i<=circular->contador; i++){

             if (i<circular->contador){


                     if(i==circular->contador-1){
                             //NO AGREGAR NODO
                     }else{
                         // nodo1---->nodo2 siguintes
                         fputs("\"node",gra);
                         fprintf(gra,"%d",i);
                         fputs("\"-> \"node",gra);
                         fprintf(gra,"%d",i+1);
                         fputs( "\";\n",gra);

                     }

                     if(i==circular->contador-1){
                             //NO AGREGAR NODO
                     }else{
                         // nodo1<----nodo2 Anteriores
                         fputs("\"node",gra);
                         fprintf(gra,"%d",i+1);
                         fputs("\"-> \"node",gra);
                         fprintf(gra,"%d",i);
                         fputs( "\";\n",gra);
                      }

                    ///Crear Apuntadores Lista Doble....
                    actual2=temporal2->primeroD;
                    while(actual2!=NULL){///Recorrer lista Doble..
                        // nodo1---->nodo2 siguintes
                        fputs("\"node",gra);
                        fprintf(gra,"%d",contadorc);
                        fprintf(gra,"%s",actual2->Album);
                        fputs("\"-> \"",gra);

                        actual3=actual2->sig;

                        if(actual3!=NULL){
                        fputs("node",gra);
                        fprintf(gra,"%d",contadorc);
                        fprintf(gra,"%s",actual3->Album);
                        fputs( "\";\n",gra);

                        fputs("\"node",gra);
                        fprintf(gra,"%d",contadorc);
                        fprintf(gra,"%s",actual3->Album);
                        fputs("\"-> \"",gra);
                        fputs("node",gra);
                        fprintf(gra,"%d",contadorc);
                        fprintf(gra,"%s",actual2->Album);
                        fputs( "\";\n",gra);

                        }else{
                            fputs("NULL",gra);
                            fprintf(gra,"%d",contadornull);
                            fputs( "\";\n",gra);
                            contadornull++;
                        }






                            contador++;
                            actual2=actual2->sig;
                    }


             }else if(i==circular->contador){
                 // enlazar los nodos primero<------>ultimo
                fputs("\"node",gra);
                fprintf(gra,"%d",0);
                fputs("\"-> \"node",gra);
                fprintf(gra,"%d",circular->contador-1);
                fputs( "\";\n",gra);

                fputs("\"node",gra);
                fprintf(gra,"%d",circular->contador-1);
                fputs("\"-> \"node",gra);
                fprintf(gra,"%d",0);
                fputs( "\";\n",gra);

             }

             contadorc++;
             temporal2= temporal2->sig;

         }

         ///Enlazar Lista Circular con Lista Doble.......

       temporal=NULL;
       temporal=primeroCir;
       for(int i=0; i<=circular->contador-1; i++){

           fputs("\"node",gra);
           fprintf(gra,"%d",i);
           fputs("\"-> \"",gra);
           fputs("node",gra);
           fprintf(gra,"%d",i);
           fprintf(gra,"%s",temporal->primeroD->Album);
           fputs( "\";\n",gra);

           temporal=temporal->sig;

       }

       ///Crear Nodos de la Lista Simple...............................
       temporal=NULL;
       temporal=primeroCir;

       actual=NULL;
       NodoS *sim;
       int cont=0;

       for(int i=0; i<=circular->contador-1; i++){///Recorrer Lista Doble Circular...
               actual=temporal->primeroD;
               while(actual!=NULL){///Recorrer Lista Doble...
                      sim=actual->primeroS;
                           while(sim!=NULL){///Recorrer Lista Simple..
                               fputs("\"",gra);
                               fputs("node",gra);
                               fprintf(gra,"%d",cont);
                               fprintf(gra,"%s",sim->Cancion);
                               fputs("\"",gra);
                               fputs("\n[ ",gra);
                               fprintf(gra, "label=\" " );
                               fprintf(gra, "%s",sim->Cancion);
                               fputs("\"];\n",gra);
                               sim=sim->sig;
                           }

                           cont++;
                   actual=actual->sig;
               }
              // printf("\n");
           temporal=temporal->sig;

       }


     ///Enlazar Lista Simple........................................................................................
       temporal=NULL;
       temporal=primeroCir;
       actual=NULL;
       sim=NULL;
       cont=0;
       int contd=0;

       for(int i=0; i<=circular->contador-1; i++){///Recorrer Lista Doble Circular...
               actual=temporal->primeroD;
               while(actual!=NULL){///Recorrer Lista Doble...
                    sim=actual->primeroS;
                           while(sim->sig!=NULL){///Recorrer Lista Simple..
                               fputs("\"node",gra);
                               fprintf(gra,"%d",cont);
                               fprintf(gra,"%s",sim->Cancion);
                               sim=sim->sig;

                               fputs("\"-> \"",gra);
                               fputs("node",gra);
                               fprintf(gra,"%d",cont);
                               fprintf(gra,"%s",sim->Cancion);
                               fputs( "\";\n",gra);

                          }

                           cont++;
                   actual=actual->sig;
               }
               contd++;
              // printf("\n");
           temporal=temporal->sig;

       }



       temporal=NULL;
       temporal=primeroCir;
       actual=NULL;
       sim=NULL;
       cont=0;


       for(int i=0; i<=circular->contador-1; i++){///Recorrer Lista Doble Circular...
               actual=temporal->primeroD;
               while(actual!=NULL){///Recorrer Lista Doble...


                   fputs("\"node",gra);
                   fprintf(gra,"%d",i);
                   fprintf(gra,"%s",actual->Album);
                   fputs("\"-> \"",gra);
                   fputs("node",gra);
                   fprintf(gra,"%d",cont);
                   fprintf(gra,"%s",actual->primeroS->Cancion);
                   fputs( "\";\n",gra);
                   printf("%d",i);

                   cont++;
                   actual=actual->sig;
               }

            temporal=temporal->sig;

       }




        fputs("}",gra);
        fclose(gra);
        system("dot -Tpng Biblioteca.dot -o Biblioteca.png");

}
























