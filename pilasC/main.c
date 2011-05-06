#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(){
	Pila pila;

	puts("Se inicializa la pila");
	inicializarPila(&pila);

	if(pilaVacia(&pila)){
		puts("la pila esta vacia");
	}
	
	puts("se apilan los numeros 10, 20, 14, 5, 12");
	apilar(&pila, 10); 
	apilar(&pila, 20); 
	apilar(&pila, 14); 
	apilar(&pila, 5); 
	apilar(&pila, 12);
	puts("");
	mostrarPila(&pila);
	
	puts("\n\nse desapilan 3 valores (12, 5, 14)");
	desapilar(&pila);
	desapilar(&pila);
	desapilar(&pila);
	puts("\n");
	mostrarPila(&pila);
	puts("\n");
	return 0;
}

