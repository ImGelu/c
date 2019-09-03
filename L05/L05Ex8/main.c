/// 3.8. Să se scrie o funcţie care primind ca parametru un număr roman sub forma unui şir de caractere, returnează numărul respectiv ca număr arab în baza 10.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(const char ch){
    switch(ch){
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

int transformare(char c[100]){
    int i, rez=0;

    for(i=0; i<strlen(c); i++){
        if(convert(c[i])>convert(c[i-1])) rez=rez+(convert(c[i])-2*convert(c[i-1]));
        else {
            rez=rez+convert(c[i]);
        }
    }

    return rez;
}

int main()
{
    int i;
    char c[100];
    printf("Introduceti numarul in cifre romane: ");
    gets(c);

    printf("%s in litere arabe: %d", c, transformare(c));

    return 0;
}
