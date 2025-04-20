#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {

    // COMPLETAR!!
    int i = 0;
    bool es_creciente = false;
    bool es_decreciente = false;

    while (i < length - 1 && a[i] < a[i+1]){
        es_creciente = true;
        i++;
    }

    while (i < length - 1 && a[i] > a[i+1]){
        es_decreciente = true;
        i++;
    }

    bool res = false;
    if (es_creciente && es_decreciente && i == length - 1){
        res = true;
    }

    return res;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {

    // COMPLETAR!!
    int k = 0;
    while ((k < length) && (a[k] < a[k+1])){
        k++;
    }
    return k;
}
