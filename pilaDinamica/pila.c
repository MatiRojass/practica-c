#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

// METODOS NODO
Nodo* crearNodo(int dato){
    Nodo* newNodo = malloc(sizeof(Nodo));

    if (newNodo == NULL){
        return NULL;
    }
    newNodo->dato = dato;
    newNodo->ps = NULL;
    return newNodo;
}

// METODOS PILA
Pila* crearPila(){
    Pila* newPila = malloc(sizeof(Pila));
    if (newPila == NULL){
        return NULL;
    }

    newPila->tope = NULL;
    return newPila;
}

int pilaVacia(Pila* p){
    return (p->tope == NULL) ? 1 : 0;
}

void apilar(Pila* p, int dato){
    Nodo* newNodo = crearNodo(dato);
    if (newNodo == NULL) return;

    if (pilaVacia(p)){
        p->tope = newNodo;
    }
    else{
        newNodo->ps = p->tope;
        p->tope = newNodo;
    }
}

int desapilar(Pila* p){
    if (pilaVacia(p)){
        puts("ERROR: no puedes desapilar en una pila vacia");
        return -999999;
    }
    Nodo* temp = p->tope;
    p->tope = p->tope->ps;

    int dato = temp->dato;
    free(temp);
    return dato;
}

void mostrarPila(Pila* p){
    Pila* aux = crearPila();
    if (aux == NULL) return;

    while (!pilaVacia(p)){
        apilar(aux, desapilar(p));
    }

    printf("[");
    while (!pilaVacia(aux)){
        int dato = desapilar(aux);
        printf(" %d ", dato);
        apilar(p, dato);
    }
    printf("]\n");

    destruirPila(aux);
}

void destruirPila(Pila* p){
    Nodo* actual = p->tope;

    while (actual != NULL){
        Nodo* aux = actual;
        actual = actual->ps;
        free(aux);
    }

    free(p);
}







