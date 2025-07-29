#include <stdio.h>
#include "pila.h"

int main(){
    puts("Se crea la pila\n");
    Pila* pila = crearPila();

    puts("Se apilan los numero 10, 25, 19, 32, 5\n");
    apilar(pila, 10);
    apilar(pila, 25);
    apilar(pila, 19);
    apilar(pila, 32);
    apilar(pila, 5);

    puts("Estado actual de la pila: ");
    mostrarPila(pila);

    puts("\nSe desapilan 3 elementos (5, 32, 19)\n");
    desapilar(pila);
    desapilar(pila);
    desapilar(pila);

    puts("Estado actual de la pila: ");
    mostrarPila(pila);

    puts("\nSe quitan los elementos restantes, la pila queda vacia\n");

    desapilar(pila);
    desapilar(pila);

    puts("Estado actual de la pila: ");
    mostrarPila(pila);

    puts("\nSe intente desapilar en la pila vacia...");
    desapilar(pila);

    puts("\nSe destruye la pila");
    destruirPila(pila);


    return 0;
}