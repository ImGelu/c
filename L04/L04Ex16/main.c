/// 3.16. Se citește un număr real în baza 10. Să se scrie programul de conversie a lui în baza B, B <= 16.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BMAX 16

int main()
{
    char s[20];

    int b, nr, i=-1, r, cn;

    printf("Baza (intre 2 si %d): ", BMAX);

    scanf("%d%*c", &b);
    printf("Numarul in baza 10: ");
    scanf("%d", &nr);

    cn=nr;

    do{
        r=cn%b;
        cn/=b;
        i++;
        if(r<10) s[i]=r+'0';
        else s[i]=r-10+'A';
    } while(cn>0);

    printf("Numarul %d transformat in baza %d: \n", nr, b);

    printf("%s", s);


    return 0;
}
