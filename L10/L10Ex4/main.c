/// 3.4. Să se scrie programul pentru concatenarea a două sau mai multe fişiere ce conţin numere reale. Se va tipări informaţia din fişierul rezultat.

#include <stdio.h>
#include <stdlib.h>

void creeaza(const char *nume){
    float x;
    FILE* pf = fopen(nume, "w");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    printf("Creare %s: Dati numere reale, iar la sfarsit Ctrl + Z: \n", nume);

    while(scanf("%f", &x)==1) fprintf(pf, "%f\n", x);

    fclose(pf);
}

void afiseaza(const char *nume){
    char s[50];

    FILE* pf = fopen(nume, "r");
    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    while(fgets(s, 50, pf)!=NULL) printf("%s", s);

    fclose(pf);
}

void concat(FILE* pr, const char *nume){
    float x;
    FILE* pf = fopen(nume, "r");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    while(fscanf(pf, "%f", &x)==1) fprintf(pr, "%f ", x);

    fprintf(pr, "\n");
    fclose(pf);
}

int main()
{
    int n, i;
    char nume[20], rez[]="rezultat.txt";

    FILE* pr=fopen(rez, "w");

    if(pr==NULL){
        perror(rez);
        exit(1);
    }

    printf("Numar fisiere: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        sprintf(nume, "fis%d.txt", i);
        creeaza(nume);
        concat(pr, nume);
    }

    fclose(pr);
    afiseaza(rez);

    return 0;
}
