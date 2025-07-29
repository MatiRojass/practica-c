#include <stdio.h>
#define MAX 5

typedef struct{
    int datos[MAX + 1];
    int cabeza;
    int final;
}Cola;

void mostrarCola(Cola* q);
void inicializarCola(Cola* q);
void agregar(Cola* q, int dato);
int quitar(Cola* q);
int colaLLena(Cola* q);
int colaVacia(Cola* q);
int siguiente(int pos);


int main(){

    Cola q;

    puts("Se inicaliza la cola con un tamaño de 5 elementos...\n");
    inicializarCola(&q);
    puts("Agregan los elementos 1, 2, 5, 6\n");

    agregar(&q, 1);
    agregar(&q, 2);
    agregar(&q, 5);
    agregar(&q, 6);

    if (!colaLLena(&q)) puts("\n[INFO] la cola aun NO esta llena");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);

    puts("Se intentan agregar 2 elementos, 1 deberia no poderse");
    agregar(&q, 11);
    agregar(&q, 9);

    if (colaLLena(&q)) puts("\n[INFO] la cola esta llena");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);


    puts("\nSe quitan 3 elementos...");
    quitar(&q);
    quitar(&q);
    quitar(&q);

    if (!colaVacia(&q)) puts("\n[INFO] la cola NO esta vacia");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);

    puts("Se agregan 2 mas, para probar el funcionamiento circular\n");
    agregar(&q, 11);
    agregar(&q, 9);

    if (!colaLLena(&q)) puts("\n[INFO] la cola aun NO esta llena");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);

    puts("\nSe quitan los elementos restantes");
    quitar(&q);
    quitar(&q);
    quitar(&q);
    quitar(&q);

    if (colaVacia(&q)) puts("\n[INFO] la cola esta vacia");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);

    puts("\nSe intenta quitar en la pila vacia");
    quitar(&q);
    if (colaVacia(&q)) puts("\n[INFO] la cola esta vacia");
    printf("Cabeza: %d\nFinal: %d\n", q.cabeza, q.final);
    mostrarCola(&q);



    return 0;
}

void mostrarCola(Cola* q){
    printf("[ ");
    for (int i = 0; i <= MAX; i++){
        printf("%d ", q->datos[i]);
    }
    printf("]\n");
}

void inicializarCola(Cola* q){
    for (int i = 0; i <= MAX; i++){
        q->datos[i] = 0;
    }
    q->cabeza = MAX;
    q->final = MAX;
}

void agregar(Cola* q, int dato){
    if (!colaLLena(q)){
        q->final = siguiente(q->final);
        q->datos[q->final] = dato;
        printf("[ADD] se agrego el dato %d\n", dato);
    }
    else{
        puts("[ERROR] Cola llena!");
    }
}

int quitar(Cola* q){
    int r = -9999;
    if (!colaVacia(q)){
        q->cabeza = siguiente(q->cabeza);
        q->datos[q->cabeza] = 0;
        r = q->datos[q->cabeza];
        printf("[DEL] se quito el dato %d\n", r);
    }
    else{
        puts("[ERROR] Cola vacia!");
    }
    return r;
}

int colaLLena(Cola* q){
    if (q->cabeza == siguiente(q->final)){
        return 1;
    }
    else{
        return 0;
    }
}

int colaVacia(Cola* q){
    if (q->cabeza == q->final){
        return 1;
    }
    else{
        return 0;
    }
}

int siguiente(int pos){
    if (pos != MAX){
        return pos + 1;
    }
    else{
        return 0;
    }
}