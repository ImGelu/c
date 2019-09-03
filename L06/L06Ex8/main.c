/// 3.8. Să se scrie o funcție pentru calculul derivatei unui polinom P(x) de grad n, într-un punct dat x=x0. Gradul și coeficienții polinomului precum și punctul x0 se vor trimite ca argumente la apelul funcției.

#include <stdio.h>
#include <stdlib.h>

float *citestePol(int *pg, char nume){
    int i;

    printf("Gradul polinomului %c: ", nume);
    scanf("%d", pg);

    float *a=calloc(*pg+1, sizeof(float));
    if(a==NULL){
        printf("Memorie insuficienta");
        exit(1);
    }

    printf("Coeficientii polinomului %c: \n", nume);
    for(i=*pg; i>=0; i--){
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }

    return a;
}

float valPolinom(float x, int n, float a[]){
    int i;
    float v;

    for(i=n; i>=1; i--) v=v*x+i*a[i];

    return v;
}

int main()
{
    int grad;
    float *a, x0;

    a=citestePol(&grad, 'P');

    printf("x0 = ");
    scanf("%f", &x0);
    printf("P(%.2f) = %.3f\n", x0, valPolinom(x0, grad, a));

    free(a);

    return 0;
}

