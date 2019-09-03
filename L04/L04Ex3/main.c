/// 3.3. De la intrarea standard sunt citite elementele reale ale unui şir de dimensiune n. Să se găsească valoarea minimă şi valoarea maximă dintre elementele şirului şi poziţia lor.

#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    float a[N];

    int n, i, imin=0, imax=0;

    for(n=-1; n<1 || n>N; scanf("%d", &n)){
        printf("Introduceti numarul elementelor (<=%d): ", N);
        fflush(stdin);
    }

    for(i=0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }

    for(i=1; i<n; i++){
        if(a[i]<a[imin]) imin=i;
        if(a[i]>a[imax]) imax=i;
    }

    printf("Minimul %.2f e pe pozitia %d\n", a[imin], imin);

    return 0;
}
