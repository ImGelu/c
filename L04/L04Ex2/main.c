/// 3.2. Se citesc 4 perechi de numere reale, care reprezintă în coordonatele vârfurilor unui patrulater. Să se stabilească natura acestui patrulater.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { float x, y; } Punct;

float panta(Punct *A, Punct *B){ return (B->y-A->y)/(B->x-A->y); }

float unghi(Punct *A, Punct *B, Punct *C, Punct *D){
    float u1, u2;

    u1=atan(panta(A, B))*180/M_PI;
    u2=atan(panta(C, D))*180/M_PI;

    return u2-u1;
}

int trapez(Punct *A, Punct *B, Punct *C, Punct *D){
    if(panta(A, B)==panta(C, D) && panta(B, C)!=panta(D, A) || panta(B, C)==panta(D, A) && panta(A, B)!=panta(C, D)) return 1;
    return 0;
}

int paralelogram(Punct *A, Punct *B, Punct *C, Punct *D){
    if(panta(A, B)==panta(A, D) && panta(B, C)==panta(D, A)) return 1;
    return 0;
}

int dreptunghi(Punct *A, Punct *B, Punct *C, Punct *D){
    if(abs(unghi(D, A, A, B))==90) return 1;
    return 0;
}

int romb(Punct *A, Punct *B, Punct *C, Punct *D){
    if(panta(A, C)*panta(B,D)==-1) return 1;
    return 0;
}

int patrat(Punct *A, Punct *B, Punct *C, Punct *D)
{
    if(dreptunghi(A, B, C, D) && romb(A, B, C, D)) return 1;
    return 0;
}


int main()
{
    Punct *A, *B, *C, *D;

    printf("Cititi varful lui A (x, y): ");
    scanf("(%lf, %lf)%*c", &A->x, &A->y);

    printf("Cititi varful lui B (x, y): ");
    scanf("(%lf, %lf)%*c", &B->x, &B->y);

    printf("Cititi varful lui C (x, y): ");
    scanf("(%f, %f)%*c", &C->x, &C->y);

    printf("Cititi varful lui D (x, y): ");
    scanf("(%f, %f)", &D->x, &D->y);

    if(patrat(A, B, C, D)==1) printf("ABCD este patrat");
    else if(trapez(A, B, C, D)==1) printf("ABCD este trapez");
    else if(dreptunghi(A, B, C, D)==1) printf("ABCD este dreptunghi");
    else if(romb(A, B, C, D)==1) printf("ABCD este romb");
    else if(paralelogram(A, B, C, D)) printf("ABCD este paralelogram");

    return 0;
}
