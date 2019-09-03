/// 3.4. Să se scrie un program care citeşte un unghi în grade sexagesimale şi calculează valoarea funcţiei sinus, cosinus şi tangentă. Se vor folosi funcțiile trigonometrice din biblioteca math.h

#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265
#include <math.h>

int main()
{
    int g;

    printf("Introduceti unghiul in grade sexagesimale: ");
    scanf("%d", &g);

    printf("Sin(%d) = %.2f", g, sin((g*M_PI)/180.0));

    return 0;
}
