/// 3.6. Să se scrie un program de generare recursivă a submulţimilor de k elemente ale mulţimii A cu n elemente (combinaţiile de n elemente luate câte k).

#include <stdio.h>
#include <stdlib.h>

void citire(int *pn, int *pp, int rez[100]){
    int i;

    printf("Introduceti n = ");
    scanf("%d", pn);

    printf("Introduceti p = ");
    scanf("%d", pp);

    for(i=0; i<=*pn; i++) rez[i]=0;
}

int valid(int *rez, int k){
    int i;
    for(i=1; i<=k-1; i++)
        if(rez[k]==rez[i]) return 0;

    return 1;
}

void afisare(int *rez, int n){
    for(int i=1; i<=n; i++) printf("%d ", rez[i]);
    printf("\n");
}

void back(int *rez, int n, int k, int p){
    int i;

    if(k==p+1) afisare(rez, p);
    else{
        if(k>1) rez[k]=rez[k-1];
        else rez[k]=0;
        while(rez[k]<n-p+k){
            rez[k]++;
            back(rez, n, k+1, p);
        }
    }
}

int main()
{
    int n, p, rez[100];

    citire(&n, &p, rez);
    back(rez, n, 1, p);


    return 0;
}
