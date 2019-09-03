/// 3.2. Să se scrie un program pentru calculul valorii z= x^y, unde x şi y sunt de tipul double. Se va utiliza funcția pow din biblioteca math.h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y, z;

    printf("Introduceti x: ");
    scanf("%lf", &x);

    printf("Introduceti y: ");
    scanf("%lf", &y);

    z=pow(x, y);

    printf("z = %.2f", z);

    return 0;
}
