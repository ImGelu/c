/// 3.5. Se citeşte un număr natural n. Să se găsească cel mai mare pătrat perfect mai mic sau egal cu n. Aceeaşi problemă, dar să se indice numărul prim cel mai mic, dar mai mare sau egal cu numărul citit.

#include <stdio.h>
#include <stdlib.h>

int prim(int n){
    if(n==0 || n==1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int d=3; d*d<=n; d=d+2)
        if(n%d==0) return 0;
}

int main()
{
    int n, n_aux;

    printf("Introduceti valoarea pentru n: ");
    scanf("%d", &n);

    n_aux=n;

    printf("Cel mai mare patrat perfect mai mic <=%d: %d\n", n, (int)sqrt(n)*(int)sqrt(n));

    while(!prim(n_aux)) n_aux++;

    printf("Cel mai mic numar prim >=%d: %d", n, n_aux);

    return 0;
}
