/// 3.15. Se dau 2 şiruri de n si respectiv m elemente de tip întreg. Să se calculeze:

#include <stdio.h>
#include <stdlib.h>

int apartine(int x, int a[], int n){
    int i;
    for(i=0; i<n; i++)
        if(x==a[i]) return 1;

    return 0;
}

int main()
{
    int nA, nB, a[100], b[100], i, j, c[100], k=0;

    printf("Introduceti numarul de elemente pentru sirul A: ");
    scanf("%d", &nA);

    for(i=0; i<nA; i++){
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Introduceti numarul de elemente pentru sirul B: ");
    scanf("%d", &nB);

    for(i=0; i<nB; i++){
        printf("B[%d] = ", i);
        scanf("%d", &b[i]);
    }

    /// a) şirul ce conţine elementele comune ale celor două şiruri;
    printf("\nIntersectie: ");
    k=0;
    for(i=0; i<nB; i++)
        if(apartine(b[i], a, nA)) c[k++]=b[i];

    for(i=0; i<k; i++) printf("%d ", c[i]);

    /// b) şirul ce conţine toate elementele celor două şiruri luate o singura dată;
    printf("\nReuniune: ");
    k=nA;
    for(i=0; i<nA; i++) c[i]=a[i];
    for(i=0; i<nB; i++)
        if(!apartine(b[i], a, nA)) c[k++]=b[i];

    for(i=0; i<k; i++) printf("%d ", c[i]);

    /// c) şirul ce conţine elementele primului şir din care au fost eliminate elementele comune.
    k=0;
    printf("\nA fara B: ");
    for(i=0; i<nA; i++)
        if(!apartine(a[i], b, nB)) c[k++]=a[i];

    for(i=0; i<k; i++) printf("%d ", c[i]);

    return 0;
}
