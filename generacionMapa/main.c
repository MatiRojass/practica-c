#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arbol 'T'
#define cesped '-   '
#define camino '#'

/**
 * Valida que tenga al menos 1 al menos un bloque de espacio con otro arbol
 */
int tieneEspacio(char** map, int heigth, int width, int posY, int posX);

/**
 * Genera caminos en el mapa
 */
void generarCaminos(char** map, int heigth, int width);

/**
 *  Crea un mapa con un terreno y arboles con una probabilidad de 20% de aparecer
 */
char** generarMapa(int heigth, int width);

/**
 * Rellena el mapa con caracteres de cesped
 */
void inicializarMapa(char** map, int heigth, int width);


/**
 * Coloca arboles (T) en el mapa
 */
void colocarArboles(char** map, int heigth, int width);

/**
 * Muestra el mapa por consola
 */
void mostrarMapa(char** map, int heigth, int width);

/**
 * Libera la memoria ocupada por el mapa
 */
void liberarMapa(char** map, int heigth);

int main(){
    srand(time(NULL));
    int heigth = 20;
    int width = 40;

    char** map = generarMapa(heigth, width);

    if (map == NULL){
        puts("[ERROR] :(");
        return 1;
    }

    mostrarMapa(map, heigth, width);

    liberarMapa(map, heigth);
    return 0;
}

void generarCaminos(char** map, int heigth, int width){

    for (int x = 0; x < width; x++){
        int randNum = rand() % width;
        if (randNum < width / 5){
            map[0][x] = camino;
        }
    }

    for (int y = 1; y < heigth; y++){
        for (int x = 0; x < width; x++){
            int supY = y - 1;

            if (map[supY][x] == camino){


                int prevX = (x > 0) ? x - 1 : 0;
                int postX = (x < width - 1) ? x + 1 : width - 1;

                //validar donde empezar el camino
                //1. verificar si tiene un camino arriba 
                //- si no tiene camino arriba, entonces de ahi continua
                //- sino, si tiene camino arriba pero no a los lados, continua en el mismo

                if (y >= 2 && map[supY - 1][x] == camino){
                    if ((postX != width - 1 && map[supY][postX] == camino) || (prevX != 0 && map[supY][prevX] == camino)){
                        continue;
                    }
                }

                map[y][x] = camino;
                int randNum = rand() % 100;

                //Si es menor al 17% se desvia a la derecha
                if (randNum <= 17){
                    map[y][postX] = camino;
                }
                else if (randNum <= 34){ //Si es menor a 34% se desvia a la izquierda
                    map[y][prevX] = camino;
                }

                //sino sigue el camino previo
            }
        }
    }
}

void colocarArboles(char** map, int heigth, int width){
    for (int i = 0; i < heigth; i++){
        for (int j = 0; j < width; j++){
            if (tieneEspacio(map, heigth, width, i, j) && map[i][j] != camino){
                int random = (rand() % 100) + 1;
                char elem = random < 15 ? arbol : cesped;
                map[i][j] = elem;
            }
        }
    }
}


void inicializarMapa(char** map, int heigth, int width){
    for (int i = 0; i < heigth; i++){
        for (int j = 0; j < width; j++){
            map[i][j] = cesped;
        }
    }
}


void mostrarMapa(char** map, int heigth, int width){
    for (int i = 0; i < heigth; i++){
        for (int j = 0; j < width; j++){
            if (map[i][j] == arbol){
                printf("\033[0;32m%c\033[0m", map[i][j]); // verde
            }
            else if (map[i][j] == cesped){
                printf("\033[0;33m%c\033[0m", map[i][j]); // amarillo
            }
            else{
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}


char** generarMapa(int heigth, int width){
    if (width < 1 || heigth < 1){
        puts("Parametros no validos (menores a 0)");
        return NULL;
    } //ERROR

    char** map = malloc(sizeof(char*) * heigth);

    if (map == NULL){
        puts("Algo salio mal : 1");
        return NULL;
    }

    for (int i = 0; i < heigth; i++){
        map[i] = malloc(sizeof(char) * width);
        if (map[i] == NULL){
            puts("Algo salio mal : 2");
            return NULL;
        }
    }

    inicializarMapa(map, heigth, width);
    generarCaminos(map, heigth, width);
    colocarArboles(map, heigth, width);

    return map;
}


int tieneEspacio(char** map, int heigth, int width, int posY, int posX){


    int minX = (posX > 0) ? posX - 1 : posX;
    int maxX = (posX < width - 1) ? posX + 1 : posX;
    int minY = (posY > 0) ? posY - 1 : posY;
    int maxY = (posY < heigth - 1) ? posY + 1 : posY;

    for (int y = minY; y <= maxY; y++){
        for (int x = minX; x <= maxX; x++){
            if (!(y == posY && x == posX) && map[y][x] == arbol){
                return 0;
            }
        }
    }
    return 1;
}

void liberarMapa(char** map, int heigth){
    for (int i = 0; i < heigth; i++){
        free(map[i]);
    }
    free(map);
}