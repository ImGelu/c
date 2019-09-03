/// 3.5. Să se scrie funcţiile pentru adunarea, scăderea şi înmulţirea a două matrice şi apoi să se calculeze A=B*C–2*(B+C), unde B şi C sunt două matrice pătratice de ordinul n.

#include <stdio.h>
#include <stdlib.h>

void citeste(int a[100][100], int *n, char c){
    int i, j;

    printf("Citeste matricea %c: \n", c);

    printf("\tNumarul de linii si coloane: ");
    scanf("%d", n);

    for(i=0; i<*n; i++)
        for(j=0; j<*n; j++){
            printf("%c[%d][%d] = ", c, i, j);
            scanf("%d", &a[i][j]);
        }
}

void afiseaza(int a[100][100], int n){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void adunare(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            c[i][j]=a[i][j]+b[i][j];
}

void scadere(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            c[i][j]=a[i][j]-b[i][j];
}

void inmultireScalar(int a[100][100], int n, int nr){
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            a[i][j]=a[i][j]*nr;
}

void inmultire(int a[100][100], int b[100][100], int c[100][100], int n){
    int i, j, k;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            c[i][j]=0;
            for(k=0; k<n; k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
}

int main()
{
    int a[100][100], b[100][100], c[100][100], *n;

    citeste(b, &n, 'B');
    citeste(c, &n, 'C');

    inmultire(b, c, a, n); /// B*C
    adunare(b, c, b, n); /// B+C
    inmultireScalar(b, n, 2); /// 2*(B+C)
    scadere(a, b, a, n); /// B*C - 2*(B+C)

    afiseaza(a, n);

    return 0;
}
