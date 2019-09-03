/// 3.5. Să se introducă tipul RAŢIONAL ca o structură formata din numărător şi numitor. Să se scrie funcţii de simplificare, adunare, scădere, înmulţire, împărţire, ridicare la putere.

#include <stdio.h>
#include <stdlib.h>

typedef struct{ int numar, numit; } Rational;

int cmmdc(int a, int b){
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

void afis(Rational f){
    if(f.numar==0) printf("0");
    else if(f.numit==1) printf("%d", f.numar);
    else printf("%d/%d", f.numar, f.numit);
}

void simplifica(Rational *pf){
    int c=cmmdc(pf->numar, pf->numit); /// = (*pf).numar
    pf->numar/=c;
    pf->numit/=c;
}

Rational aduna(Rational f1, Rational f2){
    Rational q;
    q.numar=f1.numar*f2.numit + f2.numar*f1.numit;
    q.numit=f1.numit*f2.numit;

    simplifica(&q);

    return q;
}

Rational citesteFr(char nume){
    Rational f;
    do{
        printf("Fractia %c (a/b):", nume);
        scanf("%d/%d", &f.numar, &f.numit);
        fflush(stdin);
    } while(f.numit==0);

    if(f.numit<0){
        f.numar=-f.numar;
        f.numit=-f.numit;
    }
    simplifica(&f);

    return f;
}

int main()
{
    Rational p, q, r;
    p=citesteFr('p');
    q=citesteFr('q');
    r=aduna(p, q);
    afis(p);
    printf(" + ");
    afis(q);
    printf(" = ");
    afis(r);
    printf("\n");

    return 0;
}
