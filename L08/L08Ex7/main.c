/// 3.7. Folosind tipul enumerare, să se introducă tipul boolean. Să se scrie o funcţie de ordonare crescătoare a unui şir folosind metoda bulelor şi un semafor de tipul boolean.

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

void bubble(int *a, int n){
    int i, aux;
    bool sortat=false;

    while(!sortat){
        sortat=true;
        for(i=1; i<n; i++)
            if(a[i-1]>a[i]){
                aux=a[i-1];
                a[i-1]=a[i]; /// *(a+i-1)=*(a+i)
                a[i]=aux;
                sortat=false;
            }
        n--;
    }
}

int main()
{
    int a[100], n, i;

    printf("Introduceti n: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) scanf("%d", &a[i]);

    bubble(a, n);

    for(i=0; i<n; i++) printf("%d ", a[i]);

    return 0;
}
