/// 3.3. Se citeşte n şi perechile de numere întregi (xi, yi) reprezentând o relaţie binară R peste mulţimea M. Admiţând că fiecare element din mulţimea M apare în cel puţin o pereche dintre cele citite, să se determine mulţimea M. Să se verifice dacă relaţia R este o relaţie de echivalenţă (reflexivă, simetrică şi tranzitivă).

#include <stdio.h>
#include <stdlib.h>
#define N 20

int exista(int x, int a[], int m){
    int i;

    for(i=0; i<m; i++)
        if(a[i]==x) return 1;

    return 0;
}

int exista_in_R(int x, int y, int R[][2], int n){
    int i;
    for(i=0; i<n; i++)
        if(R[i][0]==x && R[i][1]==y) return 1;

    return 0;
}

int citRel(int R[][2]){
    int n, i;
    scanf("%d", &n);
    printf("Elementele relatiei: \n");

    for(i=0; i<n; i++){
        printf("[Perechea %d]: ", i);
        scanf("%d%d", &R[i][0], &R[i][1]);
    }

    return n;
}

int detMult(int R[][2], int n, int M[]){
    int m=0, i, j;

    for(i=0; i<n; i++)
        for(j=0; j<2; j++)
            if(!exista(R[i][j], M, m)) M[m++]=R[i][j];
}

int refl(int R[][2], int n, int M[], int m){
    int i;

    for(i=0; i<m; i++)
        if(!exista_in_R(M[i], M[i], R, n)) return 0;

    return 1;
}

int sim(int R[][2], int n){
    int i;

    for(i=0; i<n; i++)
        if(!exista_in_R(R[i][1], R[i][0], R, n)) return 0;

    return 1;
}

int tranz(int R[][2], int n){
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(R[i][1]==R[j][0])
                if(!exista_in_R(R[i][0], R[j][1], R, n)) return 0;

    return 1;
}

int main()
{

    int R[N][2], M[2*N], n, m;

    n=citRel(R);
    m=detMult(R, n, M);

    if(refl(R, n, M, m)) printf("Este reflexiva\n");
    else printf("Nu este reflexiva\n");

    if(sim(R, n)) printf("Este simetrica\n");
    else printf("Nu este simetrica\n");

    if(tranz(R, n)) printf("Este tranzitiva\n");
    else printf("Nu este tranzitiva\n");

    if(refl(R, n, M, m) && sim(R, n) && tranz(R, n)) printf("Relatie de echivalenta");

    return 0;
}
