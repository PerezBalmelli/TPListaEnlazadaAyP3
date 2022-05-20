#include <stdio.h>
#include <stdlib.h>

typedef struct nombreStruct {
    int dato;
    struct nombreStruct *siguiente;
} Nodo;


void agregarElemento(Nodo **lista, int valor) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo)); //asigno un nuevo nodo
    nuevoNodo->dato = valor; //le doy un valor
    nuevoNodo->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo; //si la lista esta vacia, directamente agrega el nuevo nodo
    } else { //sino, busca el ultimo nodo
        Nodo *cursor = *lista;
        while (cursor->siguiente != NULL) {
            cursor = cursor->siguiente;
        }
        cursor->siguiente = nuevoNodo;
    }

}


void imprimir(Nodo *nodo) {
    while (nodo != NULL) {
        printf(" %d ", nodo->dato);
        nodo = nodo->siguiente;
    }
}

void obtenerLargoDeLaLista(Nodo *nodo) {
    //
}

void obtenerElemento(Nodo *nodo, int valor) {
    //
}

void eliminarElemento(Nodo **nodo, int valor) {

    //almacena
    Nodo *nodoActual = *nodo, *nodoAnterior;

    // Si el primer nodo tiene el valor se va a eliminar
    if (nodoActual != NULL && nodoActual->dato == valor) {
        *nodo = nodoActual->siguiente;
        free(nodoActual); // libera la memoria
        return;
    }

    // Busca el valor a eliminar
    while (nodoActual != NULL && nodoActual->dato != valor) {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }

    // si no se encontro el valor
    if (nodoActual == NULL) {
        printf("No se encontro el valor %d para eliminarlo de la lista. \n ", valor);
        return;
    }
    //
    nodoAnterior->siguiente = nodoActual->siguiente; // luego de encontrar une el "hueco" entre
    // los nodos.

    free(nodoActual); // libera memoria
}

int main() {

    Nodo *lista = NULL;
    agregarElemento(&lista, 20);
    agregarElemento(&lista, 4);
    agregarElemento(&lista, 15);
    agregarElemento(&lista, 38);
    eliminarElemento(&lista, 4);
    eliminarElemento(&lista, 4);

    imprimir(lista);

    return 0;
}
