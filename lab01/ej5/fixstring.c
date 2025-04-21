#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int res = 0;
    for (unsigned int i = 0; s[i] != '\0'; i++){
        res = res + 1;
    }
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool son_iguales = true;
    unsigned int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0'){
        if (s1[i] != s2[i]){
            son_iguales = false;
        }
        i++;
    }
    return son_iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool s1esMenorOIgual = false;
    bool menorEncontrado = false;
    unsigned int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && !menorEncontrado){
        if (s1[i] < s2[i]){
            s1esMenorOIgual = true;
            menorEncontrado = true;
        } else if (s1[i] > s2[i]){
            s1esMenorOIgual = false;
            menorEncontrado = true;
        }
        
        i++;
    }

    if (!menorEncontrado && fstring_length(s1) < fstring_length(s2)){
        s1esMenorOIgual = true;
    } else if (!menorEncontrado && fstring_length(s1) > fstring_length(s2)){
        s1esMenorOIgual = false;
    }
    return s1esMenorOIgual;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0'; // Agrega el terminador nulo al final
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux,s1);
    fstring_set(s1,s2);
    fstring_set(s2,aux);
}


