/// 3.18. Se citește o matrice de dimensiune nxn cu elemente 0 şi 1. Să se stabilească dacă matricea respectivă este simetrică.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100][100], n, i, j;

    printf("Introduceti valoarea pentru n: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(a[i][j]!=a[j][i]){
                printf("Matricea nu este simetrica");
                exit(1);
            }
1
    printf("Matricea este simetrica");

    return 0;
}
