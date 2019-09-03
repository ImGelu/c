/// 3.12. Să se scrie o funcție pentru a verifica dacă parametrul ei (un întreg pozitiv) este pătrat perfect. Utilizați funcția pe un șir de întregi pozitivi cu scopul extragerii tuturor pătratelor perfecte într-un alt șir.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int patratPerfect(int n){
    if((int)sqrt(n)==sqrt(n)) return 1;
    return 0;
}

int main()
{
    int n;

    printf("Introduceti un numar: ");
    scanf("%d", &n);

    if(patratPerfect(n)) printf("%d este patrat perfect", n);
    else printf("%d nu este patrat perfect", n);

    return 0;
}
