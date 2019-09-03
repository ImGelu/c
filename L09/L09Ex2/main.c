/// 3.2. Să se scrie o funcţie care să realizeze extragerea dintr-un şir de caractere sursă a unui subşir specificat prin poziţia în cadrul sursei şi a numărului de caractere extrase. Se va scrie şi programul care testează această funcţie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

void subsir(char *d, const char *s, int poz, int nr){
    if(poz>=strlen(s)) d[0]='\0';
    else {
        strncpy(d, s+poz, nr);
        d[nr]='\0';
    }
}

int main()
{
    char s[N], d[N];
    int poz, nr;

    printf("Sirul din care copiem: ");
    fgets(s, N, stdin);
    printf("Pozitia de unde copiem: ");
    scanf("%d", &poz);
    printf("Numar caractere de copiat: ");
    scanf("%d", &nr);
    subsir(d, s, poz, nr);
    printf("Subsirul extras: %s\n", d);

    return 0;
}
