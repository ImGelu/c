/// 3.2. Se citeşte gradul unui polinom şi coeficienţii săi, care sunt numere întregi: în care p0 este nenul. Ştiind că polinomul admite numai rădăcini întregi simple, să se găsească rădăcinile polinomului.

#include <stdio.h>
#include <stdlib.h>
#define GRAD_MAX 20

int citpol(int a[]);
int val_polinom(int x, int n, int a[]);
int afisRad(int n, int a[]);

int main(){

    int p[GRAD_MAX+1], grad;

    grad=citPol(p);
    printf("Radacinile intregi: ");
    if(afisRad(grad, p)==0) printf("Nu exista radacini intregi\n");

    return 0;
}

int citPol(int a[]){
    int n, i;

    printf("Gradul (<=%d): ", GRAD_MAX);
    scanf("%d", &n);
    printf("Coeficientii polinomului: \n");
    for(i=n; i>=0; i--){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    return n;
}

int val_polinom(int x, int n, int a[]){
    int i, v=0;
    for(i=n; i>=0; i--) v=v*x+a[i];

    return v;
}

int afisRad(int n, int a[]){
    int nrRad=0, d;

    for(d=1; d<=abs(a[0]); d++)
        if(a[0]%d==0){
            if(val_polinom(d, n, a)==0){
                nrRad++;
                printf("%d ", d);
            }
        }

    if(val_polinom(-d, n, a)==0){
        nrRad++;
        printf("%d ", -d);
    }

    return nrRad;
}
