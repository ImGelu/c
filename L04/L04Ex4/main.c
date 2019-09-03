/// 3.4. Să se scrie un program pentru generarea tuturor numerelor prime mai mici sau egale cu un număr natural n (Ciurul lui Eratostenes).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100000

int main()
{
    char a[N]={0};
    int n, i, sqrtn, j;

    printf("Introduceti valoarea lui n: ");
    scanf("%d", &n);

    sqrtn=sqrt(n);

    for(i=2; i<=sqrtn; i++){
        if(a[i]==0)
            for(j=i+i; j<=n; j=j+i) a[j]=1;
    }

    for(i=2; i<=n; i++)
        if(a[i]==0) printf("%d ", i);

    return 0;
}
