/// 3.2. Se citeşte de la tastatură un text care se scrie într-un fişier "text.dat". Să se afişeze apoi conţinutul fişierului (fără a cunoaşte lungimea maximă a liniilor), fiecare linie fiind precedată de numărul de ordine al ei.

#include <stdio.h>
#include <stdlib.h>

void creeaza(const char *nume){
    char s[1000];
    FILE* pf = fopen(nume, "w");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    printf("Creare %s: Dati un text, iar la sfarsit Ctrl + Z: \n", nume);

    while(scanf("%s", &s)==1) fprintf(pf, "%s\n", s);

    fclose(pf);
}

void afiseaza(const char *nume){
    int i=0;
    char s[50];
    FILE* pf = fopen(nume, "r");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    while(fgets(s, 50, pf)!=NULL) printf("%d\t%s", ++i, s);

    fclose(pf);
}

int main()
{

    creeaza("text.dat");
    afiseaza("text.dat");

    return 0;
}
