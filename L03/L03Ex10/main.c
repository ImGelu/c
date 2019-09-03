/// 3.10. Să se scrie un program ce efectuează operaţii aritmetice asupra două date de tip întreg şi real. Executaţi-l pentru valori care conduc la rezultat în afara limitelor de reprezentare internă. Ce se întâmplă în acest cazuri?

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int a = INT_MAX;
    printf("%x / %d\n\n", a, a);

    printf("a+1 = %x / %d\n", a+1, a+1);
    printf("4*a = %x / %d\n", 4*a, 4*a);

    float b = 1e15, c=13-5, d;

    d=b+c;

    printf("%f + %f = %f\n", b, c, d);

    return 0;
}
