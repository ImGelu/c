/// 3.13. Să se scrie un program pentru calculul masei ideale a unei persoane.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inaltime, varsta;
    double masa_barbat, masa_femeie;

    printf("Introduceti inaltimea: ");
    scanf("%d", &inaltime);

    printf("Introduceti varsta: ");
    scanf("%d", &varsta);

    masa_barbat=50+0.76*(inaltime-150)+(varsta-20)/4;
    masa_femeie=masa_barbat-10;

    printf("Greutatea ideala pentru barbat: %.2f\n", masa_barbat);
    printf("Greutatea ideala pentru femeie: %.2f", masa_femeie);

    return 0;
}
