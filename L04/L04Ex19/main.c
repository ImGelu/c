/// 3.19. Se citeşte o propoziţie de la intrarea standard. Să se indice numărul cuvintelor şi cuvântul cel mai lung din propoziţie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    int k=0;
    char s[1024], *cuvMax, *p;

    printf("Introduceti o propozitie: ");
    gets(s);

    p=strtok(s, " ");
    cuvMax=p;

    while(p!=NULL){
        if(strlen(p)>strlen(cuvMax)) strcpy(cuvMax, p);
        p=strtok(NULL, " ");
        k++;
    }

    printf("Sunt %d cuvinte, iar cel mai lung este %s", k, cuvMax);

    return 0;
}
