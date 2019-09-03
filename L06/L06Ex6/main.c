/// 3.6. Să se scrie o funcţie care caută prima apariţie a unui şir de caractere în alt şir de caractere, și returnează poziţia pe care apare subşirul în şir, sau -1 dacă nu a fost găsit. Folosind această funcţie, să se determine toate poziţiile pe care apare un şir de caractere într-un altul.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int pozSubsir(const char *s, const char *subsir){
    char *p=strstr(s,subsir);

    if(p!=NULL) return p-s;
    else return -1;
}

int main()
{
    int poz, nrAparitii=0, i=0;
    char s[N], subsir[N];

    printf("Introduceti sirul: ");
    gets(s);
    printf("Introduceti subsirul cautat: ");
    gets(subsir);

    while((poz=pozSubsir(s+i, subsir))>=0){
        nrAparitii++;
        printf("Subsirul apare pe pozitia: %d\n", poz+i);
        i+=poz+1;
    }

    if(nrAparitii==0) printf("Subsirul nu apare");

    return 0;

}
