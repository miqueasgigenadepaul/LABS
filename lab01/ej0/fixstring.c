#include <stdbool.h>
#include <assert.h>

#include <stdio.h>

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

/* Aca abajo con int main probé que las funciones esten bien hechas
pero deje el main comentado ya que tenemos un archivo main.c aparte
*/
int main() {
    // para fstring_length()
    char cadena[]="hola";
    printf("La longitud de %s es %u\n", cadena, fstring_length(cadena));
    
    // para fstring_eq()
    char cad[]="si";
    char chain[]="si";
    if (fstring_eq(cad, chain)){
        printf("%s y %s son iguales\n", cad, chain);
    } else {
        printf("%s y %s no son iguales\n", cad, chain);
    }

    // para fstring_less_eq()
    char c1[]="aato";
    char c2[]= "aato";
    if (fstring_less_eq(c1,c2)){
        printf("%s SI es menor o igual a %s\n", c1, c2);
    } else if (!fstring_less_eq(c1,c2)){
        printf("%s NO es menor o igual a %s\n", c1, c2);
    } 
    return 0;
}





