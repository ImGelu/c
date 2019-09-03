/// 3.3. Să se scrie un program pentru a evidenția deosebirea între împărţirea reală şi cea întreagă.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Introduceti a: ");
    scanf("%d", &a);

    printf("Introduceti b: ");
    scanf("%d", &b);

    printf("Catul impartirii: %d / %d: %d\n", a, b, a/b);
    printf("Impartire reala: %d / %d: %.2f\n", a, b, a/(float)b);

    return 0;
}
