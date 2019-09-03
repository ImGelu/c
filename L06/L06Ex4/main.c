/// 3.4. Folosind numai pointeri şi expresii cu pointeri se vor scrie funcţii de citire, afişare şi înmulţire a două matrice (precum şi programul care le testează).

#include <stdio.h>
#include <stdlib.h>
#define N 10

void citeste(float a[][N], int *pn, int *pm, char nume){

    printf("Numarul de linii pentru %c (<=%d): ", nume, N);
    scanf("%d", pn);

    printf("Numarul de coloane pentru %c (<=%d): ", nume, N);
    scanf("%d", pm);

    int i, j;
    for(i=0; i<*pn; i++)
        for(j=0; j<*pm; j++){
            printf("%c[%d, %d]=", nume, i, j);
            scanf("%f", &a[i][j]);
        }
}

void produs(const float a[][N], const float b[][N], float c[][N], int n, int m, int *pnc, int *pmc){
    int i, j, k;

    *pnc=n;
    *pmc=m;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++){
            c[i][j]=0;
            for(k=0; k<n; k++) c[i][j]+=a[i][k]*b[k][j];
        }
}

void afiseaza(float a[][N], int n, int m){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            printf("%.1f ", a[i][j]);

        printf("\n");
    }
}

int main()
{
    float A[N][N], B[N][N], C[N][N];
    int na, nb, ma, mb, nc, mc;

    citeste(A, &na, &ma, 'A');
    citeste(B, &nb, &mb, 'B');

    if(na!=mb){
        printf("Nu se poate calcula produsul");
        return 0;
    }

    printf("AxB:\n");
    produs(A, B, C, na, ma, &nc, &mc);
    afiseaza(C, nc, mc);

    return 0;
}

/// a        <=> &a[0]
/// a[i]     <=> &a[i][0]  <=> *(a+i)
/// a[i][j]  <=> *(a[i]+j) <=> *(*(a+i)+j)
/// &a[i][j] <=> a[i] + j  <=> *(a+i)+j
