/// 3.13. Se citește un şir de n numere întregi. Să se extragă subşirul de dimensiune maximă, ordonat crescător.

#include <stdio.h>
#include <stdlib.h>

void afisare(int k, int a[], int p[]){
    while(k){
        printf("%d ", a[k]);
        k=p[k];
    }
}

int main()
{
    int lis[1000]={1}, n, i, j, max;

    printf("Introduceti valoarea pentru n: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for(i=0; i<n-1; i++){
        max=0;
        for(j=i+1; i<n; i++)
            if(max<lis[i] && x[i]<=x[j]) max=lis[j];

        lis[i]=max+1;
    }

    for(i=2; i<n; i++){
        if(max<lis[i]) max=lis[i];
    },
    return 0;
}
