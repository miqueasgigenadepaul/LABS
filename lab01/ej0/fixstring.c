#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int res = 0;
    for (int i = 0; i < s; i++){
        res = res + 1;
    }
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    /*
     * COMPLETAR
     *
     */
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    /*
     * COMPLETAR
     *
     */
}

int main() {
    printf("cadena tiene %d caracteres", fstring_length("hola"));

    return 0;
}

