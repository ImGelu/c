/// 3.2. Să se scrie o funcţie recursivă şi una nerecursivă pentru calculul valorii polinoamelor Hermite H(x)

#include <stdio.h>
#include <stdlib.h>

int H(int n, int x){
    if(n==0) return 1;
    if(n==1) return 2*x;
    return 2*x*H(n-1, x)-2*(n-1)*H(n-2, x);
}

int main()
{
    int n, x, i, h2=1, h1, h;
    printf("N = ");
    scanf("%d", &n);

    printf("X = ");
    scanf("%d", &x);

    h1=2*x;

    printf("Valoarea functiei este %d", H(n, x));

    /// Nerecursiv (ca si in Fibonacci)

    for(i=2; i<=n; i++){
        h2=h1;
        h1=h;
        h=2*x*h1-2*(i-1)*h2;
    }

    return 0;
}
