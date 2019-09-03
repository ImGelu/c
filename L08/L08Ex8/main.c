/// 3.8. Se citeşte un şir de caractere format din litere şi cifre. Să se indice frecvenţa de apariţie a caracterelor întâlnite în şir folosind o listă ordonată alfabetic (nodul conţine caracterul, frecvenţa şi adresa următorului nod).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char caracter; int aparitii; } Litera;

int main()
{
    char c[1000];
    Litera l[2000];
    int i;

    printf("Introduceti sirul de caractere: ");
    gets(c);

    for(i='0'; i<='z'; i++) l[c[i]].aparitii=0;

    for(i=0; i<strlen(c); i++) l[(int)c[i]].aparitii++;

    for(i='0'; i<='z'; i++)
        if((isalpha((char)i) || isdigit((char)i)) && l[i].aparitii!=0) printf("%c apare de %d ori\n", i, l[i].aparitii);

    return 0;
}
