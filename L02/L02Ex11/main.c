/// 3.11. Scrieţi un program pentru afişarea unui întreg zecimal citit de la tastatură în octal şi hexazecimal.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, aux_x, i, k=0;
    char a[1000];

    printf("Introduceti valoarea lui x: ");
    scanf("%d", &x);

    aux_x=x;

    printf("Valoarea lui x in octal: ");

    while(x>0){
        a[k++]=x%8;
        x/=8;
    }

    for(i=k-1; i>=0; i--) printf("%d", a[i]);

    k=0;

    printf("\nValoarea lui x in hexazecimal: ");

    while(aux_x>0){
        if(aux_x%16<10) a[k++]=aux_x%16 + 48;
        else a[k++]=aux_x%16 + 55;

        aux_x/=16;
    }

    for(i=k-1; i>=0; i--) printf("%c", a[i]);

    return 0;
}
