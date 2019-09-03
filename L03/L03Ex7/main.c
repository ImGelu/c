/// 3.7. Să se scrie un program care citeşte un număr real x, ce reprezintă măsura unui unghi în radiani, şi îl transformă în grade, minute şi secunde sexagesimale.

#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265
#include <math.h>

int main()
{
    double r, grade, minute, secunde;

    printf("Introduceti gradele: ");
    scanf("%lf", &r);

    grade=r*(180/M_PI);
    minute=(grade-(int)grade)*60.0;
    secunde=(minute-(int)minute)*60.0;

    printf("%.2lf grade, %.2lf minute, %.2lf secunde", grade, minute, secunde);

    return 0;
}
