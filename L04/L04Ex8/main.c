/// 3.8. Se citesc gradul şi coeficienţii polinomului p(x)=a0+a1*x^1+...+an*x^n. Să se calculeze valoarea polinomului în punctul x=x0 (valoarea x0 se citeşte).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

int main()
{
    int a[N], n, x0, val_pol, i;

    printf("Introduceti gradul polinomului (maxim %d): ", N);
    scanf("%d", &n);

    printf("Introduceti valoarea pentru x0: ");
    scanf("%d", &x0);

    printf("Introduceti coeficientii polinomului: \n");
    for(i=0; i<=n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        val_pol+=a[i]*pow(x0, i);
    }

    printf("f(%d) = %d", x0, val_pol);

    return 0;
}
