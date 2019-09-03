/// 3.6. Se citeşte un număr natural n. Să se verifice dacă numărul respectiv este palindrom.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, n_aux, n_inv=0;

    printf("Introduceti valoarea pentru n: ");
    scanf("%d", &n);

    n_aux=n;

    while(n_aux){
        n_inv=n_inv*10+n_aux%10;
        n_aux/=10;
    }

    if(n_inv==n) printf("%d este palindrom", n);
    else printf("%d nu este palindrom", n);

    return 0;
}
