/// 3.3. De la tastatură se citesc partea reală şi partea imaginară pentru n numere complexe. Să se creeze un fişier care conţine numerele complexe citite, fiecare număr având partea reală, partea imaginară, modulul şi argumentul său. Se va afișa conținutul fișierului.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.1415
#include <math.h>

typedef struct { float re, im; double mod, arg; } Complex;

void creeaza(const char *nume){
    int n, i;
    Complex z;
    FILE* pf = fopen(nume, "w");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    printf("Numarul de numere complexe: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("[%d].re = ", i);
        scanf("%f", &z.re);

        printf("[%d].im = ", i);
        scanf("%f", &z.im);

        z.mod = sqrt(z.re*z.re + z.im*z.im);
        z.arg = atan2(z.im, z.re);

        fprintf(pf, "%f %f %f %f\n", z.re, z.im, z.mod, z.arg);
    }

    fclose(pf);
}

void afiseaza(const char *nume){
    Complex z;
    FILE *pf = fopen(nume, "r");

    if(pf==NULL){
        perror(nume);
        exit(1);
    }

    while(fscanf(pf, "%f%f%lf%lf", &z.re, &z.im, &z.mod, &z.arg)==4){
        printf("%.2f + i*%.2f\t Modul: %.3f", z.re, z.im, z.mod);
        printf("\tArg: %.2f grade\n", z.arg*180/M_PI);
    }

    fclose(pf);
}

int main()
{
    char nume[]="fis.txt";

    creeaza(nume);
    afiseaza(nume);

    return 0;
}
