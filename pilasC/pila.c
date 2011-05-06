#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPila(Pila* p){
	p->tope = -1;
}

int pilaVacia(Pila* p){
	if(p->tope==-1){
		return 1;
	}
	return 0;
}

int pilaLlena(Pila* p){
	if(p->tope==TAM_MAX-1){
		return 1;
	}
	return 0;
}

void apilar(Pila* p, int dato){
	if(pilaLlena(p)){
		printf("Error: pila llena");
	}else{
		p->tope++;
		p->datos[p->tope] = dato;
	}
}

int desapilar(Pila* p){
	int res = -99999;
	if(pilaVacia(p)){
		printf("Error: la pila esta vacia");
	}else{
		res = p->datos[p->tope];
		p->tope--;
	}

	return res;
}

void mostrarPila(Pila* p){
	Pila aux;
	inicializarPila(&aux);
	while(!pilaVacia(p)){
		apilar(&aux, desapilar(p));		
	}

	printf("[");
	while(!pilaVacia(&aux)){
		int dato = desapilar(&aux);
		printf(" %d ", dato);
		apilar(p, dato);
	}
	printf("]");
}
