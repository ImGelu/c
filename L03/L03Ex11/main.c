/// 3.11. Să se scrie un program care citește numerele întregi a, b, c, d și afișează valoarea cea mai mare dintre fracțiile a/b și c/d.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;

    printf("Introduceti valoarea pentru a: ");
    scanf("%d", &a);

    printf("Introduceti valoarea pentru b: ");
    scanf("%d", &b);

    printf("Introduceti valoarea pentru c: ");
    scanf("%d", &c);

    printf("Introduceti valoarea pentru d: ");
    scanf("%d", &d);

    if((double)a/b > (double)c/d) printf("%d/%d", a, b);
    else printf("%d/%d", c, d);

    return 0;
}
