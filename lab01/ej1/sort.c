#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*el unsigned int length lo saque porque no se usa ese parametro*/

static void insert(int a[], unsigned int i) {
    int j = i;
    while(j > 0 && a[j] < a[j-1]){
        swap(a, j-1, j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        assert(array_is_sorted(a, i)); // Parte C, chequeo de invariante 
        insert(a, i); // le saque el length ya que el parametro lo saque en la funcion del insert
    }
}
