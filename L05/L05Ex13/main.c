/// 3.13. Să se scrie o funcție care verifică dacă parametrul ei (un întreg pozitiv) este număr perfect. Numărul perfect este un număr întreg egal cu suma divizorilor săi, din care se exclude numărul însuși.

#include <stdio.h>
#include <stdlib.h>

int sDiv(int n){
    int i, s=1;
    for(i=2; i<=n/2; i++)
        if(n%i==0) s+=i;

    return s;
}

void perfect(int n){
    if(sDiv(n)==n) printf("%d este numar perfect", n);
    else printf("%d nu este numar perfect", n);
}

int main()
{
    int n;
    printf("Introduceti numarul: ");
    scanf("%d", &n);

    perfect(n);

    return 0;
}
