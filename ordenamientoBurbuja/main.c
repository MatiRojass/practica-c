#include <stdio.h>
#define TAM 10

void ordenar(int arr[], int tam);
void printArr(int arr[], int tam);

int main(int argc, char const* argv[]){

    int arreglo[TAM] = { 10,1,5,2,6,3,7,9,4,2 };

    puts("Arreglo inicial:");
    printArr(arreglo, TAM);

    ordenar(arreglo, TAM);

    puts("\n\nArreglo Ordenado:");
    printArr(arreglo, TAM);


    return 0;
}

void ordenar(int arr[], int tam){
    int b;
    int i, aux;

    do{
        b = 0;
        i = 0;
        while (i < tam - 1){
            if (arr[i] > arr[i + 1]){
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                b = 1;
            }
            i++;
        }

    } while (b != 0);
}


void printArr(int arr[], int tam){

    printf("[");
    for (int i = 0; i < TAM; i++){
        printf("%d", arr[i]);
        if (i != TAM - 1){
            printf(", ");
        }
    }
    printf("]");
}