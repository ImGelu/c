/// 3.9. Să se scrie un program pentru efectuarea operaţiilor de adunare, scădere, înmulţire şi împărţire între două polinoame:

#include <stdio.h>
#include <conio.h>
#define GRADMAX 20

void produs(int n, float a[], int m, float b[], int *p, float c[]){
    int i,j;
    *p=n+m;
    for(i=0; i<=n+m; i++) c[i]=0;
    for(i=0; i<=n; i++)
        for(j=0; j<=m; j++)
            c[i+j]+=a[i]*b[j];
}

void impartire(int n, float a[], int m, float b[], int *grad_cat, float cat[], int *grad_rest, float rest[]){
    int i,j,k;
    if(n<m){
        *grad_cat=0;
        cat[0]=0;
        *grad_rest=n;
        for(i=0; i<=n; i++) rest[i]=a[i];
    }
    else {
        *grad_cat=n-m;
        *grad_rest=m-1;
        for(i=n-m, j=n; i>=0; i--, j--){
            cat[i]=a[j]/b[m];
            for(k=m; k>=0; k--) a[i+k]=a[i+k]-cat[i]*b[k];
            a[j]=0;
        }
        for(i=0; i<=m-1; i++) rest[i]=a[i];
    }
}

void citire_polinom(int *n, float a[]){
    int i;
    printf("\nIntroduceti gradul polinomului: ");
    scanf("%d", n);

    for(i=0; i<=*n; i++){
        printf("\ta[%d]=", i);
        scanf("%f", &a[i]);
    }
}

void afis_polinom(int n, float a[], char c){
    int i;
    printf("\t%c[x]=%g", c, a[0]);
    for(i=1; i<=n; i++) printf("+%g*x^%d",a[i],i);
    printf("\n");
}

int main()
{
    int n, m, grad_r, grad_cat, grad_rest;
    float x, v, p[GRADMAX+1], q[GRADMAX+1], r[GRADMAX+1], cat[GRADMAX+1], rest[GRADMAX+1];

    citire_polinom(&n, p);
    afis_polinom(n, p, 'P');

    citire_polinom(&m, q);
    afis_polinom(m, q, 'Q');

    produs(n, p, m, q, &grad_r, r);
    printf("\n\nR[x]=P[x]*Q[x]\n\n");
    afis_polinom(grad_r, r, 'R');

    printf("\n\nRezultatul impartirii P[x]/Q[x]=>catul C[x] si restul R[x]\n\n");
    impartire(n, p, m, q, &grad_cat, cat, &grad_rest, rest);
    afis_polinom(grad_cat, cat, 'C');
    afis_polinom(grad_rest, rest, 'R');

    return 0;
}
