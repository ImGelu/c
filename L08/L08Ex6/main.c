/// 3.6. Folosind tipul uniune, care conţine câmpurile necesare pentru a putea reprezenta un cerc, un dreptunghi, un pătrat, un triunghi, să se scrie o funcţie pentru a calcula aria figurii respective.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union { float l1, l2, l3, r, h; } Forma;

Forma citesteForma(char forma[20]){
    Forma f;

    if(strcmp(forma, "patrat")==0){
        printf("Introduceti latura: ");
        scanf("%f", &f.l1);
    }
    if(strcmp(forma, "dreptunghi")==0){
        printf("Introduceti latura 1: ");
        scanf("%f", &f.l1);

        printf("Introduceti latura 2: ");
        scanf("%f", &f.l2);
    }
    if(strcmp(forma, "triunghi")==0){
        printf("Introduceti latura 1: ");
        scanf("%f", &f.l1);

        printf("Introduceti latura 2: ");
        scanf("%f", &f.l2);

        printf("Introduceti latura 3: ");
        scanf("%f", &f.l3);

        printf("Introduceti inaltime: ");
        scanf("%f", &f.h);
    }
    if(strcmp(forma, "cerc")==0){
        printf("Introduceti raza: ");
        scanf("%f", &f.r);
    }

    return f;
}

float calculeazaArie(char forma[20], Forma f){
    if(strcmp(forma, "patrat")==0) return f.l1*f.l1;
    if(strcmp(forma, "dreptunghi")==0) return f.l1*f.l2;
    if(strcmp(forma, "triunghi")==0) return f.l3*f.h;
    if(strcmp(forma, "cerc")==0) return M_PI*f.r*f.r;
}


int main()
{
    char forma[20];
    Forma f;

    printf("Ce forma doriti sa cititi? (patrat, dreptunghi, triunghi sau cerc): ");
    gets(forma);

    f=citesteForma(forma);

    printf("%f", calculeazaArie(forma, f));

    return 0;
}
