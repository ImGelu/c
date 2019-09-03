/// 3.14. Să se scrie un program pentru conversia coordonatelor carteziene ale unui punct dat în coordonate polare. În calculul unghiului din coordonatele polare se poate utiliza funcția atan2 din biblioteca math.h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y, tetha, x_pol, y_pol, r;

    printf("Introduceti coordonatele punctului (x, y): ");
    scanf("(%d, %d)", &x, &y);

    r=sqrt(x*x+y*y);
    tetha=atan(y/x);

    x_pol=r*cos(tetha);
    y_pol=r*sin(tetha);

    printf("Coordonatele polare: %.2lf(cos(%.2lf) + i*sin(%.2lf))", r, tetha, tetha);

    return 0;
}
