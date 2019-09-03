/// 3.3. Folosind numai pointeri şi expresii cu pointeri se va scrie o funcţie de interclasare a doi vectori, care conţin elemente de tip real ordonate crescător (precum şi programul care testează această funcţie).

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

void afisare(float a[], int n){
    int i;
    for(i=0; i<n; i++) printf("%.0f ", a[i]);
}

float *intercl(float a[], int na, float b[], int nb, int *pnc){
    int i=0, j=0, k=0;

    *pnc=na+nb;
    float *c = calloc(*pnc, sizeof(float));
    if(c==NULL){
        printf("Memorie insuficienta");
        exit(1);
    }

    while(i<na && j<nb)
        if(a[i]<=b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];

    while(i<na) c[k++]=a[i++];
    while(j<nb) c[k++]=b[j++];

    return c;
}

int main()
{
    float *a, *b, *c;
    int na, nb, nc;

    a=citeste(&na, 'a');
    b=citeste(&nb, 'b');
    c=intercl(a, na, b, nb, &nc);

    printf("Rezultatul interclasarii: ");
    afisare(c, nc);

    free(a);
    free(b);

    return 0;
}
