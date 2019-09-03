/// 3.4. Să se scrie o funcţie pentru ştergerea unui subşir dintr-un şir de caractere dat. Subşirul se va specifica prin poziţie şi număr de caractere. Se va scrie şi programul care testează această funcţie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void sterge(char *d, int poz, int nr){
    if(poz>=strlen(d)) return ;
    if(poz+nr>=strlen(d)) d[poz]='\0';
    else memmove(d+poz, d+poz+nr, strlen(d+poz+nr)+1);
}

int main()
{
    char s[N];
    int poz, nr;

    printf("Sirul: ");
    fgets(s, N, stdin);

    printf("Pozitia de unde stergem: ");
    scanf("%d", &poz);

    printf("Numarul de caractere sterse: ");
    scanf("%d", &nr);

    sterge(s, poz, nr);

    printf("Subsirul ramas: %s\n", s);

    return 0;
}
