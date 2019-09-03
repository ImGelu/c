/// 3.3. Problema turnurilor din Hanoi

#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char a, char b, char c){
    if(n==1) muta(a, c, n);
    else {
        Hanoi(n-1, a, c, b);
        muta(a, c, n);
        Hanoi(n-1, b, a, c);
    }
}

void muta(char a, char b, int n){
    static int i=1;
    printf("%d. %c --> %c (discul #%d)\n", i++, a, b, n);
}

int main()
{
    int n;

    printf("N = ");
    scanf("%d", &n);

    Hanoi(n, 'A', 'B', 'C');

    return 0;
}
