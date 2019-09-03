/// 3.5. Să se scrie o funcţie pentru a verifica dacă un şir dat este subşir al unui alt şir de caractere. În caz afirmativ, se va specifica poziţia pe care se regăseşte pentru prima dată. Se va scrie şi programul care testează această funcţie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int pozSubsir(const char *s, const char *subsir){
    char *p = strstr(s, subsir);

    if(p!=NULL) return p-s;
    else return -1;
}

int main()
{
    int poz, i=0, nrAparitii=0;
    char s[N], subsir[N];

    printf("Sirul principal: ");
    gets(s);

    printf("Subsirul cautat: ");
    gets(subsir);

    while((poz=pozSubsir(s+i, subsir))>=0){
        nrAparitii++;
        printf("%d ", poz+i);
        i+=poz+1;
    }

    if(nrAparitii==0) printf("Subsirul nu se gaseste in sir");

    return 0;
}
