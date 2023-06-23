#ifndef EDYA1_REEMPLAZARLD_LISTA_H
#define EDYA1_REEMPLAZARLD_LISTA_H

typedef struct nodo{
    int num;
    struct nodo *ant;
    struct nodo *sig;
}Nodo;

typedef struct lista{
    Nodo *cabecera;
}Lista;


Nodo *newNodo(int num);
Lista *newLista();
void enlistar(Lista *lista, Nodo *nodo);
void print(Lista *lista);
void reemplazar(Lista *lista,Nodo * nodo, int pos);

#endif //EDYA1_REEMPLAZARLD_LISTA_H
