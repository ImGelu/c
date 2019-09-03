/// 3.12. Să se scrie un program care determină poziția relativă a unei linii drepte față de un cerc. Programul va citi: coordonatele centrului cercului, raza cercului și coordonatele a două puncte care determină linia.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int xC, yC, r, xA, yA, xB, yB, n;
    double a, b, c, m, dist, d; /// m = panta dreptei

    printf("Cititi coordonatele centrului cercului (x, y): ");
    scanf("(%d, %d)", &xC, &yC);

    printf("Cititi raza cercului: ");
    scanf("%d%*c", &r);

    printf("Cititi coordonatele lui A (x, y): ");
    scanf("(%d, %d)%*c", &xA, &yA);

    printf("Cititi coordonatele lui B (x, y): ");
    scanf("(%d, %d)", &xB, &yB);

    m=(yB-yA)/(xB-xA);
    n=yA-m*xA;

    dist=abs(m*xC-yC+n)/sqrt(1+m*m);

    if(dist>r) printf("Dreapta este in exteriorul cercului");
    else if(dist==r) printf("Dreapta este tangenta cercului");
    else printf("Dreapta trece prin cerc");

    return 0;
}
