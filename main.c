#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int num;
    struct Nodo *siguiente;
} Nodo;

void imprimir(Nodo *nodo)
{
    while (nodo != NULL)
    {
        printf(" %d ", nodo->num);
        nodo = nodo->siguiente;
    }
}

int obtenerLargoDeLaLista(Nodo *lista){
    Nodo *cursor = lista;
    int longitud = 1;
    while(cursor-> siguiente != NULL){
        cursor = cursor ->siguiente;
        longitud = longitud + 1;
    }
    return longitud;
}

int obtenerElemento(Nodo *lista, int pos){
    Nodo *cursor = lista;
    int posAct = 0;
    int valor = -1;

    while(posAct < obtenerLargoDeLaLista(lista)){
        if(posAct == pos) {
            valor = cursor->num;
            break;
        }
        cursor = cursor ->siguiente;
        posAct = posAct + 1;
    }
    return valor;
}

void eliminarElemento(Nodo **lista, int pos){

    Nodo *cursor = *lista;
    int posAct = 0;
    if(pos != 0){
        while(posAct < obtenerLargoDeLaLista(*lista)){
            if(posAct == pos - 1) {
                break;
            }
            cursor = cursor ->siguiente;
            posAct = posAct + 1;
        }
        //suelta el nodo y une con el siguiente
        Nodo *nodoAnt = cursor;
        Nodo *nodoAEliminar = cursor->siguiente;
        nodoAnt->siguiente = nodoAEliminar->siguiente;
        free(nodoAEliminar); // libera memoria
    } else {
        *lista = cursor->siguiente;
        free(cursor); // libera memoria
    }
}

void agregarElementoEnPosicion(Nodo **lista, Nodo *nodoInsertar, int pos){

    Nodo *cursor = *lista;
    int posAct = 0;
    if(pos != 0){
        while(posAct < obtenerLargoDeLaLista(*lista)){
            if(posAct == pos - 1) {
                break;
            }
            cursor = cursor ->siguiente;
            posAct = posAct + 1;
        }
        //suelta el nodo y une con el siguiente
        Nodo *nodoAnt = cursor;
        nodoInsertar->siguiente = nodoAnt->siguiente;
        nodoAnt->siguiente = nodoInsertar;
    } else {
        nodoInsertar->siguiente = cursor;
        *lista = nodoInsertar;
    }
}

void agregarElemento(Nodo **lista, int valor){
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo)); //asigno un nuevo nodo
    nuevoNodo->num = valor; //le doy un valor
    nuevoNodo->siguiente = NULL;

    if(*lista==NULL){
        *lista = nuevoNodo; //si la lista esta vacia, directamente agrega el nuevo nodo
    } else{ //sino, busca el ultimo nodo
        Nodo *cursor = *lista;
        int posAct = 0;
        while(posAct < obtenerLargoDeLaLista(*lista) && cursor->num < valor){
            cursor = cursor ->siguiente;
            posAct = posAct + 1;
        }
        agregarElementoEnPosicion(lista, nuevoNodo, posAct);
    }

}


int main() {

    Nodo *lista = NULL;
    agregarElemento(&lista,20);
    agregarElemento(&lista,4);
    agregarElemento(&lista,15);
    agregarElemento(&lista,38);
    agregarElemento(&lista,50);
    agregarElemento(&lista,1);
    agregarElemento(&lista,-2);

    //eliminarElemento(&lista,3);

    imprimir(lista);

    //printf("%d\n",obtenerElemento(lista,2));

    //printf("%d\n",obtenerLargoDeLaLista(lista));
    return 0;
}
