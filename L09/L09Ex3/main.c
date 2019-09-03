/// 3.3. Să se scrie o funcţie pentru inserarea unui şir de caractere sursă într-un şir de caractere destinaţie, specificând poziţia din care începe inserarea. Se va scrie şi programul care testează această funcţie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void insert(char *d, const char *s , int poz){
    if(poz>=strlen(d)) strcat(d, s);
    else {
        char aux[N];
        strcpy(aux, d+poz);
        strcpy(d+poz, s);
        strcat(d, aux);
    }
}

int main()
{
    char s[N], d[N];
    int poz, nr;

    printf("Sirul initial: ");
    fgets(s, N, stdin);

    printf("Sirul pe care il introducem: ");
    fgets(d, N, stdin);

    printf("Pozitia unde inseram: ");
    scanf("%d", &poz);

    if(s[strlen(s)-1]=='\n') s[strlen(s)-1]='\0';
    insert(s, d, poz);

    printf("Sirul final: %s\n", d);

    return 0;
}
