/// 3.10. Funcţia lui Ackermann. Să se scrie programul recursiv care calculează funcţia lui Ackermann

#include <stdio.h>
#include <stdlib.h>

int Ack(int m, int n){
    if(m==0) return n+1;
    else if(n==0) return Ack(m-1, 1);
    else return Ack(m-1, Ack(m, n-1));
}

int main()
{
    int m, n;

    printf("Introduceti m: ");
    scanf("%d", &m);

    printf("Introduceti n: ");
    scanf("%d", &n);

    printf("Ack(%d, %d) = %d", m, n, Ack(m, n));

    return 0;
}
