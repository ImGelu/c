/// 3.5. Să se scrie un program recursiv de generare a produsului cartezian a n mulţimi.

#include <stdio.h>
#include <stdlib.h>

void citire(int a[100], int *pn, int rez[100]){
    int i;

    printf("Introduceti n = ");
    scanf("%d", pn);

    for(i=1; i<=*pn; i++) rez[i]=0;
    for(i=1; i<=*pn; i++) scanf("%d", &a[i]);
}

void afisare(int *rez, int n){
    for(int i=1; i<=n; i++) printf("%d ", rez[i]);
    printf("\n");
}

void back(int a[100], int *rez, int n, int k){
    int i;
    for(i=1; i<=a[k]; i++){
        rez[k]=i;
        if(k==n) afisare(rez, n);
        else back(a, rez, n, k+1);
    }
}

int main()
{
    int n, a[100], rez[100], i;

    citire(a, &n, rez);
    back(a, rez, n, 1);


    return 0;
}
