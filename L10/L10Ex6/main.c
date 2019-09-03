/// 3.6. Să se scrie un program pentru admiterea la facultate în anul I. Programul va cuprinde crearea fişierului cu candidaţii înscrişi. În final trebuie să se obţină fişierele cu candidaţii admişi şi cei respinşi, pe baza numărului de locuri disponibile şi a mediei obţinute ((bacalaureat + 2 * test_matem) / 3.0).

#include <stdio.h>
#include <stdlib.h>
#define N 60

typedef struct { char nume[N]; float bac, test, medie; } Candidat;

void *creeaza(const char *nume, int *n, int *disp){
    int i, l;

    FILE* pf = fopen(nume, "w");
    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    printf("Numarul canditatilor: ");
    scanf("%d%*c", n);

    Candidat *c=malloc(sizeof(Candidat)*(*n)+1);

    printf("Locuri disponibile: ");
    scanf("%d%*c", disp);

    fprintf(pf, "%d %d\n", *n, *disp);

    for(i=0; i<*n; i++){
        printf("\tNumele #%d: ", i);
        fgets(c[i].nume, N, stdin);

        l=strlen(c[i].nume);
        if(c[i].nume[l-1]=='\n') c[i].nume[l-1]='\0';

        printf("\tMedia bac #%d: ", i);
        scanf("%f%*c", &c[i].bac);

        printf("\tNota test mate #%d: ", i);
        scanf("%f%*c", &c[i].test);
        printf("\n");

        c[i].medie=(c[i].bac+2*c[i].test)/3;

        fprintf(pf, "%s %.2f\n", c[i].nume, c[i].medie);
    }

    fclose(pf);

    return c;
}

void sortare(Candidat *c, int n, int disp, const char *fisierAdmisi, const char *fisierRespinsi){
    int i, sortat=0, k=n;
    Candidat aux;

    FILE *pfAdmisi = fopen(fisierAdmisi, "w");
    FILE *pfRespinsi = fopen(fisierRespinsi, "w");

    if(pfAdmisi==NULL){
        perror(pfAdmisi);
        exit(1);
    }

    if(pfRespinsi==NULL){
        perror(pfRespinsi);
        exit(1);
    }

    while(!sortat){
        sortat=1;
        for(i=1; i<n; i++)
            if(c[i-1].medie<c[i].medie){
                aux=c[i-1];
                c[i-1]=c[i];
                c[i]=aux;
                sortat=0;
            }
        n--;
    }

    fprintf(pfAdmisi, "-----CANDIDATI ADMISI-----\n");
    fprintf(pfRespinsi, "-----CANDIDATI RESPINSI-----\n");

    for(i=0; i<disp; i++) fprintf(pfAdmisi, "%d\t%s\t%.2f \n", i+1, c[i].nume, c[i].medie);
    for(i=disp; i<=k; i++) fprintf(pfRespinsi, "%d\t%s\t%.2f \n", i-disp+1, c[i].nume, c[i].medie);
}


int main()
{
    Candidat *c;
    int n, disp;

    c=creeaza("date.txt", &n, &disp);
    sortare(c, n, disp, "admisi.txt", "respinsi.txt");

    return 0;
}
