/// 3.2. Folosind numai pointeri şi expresii cu pointeri se vor scrie funcţii de sortare a unui vector cu elemente reale (precum şi programul care le testează).

#include <stdio.h>
#include <stdlib.h>

float *citeste(int *pn, char nume){
    int i;

    printf("Numar de elemente pentru %c: ", nume);
    scanf("%d", pn);

    float *a = calloc(*pn, sizeof(float));
    if(a==NULL){
        printf("Memorie insuficienta");
        exit(1);
    }

    for(i=0; i<*pn; i++){
        printf("%c[%d]=", nume, i);
        scanf("%f", &a[i]);
    }

    return a;
}

void bubble(float *a, int n){
    int i, sortat=0;
    float aux;

    while(!sortat){
        sortat=1;
        for(i=1; i<n; i++)
            if(a[i-1]>a[i]){
                aux=a[i-1];
                a[i-1]=a[i]; /// *(a+i-1)=*(a+i)
                a[i]=aux;
                sortat=0;
            }
        n--;
    }
}

void afiseaza(float a[], int n){
    int i;
    for(i=0; i<n; i++) printf("%.0f ", a[i]);
}

int main()
{
    int n;
    float *a;

    a=citeste(&n, 'a');
    bubble(a, n);
    printf("Dupa sortare:\n");
    afiseaza(a, n);
    free(a);

    return 0;
}

/// t      <=> &t[0]
/// *t     <=> t[0]
/// t+i    <=> &t[i]
/// *(t+i) <=> t[i]
