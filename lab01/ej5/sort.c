#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    unsigned int i;
    unsigned int j;
    ppiv = izq;
    i=izq+1;
    j=der;

    while (i <= j){
        if (a[i] <= a[ppiv]){
            i++;
        } else if (a[j] >= a[ppiv]){
            j--;
        } else {
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a,ppiv,j);
    return j;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der, unsigned int length) {
    unsigned int ppiv;
    if ((der > izq) && (der < length + 1)){
        ppiv = partition(a,izq,der);
        quick_sort_rec(a,izq,ppiv-1,length);
        quick_sort_rec(a,ppiv+1,der,length);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}


