#include <stdio.h>
#include "lista.h"

int main() {
    Lista * lista = newLista();
    enlistar(lista,newNodo(1));
    enlistar(lista,newNodo(2));
    enlistar(lista,newNodo(3));
    enlistar(lista,newNodo(4));
    enlistar(lista,newNodo(5));
    print(lista);
    reemplazar(lista, newNodo(3),4);
    return 0;
}
