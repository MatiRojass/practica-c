#ifndef UTILS_H
#define UTILS_H

/**
 * Compara 2 cadenas de caracteres
 *
 * @param char* str1
 * @param char* str2
 *
 * @return
 * - 1 : Si son iguales
 *
 * - 0 :  Si son diferentes
 *
 */
int equals(const char* str1, const char* str2);

/**
 * Devuelve la longitud de una cadena
 *
 * @param char* str
 *
 * @return
 *  int: la longitud de la cadena
 */
int length(const char* str);

/**
 * Quita los espacios al inicio y final de una cadena
 *
 * @param char* str
 *
 * @return
 * Nueva cadena sin espacios
 */
char* trim(const char* str);

int matches(const char* str, const char match);

char** split(const char* str, const char delim);

#endif //UTILS_H