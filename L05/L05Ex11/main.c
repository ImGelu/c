/// 3.11. Să se scrie o funcție pentru a verifica dacă un șir de caractere este subșir al altui șir de caractere. În caz afirmativ funcția trebuie să returneze poziția la care începe subșirul, iar în caz negativ trebuie să returneze valoarea -1.

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

   while((poz=pozSubsir(s+i, subsir))>=0)
   {
       nrAparitii++;
       printf("Subsirul apare pe pozitia: %d ", poz+i);
       i+=poz+1;
   }

   if(nrAparitii==0) printf("Subsirul nu apare");

   return 0;
}
