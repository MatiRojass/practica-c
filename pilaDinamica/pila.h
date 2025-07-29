#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

// Defincion de un Nodo
typedef struct Nodo{
    int dato;
    struct Nodo* ps;
} Nodo;

// Definicion de la Pila
typedef struct{
    Nodo* tope;
} Pila;

// Metodos del Nodo
Nodo* crearNodo(int dato);

// Metodos de la Pila
Pila* crearPila();              // crea una pila vacia
int pilaVacia(Pila* p);         // devuelve 1 o 0 segun si la pila este vacia
void apilar(Pila* p, int dato); // apila un nuevo dato
int desapilar(Pila* p);         // quita el ultimo elemento agregado
void mostrarPila(Pila* p);      //
void destruirPila(Pila* p);

#endif // PILA_DINAMICA_H