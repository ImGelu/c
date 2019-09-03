/// 3.2 Scrieţi un program pentru a verifica modul de execuţie a funcţiei getch când se apasă o tastă specială (F1...F12, CTRL/tastă).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Apasati o tasta speciala: ");
    char c = getch();

    printf("%d ", c);

    c=getch();

    printf("%d\n", c);

    return 0;
}
