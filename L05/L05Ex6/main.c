/// 3.6. Să se scrie funcţia care realizează operaţiile aritmetice asupra a două matrice rare (matricea rară este o matrice de dimensiune mare, care are majoritatea elementelor nule).

#include <stdio.h>
#include <stdlib.h>

void citeste(int a[100][100], int *n, int *m, char c){
    int i, j;

    printf("Citeste matricea %c: \n", c);

    printf("\tNumarul de linii: ");
    scanf("%d", n);

    printf("\tNumarul de coloane: ");
    scanf("%d", m);

    for(i=0; i<*n; i++)
        for(j=0; j<*m; j++){
            printf("%c[%d][%d] = ", c, i, j);
            scanf("%d", &a[i][j]);
        }
}

void afiseaza(int a[100][100], int n, int m){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void adunare(int a[100][100], int b[100][100], int c[100][100], int nA, int mA, int nB, int mB){
    int i, j;

    if(nA!=nB || mA!=mB){
        printf("Matricele nu sunt patratice");
        exit(1);
    }
    else{
        for(i=0; i<nA; i++)
            for(j=0; j<mA; j++)
                c[i][j]=a[i][j]+b[i][j];
    }
}

void scadere(int a[100][100], int b[100][100], int c[100][100], int nA, int mA, int nB, int mB){
    int i, j;

    if(nA!=nB || mA!=mB){
        printf("Matricele nu sunt patratice");
        exit(1);
    }
    else{
        for(i=0; i<nA; i++)
            for(j=0; j<mA; j++)
                c[i][j]=a[i][j]-b[i][j];
    }
}

void inmultireScalar(int a[100][100], int nA, int mA, int nr){
    int i, j;

    for(i=0; i<nA; i++)
        for(j=0; j<mA; j++)
            a[i][j]=a[i][j]*nr;
}

void inmultire(int a[100][100], int b[100][100], int c[100][100], int nA, int mA, int nB, int mB){
    int i, j, k;

    for(i=0; i<nA; i++)
        for(j=0; j<mA; j++){
            c[i][j]=0;
            for(k=0; k<nB; k++)
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
}


int main()
{
    int a[100][100], b[100][100], c[100][100], *nA, *mA, nB, mB;

    citeste(a, &nA, &mA, 'A');
    citeste(b, &nB, &mB, 'B');

    printf("A + B\n");
    adunare(a, b, c, nA, mA, nB, mB);
    afiseaza(c, nA, mB);

    printf("\nA - B\n");
    scadere(a, b, c, nA, mA, nB, mB);
    afiseaza(c, nA, mB);

    printf("\nA * B\n");
    inmultire(a, b, c, nA, mA, nB, mB);
    afiseaza(c, nA, mB);

    return 0;
}
