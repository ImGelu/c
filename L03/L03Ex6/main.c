/// 3.6. Folosind expresii condiţionale, să se scrie un program care citeşte valoarea reală a lui x şi calculează valoarea funcţiei:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x;

    printf("Introduceti o valoare pentru x: ");
    scanf("%lf", &x);

    if(x<-2) printf("f(%.2f) = %.2f", x, x*x+4*x+4);
    else if(x==-2) printf("f(%.2f) = 0", x);
    else printf("f(%.2f) = %.2f", x, x*x+5*x);

    return 0;
}
