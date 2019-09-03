/// 3.12. Se citește un şir de n elemente reale ordonate crescător. Să se verifice dacă o valoare citită x se găseşte în şir şi să se indice poziţia sa.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], n, x, i, mij, ls=0, ld;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    printf("Introduceti valoarea cautata: ");
    scanf("%d", &x);

    ld=n;

    for(i=0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    while(ls<=ld){
        mij=(ld+ls)/2;
        if(a[mij]==x){
            printf("S-a gasit %d pe pozitia %d", x, mij);
            exit(1);
        }
        if(a[mij]>x) ld=mij-1;
        else ls=mij+1;
    }

    printf("Nu s-a gasit nicaieri valoarea %d", x);

    return 0;
}
