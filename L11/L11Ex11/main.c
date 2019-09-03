/// 3.11. Să se scrie un program recursiv pentru căutarea eficientă a unei valori într-un tablou care conține numere reale ordonate crescător.

#include <stdio.h>
#include <stdlib.h>

void citire(int a[100], int *pn, int *x){
    int i;

    printf("Introduceti n: ");
    scanf("%d", pn);

    for(i=0; i<*pn; i++){
        scanf("%d", &a[i]);
    }

    printf("Introduceti valoarea cautata: ");
    scanf("%d", x);
}

int cautareBinara(int *a, int x, int ls, int ld){
    int mij;

    if(ls>ld) return -1;
    else {
        mij=(ls+ld)/2;
        if(a[mij]==x) return mij;
        if(x<a[mij]) return cautareBinara(a, x, ls, ld-1);
        else return cautareBinara(a, x, ls+1, ld);
    }
}

int main()
{
    int a[100], n, x, rez;

    citire(a, &n, &x);
    rez=cautareBinara(a, x, 1, n);

    if(rez==-1) printf("%d nu a fost gasit in sir", x);
    else printf("%d a fost gasit pe pozita %d in sir", x, rez);

    return 0;
}
