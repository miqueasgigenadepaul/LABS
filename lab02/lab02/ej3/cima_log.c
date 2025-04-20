#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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

 static int cima_rec(int a[], int lft, int rgt) {
    int mid;
    bool es_cima;
    bool izq_cima;
    int res;

    mid = (lft + rgt) / 2;

    es_cima = ( (mid == 0 || a[mid - 1] < a[mid]) &&
                (mid == rgt || a[mid] > a[mid + 1]) );

    izq_cima = (mid > 0 && a[mid - 1] > a[mid]);

    if (es_cima) {
        res = mid;
    } else if (izq_cima) {
        res = cima_rec(a, lft, mid - 1);
    } else {
        res = cima_rec(a, mid + 1, rgt);
    }

    return res; 
}

int cima_log(int a[], int length) {
    return cima_rec(a, 0, length - 1);
}
