#include <stdio.h>
#define TAM 10

/**
 * ORDENAMIENTO BURBUJA
 */

void ordenar(int arr[], int tam);
void printArr(int arr[], int tam);

int main(){
    int arreglo[TAM] = { 10,1,3,8,2,6,10,7,7,9 };

    puts("Arreglo inicial: ");
    printArr(arreglo, TAM);

    ordenar(arreglo, TAM);

    puts("\n\nArreglo ordenado: ");
    printArr(arreglo, TAM);

}

void ordenar(int arr[], int tam){
    int i = 0;
    int j, p;
    int aux;
    while (i < tam - 1){
        p = i;
        j = i + 1;

        while (j < tam){
            if (arr[p] > arr[j]){
                p = j; //guarda la posicion del elemnto mas chico a partir de i
            }
            j++;
        }

        //se hace el switch entre el elemento actual y el mas chico
        aux = arr[i];
        arr[i] = arr[p];
        arr[p] = aux;

        i++;
    }
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