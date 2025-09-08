#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/utils.h"
#define NRO_COMANDOS 3



char* leerLinea();
int extraerArgumentos(char* linea, char** args);
int ejecutarComando(char** args, const char** comandos, int comandosLen, void (*comandosFn[])(char**));

void exit_cm(char** args);
void echo_cm(char** args);
void sum_cm(char** args);

int main(){

    const char* comandos[NRO_COMANDOS] = { "exit", "echo", "sum" };
    void (*comandosFn[NRO_COMANDOS])(char**) = {
        exit_cm, echo_cm, sum_cm
    };
    char* linea;
    char** args;

    puts("Bienvenido a shell-c. Para revisar la lista de comandos escribe help");

    int b = 1;
    while (b == 1){
        printf("shell-c_> ");
        linea = leerLinea();
        args = split(linea, ' ');

        int opc = ejecutarComando(args, comandos, 3, comandosFn);
        if (opc == 0) b = 0;
    }

    free(linea);
    for (int i = 0; args[i]; i++){
        free(args[i]);
    }
    free(args);

    return 0;
}

void exit_cm(char** args){
    puts("Hasta la proximaa :)");
}

void echo_cm(char** args){
    for (int i = 1; args[i]; i++){
        printf("%s", args[i]);
        if (args[i + 1] != NULL){
            printf(" ");
        }
    }
    printf("\n");
}

void sum_cm(char** args){
    puts("Esta funcion todavia no existe.");
}

int ejecutarComando(char** args, const char** comandos, int comandosLen, void (*comandosFn[])(char**)){

    for (int i = 0; i < comandosLen; i++){
        if (equals(args[0], comandos[i])){
            comandosFn[i](args);
            return i;
        }
    }

    puts("Comando no reconocido.");

    return -1;
}


char* leerLinea(){


    int tam = 20;
    char* linea = malloc(sizeof(char) * tam);

    if (!linea){
        puts("[ERROR] No se pudo localizar memoria");
        exit(EXIT_FAILURE);
    }

    char c;
    int cont = 0;
    while ((c = getchar()) != '\n' && c != EOF){

        if (cont >= tam){
            tam *= 2;
            realloc(linea, tam);

            if (!linea){
                puts("[ERROR] No se pudo localizar memoria");
                exit(EXIT_FAILURE);
            }
        }

        linea[cont] = c;

        cont++;
    }

    linea[cont] = '\0';

    return linea;
}
