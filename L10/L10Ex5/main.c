/// 3.5. Să se creeze un fişier care să conţină produsele unui magazin. Un produs este reprezentat printr-o structură ce conţine codul produsului, denumirea, unitatea de măsură, cantitatea, preţul unitar. Scrieţi funcţii de intrare şi de ieşire a produselor magazinului. Plecând de la acest fişier, să se obţină un fişier sortat după cod.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct { char cod[N], denumire[N], unitate[N]; float pret, cant; } Produs;

void *creeaza(const char *nume, int *n){
    int i, l;

    FILE* pf = fopen(nume, "w");
    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    printf("Introduceti numarul de produse: ");
    scanf("%d%*c", n);

    Produs *p=malloc(sizeof(Produs)*(*n)+1);

    for(i=0; i<*n; i++){
        printf("\nProdusul #%d: \n", i);

        printf("\tCodul produsului #%d: ", i);
        fgets(p[i].cod, N, stdin);

        l=strlen(p[i].cod);
        if(p[i].cod[l-1]=='\n') p[i].cod[l-1]='\0';

        printf("\tDenumirea produsului #%d: ", i);
        fgets(p[i].denumire, N, stdin);

        l=strlen(p[i].denumire);
        if(p[i].denumire[l-1]=='\n') p[i].denumire[l-1]='\0';

        printf("\tUnitarea de masura #%d: ", i);
        fgets(p[i].unitate, N, stdin);

        l=strlen(p[i].unitate);
        if(p[i].unitate[l-1]=='\n') p[i].unitate[l-1]='\0';

        printf("\tCantitatea #%d: ", i);
        scanf("%f%*c", &p[i].cant);

        printf("\tPretul #%d: ", i);
        scanf("%f%*c", &p[i].pret);

        fprintf(pf, "%s\t%s\t%s\t%.2f\t%.2f\n", p[i].cod, p[i].denumire, p[i].unitate, p[i].cant, p[i].pret);
    }

    fclose(pf);

    return p;
}

void sortare(Produs *p, int n, const char *lista){
    int i, sortat=0, k=0;
    k=n;
    Produs aux;

    FILE *pf = fopen(lista, "w+");

    if(pf==NULL){
        perror(pf);
        exit(1);
    }

    while(!sortat){
        sortat=1;
        for(i=1; i<n; i++)
            if(strcmp(p[i-1].cod, p[i].cod)>=0){
                aux=p[i-1];
                p[i-1]=p[i];
                p[i]=aux;
                sortat=0;
            }
        n--;
    }

    fprintf(pf, "-----PRODUSE-----\n");

    for(i=0; i<k; i++) fprintf(pf, "%s\t%s\t%s\t%.2f\t%.2f\n", p[i].cod, p[i].denumire, p[i].unitate, p[i].cant, p[i].pret);

}

int main()
{
    Produs *p;
    int n;

    p=creeaza("date.txt", &n);
    sortare(p, n, "produse.txt");

    return 0;
}
