#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int equals(const char* str1, const char* str2){

    if (str1 == NULL || str2 == NULL){
        puts("[ERROR] No puede pasar un paramtro nulo");
        exit(EXIT_FAILURE);
    }

    char c1;
    char c2;
    int i;

    for (
        i = 0;
        ((c1 = str1[i]) != '\0') && ((c2 = str2[i]) != '\0');
        i++
        ){

        if (c1 != c2){
            return 0;
        }
    }

    if (str1[i] == '\0' && str2[i] != '\0') return 0;
    if (str1[i] != '\0' && str2[i] == '\0') return 0;

    return 1;
}


int length(const char* str){

    if (str == NULL){
        puts("[ERROR] No puede pasar un paramtro nulo");
        exit(EXIT_FAILURE);
    }

    int i;

    for (i = 0; str[i] != '\0'; i++);

    return i;
}


char* trim(const char* str){

    char* newStr;
    int tam;
    int start;
    int end;
    int len;
    int i;

    len = length(str);
    i = len - 1;

    while (i >= 0 && str[i] == ' ') i--;
    end = i;

    i = 0;
    while (i <= end && str[i] == ' ') i++;
    start = i;


    tam = end - start + 1;

    newStr = malloc(sizeof(char) * (tam + 1));

    if (!newStr){
        puts("[ERROR] No se pudo reservar memoria");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i < tam){
        newStr[i] = str[start + i];
        i++;
    }

    newStr[i] = '\0';

    return newStr;

}

int matches(const char* str, const char match){
    int cont = 0;
    int i;

    // Contar cantidad de argumentos
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == match){
            cont++;
        }
    }

    return cont;
}


char** split(const char* str, const char delim){
    int start;
    int end;
    int i;
    int len;
    int cont;
    int tokCount;

    start = 0;
    end = 0;
    len = length(str);
    i = 0;
    cont = 0;
    tokCount = matches(str, delim) + 1;

    char** tokens = malloc(sizeof(char*) * (tokCount + 1)); //RESERVA UNO PARA NULL

    while (i <= len){
        if (str[i] == delim || str[i] == '\0'){
            end = i;

            int tokenTam = end - start + 1;
            tokens[cont] = malloc(sizeof(char) * tokenTam);

            if (!tokens[cont]){
                puts("[ERROR] No se pudo reservar memoria");
                exit(EXIT_FAILURE);
            }

            int k = 0;
            int j = start;
            while (j < end){
                tokens[cont][k] = str[j];
                j++;
                k++;
            }
            tokens[cont][k] = '\0';
            cont++;
            start = end + 1;
        }
        i++;
    }

    tokens[cont] = NULL;

    return tokens;
}