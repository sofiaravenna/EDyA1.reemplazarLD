#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *newNodo(int num) {
    Nodo *aux= NULL;
    aux= malloc((sizeof (Nodo)));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->num=num;
        aux->ant=NULL;
        aux->sig=NULL;
    }

    return aux;
}

Lista *newLista() {
    Lista *aux= NULL;
    aux= malloc((sizeof (Lista)));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabecera=NULL;
    }
    return aux;
}

void print(Lista *lista) {
    Nodo * aux= lista->cabecera;
    while (aux != NULL){
        printf("%d\t",aux->num);
        aux=aux->sig;
    }
    printf("\n");
}

void enlistar(Lista *lista, Nodo *nodoInsertar) {
    if(lista->cabecera==NULL){
        lista->cabecera=nodoInsertar;
        nodoInsertar->ant=NULL;
    } else{
        Nodo *aux=lista->cabecera;
        while (aux->sig != NULL){
            aux=aux->sig;
        }
        aux->sig=nodoInsertar;
        nodoInsertar->ant=aux;
    }
}

void reemplazar(Lista *lista, Nodo *nodo, int pos) {
    Nodo *aux = lista->cabecera;
    for (int i = 0; i < pos && aux != NULL; ++i) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        if (aux->sig == NULL) {
            nodo->sig = NULL;
            aux->ant->sig = nodo;
            nodo->ant = aux->ant;
        } else {
            if (aux == lista->cabecera) {
                nodo->sig = aux->sig;
                lista->cabecera = nodo;
                nodo->ant = NULL;
                aux->sig->ant = nodo;
            } else {
                nodo->ant = aux->ant;
                nodo->sig = aux->sig;
                aux->ant->sig = nodo;
                aux->sig->ant = nodo;
            }
        }
        free(aux);
    }
}