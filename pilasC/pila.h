#ifndef PILA_H
#define PILA_H

#define TAM_MAX 100

typedef struct{
	int datos[TAM_MAX];
	int tope;
}Pila;

void inicializarPila(Pila* p);
int pilaVacia(Pila* p);
int pilaLlena(Pila* p);
void apilar(Pila* p, int dato);
int desapilar(Pila* p);
void mostrarPila(Pila* p);

#endif
