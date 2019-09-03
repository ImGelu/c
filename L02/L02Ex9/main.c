/// 3.9. Scrieţi un program care realizează suma, diferenţa, produsul şi împărţirea a două numere reale. Afişarea se va face sub formă tabelară.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;

    printf("Introduceti x: ");
    scanf("%d", &x);

    printf("Introduceti y: ");
    scanf("%d", &y);

    printf("\t x \t y \t x+y \t x-y \t x*y \t x/y \n");
    printf("\t %d \t %d \t %d \t %d \t %d \t %lf ", x, y, x+y, x-y, x*y, (float)x/y);

    return 0;
}
